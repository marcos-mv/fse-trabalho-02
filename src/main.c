#include <stdio.h>
#include <signal.h>
#include <time.h>
#include <pthread.h>
#include <string.h>
#include "switch.h"
#include "onoff.h"
#include "uart.h"
#include "lcd.h"
#include "bme280.h"
#include "pwm.h"
#include "pid.h"

#define ON_OFF 0
#define PID 1

#define SWITCH 0
#define CONTROL_CUSTOM 1

#define POTENCIOMETER 0
#define TEMP_CUSTOM 1

FILE *logger;
float ti, tr, te, tr_temp;
float histerese = 4.0;
int temp_type = POTENCIOMETER;
int control_define = SWITCH;
int control_type = ON_OFF;
int prev_switch;
int loop = 0;
int aux = -1;

void *menu() {
    while(1) {
        aux = -1;
        printf("\nDefinir controle ou temperatura:\n0 - Controle\n1 - Temperatura\n");
        scanf(" %d", &aux);
        if(aux == 0){
            aux = -1;
            printf("\nEscolha como será definido o tipo de controle:\n0 - Botão switch físico\n1 - Entrada do teclado\n");
            scanf(" %d", &aux);
            if(aux == SWITCH)
                control_define = SWITCH;
                
            else if(aux == CONTROL_CUSTOM){
                aux = -1;
                control_define = CONTROL_CUSTOM;
                printf("\nEscolha um tipo de controle:\n0 - ON/OFF\n1 - PID\n");
                scanf(" %d", &aux); 
                if(aux == ON_OFF){
                    control_type = ON_OFF;
                    printf("\nDigite a faixa da histerese em gruas Celsius:\n");
                    scanf(" %f", &histerese); 
                }
                else if(aux == PID){
                    control_type = PID;
                }
            }
            aux = 0;
        }
        else if(aux == 1){
            aux = -1;
            printf("\nEscolha como será definida a temperatura referencial:\n0 - Potenciomêtro\n1 - Entrada do teclado\n");
            scanf(" %d", &aux);
            if(aux == POTENCIOMETER)
                temp_type = POTENCIOMETER;
            else if(aux == 1){
                temp_type = TEMP_CUSTOM;
                printf("\nDigite a temperatura referencial\n");
                scanf(" %f", &tr_temp);   
            }
        }
    }
}

void shut_down() {
    while(turn_off(FAN));
    while(turn_off(RESISTOR));
    fclose(logger);
    exit(0);
}

void routine() {
    alarm(1);
    struct tm *info;
    char datetime[80];
    double pid_value;
    time_t rawtime;
    time(&rawtime);
    info = localtime(&rawtime);
    strftime(datetime, 80, "%d/%m/%Y %X", info);
    loop = loop % 2;

    do {
    ti = get_temperature(INTERNAL);
    } while (ti == -1.0);

    if (temp_type == POTENCIOMETER) {
        do {
        tr = get_temperature(REFERENCE);
        } while (tr == -1.0);
    } else {
        tr = tr_temp;
    }
    te = get_external_temperature();
    
    if(control_define == SWITCH){
        control_type = get_switch_status(SWITCH_STATUS);
        printf("\nSwitch status: %d\n", control_type);
    }
    printf("\nTI: %f\nTR: %f\nTE: %f\n", ti, tr, te);

    if(control_type == PID) {
        pid_set_constants(5.0, 1.0, 5.0);
        pid_set_reference(tr);
        pid_value = pid_control(ti);

        // Write temperatures on LCD
        write_temperatures(ti, tr, te);

        if(pid_value > 0) {
            while (control(RESISTOR, (int)pid_value));
            while (turn_off(FAN));
        } else {
            if(pid_value < -40.0) {
                while (control(FAN, (int)(-1.0*pid_value)));
            }
            while(turn_off(RESISTOR));
        }
        send_control_signal((int)pid_value);
    }
    else if(control_type == ON_OFF) {
        int on_off = on_off_control(ti, tr, histerese);
        // Write temperatures on LCD
        write_temperatures(ti, tr, te);
        if(on_off > 0) {
            while (control(RESISTOR, 100));
            while (turn_off(FAN));
            send_control_signal(100);
        } else if (on_off == 0) {
            while(turn_off(RESISTOR));
            while (control(FAN, 100));
            send_control_signal(-100);
        }
    }

    if (loop == 0) {
        fprintf(logger, "%s, %.2f, %.2f, %.2f, %.2f\n", datetime, ti, te, tr, pid_value);
    }
    loop++;
}

int main() {
    logger = fopen("logger.csv", "w+");
    fprintf(logger, "Data/Hora, TI, TE, TR, PID\n");

    pthread_t id;

    while(lcd_setup());

    signal(SIGALRM, routine);
    signal(SIGINT, shut_down);

    pthread_create(&id, NULL, menu, NULL);
    routine();

    while (1);

    return 0;
}
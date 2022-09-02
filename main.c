#include <stdio.h>
#include <stdlib.h>
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
#include "menu.h"

void testeUart(){
    get_temperature(SOLICITARTEMP);
    
}
void modo2(){
    printf("modo 2\n");
}
void modo3(){
    printf("modo 3\n");
}
void modo4(){
    printf("modo 4\n");
}
void modo5(){
    printf("modo 5\n");
}
void modo6(){
    printf("modo 6\n");
}
void modo8(){
    printf("modo 8\n");
}

int main(){
    int opcao = 0;

    printf("            ====Airfrier====\n");

    printf("Escolha o modo de funcionamento.\n");

    printf("1 - Liga o Forno      2 - Desliga o Forno\n");
    printf("3 - Inicia Aquecimento      4 - Cancela processo\n");    
    printf("5 - Tempo +      6 - Tempo -\n");    
    printf("7 - Menu      8 - Modo 8\n");

    scanf("%d", &opcao);

    printf("%d\n", opcao);

    switch(opcao){
        case 1:
            printf("Ligando Forno\n");
            LigaForno();
            break;
        case 2:
            printf("Desligando Forno.\n");
            modo2();
            break;
        case 3:
            printf("Iniciando Aquecimento\n");
            modo3();
            break;
        case 4:
            printf("Processo Cancelado.\n");
            modo4();
            break;
        case 5:
            printf("Mais 1 min.\n");
            modo5();
            break;
        case 6:
            printf("Menos 1 min.\n");
            modo6();
            break;
        case 7:
            printf("Acessando Menu.\n");
            menu();
            break;
        case 8:
            printf("Modo 8 - Ativado.\n");
            modo8();
            break;
        default:
            printf("Modo inexistente. PorFavor escolha novamente.\n");       
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "uart.h"
#include "pwm.h"
#include "menu.h"
#include "bme280.h"
#include "temperaturas.h"

float SolicitaTempInterna()
{
    printf("\nTemperatura Interna: %.2f \n", get_temperature(SOLICITARTEMP));
    return get_temperature(SOLICITARTEMP);
}

float SolicitaTempRef()
{
    printf("Temperatura de Referência: %.2f \n", get_temperature(SOLICITARTEMPREF));
    return get_temperature(SOLICITARTEMPREF);
}

float SolicitaTempAmbiente()
{
    printf("Temperatura Ambiente BME280: %.2f \n", TemperaturaAmbienteBME280());
    return TemperaturaAmbienteBME280();
}

void acionaResistor(float temperaturaInterna, float temperaturaRef, int tempo){
    
    int segundos = tempo * 60;
    int j = 0;

    printf("Acionando Resistor");
    //chama função pra esquentar

    if (temperaturaInterna == (temperaturaRef-1) ){
        for(int i=segundos; i==0; i--){
            printf("TI: %f TF: %f\n",temperaturaInterna,temperaturaRef);
            printf("Time: %d min\n", tempo);
            j++;

            if(j==60){
                tempo --;
                j=0;
            }           
        };
    }

    if (tempo == 0){
        acionaFan(temperaturaInterna);
    }
}

void acionaFan(float temperaturaInterna){

    printf("Acionando Fan");
    //chama função pra esquentar

    while ((temperaturaInterna - 2) != (TemperaturaAmbienteBME280()) )
    {
        printf("Resfriando");
    }
}

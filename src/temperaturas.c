#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "uart.h"
#include "pwm.h"
#include "menu.h"
#include "bme280.h"
#include "temperaturas.h"


void SolicitaTempInterna()
{
    printf("\nTemperatura Interna: %.2f \n", get_temperature(SOLICITARTEMP));
}

void SolicitaTempRef()
{
    printf("Temperatura de Referência: %.2f \n", get_temperature(SOLICITARTEMPREF));
}

void SolicitaTempAmbiente()
{
    printf("Temperatura Ambiente BME280: %.2f \n", TemperaturaAmbienteBME280());
}
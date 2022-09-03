#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "uart.h"
#include "pwm.h"
#include "menu.h"
#include "bme280.h"
#include "temperaturas.h"
#include "telainicial.h"

void LeComandoUsuario()
{
    while (1)
    {
        printf("Lendo Comandos do Usuário: %f\n", (LECOMANDOUSUARIO));
        sleep(1);
    }
}
void EnviaSinalControle()
{
    while (1)
    {
        printf("Enviando Sinal de Controle: %d\n", send_control_signal(SEND_SIGNAL_CONTROL));
        sleep(1);
    }
}
void EnviaSinalReferencia()
{
    while (1)
    {
        printf("Envia Sinal de Referência %d\n", get_temperature(LECOMANDOUSUARIO));
        sleep(1);
    }
}
void modo6()
{
    printf("modo 6\n");
}
void modo8()
{
    printf("modo 8\n");
}

// void aquecer(){

// }

// void resfriar(){

// }



int main()
{
    telaInicial();

    return 0;
}
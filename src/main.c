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

// void aquecer(){

// }

// void resfriar(){

// }

int main()
{
    float temperatura = 0;
    int tempo = 0;

    printf("Sistema Acionado\n");
    printf("\nAcione o Botão de Ligar na Dasboard para iniciar os procedimentos\n");

    while(1){
        get_user_comand(LECOMANDOUSUARIO);

        if(get_user_comand(LECOMANDOUSUARIO) == 0x01){
        printf("Comando  do usuário %d\n", get_user_comand(LECOMANDOUSUARIO));
        printf("Ligando Airfryer.\n\n");
        telaInicial(tempo, temperatura);
        break;
        }
    }
    return 0;
}
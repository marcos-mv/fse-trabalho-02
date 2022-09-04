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
    int ligado = 0;

    printf("Sistema Acionado\n");
    printf("Acione o Botão de Ligar ou digite 1 para iniciar os procedimentos.\n");

    while(1){
        scanf("%d", &ligado);
        get_user_comand(LECOMANDOUSUARIO);
        printf("Comando  do usuário %d\n", get_user_comand(LECOMANDOUSUARIO));

        if(get_user_comand(LECOMANDOUSUARIO) == 0x01 || ligado == 1){
        printf("Ligando Airfryer.\n\n");
        telaInicial();
        break;
        }
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "uart.h"
#include "pwm.h"
#include "menu.h"
#include "bme280.h"
#include "temperaturas.h"

void LeComandoUsuario()
{

    while (1)
    {
        printf("Lendo Comandos do Usuário: %d\n", get_user_comand(LECOMANDOUSUARIO));
        int comando = get_user_comand(LECOMANDOUSUARIO);
        sleep(1);

        if (comando == 0x01)
        {
            printf("Ligando Airfryer\n");
        }
        else if (comando == 0x02)
        {   
            printf("Desligando Airfryer\n");
            exit(0);
        }
        else if (comando == 0x03)
        {
            printf("Iniciando Aquecimento\n");

        }
        else if (comando == 0x04)
        {
            printf("Cancelando Processo\n");
        }
        else if (comando == 0x05)
        {
            printf("+ 1 minuto\n");
        }
        else if (comando == 0x06)
        {
            printf("- 1 minuto\n");
        }
        else if( comando == 0x07){
            printf("Abrindo menu");
        }
        else
            {
                printf("Abrindo Menu\n");
            }
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

void ligandoForno()
{
    printf("\nLigando Forno\n");
}
void desligaForno()
{
    printf("\nDesligando Forno\n");
}

void iniciaAquecimento()
{
    printf("\nIniciando Aquecimento\n");
}

void cancelaProcesso()
{
    printf("\nProcesso Cancelado\n");
}

void maisUmMinuto()
{
    printf("\nMais um Minuto\n");
}

void menosUmMinuto()
{
    printf("\nMenos um Minuto\n");
}

void telaInicial()
{
    int opcao = 0;

    printf("            ====Airfrier====\n");

    printf("Escolha o modo de funcionamento.\n");

    printf("1 - Liga o Forno                    2 - Desliga o Forno\n");
    printf("3 - Inicia Aquecimento              4 - Cancela processo\n");
    printf("5 - Tempo +                         6 - Tempo -\n");
    printf("7 - Menu                            8 - Solicita Temp interna e de Referência\n");
    printf("9 - Lê comandos do Usuário\n");
    printf("10 - Envia Sinal de Controle        11 - Envia Sinal de Referência\n");
    printf("12 - Envia Estado do Sistema        13 - Modo de Controle da Temperatura de Referência\n");
    printf("13 - Envia Estado de Funcionamento      14 - Envia Valor do Temporizador\n");

    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        ligandoForno();
        break;
    case 2:
        printf("Desligando Forno.\n");
        desligaForno();
        break;
    case 3:
        printf("Iniciando Aquecimento\n");
        iniciaAquecimento();
        break;
    case 4:
        printf("Processo Cancelado.\n");
        cancelaProcesso();
        break;
    case 5:
        printf("Mais 1 min.\n");
        maisUmMinuto();
        break;
    case 6:
        printf("Menos 1 min.\n");
        menosUmMinuto();
        break;
    case 7:
        printf("Acessando Menu.\n");
        menu();
        break;
    case 8:
        printf("Solicitando Temp Interna, de Referencia e Ambiente\n");

        while (1)
        {
            sleep(1);
            SolicitaTempInterna();
            SolicitaTempRef();
            SolicitaTempAmbiente();
        }

        break;
    case 9:
        printf("Lendo Comandos do Usuário.\n");
        LeComandoUsuario();
        break;
    case 10:
        printf("Envia Sinal de Controle.\n");
        EnviaSinalControle();
        break;
    case 11:
        printf("Envia Sinal de Referência.\n");
        EnviaSinalReferencia();
        break;
    default:
        printf("Modo inexistente. PorFavor escolha novamente.\n");
    }
}
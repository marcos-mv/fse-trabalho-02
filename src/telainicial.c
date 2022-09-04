#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

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
        printf("Lendo Comandos do Usuário: %d\n", get_user_comand(LECOMANDOUSUARIO));
        int comando = get_user_comand(LECOMANDOUSUARIO);
        sleep(1);

        if (comando == 0x02)
        {
            printf("Desligando Airfryer\n"); // Desliga Airfryer e manda o usuário para a tela de seleção de opções.
            exit(0);
        }
        else if (comando == 0x03)
        {
            printf("Iniciando Aquecimento\n");

            while (get_user_comand(LECOMANDOUSUARIO) != 0x02 || get_user_comand(LECOMANDOUSUARIO) != 0x04)
            {
                get_user_comand(LECOMANDOUSUARIO);
                SolicitaTempInterna();
                SolicitaTempRef();
                SolicitaTempAmbiente();
                time_t clk = time(NULL);
                printf("%s", ctime(&clk));
            }
        }
        else if (comando == 0x04)
        {
            printf("Cancelando Processo\n");
            telainicial();
        }
        else if (comando == 0x05)
        {
            printf("+ 1 minuto\n");
        }
        else if (comando == 0x06)
        {
            printf("- 1 minuto\n");
        }
        else if (comando == 0x07)
        {
            printf("Abrindo menu");
        }
        else
        {
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

    telaInicial(int tempo,  );
}

void menosUmMinuto()
{
    printf("\nMenos um Minuto\n");
}

void telaInicial(int tempo, float temperatura)
{
    int opcao = 0;
    int tempo1 = tempo;
    int aquecimento = 0;
    int resfriamento = 0;
    int temperatura1 = temperatura;
    
    printf("            ====Airfrier====\n");

    printf("Escolha o modo de funcionamento.\n");

    printf("1 - Desliga o Forno\n");
    printf("2 - Inicia Aquecimento              3 - Cancela processo\n");
    printf("4 - Tempo +                         5 - Tempo -\n");
    printf("6 - Menu\n\n");
    printf("7 - Solicita Temperaturas           8 - Lê comandos do Usuário\n");
    printf("9 - Envia Sinal de Controle         10 - Envia Sinal de Referência\n");
    printf("11 - Envia Estado do Sistema        12 - Modo de Controle da Temperatura de Referência\n");
    printf("13 - Envia Estado de Funcionamento  14 - Envia Valor do Temporizador\n");

    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        printf("Desligando Forno.\n");
        desligaForno();
        break;
    case 2:
        printf("Iniciando Aquecimento\n");
        iniciaAquecimento();
        break;
    case 3:
        printf("Processo Cancelado.\n");
        cancelaProcesso();
        break;
    case 4:
        printf("Mais 1 min.\n");
        maisUmMinuto();
        break;
    case 5:
        printf("Menos 1 min.\n");
        menosUmMinuto();
        break;
    case 6:
        printf("Acessando Menu.\n");
        menu();
        break;
    case 7:
        printf("Solicitando Temp Interna, de Referencia e Ambiente\n");

        while (1)
        {
            sleep(1);
            SolicitaTempInterna();
            SolicitaTempRef();
            SolicitaTempAmbiente();
        }

        break;
    case 8:
        printf("Lendo Comandos do Usuário.\n");
        LeComandoUsuario();
        break;
    case 9:
        printf("Envia Sinal de Controle.\n");
        EnviaSinalControle();
        break;
    case 10:
        printf("Envia Sinal de Referência.\n");
        EnviaSinalReferencia();
        break;
    default:
        printf("Modo inexistente. PorFavor escolha novamente.\n");
    }
}
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
#include "controle.h"

void telaInicial(int tempo, float temperatura)
{
    int opcao = 0;
    int tempo1 = tempo;
    int aquecimento = 0;
    int resfriamento = 0;
    float temperatura1 = temperatura;
    
    printf("            ====Airfrier====\n");

    printf("\nTempo: %d min Temperatura: %.2f\n\n", tempo1, temperatura1);

    printf("Escolha o modo de funcionamento.\n");

    printf("1 - Desliga o Forno\n");
    printf("2 - Inicia Aquecimento              3 - Cancela processo\n");
    printf("4 - Tempo +                         5 - Tempo -\n");
    printf("6 - Menu\n\n");
    // printf("7 - Solicita Temperaturas           8 - Lê comandos do Usuário\n");
    // printf("9 - Envia Sinal de Controle         10 - Envia Sinal de Referência\n");
    // printf("11 - Envia Estado do Sistema        12 - Modo de Controle da Temperatura de Referência\n");
    // printf("13 - Envia Estado de Funcionamento  14 - Envia Valor do Temporizador\n");

    printf("\n\nEsperando comando do usuário na Dasboard\n\n");

    leComandoUsuario();
    // scanf("%d", &opcao);

    // switch ()
    // {
    // case 1:
    //     printf("Desligando Forno.\n");
    //     desligaForno();
    //     break;
    // case 2:
    //     printf("Iniciando Aquecimento\n");
    //     iniciaAquecimento(tempo, temperatura1);
    //     break;
    // case 3:
    //     printf("Processo Cancelado.\n");
    //     cancelaProcesso();
    //     break;
    // case 4:
    //     printf("Mais 1 min.\n");
    //     maisUmMinuto(tempo1,temperatura1);
    //     break;
    // case 5:
    //     printf("Menos 1 min.\n");
    //     menosUmMinuto(tempo1, temperatura1);
    //     break;
    // case 6:
    //     printf("Acessando Menu.\n");
    //     menu();
    //     break;
    // case 7:
    //     printf("Solicitando Temp Interna, de Referencia e Ambiente\n");

    //     while (1)
    //     {
    //         sleep(1);
    //         SolicitaTempInterna();
    //         SolicitaTempRef();
    //         SolicitaTempAmbiente();
    //     }

    //     break;
    // case 8:
    //     printf("Lendo Comandos do Usuário.\n");
    //     LeComandoUsuario();
    //     break;
    // case 9:
    //     printf("Envia Sinal de Controle.\n");
    //     EnviaSinalControle();
    //     break;
    // case 10:
    //     printf("Envia Sinal de Referência.\n");
    //     EnviaSinalReferencia();
    //     break;
    // default:
    //     printf("Modo inexistente. PorFavor escolha novamente.\n");
    // }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "uart.h"
#include "pwm.h"
#include "menu.h"

void SolicitaTempInterna()
{

    while (1)
    {
        printf("%f", get_temperature(SOLICITARTEMP));
        sleep(1);
    }
}
void SolicitaTempRef()
{
    while (1)
    {
        printf("%f", get_temperature(SOLICITARTEMPREF));
        sleep(1);
    }
}
void LeComandoUsuario(){

    while (1)
    {
        printf("%f", get_temperature(LECOMANDOUSUARIO));
        sleep(1);
    }
}
void modo4()
{
    printf("modo 4\n");
}
void modo5()
{
    printf("modo 5\n");
}
void modo6()
{
    printf("modo 6\n");
}
void modo8()
{
    printf("modo 8\n");
}

int main()
{
    int opcao = 0;

    printf("            ====Airfrier====\n");

    printf("Escolha o modo de funcionamento.\n");

    printf("1 - Liga o Forno      2 - Desliga o Forno\n");
    printf("3 - Inicia Aquecimento      4 - Cancela processo\n");
    printf("5 - Tempo +      6 - Tempo -\n");
    printf("7 - Menu      8 - Solicita Temp interna\n");
    printf("9 - Solicita Temperatura de Referência      10 - Lê comandos do Usuário\n");

    scanf("%d", &opcao);

    printf("%d\n", opcao);

    switch (opcao)
    {
    case 1:
        printf("Ligando Forno\n");
        break;
    case 2:
        printf("Desligando Forno.\n");
        break;
    case 3:
        printf("Iniciando Aquecimento\n");
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
        printf("Solicitando TempREF.\n");
        SolicitaTempInterna();
        break;
    case 9:
        printf("Solicitando TempREF.\n");
        SolicitaTempRef();
        break;
    case 10:
        printf("Lendo Comandos do Usuário.\n");
        LeComandoUsuario();
        break;
    default:
        printf("Modo inexistente. PorFavor escolha novamente.\n");
    }

    return 0;
}
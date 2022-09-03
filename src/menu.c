#include <stdio.h>
#include <stdlib.h>

void menu()
{
    int opcao = 0;
    int temperatura = 0;
    int tempo = 0;

    printf("=== Lista de Alimentos ===\n");
    printf("Escolha um alimento abaixo.\n");

    printf("1 - Frango a Passarinho      2 - Peixe \n");
    printf("3 - Pão de Queijo      4 - Coxinha de Frango\n");
    printf("5 - Pudim      6 - Costelinha de Porco -\n");
    printf("7 - Batata Frita      8 - Almôndegas\n");
    printf("9 - Voltar a tela Inicial.\n");

    scanf("%d", &opcao);

    printf("%d\n", opcao);

    switch (opcao)
    {
    case 1:
        temperatura = 80;
        tempo = 1;
        printf("Frango a Passarinho\n");
        printf("Temperatura %d Tempo: %d min\n", temperatura, tempo);
        break;
    case 2:
        temperatura = 40;
        tempo = 1;
        printf("Peixe\n");
        printf("Temperatura: %d Tempo: %d min\n", temperatura, tempo);

        break;
    case 3:
        temperatura = 45;
        tempo = 1;
        printf("Pão de Queijo\n");
        printf("Temperatura: %d Tempo: %d min\n", temperatura, tempo);

        break;
    case 4:
        temperatura = 50;
        tempo = 1;
        printf("Coxinha de Frango\n");
        printf("Temperatura: %d Tempo: %d min\n", temperatura, tempo);

        break;
    case 5:
        temperatura = 70;
        tempo = 1;
        printf("Pudim\n");
        printf("Temperatura: %d Tempo: %d min\n", temperatura, tempo);

        break;
    case 6:
        temperatura = 60;
        tempo = 1;
        printf("Costelinha de Porco\n");
        printf("Temperatura %d Tempo: %d min\n", temperatura, tempo);

        break;
    case 7:
        temperatura = 80;
        tempo = 1;
        printf("Batata Frita\n");
        printf("Temperatura: %d Tempo: %d min\n", temperatura, tempo);

        break;
    case 8:
        temperatura = 90;
        tempo = 1;
        printf("Almôndegas\n");
        printf("Temperatura: %d Tempo: %d min\n", temperatura, tempo);

        break;
    case 9:
        temperatura = 90;
        tempo = 1;
        printf("Voltando para Tela Inicial\n");
        telainicial();

        break;
    default:
        printf("Escolha inválida. Por Favor escolha novamente.\n");
    }
}
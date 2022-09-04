#include <stdio.h>
#include <stdlib.h>
#include "telainicial.h"
#include <string.h>
#include "lcd.h"


void recebeValores(float temperatura, int tempo, char *alimento, int opcao){

    printf("\nTemperatura : %.2f°   Tempo: %d min   Alimento: %s \n\n",temperatura , tempo, alimento);

    printf("Recebi os valores.\n\n");
    
    // mostra_menu(opcao);
    telaInicial(tempo,temperatura);
}

void menu()
{
    int opcao = 0;
    float temperatura = 0;
    int tempo = 0;
    char alimento[16];

    printf("\n\n        === Lista de Alimentos ===\n");
    printf("Escolha um alimento abaixo.\n\n");

    printf("1 - Frango                  2 - Peixe \n");
    printf("3 - Pão de Queijo           4 - Coxinha de Frango\n");
    printf("5 - Pudim                   6 - Carne de Porco -\n");
    printf("7 - Batata Frita            8 - Voltar a tela Inicial.\n\n");

    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        temperatura = 80;
        tempo = 1;
        strcpy(alimento,"Frango");
        recebeValores(temperatura, tempo, alimento, opcao);       
        break;
    case 2:
        temperatura = 40;
        tempo = 1;
        strcpy(alimento,"Peixe");
        recebeValores(temperatura, tempo, alimento, opcao);
        break;
    case 3:
        temperatura = 45;
        tempo = 1;
        strcpy(alimento,"Pão de Queijo");
        recebeValores(temperatura, tempo, alimento, opcao);
        break;
    case 4:
        temperatura = 50;
        tempo = 1;
        strcpy(alimento,"Bolo");
        recebeValores(temperatura, tempo, alimento, opcao);
        break;
    case 5:
        temperatura = 70;
        tempo = 1;
        strcpy(alimento,"Pudim");
        recebeValores(temperatura, tempo, alimento, opcao);
        break;
    case 6:
        temperatura = 60;
        tempo = 1;
        strcpy(alimento,"Carne de Porco");
        recebeValores(temperatura, tempo, alimento, opcao);
        break;
    case 7:
        temperatura = 80;
        tempo = 1;
        strcpy(alimento,"Batata Frita");
        recebeValores(temperatura, tempo, alimento, opcao);
        break;
    case 8:
        printf("Voltando para Tela Inicial\n");
        // mostra_menu(opcao);
        telaInicial(0,0);

        break;
    default:
        printf("Escolha inválida. Por Favor escolha novamente.\n");
    }
}
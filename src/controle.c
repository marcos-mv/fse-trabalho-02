#include "controle.h"

void leComandoUsuario()
{
    while (1)
    {
        printf("Lendo Comandos do Usuário: %d\n", get_user_comand(LECOMANDOUSUARIO));
        int comando = get_user_comand(LECOMANDOUSUARIO);

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
                printf("\ncomando usuario: %d", get_user_comand(LECOMANDOUSUARIO));
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
            telaInicial(0,0);
        }
        else if (comando == 0x05)
        {
            printf("+ 1 minuto\n");
            maisUmMinuto(1,200);
        }
        else if (comando == 0x06)
        {
            printf("- 1 minuto\n");
            menosUmMinuto(1,100);
        }
        else if (comando == 0x07)
        {
            printf("Abrindo menu");
            menu();
        }
        else
        {
            printf("Comando Inexistente.\n");            
        }
        usleep(1000000);
    }
}
void EnviaSinalControle()
{
    while (1)
    {
        printf("Enviando Sinal de Controle: %d\n", send_control_signal(SEND_SIGNAL_CONTROL));
        usleep(600000);
    }
}
void EnviaSinalReferencia()
{
    while (1)
    {
        printf("Envia Sinal de Referência %d\n", get_temperature(LECOMANDOUSUARIO));
        usleep(600000);
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

void iniciaAquecimento(int tempo, float temperatura)
{

    printf("\nIniciando Aquecimento\n");
    acionaResistor(SolicitaTempInterna(),SolicitaTempRef(),tempo);
    SolicitaTempInterna();
    SolicitaTempRef();
}

void cancelaProcesso()
{
    float temperatura = 0;
    int tempo = 0;
    printf("\nProcesso Cancelado\n");
    telaInicial(tempo, temperatura);
}

void maisUmMinuto(int tempo, float temperatura)
{
    int newtempo = tempo + 1;

    printf("\nTempo %d Temperatura: %d\n", newtempo, temperatura);

    telaInicial(newtempo, temperatura);
}

void menosUmMinuto(int tempo, float temperatura)
{
    int newtempo = tempo - 1;

    printf("\nTempo %d Temperatura: %f\n", newtempo, temperatura);

    telaInicial(newtempo, temperatura);
}

void aumentaTemperatura(int tempo, float temperatura)
{
    float newTemperatura = temperatura + 5;

    printf("\nTempo %d Temperatura: %f\n", tempo, newTemperatura);

    telaInicial(tempo, newTemperatura);
}

void diminuiTemperatura(int tempo, float temperatura)
{
    float newTemperatura = temperatura - 5;

    printf("\nTempo %d Temperatura: %d\n", tempo, newTemperatura);

    telaInicial(tempo, newTemperatura);
}
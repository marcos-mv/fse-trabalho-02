#include "controle.h"

void leComandoUsuario()
{
    while (1)
    {   
        
        int comando = get_user_comand(LECOMANDOUSUARIO);
        printf("Lendo Comandos do Usuário: %d\n", get_user_comand(LECOMANDOUSUARIO));

        if (comando == 0x02)
        {
            desligaAir();
        }
        else if (comando == 0x03)
        {
            printf("Iniciando Aquecimento\n");

            while (get_user_comand(LECOMANDOUSUARIO) != 4)
            {
                if (get_user_comand(LECOMANDOUSUARIO) == 2)
                {   
                    printf("\ncomando usuario: %d", get_user_comand(LECOMANDOUSUARIO));
                    desligaAir();
                }
                get_user_comand(LECOMANDOUSUARIO);
                sleep(1);
                printf("\ncomando usuario: %d", get_user_comand(LECOMANDOUSUARIO));
                SolicitaTempInterna();
                SolicitaTempRef();
                SolicitaTempAmbiente();
                time_t clk = time(NULL);
                printf("%s\n",ctime(&clk));
                // printf("\n\n%s,%.2f,%.2f,%.2f\n\n", ctime(&clk),SolicitaTempInterna(),SolicitaTempRef(),SolicitaTempAmbiente());
            }
        }
        else if (comando == 0x04)
        {
            printf("Cancelando Processo\n");
            telaInicial(0, 0);
        }
        else if (comando == 0x05)
        {
            printf("+ 1 minuto\n");
            maisUmMinuto(1, 200);
        }
        else if (comando == 0x06)
        {
            printf("- 1 minuto\n");
            menosUmMinuto(1, 100);
        }
        else if (comando == 0x07)
        {
            printf("Abrindo menu");
            menu();
        }
        else if (comando <= 0)
        {
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
        printf("Envia Sinal de Referência %f\n", get_temperature(LECOMANDOUSUARIO));
        usleep(600000);
    }
}

void ligandoAir()
{
    printf("\nLigando Airfryer\n");
}
void desligaAir()
{
    printf("\nDesligando Airfryer\n");
    exit(0);
}

void iniciaAquecimento(int tempo, float temperatura)
{

    printf("\nIniciando Aquecimento\n");
    acionaResistor(SolicitaTempInterna(), SolicitaTempRef(), tempo);
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

    printf("\nTempo %d Temperatura: %f\n", newtempo, temperatura);

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

    printf("\nTempo %d Temperatura: %f\n", tempo, newTemperatura);

    telaInicial(tempo, newTemperatura);
}
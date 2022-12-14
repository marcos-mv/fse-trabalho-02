#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#include "uart.h"
#include "pwm.h"
#include "bme280.h"
#include "uart.h"
#include "menu.h"

void LeComandoUsuario();
void EnviaSinalControle();
void EnviaSinalReferencia();
void ligandoForno();
void desligaForno();
void iniciaAquecimento(int tempo, float temperatura);
void cancelaProcesso();

void maisUmMinuto(int tempo, float temperatura);
void menosUmMinuto(int tempo, float temperatura);

void telaInicial(int tempo, float temperatura);
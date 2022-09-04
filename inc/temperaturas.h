#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "uart.h"
#include "pwm.h"
#include "bme280.h"
#include "uart.h"

float SolicitaTempInterna();

float SolicitaTempRef();

float SolicitaTempAmbiente();

void acionaResistor(float temperaturaInterna, float temperaturaRef, int tempo);

void acionaFan(float temperaturaInterna);

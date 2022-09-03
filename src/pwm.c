#include "pwm.h"
#include <stdio.h>
#include <stdlib.h>
#include "wiringPi.h"
#include "softPwm.h"
#include <unistd.h>

int inicializar()
{

    if (wiringPiSetup() == -1)
    {
        return 1;
    }

    softPwmCreate(RESISTOR, 0, 100);
    softPwmCreate(FAN, 0, 100);

    return EXIT_SUCCESS;
}

int aquecer(int sinal)
{
    softPwmWrite(RESISTOR, sinal);
    return EXIT_SUCCESS;
}

int refriar(int sinal)
{
    softPwmWrite(FAN, sinal);
    return EXIT_SUCCESS;
}

int desligar()
{
    softPwmStop(RESISTOR);
    softPwmStop(FAN);
    return EXIT_SUCCESS;
}
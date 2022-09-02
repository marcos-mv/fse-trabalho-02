#include "pwm.h"

int control(int pin, int value)
{
    if (wiringPiSetup() == -1)
    {
        return 1;
    }

    softPwmCreate(pin, 1, 100);
    softPwmWrite(pin, value);
    delay(10);

    return 0;
}

int turn_off(int pin)
{
    if (wiringPiSetup() == -1)
    {
        return 1;
    }

    softPwmCreate(pin, 1, 100);
    softPwmWrite(pin, 0);
    delay(10);

    return 0;
}

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
}
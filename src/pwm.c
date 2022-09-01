#include "pwm.h"

int control(int pin, int value){
    if (wiringPiSetup () == -1) {
        return 1;
    }

    pinMode (pin, OUTPUT);
    softPwmCreate(pin, 1, 100);
    softPwmWrite (pin, value);
    delay(10);

    return 0;
}

int turn_off(int pin) {
    if (wiringPiSetup () == -1) {
        return 1;
    }

    pinMode (pin, OUTPUT);
    softPwmCreate(pin, 1, 100);
    softPwmWrite (pin, 0);
    delay(10);

    return 0;
}
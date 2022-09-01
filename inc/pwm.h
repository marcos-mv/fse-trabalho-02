#ifndef PWM_H
#define PWM_H

#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <softPwm.h>

#define RESISTOR 4
#define FAN 5
 
int control(int, int);
int turn_off(int);

#endif
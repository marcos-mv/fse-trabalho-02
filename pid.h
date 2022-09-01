#ifndef PID_H_
#define PID_H_

#include <stdio.h>

void pid_set_constants(double Kp_, double Ki_, double Kd_);
void pid_set_reference(float reference_);
double pid_control(double temperature);

#endif /* PID_H_ */
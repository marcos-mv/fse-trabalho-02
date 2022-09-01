#ifndef ON_OFF_H
#define ON_OFF_H

int on_off_control(float initial_temp, float ref_temp, float histerese);
// 0 desliga o resistor e liga a ventoinha
// 1 desliga a ventoinha e liga o resistor
// -1 mantém estado atual

#endif
#include "onoff.h"

int on_off_control(float internal_temp, float ref_temp, float histerese){
    
    float top_temp = ref_temp + (histerese/2);
    float bottom_temp = ref_temp - (histerese/2);
    
    if(internal_temp > top_temp)
        return 0; // turn off resistor, turn on fan
    else if(internal_temp < bottom_temp)
        return 1; // turn on resistor, turn off fan
    
    return -1; // do nothing
}
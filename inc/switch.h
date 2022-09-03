#ifndef SWITCH_H
#define SWITCH_H

#include <string.h>
#include "uart.h"
#include "crc16.h"

int get_switch_status(unsigned char code);

#endif
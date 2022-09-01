#ifndef UART_H
#define UART_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <stdlib.h>
#include "crc.h"

#define DEVICE 0x01

#define GET_CODE 0x23
#define SEND_CODE 0x16

#define INTERNAL 0xC1
#define REFERENCE 0xC2
#define SWITCH_STATUS 0xC3
#define SEND_SIGNAL 0xD1

int open_uart();
void set_attributes(int);
void send_request(int, unsigned char, unsigned char, int, int);
void read_response(int, unsigned char*);
float get_temperature(unsigned char);
int send_control_signal(int);

#endif
Footer

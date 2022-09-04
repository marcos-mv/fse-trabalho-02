#ifndef UART_H
#define UART_H

#define DEVICE 0x01

#define GET_CODE 0x23
#define SEND_CODE 0x16

// #define INTERNAL 0xC1
// #define REFERENCE 0xC2
// #define SWITCH_STATUS 0xC3

int open_uart();
void set_attributes(int);
void send_request(int, unsigned char, unsigned char, int, int);
void read_response(int, unsigned char*);
float get_temperature(unsigned char);
int get_user_comand(unsigned char sub_code);
int send_control_signal(int);

#define SOLICITARTEMP 0XC1
#define SOLICITARTEMPREF 0xC2
#define LECOMANDOUSUARIO 0xC3

#define SEND_SIGNAL_CONTROL 0xD1
#define SEND_SIGNAL_REF 0xD2
// #define 


#endif

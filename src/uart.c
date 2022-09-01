#include "uart.h"

int open_uart() {
    return open("/dev/serial0", O_RDWR | O_NOCTTY | O_NDELAY);
}

void set_attributes(int uart_filestream) {
    struct termios options;
    tcgetattr(uart_filestream, &options);
    options.c_cflag = B9600 | CS8 | CLOCAL | CREAD;
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    tcflush(uart_filestream, TCIFLUSH);
    tcsetattr(uart_filestream, TCSANOW, &options);
}

void send_request(int uart_filestream, unsigned char code, unsigned char sub_code, int flag_data, int data) {
    unsigned char tx_buffer[13] = {DEVICE, code, sub_code, 0x02, 0x08, 0x04, 0x05};
    int crc_size = 7; 
    // flag = 1 -> data exists
    if(flag_data){
        memcpy(&tx_buffer[7], &data, 4);
        crc_size = 11;
    }

    short crc = get_CRC(tx_buffer, crc_size);
    memcpy(&tx_buffer[crc_size], &crc, 2);

    write(uart_filestream, &tx_buffer[0], crc_size+2);
}

void read_response(int uart_filestream, unsigned char* rx_buffer) {
    int rx_length = read(uart_filestream, (void*)rx_buffer, 10);
    rx_buffer[rx_length] = '\0';
}

float get_temperature(unsigned char sub_code) {
    int uart_filestream = -1;
    unsigned char rx_buffer[9];
    float temperature;
    short crc, check_crc;

    uart_filestream = open_uart();
    if (uart_filestream == -1) {
        return -1.0;
    }

    set_attributes(uart_filestream);
    send_request(uart_filestream, GET_CODE, sub_code, 0, 0);
    usleep(100000);
    read_response(uart_filestream, &rx_buffer[0]);

    memcpy(&temperature, &rx_buffer[3], 4);
    memcpy(&crc, &rx_buffer[7], 2);
    check_crc = get_CRC(&rx_buffer[0], 7);

    if (rx_buffer[0] != 0x00 || rx_buffer[1] != 0x23 || rx_buffer[2] != sub_code || crc != check_crc)
        return -1.0;
    close(uart_filestream);

    return temperature;
}

int send_control_signal(int control_signal) {
    int uart_filestream = -1;

    uart_filestream = open_uart();
    if (uart_filestream == -1) {
        return -1;
    }

    set_attributes(uart_filestream);
    send_request(uart_filestream, SEND_CODE, SEND_SIGNAL, 1, control_signal);
    close(uart_filestream);

    return 0;
}
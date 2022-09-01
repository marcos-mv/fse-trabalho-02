#include "switch.h"

int get_switch_status(unsigned char sub_code) {
    // 0 ON-OFF
    // 1 PID
    
    int uart_filestream = -1;
    unsigned char rx_buffer[9];
    int status;
    short crc, check_crc;

    uart_filestream = open_uart();
    if (uart_filestream == -1) {
        return -1.0;
    }

    set_attributes(uart_filestream);
    send_request(uart_filestream, GET_CODE, sub_code, 0, 0);
    usleep(100000);
    read_response(uart_filestream, &rx_buffer[0]);

    memcpy(&status, &rx_buffer[3], 4);
    memcpy(&crc, &rx_buffer[7], 2);
    check_crc = get_CRC(&rx_buffer[0], 7);

    if (rx_buffer[0] != 0x00 || rx_buffer[1] != 0x23 || rx_buffer[2] != sub_code || crc != check_crc)
        return -1.0;
    close(uart_filestream);

    return status;
}
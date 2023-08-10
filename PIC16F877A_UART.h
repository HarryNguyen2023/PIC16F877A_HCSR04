#ifndef PIC16F877A_UART_H
#define PIC16F877A_UART_H

#include <xc.h>

// Define the baud rate for the UART module
#define BAUD_RATE 57600

// Variable to keep track the string reception via UART
uint16_t uart_str_idx = 0;

// UART receive buffer
extern uint16_t str_len;
char

    void
    UARTTransInit(void);
void UARTRcvInit(void);
void UARTTransRcvInit(void);
void UARTsendChar(char c);
void UARTsendString(char *str);
char UARTrcvChar(void);
char *UARTrcvString(uint16_t length);

#endif
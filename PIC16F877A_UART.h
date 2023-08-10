#ifndef PIC16F877A_UART_H
#define PIC16F877A_UART_H

#include <xc.h>

void UARTInit(void);
void UARTsendChar(char c);
void UARTsendString(char *str);
char UARTrcvChar(void);
char* UARTrcvString(uint16_t length);

#endif
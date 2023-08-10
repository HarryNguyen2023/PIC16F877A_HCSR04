#include "config.h"
#include "PIC16F877A_HCSR04.h"
#include "PIC16F877A_timer0.h"
#include "PIC16F877A_UART.h"
#include <stdio.h>

// Global variables
uint8_t count = 0;
float dist;

// UART send buffer
char send_buff[35];

// Function to handle interrupt
void __interrupt() ISR(void)
{
    // Timer 0 overflow interrupt
    if (TMR0IF)
    {
        TMR0 = 6;
        if (count++ == 100)
        {
            count = 0;
            hcsr04Trigger();
        }
        TMR0IF = 0;
    }
    // Input capture 1 interrupt
    if (CCP1IF)
    {
        hcsr04Distance();
        dist = getDistance();
        if(dist > 0)
        {
            sprintf(send_buff, "Distance to obstacle: %.3f cm\r\n", hcsr04_distance);
            UARTsendString(send_buff);
        }
        CCP1IF = 0;
    }
}

void main(void)
{
    // Initiate Timer 0 timer mode
    TMR0 = 6;
    timer0TimerInit(TIMER0_DIV_16);

    // Initiate the HCSR04 sensor interface
    hcsr04Init();
    
    // Initiate the UART transmit 
    UARTTransInit();

    while (1)
    {
    }
    return;
}

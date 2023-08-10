#include "config.h"
#include "PIC16F877A_HCSR04.h"
#include "PIC16F877A_timer0.h"
#include "PIC16F877A_UART.h"
#include <stdlib.h>
#include <string.h>

// Globale variable
uint8_t count = 0;

// UART send buffer
char send_buff[45];

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
            double dist = getDistance();
            if (dist > 0)
            {
                memset(send_buff, '\0', sizeof(send_buff));
                sprintf(send_buff, "Distance to obstacle: %.3f cm\n", dist);
                UARTsendString(send_buff);
            }
        }
        TMR0IF = 0;
    }
    // Input capture 1 interrupt
    if (CCP1IF)
    {
        hcsr04Distance();
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

    while (1)
    {
    }
    return;
}

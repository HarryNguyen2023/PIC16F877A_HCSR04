#include "config.h"
#include "PIC16F877A_HCSR04.h"
#include "PIC16F877A_timer0.h"

// Globale variable
uint8_t count  = 0;

// Function to handle interrupt
void __interrupt() ISR(void)
{
    // Timer 0 overflow interrupt
    if(TMR0IF)
    {
        if(count++ == 100)
        {
            count = 0;
            hcsr04Trigger();
        }
        TMR0IF = 0;
    }
    // Input capture 1 interrupt
    if(CCP1IF)
    {
        hcsr04Distance();
        CCP1IF = 0;
    }
}

void main(void) {
    // Initiate Timer 0 timer mode
    TMR0 = 6;
    timer0TimerInit(TIMER0_DIV_16);
    
    // Initiate the HCSR04 sensor interface
    hcsr04Init();
    
    while(1)
    {
    }
    return;
}

#include "PIC16F877A_HCSR04.h"

// ------------------Static functions used only by internal functions and hidden from user---------------------

// Trigger pins configuration
static void trigConfig()
{
    // Sequentailly define the trigger pins of each HCSR04 sensor
    TRISD0 = 0;
    TRIG1 = 0;
}

// Function to calculate the distance from the HCSR04 sensor
static double calDistance()
{
    double time = ((fallT2 - riseT1) / 2.0) * (4 / _XTAL_FREQ);
    double distance = SOUND_SPEED * time;
    return distance;
}

// ----------------------------------Functions that interface with user----------------------------------------

// Function to initiate the HCSR04 sensor
void hcsr04Init()
{
    // configure trigger pins
    trigConfig();
    // Initiate the input capture CCP1 module
    captureRisingInit();
}

// Function to send the trigger pulse to the HCSR04
void hcsr04Trigger()
{
    TRIG1 = 1;
    __delay_us(2);
    TRIG1 = 0;
    // Set the timer 1 pre load register to 0
    TMR1 = 0;
}

// Function to get the value of the distance from the HCSR04 sensor and will be called inside the interrupt function
void hcsr04Distance()
{
    if (hcsr04_state == IDLE)
    {
        riseT1 = CCPR1;
        // Change input capture mode to falling edge
        changeModeFalling();
        hcsr04_state = DONE;
    }
    else if (hcsr04_state == DONE)
    {
        fallT2 = CCPR1;
        hcsr04_distance = calDistance();
        // Add some code for transmission data if necessary
        // Change input capture mode to rising edge
        changeModeRising();
        hcsr04_state = IDLE;
    }
}

// Function to get the distance of the HCSR04 sensor
double getDistance()
{
    return hcsr04_distance;
}
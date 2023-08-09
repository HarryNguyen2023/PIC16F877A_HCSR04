#ifndef PIC16F877A_HCSR04_H
#define PIC16F877A_HCSR04_H

#include "PIC16F877A_input_capture.h"

// Define the clock frequency of the system
#define _XTAL_FREQ 16000000

// Define the sound speed in air with unit cm/s
#define SOUND_SPEED 34000

// Define pins connect to the HCSR04
#define TRIG1 RD0 // If you want to change the trigger pin please also change the pin configuration function

// Define the state of the receive pulse
enum state
{
    IDLE,
    DONE
};

// Define some configuration variables
uint8_t hcsr04_state = IDLE;
uint16_t riseT1 = 0;
uint16_t fallT2 = 0;
double hcsr04_distance = 0;

void hcsr04Init(void);
void hcsr04Trigger(void);
void hcsr04Distance(void);
double getDistance(void);

#endif
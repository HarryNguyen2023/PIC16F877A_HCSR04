# PIC16F877A_HCSR04
## Author Harry Nguyen (created 08/10/2023)

### Introduction:
HCSR04 is sensor using ultrasonic wave to measure the distance to the obstacle with maximum range up to 4m. This sensor is widely used by hobbists to build simple robotics models, as well as applied in many different scenario. Thus, I have build a library for PIC16F877A uisng input capture module to interface with the HCSR04 sensor to implement in into other more complicated project. This approach is more elegant as it does not required all the CPU resources for only interfacing with the sensor while using conventional method.

Besides, during this project, I have also built a series of peripheral interface for the PIC16F877A to be reused easily in the future, using standard C library format to avoid import collision.

### References:
[1]. Khaled Magdy, Ultrasonic Sensor HC-SR04 With PIC Microcontrollers Tutorial, https://deepbluembedded.com/ultrasonic-sensor-hc-sr04-pic-microcontrollers-tutorial/.

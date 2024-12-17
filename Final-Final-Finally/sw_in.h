/* 
 * File:   sw_in.h
 * Author: nestorj
 *
 * Module to initialize and use two GPIO inputs
 * as switches with internall pullup
 */

#ifndef SW_IN_H
#define SW_IN_H

#include "pico/stdlib.h"

// Button GPIO pin assignments
//Bottom Hose Clamp
#define SW1_PIN 10  // Motor 1 Forward
#define SW2_PIN 0  // Motor 1 Backward
//Raise and Lower Arm 
#define SW3_PIN 8 // Motor 2 Forward
#define SW4_PIN 9 // Motor 2 Backward
//Top Hose Clamp
#define SW5_PIN 14 // Motor 3 Forward
#define SW6_PIN 13 // Motor 3 Backward
//Opener
#define SW7_PIN 15 // Motor 4 Forward

// Initialize GPIO pins for buttons
void sw_in_init();

// Read the debounced state of each button
bool sw_in_read1();
bool sw_in_read2();
bool sw_in_read3();
bool sw_in_read4();
bool sw_in_read5();
bool sw_in_read6();
bool sw_in_read7();

#endif // SW_IN_H

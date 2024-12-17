#ifndef BUTTONS_H
#define BUTTONS_H

#include "pico/stdlib.h"

// Initialize all buttons
void buttons_init();

// Read the debounced state of each button
bool button_read1(); // Forward for Motor 1
bool button_read2(); // Backward for Motor 1
bool button_read3(); // Forward for Motor 2
bool button_read4(); // Backward for Motor 2
bool button_read5(); // Forward for Motor 3
bool button_read6(); // Backward for Motor 3
bool button_read7(); // Forward for Motor 4

#endif // BUTTONS_H

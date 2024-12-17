#include "Buttons.h"
#include "sw_in.h"
#include "stdio.h"
#include "pico/stdlib.h"



//#define BUTTON_1_PIN 6
// Initialize all buttons
void buttons_init() {
    sw_in_init(); // Initialize GPIO pins for buttons
}

// Read the state of each button (debounced)
bool button_read1() { return sw_in_read1(); }
bool button_read2() { return sw_in_read2(); }
bool button_read3() { return sw_in_read3(); }
bool button_read4() { return sw_in_read4(); }
bool button_read5() { return sw_in_read5(); }
bool button_read6() { return sw_in_read6(); }
bool button_read7() { return sw_in_read7(); }



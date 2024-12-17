/*
 * File:   sw_in.c
 * Author: nestorj
 * 
 * Reference implementation of sw_in module
 */

#include "sw_in.h"
#include "pico/stdlib.h"
#include "stdbool.h"


// Initialize GPIO pins for buttons
void sw_in_init() {
    gpio_init(SW1_PIN);
    gpio_set_dir(SW1_PIN, false);
    gpio_pull_up(SW1_PIN);

    gpio_init(SW2_PIN);
    gpio_set_dir(SW2_PIN, false);
    gpio_pull_up(SW2_PIN);

    gpio_init(SW3_PIN);
    gpio_set_dir(SW3_PIN, false);
    gpio_pull_up(SW3_PIN);

    gpio_init(SW4_PIN);
    gpio_set_dir(SW4_PIN, false);
    gpio_pull_up(SW4_PIN);

    gpio_init(SW5_PIN);
    gpio_set_dir(SW5_PIN, false);
    gpio_pull_up(SW5_PIN);

    gpio_init(SW6_PIN);
    gpio_set_dir(SW6_PIN, false);
    gpio_pull_up(SW6_PIN);

    gpio_init(SW7_PIN);
    gpio_set_dir(SW7_PIN, false);
    gpio_pull_up(SW7_PIN);
}

// Read the state of each button
bool sw_in_read1() { return !gpio_get(SW1_PIN); }
bool sw_in_read2() { return !gpio_get(SW2_PIN); }
bool sw_in_read3() { return !gpio_get(SW3_PIN); }
bool sw_in_read4() { return !gpio_get(SW4_PIN); }
bool sw_in_read5() { return !gpio_get(SW5_PIN); }
bool sw_in_read6() { return !gpio_get(SW6_PIN); }
bool sw_in_read7() { return !gpio_get(SW7_PIN); }

#include "Motors.h"
#include "pico/stdlib.h"
#include "stdio.h"
#include "pico_servo.h"



// Initialize the motor with a GPIO pin
void motor_init(Motor *motor, uint16_t gpio_pin) {
    (*motor).gpio_pin = gpio_pin;
    (*motor).state = MOTOR_STOP; // Default state is stopped


    gpio_init(gpio_pin);
    gpio_set_dir(gpio_pin, GPIO_OUT);
    gpio_put(gpio_pin, 0); // Ensure the motor is stopped initially
}

// Control the motor by setting its state
void motor_control(Motor *motor, int16_t state) {
    (*motor).state = state;

    if (state == MOTOR_FORWARD) {
        gpio_put((*motor).gpio_pin, 1); // High output for forward



    } else if (state == MOTOR_BACKWARD || state == MOTOR_STOP) {
        gpio_put((*motor).gpio_pin, 0); // Low output for backward or stop
    }
}

#ifndef MOTORS_H
#define MOTORS_H

#include "pico/stdlib.h"
//#include "cstdint"

// Motor state constants
#define MOTOR_FORWARD  100
#define MOTOR_BACKWARD -100
#define MOTOR_STOP     0

// Motor structure
typedef struct {
    uint16_t gpio_pin;       // GPIO pin used for the motor
    int16_t state;       // Current state of the motor
} Motor;

// Motor initialization
void motor_init(Motor *motor, uint16_t gpio_pin);

// Motor control
void motor_control(Motor *motor, int16_t state);

#endif // MOTORS_H

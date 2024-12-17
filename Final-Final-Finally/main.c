#include "Motors.h"
#include "Buttons.h"
#include "stdio.h"
#include "pico/stdlib.h"
#include "pico_servo.h"
#include "pico/types.h"
//#include "src/common/pico_base_headers/include/pico/types.h"

// Define motors
#define BUTTON_PIN 
#define MOTOR_PIN 4
 Motor bottom_hose_clamp, top_hose_clamp, arm, opener;


const uint M1 = 2;
const uint M2 = 3;
const uint M3 = 4;
const uint M4 = 5;


// Initialize all components
void setup() {
    motor_init(&bottom_hose_clamp, 2);  // Motor 1 GPIO
    motor_init(&top_hose_clamp, 3);     // Motor 2 GPIO
    motor_init(&arm, 4);                // Motor 3 GPIO
    motor_init(&opener, 5);             // Motor 4 GPIO

    buttons_init(); // Initialize buttons
}

void light() {

  const uint LED_PIN = PICO_DEFAULT_LED_PIN;
            gpio_init(LED_PIN);
            gpio_set_dir(LED_PIN, GPIO_OUT);
            for (int i = 2; i<5;) {
            gpio_put(LED_PIN, 1);
            sleep_ms(100);
            gpio_put(LED_PIN, 0);
            sleep_ms(100);
            i++;
            }

}

// Main control loop
void loop() {
    
                   servo_enable(M1);
                   servo_enable(M2);
                   servo_enable(M3);
                   servo_enable(M4);

    printf("Main)");
    // Control Motor 1 (Bottom Hose Clamp)
    if (button_read1()) {


        motor_control(&bottom_hose_clamp, MOTOR_FORWARD);

           light;


    } else if (!button_read2()) {
        motor_control(&bottom_hose_clamp, MOTOR_BACKWARD);
        printf("testing2");


            light;


    } else {
        motor_control(&bottom_hose_clamp, MOTOR_STOP);
        servo_disable(M1);
    }
    printf("Main2)");











    // Control Motor 2 (Top Hose Clamp)
    if (!button_read3()) {
        motor_control(&top_hose_clamp, MOTOR_FORWARD);
        printf("testing7");




        light;

    } else if (!button_read4()) {
        motor_control(&top_hose_clamp, MOTOR_BACKWARD);




        light;
    
    } 
    
    else {
        motor_control(&top_hose_clamp, MOTOR_STOP);
        servo_disable(M2);
    }










    printf("Main3)");
    // Control Motor 3 (Arm)
    if (!button_read5()) {
        motor_control(&arm, MOTOR_FORWARD);
    




        light;
    
    } else if (!button_read6()) {
        motor_control(&arm, MOTOR_BACKWARD);
    



        light;
    
    } else {
        motor_control(&arm, MOTOR_STOP);
        servo_disable(M3);
    }









    printf("Main4)");
    // Control Motor 4 (Opener)
    if (!button_read7()) {
        motor_control(&opener, MOTOR_FORWARD);
    




        light;
    
    } else {
        motor_control(&opener, MOTOR_STOP);
        servo_disable(M4);
    }

    sleep_ms(100); // Prevent excessive CPU usage
        printf("Main5)");

}















int main() {
    
   
    setup(); // Initialize components

    while (1) {
            printf("Looping)");

        loop(); // Continuously execute control logic

            
    }
    printf("Fail)");

   

    return 0;
}

#include "alarm_intf.h"
#include "stdbool.h"
#include "pico/stdlib.h"


// Sets up all inputs and outputs 
void initAlarm(){
    gpio_init(LED);
    gpio_init(ALARM);
    gpio_init(DOOR_SENSOR);
    gpio_pull_up(DOOR_SENSOR);
    gpio_set_dir(DOOR_SENSOR,0);
    gpio_set_dir(ALARM,1);
    gpio_set_dir(LED,1);
}

unit8_t readDoor() {
    if(gpio_get(DOOR_SENSOR)){
        return 0x00;
    }
    else{
        return 0xff;
    }
}


void ledOff(){
    gpio_put(LED,0);
}

void ledOn(){
    gpio_put(LED,1);
}

void alarmOFF(){
    gpio_put(ALARM,0);
}

void alarmOn(){
    gpio_put(ALARM,1);
}


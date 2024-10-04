#ifdef ALARM_INTF_H
#define ALARM__INTF_H
#include <inttypes.h>

        //everything besides what is in between these  
        //lines was taken from the HW handout
        #define ALARM 25
        #define LED 26
        #define DOOR_SENSOR 11
        //


//Initialize the alarm interfaces
void initAlarm();

unit_8 readDoor();

//turn warning LED OFF
void ledOff();

// turn warning LED ON
void ledOn();

// turn alarm buzzer OFF
void alarmOFF();

//turn alarm buzzer ON
void alarmOn();

#endif
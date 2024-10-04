#include "pico/stdlib.h"
#include "inttypes.h"
#include "stdbool.h"
#include "alarm_intf.h"
#include "alrmfsm.h"

static enum DOOR3STATE {
DOORC,
DOORO,
THIRTYSEC
} DOOR3STATE;

// sets Elaspsed time to 30 seconds
uint16_t TElapsed = 30000;
bool warn_g;
bool Tick;
int Seconds;

void ALARM(){
    bool warn_g=false;
    bool Tick=false;
    DOOR3STATE = DOORC;
    Seconds = 0;
}

bool ALARM(){
    return warn_g;
}

void TICK(){
//Manages the FSM of the internal ALRM
switch(DOOR3STATE){
    
    case DOORC:
        warn_g = false;
        Seconds = 0;
        alarmOFF();
        if(gpio_get(DOOR_SENSOR))
            DOOR3STATE=DOORO;
        else
            DOOR3STATE=DOORC;
    break;

    case DOORO:
        warn_g = true;
        Seconds++;
        alarmOFF();
        if(gpio_get(DOOR_SENSOR) && Tick)
            DOOR3STATE=DOORO;
        else if(gpio_get(DOOR_SENSOR) && !Tick)
            DOOR3STATE=THIRTYSEC;
        else
            DOOR3STATE=DOORC;
    break;

    case THIRTYSEC:
        alarmON();
        if(gpio_get(DOOR_SENSOR))
            DOOR3STATE=THIRTYSEC
        else
            DOOR3STATE=DOORC
    break;


}

}
#include "pico/stdlib.h"
#include "inttypes.h"
#include "alarm_intf.h"
#include "wrnfsm.h"
#include "alrmfsm.h"
#include "timer.h"
//timer.c and timer.h have been used elsewhere in this assignment in place of 
//new timer files.


int main(){
    if(zTimerReadFlag()){
        tickFct_ALARMFSM();
        tickFct_WARNFSM();
    }
    else{
        initAlarm();
        ALARM();

        //didn't know what to do to get the timer fully set up
        // here are some calls that might work
        zTimerSet(uint16_t TElapsed = 1000);
        zTimerOn();
    }

}

#include "WRNFSM.h"
#include "pico/stdlib.h"
#include "ALRMFSM.h"
#include "alarm_intf.c"
#include "stdbool.h"


static enum FSM {
WRNOFF,
WRNON
} FSM;

void HalfMinCount(){
    FSM = WRNOFF;
    ledOff();
}

void tickFct_WARNFSM(){
    bool warn_g = warn_gT()
    switch(FSM)
        {
            case WRNOFF:
                ledOFF();

                if(warn_g){
                    FSM = WRNON;
                }
                else{
                    FSM = WRNOFF;
                }
            break;

            case WRNON:
                ledON();
                FSM = WRNOFF;
            break;

        }

}
bool warn_gT(){
    return warn_g;
}
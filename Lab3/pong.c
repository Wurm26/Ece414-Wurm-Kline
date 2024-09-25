
#include "pico/stdlib.h"
#include "stdbool.h"
#include "stdint.h"
#include "stdio.h"
#include "sw_in.h"
#include "debounce_sw1.h"
#include "debounce_sw2.h"
#include "timer.h"
#include "led_out.h"


uint32_t PONGPERIOD = 300; //starting speed

static enum FSM {
    START,
    SERVER,
    SERVEL,
    L1,
    L2,
    L3, 
    L4,
    L5,
    L6,
    L7,
    L8, 
    WIN
} FSM; //all of the different states


int pong()
{
    bool btn_pressed1, btn_pressed2;
    btn_pressed1 = debounce_sw1_pressed(); //left
    btn_pressed2 = debounce_sw2_pressed(); //right

    static int serve;
    static bool dir_right; // direction dictates which way it moves (true for right, false for left)
    static bool win; //left = 0, right = 1


    switch (FSM) // states for pong
    {

    case START:
        
        serve = rand() %2; //decides which side starts with the "ball".
        if(serve==1)
        {
            FSM = SERVER;
        }
        else
        {
            FSM = SERVEL;
        }
        break;

    case SERVER: //when the ball is started on the right
        if (btn_pressed2)
        {
            dir_right = false; //starting direction (left)
            FSM = L7; //skips L8 for better visual flow
        }
        else
        {
            FSM = SERVER;
        }
        break;

    case SERVEL: //when the ball is started on the left
        if (btn_pressed1)
        {
            dir_right = true; //light moves right
            FSM = L2; //skips L1 for better visual flow
        }
        else
        {
            FSM = SERVEL; //loops until button pressed
        }
        break;

    case L1: // double !dir_right is redundant, but used for safety

        if (!dir_right && btn_pressed1)
        {
            if (PONGPERIOD > 100) //speeds up pong after every hit
            {
                PONGPERIOD = PONGPERIOD - 5;
            }
            dir_right = true; //switch direction
            FSM = L2; 
        }
        else if (!btn_pressed1 && !dir_right) //win condition
        {
            FSM = WIN;
            win = 1;
        }
        else //should not occur, mainly to see if pong is broken (i.e. if dir_right = true inside of L1)
        {
            FSM = L1; 
        }
        break;

    case L2: //light 2

        if (dir_right)
        {
            FSM = L3;
        }
        else if (!dir_right)
        {
            FSM = L1;
        }
        break;

    case L3: //light 3

        if (dir_right)
        {
            FSM = L4;
        }
        else if (!dir_right)
        {
            FSM = L2;
        }
        break;

    case L4: // light 4

        if (dir_right)
        {
            FSM = L5;
        }
        else if (!dir_right)
        {
            FSM = L3;
        }
        break;

    case L5: //light 5
        
        if (dir_right)
        {
            FSM = L6;
        }
        else if (!dir_right)
        {
            FSM = L4;
        }
        break;

    case L6: //light 6
        
        if (dir_right)
        {
            FSM = L7;
        }
        else if (!dir_right)
        {
            FSM = L5;
        }
        break;

    case L7: //light 7
        
        if (dir_right)
        {
            FSM = L8;
        }
        else if (!dir_right)
        {
            FSM = L6;
        }
        break;

    case L8:
        
        if (dir_right && btn_pressed2) //button is pressed, lights move the other way
        {
            if (PONGPERIOD > 100) //speeds up pong after every hit
            {
                PONGPERIOD = PONGPERIOD - 5;
            }
            dir_right = false;
            FSM = L7; 
        }
        else if (!btn_pressed1 && dir_right) //win state
        {
            win = 0;
            FSM = WIN;
        }
        else //should not occur, mainly to see if pong is broken
        {
            FSM = L8;
        }
        break;

    case WIN: // flashes led that corresponds to the winning player, then returns to start
        if(win) //right wins
        {
            printf("Right Wins!\n");
            led_out_write(0b00000001);//flash code taken from lab 1
            sleep_ms(100);
            led_out_write(0b00000000);
            sleep_ms(100);
            led_out_write(0b00000001);
            sleep_ms(100);
            led_out_write(0b00000000);
            sleep_ms(100);
            led_out_write(0b00000001);
            sleep_ms(100);
            led_out_write(0b00000000);
            FSM = START;

        }
        else if(!win) //left wins
        {
            printf("Left Wins!\n");
            led_out_write(0b10000000);//flash code taken from lab 1
            sleep_ms(100);
            led_out_write(0b00000000);
            sleep_ms(100);
            led_out_write(0b10000000);
            sleep_ms(100);
            led_out_write(0b00000000);
            sleep_ms(100);
            led_out_write(0b10000000);
            sleep_ms(100);
            led_out_write(0b00000000);
            FSM = START;
        }


    }
    switch (FSM) //FSM cases to show which light is on
    {
    case START:
        break;

    case SERVEL:
        led_out_write(0b10000000);
        break;

    case SERVER:
        led_out_write(0b00000001);
        break;

    case L1:
        led_out_write(0b10000000);
        break;

    case L2:
        led_out_write(0b01000000);
        break;

    case L3:
        led_out_write(0b00100000);
        break;

    case L4:
        led_out_write(0b00010000);
        break;

    case L5:
        led_out_write(0b00001000);
        break;

    case L6:
        led_out_write(0b00000100);
        break;

    case L7:
        led_out_write(0b00000010);
        break;

    case L8:
        led_out_write(0b00000001);
        break;
    }
}


int main() 
{
   
    uint32_t t1, t2, t1_debouncer, t2_debouncer; //timer variables
    stdio_init_all();
    sw_in_init();
    led_out_init();
    bool led_state = true;
    static int DEBOUNCEPERIOD = 50;

    t1 = timer_read();
    t1_debouncer = timer_read();
    printf("Hello!\n"); //check to see that the terminal works
    while (1) //runs timers for debouncer and pong
    {

        t2 = timer_read();
        t2_debouncer = timer_read();

        if (timer_elapsed_ms(t1_debouncer, t2_debouncer) > DEBOUNCEPERIOD)
        {
            debounce_sw1_tick();
            debounce_sw2_tick();
            t1_debouncer = t2_debouncer;
        }

        if (timer_elapsed_ms(t1, t2) > PONGPERIOD)
        {
            pong();
            t1 = t2;
        }
    }
}

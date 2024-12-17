
#include "pico/stdlib.h"
#include "stdbool.h"
#include "stdint.h"
#include "stdio.h"
#include "ts_lcd.h"
#include "TFTMaster.h"
#include "touchscreen.h"

    uint16_t operand1;
    uint16_t operand2;
    uint16_t result;
    int input;

static enum FSM {
    START,
    RESET,
    OP1,
    MULT,
    DIV,
    ADD,
    SUB,
    EQ,
    OVERE,
    DIV0E
} FSM;


int math()
{
    struct TSPoint p;
      p.x = 0;
      p.y = 0;
      p.z = 0;
    

    
    char starting[30];
    char results[30];
    tft_setTextSize(2);
    tft_setTextColor(ILI9340_WHITE);
    tft_setCursor(20, 24);
    //sprintf(starting, "%d", operand1); //should display 0
    //tft_writeString(starting);

    switch (FSM)
    {

    case START://starts calculator
        FSM = OP1;
        break;

    case RESET:
        operand1 = 0;
        operand2 = 0;
        result = 0;
        tft_fillRoundRect(0, 15, 300, 45, 10, ILI9340_BLACK );
        tft_setTextSize(2);
        tft_setTextColor(ILI9340_WHITE);
        tft_setCursor(20, 24);
        sprintf(results, "%d", "0");
        tft_writeString(results);

        FSM = OP1;
    break;

    case OP1://takes touchscreen inputs and makes it into the first operand
        getPoint(&p);
        if (p.z < 600)
        {

            if ((p.x > 3000 && p.x < 3400) && p.y > 2800 && p.y < 3500)
            {
            ////tft_fillRoundRect(0, 15, 300, 45, 10, ILI9340_BLUE );
            operand1 = (operand1 * 10) + 0;
            
            tft_fillRoundRect(0, 15, 300, 45, 10, ILI9340_BLACK );
            tft_setTextSize(2);
            tft_setTextColor(ILI9340_WHITE);
            tft_setCursor(20, 24);
            sprintf(results, "%d", operand1);
            tft_writeString(results);
            FSM = OP1;
            }
            else if ((p.x > 3000 && p.x < 3400) && p.y > 2800 && p.y < 3500)
            {
            operand1 = (operand1 * 10) + 1;
            tft_fillRoundRect(0, 15, 300, 45, 10, ILI9340_BLACK );
            tft_setTextSize(2);
            tft_setTextColor(ILI9340_WHITE);
            tft_setCursor(20, 24);
            sprintf(results, "%d", operand1);
            tft_writeString(results);
            FSM = OP1;
            }
            else if ((p.x > 3000 && p.x < 3400) && p.y > 2000 && p.y < 2800)
            {
            operand1 = (operand1 * 10) + 2;
            tft_fillRoundRect(0, 15, 300, 45, 10, ILI9340_BLACK );
            tft_setTextSize(2);
            tft_setTextColor(ILI9340_WHITE);
            tft_setCursor(20, 24);
            sprintf(results, "%d", operand1);
            tft_writeString(results);
            FSM = OP1;
            }
            else if ((p.x > 3000 && p.x < 3400) && p.y > 1200 && p.y < 2000)
            {
            operand1 = (operand1 * 10) + 3;
            tft_fillRoundRect(0, 15, 300, 45, 10, ILI9340_BLACK );
            tft_setTextSize(2);
            tft_setTextColor(ILI9340_WHITE);
            tft_setCursor(20, 24);
            sprintf(results, "%d", operand1);
            tft_writeString(results);
            FSM = OP1;
            }
            else if ((p.x > 2500 && p.x < 3000) && p.y > 2800 && p.y < 3500)
            {
            operand1 = (operand1 * 10) + 4;
            tft_fillRoundRect(0, 15, 300, 45, 10, ILI9340_BLACK );
            tft_setTextSize(2);
            tft_setTextColor(ILI9340_WHITE);
            tft_setCursor(20, 24);
            sprintf(results, "%d", operand1);
            tft_writeString(results);
            FSM = OP1;
            }
            else if ((p.x > 2500 && p.x < 3000) && p.y > 2000 && p.y < 2800)
            {
            operand1 = (operand1 * 10) + 5;
            tft_fillRoundRect(0, 15, 300, 45, 10, ILI9340_BLACK );
            tft_setTextSize(2);
            tft_setTextColor(ILI9340_WHITE);
            tft_setCursor(20, 24);
            sprintf(results, "%d", operand1);
            tft_writeString(results);
            FSM = OP1;
            }
            else if ((p.x > 2500 && p.x < 3000) && p.y > 1200 && p.y < 2000)
            {
            operand1 = (operand1 * 10) + 6;
            tft_fillRoundRect(0, 15, 300, 45, 10, ILI9340_BLACK );
            tft_setTextSize(2);
            tft_setTextColor(ILI9340_WHITE);
            tft_setCursor(20, 24);
            sprintf(results, "%d", operand1);
            tft_writeString(results);
            FSM = OP1;
            }
            else if ((p.x > 1500 && p.x < 1950) && p.y > 2800 && p.y < 3500)
            {
            operand1 = (operand1 * 10) + 7;
            tft_fillRoundRect(0, 15, 300, 45, 10, ILI9340_BLACK );
            tft_setTextSize(2);
            tft_setTextColor(ILI9340_WHITE);
            tft_setCursor(20, 24);
            sprintf(results, "%d", operand1);
            tft_writeString(results);
            FSM = OP1;
            }
            else if ((p.x > 1500 && p.x < 1950) && p.y > 2000 && p.y < 2800)
            {
            operand1 = (operand1 * 10) + 8;
            tft_fillRoundRect(0, 15, 300, 45, 10, ILI9340_BLACK );
            tft_setTextSize(2);
            tft_setTextColor(ILI9340_WHITE);
            tft_setCursor(20, 24);
            sprintf(results, "%d", operand1);
            tft_writeString(results);
            FSM = OP1;
            }
            else if ((p.x > 1500 && p.x < 1950) && p.y > 1200 && p.y < 2000)
            {
            operand1 = (operand1 * 10) + 9;
            tft_fillRoundRect(0, 15, 300, 45, 10, ILI9340_BLACK );
            tft_setTextSize(2);
            tft_setTextColor(ILI9340_WHITE);
            tft_setCursor(20, 24);
            sprintf(results, "%d", operand1);
            tft_writeString(results);
            FSM = OP1;
            }
            else if ((p.x > 1500 && p.x < 1950) && p.y > 500 && p.y < 1200)
            {
            tft_fillRoundRect(0, 15, 300, 45, 10, ILI9340_BLACK );
            tft_setTextSize(2);
            tft_setTextColor(ILI9340_WHITE);
            tft_setCursor(20, 24);
            sprintf(results, "%c", '+');
            tft_writeString(results);
            FSM = ADD;
            }
            else if ((p.x > 1950 && p.x < 2500) && p.y > 500 && p.y < 1200)
            {
            tft_fillRoundRect(0, 15, 300, 45, 10, ILI9340_BLACK );
            tft_setTextSize(2);
            tft_setTextColor(ILI9340_WHITE);
            tft_setCursor(20, 24);
            sprintf(results, "%s", '-');
            tft_writeString(results);
            FSM = SUB;
            }
            else if ((p.x > 2500 && p.x < 3000) && p.y > 500 && p.y < 1200)
            {
            tft_fillRoundRect(0, 15, 300, 45, 10, ILI9340_BLACK );
            tft_setTextSize(2);
            tft_setTextColor(ILI9340_WHITE);
            tft_setCursor(20, 24);
            sprintf(results, "%s", 'x');
            tft_writeString(results);
            FSM = MULT;
            }
            else if ((p.x > 3000 && p.x < 3500) && p.y > 500 && p.y < 1200)
            {
            tft_fillRoundRect(0, 15, 300, 45, 10, ILI9340_BLACK );
            tft_setTextSize(2);
            tft_setTextColor(ILI9340_WHITE);
            tft_setCursor(20, 24);
            sprintf(results, "%s", '/');
            tft_writeString(results);
            FSM = DIV;
            }
            else if ((p.x > 3000 && p.x < 3400) && p.y > 2000 && p.y < 2800)
            {
                operand1 = 0;
                tft_fillRoundRect(0, 15, 300, 45, 10, ILI9340_BLACK );
                tft_setTextSize(2);
                tft_setTextColor(ILI9340_WHITE);
                tft_setCursor(20, 24);
                sprintf(results, "%d", 0);
                tft_writeString(results);
                FSM = RESET;
            }
        }
        break;

    case MULT: //fills second operand and runs calculation
        getPoint(&p);
        if (p.z < 600)
        {

            if ((p.x > 3000 && p.x < 3400) && p.y > 2800 && p.y < 3500)
            {
            operand2 = (operand2 * 10) + 0;
            
            tft_fillRoundRect(0, 15, 300, 45, 10, ILI9340_BLACK );
            tft_setTextSize(2);
            tft_setTextColor(ILI9340_WHITE);
            tft_setCursor(20, 24);
            sprintf(results, "%d", operand1);
            tft_writeString(results);
            FSM = OP1;
            }
            else if ((p.x > 3000 && p.x < 3400) && p.y > 2800 && p.y < 3500)
            {
            operand2 = (operand2 * 10) + 1;
            tft_fillRoundRect(0, 15, 300, 45, 10, ILI9340_BLACK );
            tft_setTextSize(2);
            tft_setTextColor(ILI9340_WHITE);
            tft_setCursor(20, 24);
            sprintf(results, "%d", operand1);
            tft_writeString(results);
            FSM = OP1;
            }
            else if ((p.x > 2500 && p.x < 3000) && p.y > 2000 && p.y < 2800)
            {
            operand2 = (operand2 * 10) + 2;
            tft_fillRoundRect(0, 15, 300, 45, 10, ILI9340_BLACK );
            tft_setTextSize(2);
            tft_setTextColor(ILI9340_WHITE);
            tft_setCursor(20, 24);
            sprintf(results, "%d", operand1);
            tft_writeString(results);
            FSM = OP1;
            }
            else if ((p.x > 2500 && p.x < 3000) && p.y > 1200 && p.y < 2000)
            {
            operand2 = (operand2 * 10) + 3;
            tft_fillRoundRect(0, 15, 300, 45, 10, ILI9340_BLACK );
            tft_setTextSize(2);
            tft_setTextColor(ILI9340_WHITE);
            tft_setCursor(20, 24);
            sprintf(results, "%d", operand1);
            tft_writeString(results);
            FSM = OP1;
            }
            else if ((p.x > 1950 && p.x < 2500) && p.y > 2800 && p.y < 3500)
            {
            operand2 = (operand2 * 10) + 4;
            tft_fillRoundRect(0, 15, 300, 45, 10, ILI9340_BLACK );
            tft_setTextSize(2);
            tft_setTextColor(ILI9340_WHITE);
            tft_setCursor(20, 24);
            sprintf(results, "%d", operand1);
            tft_writeString(results);
            FSM = OP1;
            }
            else if ((p.x > 1950 && p.x < 2500) && p.y > 2000 && p.y < 2800)
            {
            operand2 = (operand2 * 10) + 5;
            tft_fillRoundRect(0, 15, 300, 45, 10, ILI9340_BLACK );
            tft_setTextSize(2);
            tft_setTextColor(ILI9340_WHITE);
            tft_setCursor(20, 24);
            sprintf(results, "%d", operand1);
            tft_writeString(results);
            FSM = OP1;
            }
            else if ((p.x > 1950 && p.x < 2500) && p.y > 1200 && p.y < 2000)
            {
            operand2 = (operand2 * 10) + 6;
            tft_fillRoundRect(0, 15, 300, 45, 10, ILI9340_BLACK );
            tft_setTextSize(2);
            tft_setTextColor(ILI9340_WHITE);
            tft_setCursor(20, 24);
            sprintf(results, "%d", operand1);
            tft_writeString(results);
            FSM = OP1;
            }
            else if ((p.x > 1500 && p.x < 1950) && p.y > 2800 && p.y < 3500)
            {
            operand2 = (operand2 * 10) + 7;
            tft_fillRoundRect(0, 15, 300, 45, 10, ILI9340_BLACK );
            tft_setTextSize(2);
            tft_setTextColor(ILI9340_WHITE);
            tft_setCursor(20, 24);
            sprintf(results, "%d", operand1);
            tft_writeString(results);
            FSM = OP1;
            }
            else if ((p.x > 1500 && p.x < 1950) && p.y > 2000 && p.y < 2800)
            {
            operand2 = (operand2 * 10) + 8;
            tft_fillRoundRect(0, 15, 300, 45, 10, ILI9340_BLACK );
            tft_setTextSize(2);
            tft_setTextColor(ILI9340_WHITE);
            tft_setCursor(20, 24);
            sprintf(results, "%d", operand1);
            tft_writeString(results);
            FSM = OP1;
            }
            else if ((p.x > 1500 && p.x < 1950) && p.y > 1200 && p.y < 2000)
            {
            operand2 = (operand2 * 10) + 9;
            tft_fillRoundRect(0, 15, 300, 45, 10, ILI9340_BLACK );
            tft_setTextSize(2);
            tft_setTextColor(ILI9340_WHITE);
            tft_setCursor(20, 24);
            sprintf(results, "%d", operand1);
            tft_writeString(results);
            FSM = OP1;
            }
            else if ((p.x > 1500 && p.x < 1950) && p.y > 500 && p.y < 1200)
            {
            tft_fillRoundRect(0, 15, 300, 45, 10, ILI9340_BLACK );
            tft_setTextSize(2);
            tft_setTextColor(ILI9340_WHITE);
            tft_setCursor(20, 24);
            sprintf(results, "%c", '+');
            tft_writeString(results);
            FSM = ADD;
            }
            else if ((p.x > 1950 && p.x < 2500) && p.y > 500 && p.y < 1200)
            {
            tft_fillRoundRect(0, 15, 300, 45, 10, ILI9340_BLACK );
            tft_setTextSize(2);
            tft_setTextColor(ILI9340_WHITE);
            tft_setCursor(20, 24);
            sprintf(results, "%s", '-');
            tft_writeString(results);
            FSM = SUB;
            }
            else if ((p.x > 2500 && p.x < 3000) && p.y > 500 && p.y < 1200)
            {
            tft_fillRoundRect(0, 15, 300, 45, 10, ILI9340_BLACK );
            tft_setTextSize(2);
            tft_setTextColor(ILI9340_WHITE);
            tft_setCursor(20, 24);
            sprintf(results, "%s", 'x');
            tft_writeString(results);
            FSM = MULT;
            }
            else if ((p.x > 3000 && p.x < 3500) && p.y > 500 && p.y < 1200)
            {
            tft_fillRoundRect(0, 15, 300, 45, 10, ILI9340_BLACK );
            tft_setTextSize(2);
            tft_setTextColor(ILI9340_WHITE);
            tft_setCursor(20, 24);
            sprintf(results, "%s", '/');
            tft_writeString(results);
            FSM = DIV;
            }
            else if ((p.x > 3000 && p.x < 3400) && p.y > 2000 && p.y < 2800)
            {
                operand1 = 0;
                tft_fillRoundRect(0, 15, 300, 45, 10, ILI9340_BLACK );
                tft_setTextSize(2);
                tft_setTextColor(ILI9340_WHITE);
                tft_setCursor(20, 24);
                sprintf(results, "%d", 0);
                tft_writeString(results);
                FSM = RESET;
            }
            else if ((p.x > 3000 && p.x < 3400) && p.y > 1200 && p.y < 2000)
            {
                result = operand1 * operand2;
                tft_fillRoundRect(0, 15, 300, 45, 10, ILI9340_BLACK );
                tft_setTextSize(2);
                tft_setTextColor(ILI9340_WHITE);
                tft_setCursor(20, 24);
                sprintf(results, "%d", result);
                tft_writeString(results);
            }

        else{
            FSM = MULT;
        }
        break;

    case DIV:
    //input = lcdinput();
        if(input = 20)
        {
            FSM = START;
        } 
        else if (input > 10)
        {
            operand2 = (operand2 * 10) + input;
            
            tft_setTextSize(2);
            tft_setTextColor(ILI9340_WHITE);
            tft_setCursor(20, 24);
            sprintf(results, "%d", operand2);
            tft_writeString(results);
            FSM = DIV;
        }

        else if(input = 15 && operand2 != 0) // looks for if the second operand is zero before running calculations
        {
            FSM = DIV0E;
        }

        else{
            FSM = DIV;
        }
        break;

    case ADD:
    //input = lcdinput();
        if(input = 20)
        {
            FSM = START;
        }
        else if (input > 10)
        {
            operand2 = (operand2 * 10) + input;
            
            tft_setTextSize(2);
            tft_setTextColor(ILI9340_WHITE);
            tft_setCursor(20, 24);
            sprintf(results, "%d", operand2);
            tft_writeString(results);
            FSM = ADD;
        }
        else if(input = 15)
        {
            result = operand1 + operand2;
            if(result > 2147483647 || result < -2147483648) //check bounds for overflow
            {
                FSM = OVERE; //runs overflow error
            }
            else
            {
                FSM = EQ;
            }
        }
        else{
            FSM = ADD;
        }
        break;

    case SUB:
    //input = lcdinput();
        if(input = 20)
        {
            FSM = START;
        }
        else if (input > 10)
        {
            operand2 = (operand2 * 10) + input;
            
            tft_setTextSize(2);
            tft_setTextColor(ILI9340_WHITE);
            tft_setCursor(20, 24);
            sprintf(results, "%d", operand2);
            tft_writeString(results);
            FSM = SUB;
        }
        if(input = 15)
        {
            result = operand1 - operand2;
            if(result > 2147483647 || result < -2147483648) //check bounds
            {
                FSM = OVERE; //runs overflow error
            }
            else
            {
                FSM = EQ;
            }
        }
        else{
            FSM = SUB;
        }
        break;

    case EQ:
    //input = lcdinput();
    tft_setTextSize(2);
    tft_setTextColor(ILI9340_WHITE);
    tft_setCursor(20, 24);
    sprintf(results, "%d", result);
    tft_writeString(results);
        if(input = 20)
        {
            FSM = START;
        }
        else{
            FSM = EQ;
        }
        break;

    case OVERE: //display 'ERROR' and waits for a clear
    //input = lcdinput();
        tft_setTextSize(2);
        tft_setTextColor(ILI9340_WHITE);
        tft_setCursor(20, 24);
        sprintf(results,"%s", "ERROR");
        tft_writeString(results);

        if(input = 20)
        {
            FSM = START;
        }
        else{
            FSM = OVERE;
        }
        break;

    case DIV0E: //display 'DIV 0' and waits for a clear
    //input = lcdinput();
    tft_setTextSize(2);
    tft_setTextColor(ILI9340_WHITE);
    tft_setCursor(20, 24);
    sprintf(results,"%s", "DIV 0");
     tft_writeString(results);

        if(input = 20)
        {
            FSM = START;
        }
        else{
            FSM = DIV0E;
        }
        break;
    
}   
}
}

int main() 
{

    ts_lcd_init();
    while(1)
    {
        math(); 
    }
}

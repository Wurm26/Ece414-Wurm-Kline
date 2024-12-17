/* 
 * File:   touch_main.c
 * Author: Matthew Watkins
 * Ported to Pico by John Nestor
 *
 * Description: Prints out the detected position (x, y) of a press on the
 * touchscreen as well as the pressure (z).
 * 
 * IMPORTANT: For this example to work, you need to make the following 
 * connections from the touchpad to the Pico:
 *  Y+ => ADC1/GP27 (Pin 32)
 *  Y- => GP21 (Pin 27)
 *  X+ => GP22 (Pin 29)
 *  X- => ADC0/GP26 (Pin 31)
 * 
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"
#include "TouchScreen.h"
#include "TFTMaster.h"
#include "stdbool.h"
//#include <cstdint>
#include "ts_lcd.h"


bool get_ts_lcd(uint16_t *pz)
{
      if(*pz<600){
            return true;
        }
        else {
            return false;
        }
}

void ts_lcd_init(){
    adc_init();
    //initialize screen
    tft_init_hw();
    tft_begin();
    tft_setRotation(3); 
    tft_fillScreen(ILI9340_BLACK);
    char buffer[30];
    
    //Display 0
    tft_setCursor(0, 195);
    tft_fillRoundRect(0, 195, 80, 45, 10, ILI9340_WHITE );
    tft_setTextSize(2);
    tft_setTextColor(ILI9340_BLACK);
    tft_setCursor(40,217.5);
    sprintf(buffer, "%d", 0);
    tft_writeString(buffer);

    //Display 1
    tft_setCursor(0,150);
    tft_fillRoundRect(0, 150, 80, 45, 10, ILI9340_WHITE );
    tft_setTextSize(2);
    tft_setTextColor(ILI9340_BLACK);
    tft_setCursor(40,172.5);
    sprintf(buffer, "%d", 1);
    tft_writeString(buffer);

    //Display 2 
    tft_setCursor(80,150);
    tft_fillRoundRect(80, 150, 80, 45, 10, ILI9340_WHITE );
    tft_setTextSize(2);
    tft_setTextColor(ILI9340_BLACK);
    tft_setCursor(120,172.5);
    sprintf(buffer, "%d", 2);
    tft_writeString(buffer);

    //Display 3
    tft_setCursor(160,150);
    tft_fillRoundRect(160, 150, 80, 45, 10, ILI9340_WHITE );
    tft_setTextSize(2);
    tft_setTextColor(ILI9340_BLACK);
    tft_setCursor(200,172.5);
    sprintf(buffer, "%d", 3);
    tft_writeString(buffer);

    //Display 4
    tft_setCursor(0,105);
    tft_fillRoundRect(0, 105, 80, 45, 10, ILI9340_WHITE );
    tft_setTextSize(2);
    tft_setTextColor(ILI9340_BLACK);
    tft_setCursor(40,127.5);
    sprintf(buffer, "%d", 4);
    tft_writeString(buffer);

    //Display 5
    tft_setCursor(80,105);
    tft_fillRoundRect(80, 105, 80, 45, 10, ILI9340_WHITE );
    tft_setTextSize(2);
    tft_setTextColor(ILI9340_BLACK);
    tft_setCursor(120,127.5);
    sprintf(buffer, "%d", 5);
    tft_writeString(buffer);

    //Display 6
    tft_setCursor(160,105);
    tft_fillRoundRect(160, 105, 80, 45, 10, ILI9340_WHITE );
    tft_setTextSize(2);
    tft_setTextColor(ILI9340_BLACK);
    tft_setCursor(200,127.5);
    sprintf(buffer, "%d", 6);
    tft_writeString(buffer);

    // Display 7
    tft_setCursor(0,60);
    tft_fillRoundRect(0, 60, 80, 45, 10, ILI9340_WHITE);
    tft_setTextSize(2);
    tft_setTextColor(ILI9340_BLACK);
    tft_setCursor(40,82.5);
    sprintf(buffer, "%d", 7);
    tft_writeString(buffer);

    //Display 8
    tft_setCursor(80,60);
    tft_fillRoundRect(80, 60, 80, 45, 10, ILI9340_WHITE );
    tft_setTextSize(2);
    tft_setTextColor(ILI9340_BLACK);
    tft_setCursor(120,82.5);
    sprintf(buffer, "%d", 8);
    tft_writeString(buffer);

    // Display 9
    tft_setCursor(160,60);
    tft_fillRoundRect(160, 60, 80, 45, 10, ILI9340_WHITE );
    tft_setTextSize(2);
    tft_setTextColor(ILI9340_BLACK);
    tft_setCursor(200,82.5);
    sprintf(buffer, "%d", 9);
    tft_writeString(buffer);

    // Display +
    tft_setCursor(240,60);
    tft_fillRoundRect(240, 60, 80, 45, 10, ILI9340_GREEN);
    tft_setTextSize(2);
    tft_setTextColor(ILI9340_BLACK);
    tft_setCursor(280,82.5);
    sprintf(buffer, "%c", '+');
    tft_writeString(buffer);

    //Display - 
    tft_setCursor(240,105);
    tft_fillRoundRect(240, 105, 80, 45, 10, ILI9340_GREEN );
    tft_setTextSize(2);
    tft_setTextColor(ILI9340_BLACK);
    tft_setCursor(280,127.5);
    sprintf(buffer, "%s", "-");
    tft_writeString(buffer);


    

    //Display X
    tft_setCursor(240,150);
    tft_fillRoundRect(240, 150, 80, 45, 10, ILI9340_GREEN );
    tft_setTextSize(2);
    tft_setTextColor(ILI9340_BLACK);
    tft_setCursor(280,172.5);
    sprintf(buffer, "%s", "x");
    tft_writeString(buffer);

   //Display C
    tft_setCursor(0, 195);
    tft_fillRoundRect(80, 195, 80, 45, 10, ILI9340_RED );
    tft_setTextSize(2);
    tft_setTextColor(ILI9340_BLACK);
    tft_setCursor(120,217.5);
    sprintf(buffer, "%s", "C");
    tft_writeString(buffer);

    //Display =
    tft_setCursor(0, 195);
    tft_fillRoundRect(160, 195, 80, 45, 10, ILI9340_BLUE );
    tft_setTextSize(2);
    tft_setTextColor(ILI9340_BLACK);
    tft_setCursor(200,217.5);
    sprintf(buffer, "%s", "=");
    tft_writeString(buffer);

    //Display /
    tft_setCursor(0, 195);
    tft_fillRoundRect(240, 195, 80, 45, 10, ILI9340_GREEN );
    tft_setTextSize(2);
    tft_setTextColor(ILI9340_BLACK);
    tft_setCursor(280,217.5);
    sprintf(buffer, "%s", "/");
    tft_writeString(buffer);
}

int lcdinput(int x, int y)
{
            if ((x > 1950 && x < 2450) && y > 1950 && y < 2750)
            {
            return 3;
            }
            else if ((x > 170 && x < 180) && y > 380 && y < 550)
            {
            return 1;
            
            }
            else if ((x > 140 && x < 170) && y > 380 && y < 550)
            {
            return 2;
            
            }
            else if ((x > 160 && x < 240) && y > 150 && y < 195)
            {
            return 3;
            
            }
            else if ((x > 0 && x < 80) && y > 105 && y < 150)
            {
            return 4;
            
            }
            else if ((x > 80 && x < 160) && y > 105 && y < 150)
            {
            return 5;
            
            }
            else if ((x > 160 && x < 240) && y > 105 && y < 150)
            {
            return 6;
            
            }
            else if ((x > 0 && x < 80) && y > 60 && y < 105)
            {
            return 7;
            
            }
            else if ((x > 80 && x < 160) && y > 60 && y < 105)
            {
              return 8;
              
            }
            else if ((x > 160 && x < 240) && y > 60 && y < 105)
            {
            return 9;
            
            }
            else if ((x > 240 && x < 320) && y > 60 && y < 105)
            {
            return 11;
            
            }
            
            else if ((x > 240 && x < 320) && y > 105 && y < 150)
            {
            return 14;
            
            }
            else if ((x > 240 && x < 320) && y > 150 && y < 195)
            {
            return 13;
            
            }
            else if ((x > 80 && x < 160) && y > 195 && y < 240)
            {
            return 20;
            
            }
            else if ((x > 160 && x < 240) && y > 195 && y < 240)
            {
            return 15;
            
            }
            else if ((x > 240 && x < 320) && y > 195 && y < 240)
            {
            return 12;
            
            }
}



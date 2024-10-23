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
//#include "ts_lcd.h"


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
}

/*int ts_test(){

    sprintf(buffer,"x: %d, y: %d, z: %d", p.x, p.y, p.z);
    tft_writeString(buffer);

    sprintf(buffer,"X");

    if (get_ts_lcd){
        //erase old text
        tft_setTextColor(ILI9340_BLACK);
        tft_writeString(buffer);
    }
}*/


int main() {
    ts_lcd_init();

    char buffer[30];
    
     int x_pos;
     int y_pos;
     int x_save;
     int y_save;

    struct TSPoint p;
          p.x = 0;
          p.y = 0;
          p.z = 0;
        

    
    while(1){
        
       
        int x_pos = (((-p.y*519) / 2729)); // Scale p.x to 0-319 Width
        int y_pos = (((p.x*239) / 4095)); // Scale p.y to 0-239 Height

        
        //ts_test();
        
        getPoint(&p);
        printf("Retrieved point: x=%d, y=%d, z=%d\n", p.x, p.y, p.z); // Debug output

        if(get_ts_lcd(&p.z)){
          tft_fillScreen(ILI9340_BLACK);
          tft_setCursor(20, 200);
          tft_setTextColor(ILI9340_WHITE); tft_setTextSize(2);
          //tft_setCursor(p.x, p.y);
            tft_setTextColor(ILI9340_BLACK);
            tft_writeString(buffer);
          
        
          tft_drawFastHLine(x_pos-10, y_pos, 20, ILI9340_RED);
          tft_drawFastVLine(x_pos, y_pos-10, 20, ILI9340_RED);

          tft_setCursor(20, 200);
          tft_setTextColor(ILI9340_WHITE);
          sprintf(buffer, "x: %d, y: %d", p.x, p.y);
          tft_writeString(buffer);

        //tft_writeString(buffer);
          tft_setTextColor(ILI9340_RED);
          tft_setCursor(x_pos, y_pos);
          tft_setTextSize(4);
          sprintf(buffer,"X");
          tft_writeString(buffer);

          tft_setCursor(x_pos, y_pos);
          printf(buffer, "X", x_pos, y_pos);
          tft_writeString(buffer);
        
          /*
        tft_setCursor(y_pos, x_pos);
          sprintf(buffer,"X");
          tft_writeString(buffer);
          printf(buffer, "X", y_pos, x_pos);
          tft_writeString(buffer);
          */

          //sleep_ms(100);
          tft_setTextSize(2);

          x_save=x_pos;
          y_save=y_pos;

        }
        else{
          x_save=x_save;
          y_save=y_save;
          tft_drawFastHLine(x_save-10, y_save, 20, ILI9340_YELLOW);
          tft_drawFastVLine(x_save, y_save-10, 20, ILI9340_YELLOW);

          tft_fillScreen(ILI9340_BLACK);
          tft_setTextColor(ILI9340_YELLOW);
          tft_setCursor(20, 200);
          sprintf(buffer,"x: %d, y: %d", p.x, p.y);
          tft_writeString(buffer);
       
          //tft_drawFastHLine(x_pos-10, y_pos, 20, ILI9340_RED);
          //tft_drawFastVLine(x_pos, y_pos-10, 20, ILI9340_RED);
          //tft_writeString(buffer);


          /*
          tft_setCursor(x_save, y_save);

          tft_setTextColor(ILI9340_MAGENTA);
          sprintf(buffer,"X");
          tft_writeString(buffer);
          printf(buffer, "X", x_save, y_save);
          tft_writeString(buffer);
          */
          /*
          tft_setCursor(y_pos, x_pos);
          sprintf(buffer,"X");
          tft_writeString(buffer);
          printf(buffer, "X", p.x, p.y);
          tft_writeString(buffer);
          */

        }
     sleep_ms(100);
    }
}


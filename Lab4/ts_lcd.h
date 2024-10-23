
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"
#include "stdio.h"
#include "TouchScreen.h"
#include "TFTMaster.h"
#ifndef _TS_LCD_H_
#define _TS_LCD_H_

bool get_ts_lcd(uint16_t *px, uint16_t *py);

void ts_lcd_init();

int  ts_test();

#endif 


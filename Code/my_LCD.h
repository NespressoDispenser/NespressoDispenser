#ifndef _MY_LCD_H_
#define _MY_LCD_H_
//--|Include systeme|------------------------------------------------------------------------
#include <Adafruit_LiquidCrystal.h>
#include <Arduino.h>
//--|Include user|---------------------------------------------------------------------------
#include "utility.h"
//--|Constants|---------------------------------------------------------------------------
#define DISPLAY_TIME 2000
#define LOGOUT_TIME 20000
#define LINE_ONE 0,0
#define LINE_TWO 0,1
#define LCD_PINS (50, 51, 39, 37,35, 33)
//--|Prototype|------------------------------------------------------------------------------
void display(eState state, Adafruit_LiquidCrystal my_LCD);
//-------------------------------------------------------------------------------------------
#endif /* _MY_LCD_H_ */

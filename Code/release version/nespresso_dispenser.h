#ifndef _NESPRESSO_H_
#define _NESPRESSO_H_
//--|Include systeme|------------------------------------------------------------------------
#include <Adafruit_LiquidCrystal.h>
#include <Servo.h>
#include <stdbool.h>
#include <Arduino.h>
//--|Include user|---------------------------------------------------------------------------
#include "my_LCD.h"
#include "my_servomoteur.h"
#include "sensors_functions.h"
#include "utility.h"
#include "led_functions.h"
#include "rfid_reader.h"
//--|Preprocesseur symbol|-------------------------------------------------------------------
#define POS_REST_1  87
#define POS_REST_2  94
#define POS_REST  90
#define POS_CAPSULE_1  155
#define POS_CAPSULE_2  25
#define POS_CAPSULE_3  155
#define POS_CAPSULE_4  25

#define COLUMN_LCD 16
#define ROW_LCD 2

#define DELAY_RESET 90000

//-------------------------------------------------------------------------------------------
#endif /* _NESPRESSO_H_ */

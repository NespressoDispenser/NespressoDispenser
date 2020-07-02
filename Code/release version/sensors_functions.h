#ifndef _HEADERFILE__SENSOR_FUNCTIONS_H
#define _HEADERFILE__SENSOR_FUNCTIONS_H

#include "Arduino.h"
//!!values might change upon your editing
// Definition pins inductives sensors
#define IND_SENS_1		30
#define IND_SENS_2		32
#define IND_SENS_3		36
#define IND_SENS_4		34
// Definition pins touch sensors
#define TOUCH_SENS_1	62
#define TOUCH_SENS_2	63
#define TOUCH_SENS_3	64
#define TOUCH_SENS_4	65
//Definition push buttons
#define CONFIRM_BUTTON 66
#define CANCEL_BUTTON 67
//macros
#define READ_IND_SENS(number) (!digitalRead(number))
#define READ_TOUCH_SENS(number) (digitalRead(number))
#define READ_PUSH_BT(number) (digitalRead(number))
// Initialization pins
void init_pins();
#endif //_HEADERFILE__SENSOR_FUNCTIONS_H

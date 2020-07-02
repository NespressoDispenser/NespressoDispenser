#ifndef _MY_SERVO_H_
#define _MY_SERVO_H_
//--|Include systeme|------------------------------------------------------------------------
#include <Servo.h>
#include <Arduino.h>
#define STEP_DELAY 10
//--|Structured type|------------------------------------------------------------------------
typedef struct
{
  uint16_t pos;
  uint8_t pin;
} sServo;
//--|Prototype|------------------------------------------------------------------------------
void rotate_servo(sServo servo, Servo order_servo, uint16_t end_pos);
//-------------------------------------------------------------------------------------------
#endif /* _MY_SERVO_H_ */

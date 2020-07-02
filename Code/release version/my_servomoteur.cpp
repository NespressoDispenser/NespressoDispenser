//--|Include user|---------------------------------------------------------------------------
#include "my_servomoteur.h"
//-------------------------------------------------------------------------------------------
void rotate_servo(sServo servo, Servo order_servo, uint16_t end_pos)
{
  if (end_pos > servo.pos)
  {
    for (servo.pos = servo.pos; servo.pos < end_pos; servo.pos++)
    {
      order_servo.write(servo.pos);
      delay(STEP_DELAY);
    }
  }
  else if (end_pos < servo.pos)
  {
    for (servo.pos = servo.pos; servo.pos > end_pos; servo.pos--)
    {
      order_servo.write(servo.pos);
      delay(STEP_DELAY);
    }
  }
}
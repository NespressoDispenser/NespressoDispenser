#include "sensors_functions.h"
void init_pins() {
  // Inductive sensors pins as input
  pinMode(IND_SENS_1, INPUT);
  pinMode(IND_SENS_2, INPUT);
  pinMode(IND_SENS_3, INPUT);
  pinMode(IND_SENS_4, INPUT);
  // Touch sensors pins as input
  pinMode(TOUCH_SENS_1, INPUT);
  pinMode(TOUCH_SENS_2, INPUT);
  pinMode(TOUCH_SENS_3, INPUT);
  pinMode(TOUCH_SENS_4, INPUT);
  // Push buttons
  pinMode(CONFIRM_BUTTON, INPUT);
  pinMode(CANCEL_BUTTON, INPUT);
}

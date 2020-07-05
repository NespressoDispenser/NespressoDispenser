//--|Include user|---------------------------------------------------------------------------
#include "nespresso_dispenser.h"
//-------------------------------------------------------------------------------------------
//----|Setup|--------------------------------------------------------------------------------
//detection capsule
bool sensor_capsule;
bool sensor_capsule_1;
bool sensor_capsule_2;
bool sensor_capsule_3;
bool sensor_capsule_4;
int num_sensor;
/*----------------Leds----------------------*/
CRGB strip_leds[NUM_LEDS];
const unsigned int capsule_1 = 3;
const unsigned int capsule_2 = 2;
const unsigned int capsule_3 = 1;
const unsigned int capsule_4 = 0;
/*----------------Switch-----------------------*/
//touch sensor 1-4
bool choice_1_active = false;
bool choice_2_active = false;
bool choice_3_active = false;
bool choice_4_active = false;
//confirm push button
bool confirm_active = false;
//cancel push button
bool cancel_active = false;
/*----------------Servomoteur-----------------------*/
//servo 1
sServo servo_1;
Servo order_servo_1;
//servo 2
sServo servo_2;
Servo order_servo_2;
//Fin de course
uint16_t end_position;
/*----------------LCD-----------------------*/
Adafruit_LiquidCrystal LCD(LCD_PINS);

/*----------------State Machine-----------------------*/
eState state_machine;
/*---------------old_time-----------------------*/
uint32_t old_time;
uint8_t capteurCapsuleDispo;
bool rfid;
int argentSuffisant;

USER active_user;
USER user1;
USER user2;

void receiveEvent(int howMany)
{
  int i = 0;
  while (Wire.available()) // loop through all
  {
    byte c = Wire.read();
    active_user.set_id(c, i);
    i++;
  }
  //we've decided to compare only the third byte for the demo
  if (active_user.get_id(3) == user1.get_id(3)) {
    active_user.set_solde(user1.get_solde());
  }
  if (active_user.get_id(3) == user2.get_id(3)) {
    active_user.set_solde(user2.get_solde());
  }
  active_user.log_in();
}

void setup()
{
  //Serial.begin(9600);
  init_reader();
  Wire.onReceive(receiveEvent);
  delay(DISPLAY_TIME);
  //load user's ID in objects
  for (int i = 0; i < ID_LENGTH; i++) {
    user1.set_id(DATABASE[0][i], i);
    user2.set_id(DATABASE[1][i], i);
  }
  user1.set_solde(1000);
  user2.set_solde(500);
  /*----------------Sensor-----------------------*/
  init_pins();
  sensor_capsule = false;
  sensor_capsule_1 = false;
  sensor_capsule_2 = false;
  sensor_capsule_3 = false;
  sensor_capsule_4 = false;
  /*----------------Led-----------------------*/
  FastLED.addLeds<WS2812, LED_PIN, GRB>(strip_leds, NUM_LEDS);
  /*----------------Servomoteur-----------------------*/
  //servo 1
  servo_1.pin = 8;
  servo_1.pos = POS_REST;
  order_servo_1.attach(servo_1.pin);
  order_servo_1.write(servo_1.pos);
  order_servo_1.detach();
  end_position = 0;
  //servo 2
  servo_2.pin = 9;
  servo_2.pos = POS_REST;
  order_servo_2.attach(servo_2.pin);
  order_servo_2.write(servo_2.pos);
  order_servo_2.detach();
  /*----------------LCD-----------------------*/
  LCD.begin(COLUMN_LCD, ROW_LCD);
  LCD.clear();
  /*----------------State Machine-----------------------*/
  leds_capsules(strip_leds, capsule_1, CRGB::Black);
  leds_capsules(strip_leds, capsule_2, CRGB::Black);
  leds_capsules(strip_leds, capsule_3, CRGB::Black);
  leds_capsules(strip_leds, capsule_4, CRGB::Black);
  state_machine = READ_RFID;
  /*----------------capsule-----------------------*/
  old_time = 0;
}
//-------------------------------------------------------------------------------------------
//----|Boucle Infinie|-----------------------------------------------------------------------
void loop()
{
  switch (state_machine)
  {
    case CHOICE_CAPSULE :
      display(state_machine, LCD);
      sensor_capsule_1 = READ_IND_SENS(IND_SENS_1);
      sensor_capsule_2 = READ_IND_SENS(IND_SENS_2);
      sensor_capsule_3 = READ_IND_SENS(IND_SENS_3);
      sensor_capsule_4 = READ_IND_SENS(IND_SENS_4);
      //switch on capsule colors upon availability
      sensor_capsule_1 ? leds_capsules(strip_leds, capsule_1, CRGB::Green) : leds_capsules(strip_leds, capsule_1, CRGB::Red);
      sensor_capsule_2 ? leds_capsules(strip_leds, capsule_2, CRGB::Green) : leds_capsules(strip_leds, capsule_2, CRGB::Red);
      sensor_capsule_3 ? leds_capsules(strip_leds, capsule_3, CRGB::Green) : leds_capsules(strip_leds, capsule_3, CRGB::Red);
      sensor_capsule_4 ? leds_capsules(strip_leds, capsule_4, CRGB::Green) : leds_capsules(strip_leds, capsule_4, CRGB::Red);

      choice_1_active = READ_TOUCH_SENS(TOUCH_SENS_1);
      choice_2_active = READ_TOUCH_SENS(TOUCH_SENS_2);
      choice_3_active = READ_TOUCH_SENS(TOUCH_SENS_3);
      choice_4_active = READ_TOUCH_SENS(TOUCH_SENS_4);
      cancel_active  =  READ_PUSH_BT(CANCEL_BUTTON);
      if (choice_1_active)
      {
        end_position = POS_CAPSULE_1;
      }
      else if (choice_2_active)
      {
        end_position = POS_CAPSULE_2;
      }
      else if (choice_3_active)
      {
        end_position = POS_CAPSULE_3;
      }
      else if (choice_4_active)
      {
        end_position = POS_CAPSULE_4;
      }
      if (choice_1_active || choice_2_active || choice_3_active || choice_4_active)
      {
        state_machine = CHECK_CAPSULE_AVAILABLE;
        LCD.clear();
      }
      else if (cancel_active || ((millis() - old_time) >= LOGOUT_TIME)) //checking 20s
      {
        LCD.clear();
        LCD.setCursor(LINE_ONE);
        LCD.print("Bienvenue");
        LCD.setCursor(LINE_TWO);
        LCD.print("Carte SVP");
        cancel_active = false;
        state_machine = TURN_OFF_LED;
      }
      else
      {
        state_machine = CHOICE_CAPSULE;
      }
      break;
    case CHECK_CAPSULE_AVAILABLE :
      if (choice_1_active)
      {
        num_sensor = IND_SENS_1;
      }
      else if (choice_2_active)
      {
        num_sensor = IND_SENS_2;
      }
      else if (choice_3_active)
      {
        num_sensor = IND_SENS_3;
      }
      else if (choice_4_active)
      {
        num_sensor = IND_SENS_4;
      }
      sensor_capsule = READ_IND_SENS(num_sensor);
      if (sensor_capsule)
      {
        state_machine = CHECK_MONEY_SUFFICIENT;
        old_time = millis();
        LCD.clear();
      }
      else
      {
        state_machine = CAPSULE_UNAVAILABLE;
      }
      break;
    case CAPSULE_UNAVAILABLE :
      display(state_machine, LCD);
      delay(DISPLAY_TIME);
      state_machine = CHOICE_CAPSULE;
      LCD.clear();
      break;
    case READ_RFID :
      display(state_machine, LCD);
      rfid = active_user.is_logged();
      if (rfid)
      {
        rfid = false;
        turn_on_light(strip_leds);
        old_time = millis();
        LCD.clear();
        state_machine = CHOICE_CAPSULE;
      }
      else
      {
        state_machine = READ_RFID;
      }
      break;
    case CHECK_MONEY_SUFFICIENT :
      argentSuffisant = active_user.get_solde();
      state_machine =  (argentSuffisant >= CAPSULE_PRICE) ? MONEY_SUFFICIENT : MONEY_INSUFFICIENT;
      break;
    case MONEY_SUFFICIENT :
      display(state_machine, LCD);
      state_machine = CONFIRMATION_PAYMENT;
      LCD.setCursor(LINE_TWO);
      LCD.print("Solde : ");
      //print floating number out of integer variable
      LCD.print((active_user.get_solde() / 100));
      LCD.print(".");
      LCD.print((active_user.get_solde() % 100));
      LCD.print(" CHF");
      delay(DISPLAY_TIME);
      old_time = millis();
      LCD.clear();
      break;
    case MONEY_INSUFFICIENT :
      display(state_machine, LCD);
      delay(DISPLAY_TIME);
      state_machine = CHOICE_CAPSULE;
      LCD.clear();
      break;
    case CONFIRMATION_PAYMENT :
      display(state_machine, LCD);
      confirm_active = READ_PUSH_BT(CONFIRM_BUTTON);
      cancel_active = READ_PUSH_BT(CANCEL_BUTTON);
      if (confirm_active)
      {
        state_machine = PAYMENT;
        confirm_active = false;
      }
      else if ((cancel_active) or ((millis() - old_time) >= LOGOUT_TIME))
      {
        cancel_active = false;
        state_machine = CHOICE_CAPSULE;
        LCD.clear();
      }
      else
      {
        state_machine = CONFIRMATION_PAYMENT;
      }
      break;
    case PAYMENT :
      display(state_machine, LCD);
      delay(DISPLAY_TIME);
      active_user.buy_capsule(CAPSULE_PRICE);
      //check active user and update solde (just for the demo)
      if (active_user.get_id(3) == user1.get_id(3)) {
        user1.set_solde(active_user.get_solde());
      }
      if (active_user.get_id(3) == user2.get_id(3)) {
        user2.set_solde(active_user.get_solde());
      }
      state_machine = DROPPING_CAPSULE;
      break;
    case DROPPING_CAPSULE :
      display(state_machine, LCD);
      if (choice_1_active or choice_2_active)
      {
        order_servo_1.attach(servo_1.pin);
        rotate_servo(servo_1, order_servo_1, end_position);
        servo_1.pos = end_position;
        order_servo_1.detach();
        if (choice_1_active)
        {
          end_position = POS_REST_1;
        }
        else
        {
          end_position = POS_REST;
        }
      }
      else if (choice_3_active or choice_4_active)
      {
        order_servo_2.attach(servo_2.pin);
        rotate_servo(servo_2, order_servo_2, end_position);
        servo_2.pos = end_position;
        order_servo_2.detach();
        if (choice_4_active)
        {
          end_position = POS_REST_2;
        }
        else
        {
          end_position = POS_REST;
        }
      }
      delay(DISPLAY_TIME);
      state_machine = CAPSULE_DROPPED;
      break;
    case CAPSULE_DROPPED :
      display(state_machine, LCD);
      if (choice_1_active or choice_2_active)
      {
        order_servo_1.attach(servo_1.pin);
        rotate_servo(servo_1, order_servo_1, end_position);
        order_servo_1.detach();
        delay(DISPLAY_TIME);
        servo_1.pos = end_position;
        choice_1_active = false;
        choice_2_active = false;
      }
      else if (choice_3_active or choice_4_active)
      {
        order_servo_2.attach(servo_2.pin);
        rotate_servo(servo_2, order_servo_2, end_position);
        order_servo_2.detach();
        servo_2.pos = end_position;
        choice_3_active = false;
        choice_4_active = false;
      }
      state_machine = TURN_OFF_LED;
      break;
    case  TURN_OFF_LED:
      turn_off_light(strip_leds);
      active_user.logout();
      leds_capsules(strip_leds, capsule_1, CRGB::Black);
      leds_capsules(strip_leds, capsule_2, CRGB::Black);
      leds_capsules(strip_leds, capsule_3, CRGB::Black);
      leds_capsules(strip_leds, capsule_4, CRGB::Black);
      state_machine = READ_RFID;
      delay(DISPLAY_TIME);
      LCD.clear();
      break;
    default :
      break;
  }
}

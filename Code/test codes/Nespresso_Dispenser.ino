//--|Informations|---------------------------------------------------------------------------
//--HEIG - VD, Haute Ecole d'Ingenierie et de Gestion du canton de Vaud
//--
//--Fichier       : Nespresso_Dispenser.h
//--Description   : Nespresso_dispenser library header file.
//--
//--Auteur  : L.Fournier
//--Date    : 10.06.2020
//--Version : 1.0
//--Bug     : None
//--
//--Utilise : 
//--
//--|Modifications|--------------------------------------------------------------------------
//--Ver        Auteur   Date           Description
//--1.0        LFR      10.06.2020     Nespresso_dispenser header file.
//--                                      
//-------------------------------------------------------------------------------------------

//--|Include user|---------------------------------------------------------------------------
#pragma once
#include "nespresso_dispenser.h"  
#include "database.h"
#include "rfid_reader.h"


//-------------------------------------------------------------------------------------------
 
//----|Setup|--------------------------------------------------------------------------------
//detection capsule
int sensor_capsule;
int sensor_capsule_1;
int sensor_capsule_2;
int sensor_capsule_3;
int sensor_capsule_4;
IND_SENS_INPUT num_sensor;

/*----------------Database variables----------------------*/
USER user_base[NBR_PERS];
USER utilisateur_actif;
/*----------------Leds----------------------*/
CRGB strip_leds[NUM_LEDS];
const unsigned int capsule_1 = 0;
const unsigned int capsule_2 = 1;
const unsigned int capsule_3 = 2;
const unsigned int capsule_4 = 3;


/*----------------Switch-----------------------*/
//Switch choix 1
sSwitch switch_choice_1;  

//Switch choix 2
sSwitch switch_choice_2;  

//Switch choix 3
sSwitch switch_choice_3; 

//Switch choix 4
sSwitch switch_choice_4;

//Switch validation
sSwitch switch_validation;   

//Switch reset
sSwitch switch_reset;

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
Adafruit_LiquidCrystal LCD(50, 51, 39, 37, 
                              35, 33);

/*----------------State Machine-----------------------*/
eState state_machine;

/*----------------capsule-----------------------*/
//bool capsule_pick ;

/*---------------Attente-----------------------*/
uint32_t attente;

uint8_t capteurCapsuleDispo;
uint8_t rfid;
uint8_t argentSuffisant;

void setup() 
{
   /*----------------SEnsor-----------------------*/
    init_pins();
    sensor_capsule = 1;
    sensor_capsule_1 = 1;
    sensor_capsule_2 = 1;
    sensor_capsule_3 = 1;
    sensor_capsule_4 = 1;
    pinMode(IND_SENS_1,INPUT);
    pinMode(IND_SENS_2,INPUT);
    pinMode(IND_SENS_3,INPUT);
    pinMode(IND_SENS_4,INPUT);
    num_sensor = IND_SENS_INPUT_1;

    /*----------------Led-----------------------*/
    
    
    FastLED.addLeds<WS2812, LED_PIN, GRB>(strip_leds, NUM_LEDS);
    turn_on_light(strip_leds);
    
    sensor_capsule_1 = digitalRead(IND_SENS_1);
    if(sensor_capsule_1 == 0)
    {
      leds_capsules(strip_leds, capsule_1, CRGB::Green);
      sensor_capsule_1 = 1;
    }
    else
    {
      leds_capsules(strip_leds, capsule_1, CRGB::Red);
    }

    sensor_capsule_2 = digitalRead(IND_SENS_2);
    if(sensor_capsule_2 == 0)
    {
      leds_capsules(strip_leds, capsule_2, CRGB::Green);
      sensor_capsule_2 = 1;
    }
    else
    {
      leds_capsules(strip_leds, capsule_2, CRGB::Red);
    }

    sensor_capsule_3 = digitalRead(IND_SENS_3);
    if(sensor_capsule_3 == 0)
    {
      leds_capsules(strip_leds, capsule_3, CRGB::Green);
      sensor_capsule_3 = 1;
    }
    else
    {
      leds_capsules(strip_leds, capsule_3, CRGB::Red);
    }

    sensor_capsule_4 = digitalRead(IND_SENS_4);
    if(sensor_capsule_4 == 0)
    {
      leds_capsules(strip_leds, capsule_4, CRGB::Green);
      sensor_capsule_4 = 1;
    }
    else
    {
      leds_capsules(strip_leds, capsule_4, CRGB::Red);
    }
    

    
   /*----------------Switch-----------------------*/
   //Switch choix 1
   switch_choice_1.pin = 62;
   switch_choice_1.is_pressed = 0;
   pinMode(switch_choice_1.pin,INPUT);
   
   //Switch choix 2  
   switch_choice_2.pin = 63;
   switch_choice_2.is_pressed = 0;
   pinMode(switch_choice_2.pin,INPUT);

   //Switch choix 3
   switch_choice_3.pin = 64;
   switch_choice_3.is_pressed = 0;
   pinMode(switch_choice_3.pin,INPUT);
 
   //Switch choix 4
   switch_choice_4.pin = 65;
   switch_choice_4.is_pressed = 0;
   pinMode(switch_choice_4.pin,INPUT);

  //Switch validation
   switch_validation.pin = 66;
   switch_validation.is_pressed = 0;
   pinMode(switch_validation.pin,INPUT);

  //Switch reset
   switch_reset.pin = 67;
   switch_reset.is_pressed = 0;
   pinMode(switch_reset.pin,INPUT);

   /*----------------Servomoteur-----------------------*/
   //servo 1
   servo_1.pin = 8;
   servo_1.pos = 90;//POS_REST;
   order_servo_1.attach(servo_1.pin);    
   order_servo_1.write(servo_1.pos);  
   order_servo_1.detach();
   end_position = 0;

   //servo 2
   servo_2.pin = 9;
   servo_2.pos = 90;//POS_REST;
   order_servo_2.attach(servo_2.pin);    
   
   order_servo_2.write(servo_2.pos); 
   order_servo_2.detach();

   /*----------------LCD-----------------------*/

   LCD.begin(COLUMN_LCD, ROW_LCD);   
   LCD.clear();

   /*----------------State Machine-----------------------*/

   state_machine = CHOICE_CAPSULE; 
   
   /*----------------capsule-----------------------*/
  attente = 0;


init_reader();
  
}
//-------------------------------------------------------------------------------------------

//----|Boucle Infinie|-----------------------------------------------------------------------
void loop() 
{
    
    switch(state_machine)
    {
      case CHOICE_CAPSULE : 
      
        display(state_machine, LCD);

        switch_choice_1.is_pressed = digitalRead(switch_choice_1.pin);
        switch_choice_2.is_pressed = digitalRead(switch_choice_2.pin);
        switch_choice_3.is_pressed = digitalRead(switch_choice_3.pin);
        switch_choice_4.is_pressed = digitalRead(switch_choice_4.pin);
        
        if(switch_choice_1.is_pressed == 1)
        {
          end_position = POS_CAPSULE_1;
        }
        else if(switch_choice_2.is_pressed == 1)
        {
          end_position = POS_CAPSULE_2;
        }
        else if(switch_choice_3.is_pressed == 1)
        {
          end_position = POS_CAPSULE_3;
        }     
        else if(switch_choice_4.is_pressed == 1)
        {
          end_position = POS_CAPSULE_4;
        }

        if((switch_choice_1.is_pressed == 1)||(switch_choice_2.is_pressed == 1)||(switch_choice_3.is_pressed == 1)||(switch_choice_4.is_pressed == 1))
        {
          state_machine = CHECK_CAPSULE_AVAILABLE;
        }
         else
        {
          state_machine = CHOICE_CAPSULE;
        }
   
      break;
      case CHECK_CAPSULE_AVAILABLE :
      
         if(switch_choice_1.is_pressed == 1)
         {
            num_sensor = IND_SENS_1;
         }
         else if(switch_choice_2.is_pressed == 1)
         {
            num_sensor = IND_SENS_2;
         }
         else if(switch_choice_3.is_pressed == 1)
         {
            num_sensor = IND_SENS_3;
         }
         else if(switch_choice_4.is_pressed == 1)
         {
            num_sensor = IND_SENS_4;
         }

        sensor_capsule = digitalRead(num_sensor);
        
        if(sensor_capsule == 0)
        {
          state_machine = CAPSULE_AVAILABLE; 
          sensor_capsule = 1;  
        }  
        else
        {
          state_machine = CAPSULE_UNAVAILABLE;    
        } 

      break;
      case CAPSULE_AVAILABLE : 
      
        state_machine = READ_RFID;    
        
        attente = millis(); 
        LCD.clear();   
        
      break;
      case CAPSULE_UNAVAILABLE : 
      
        display(state_machine, LCD);
        delay(3000);
        
        state_machine = CHOICE_CAPSULE; 
               
        LCD.clear();
        
      break;
      case READ_RFID : 
      
        display(state_machine, LCD);
        rfid = 1;
        //read_card(0x30,4, &utilisateur_actif);
        char id_test[8] = {utilisateur_actif.get_id()};
//        LCD.clear();
//        LCD.setCursor(0,1);
//        LCD.print(id_test);
        delay(3000);
        //rfid = is_logged(&utilisateur_actif);
        switch_reset.is_pressed = digitalRead(switch_reset.pin);
        
        if((switch_reset.is_pressed == 1)||((millis() - attente) >= 90000))
        {
          switch_reset.is_pressed = 0;
          state_machine = CHOICE_CAPSULE;
          
          LCD.clear();
        }
        else if(rfid == 1)
        {
          state_machine = RFID_RECOGNIZED;        
        }
        else
        {
          state_machine = READ_RFID;      
        }
      break;
      case RFID_RECOGNIZED : 
      
        state_machine = CHECK_MONEY_SUFFICIENT;   
             
      break;
      case CHECK_MONEY_SUFFICIENT : 
      
        argentSuffisant = 1;
        //argentSuffisant = enough_money(50,&utilisateur_actif);
        //buy_capsule(50,&utilisateur_actif);
        if(argentSuffisant == 1)
        {
          state_machine = MONEY_SUFFICIENT;
        }
        else
        {
          state_machine = MONEY_INSUFFICIENT;   
        }    
         
      break;
      case MONEY_SUFFICIENT : 
          //int actual_money = utilisateur_actif.get_solde();
          display(state_machine, LCD); 
          //LCD.print(actual_money);
          delay(3000);
         
         state_machine = CONFIRMATION_PAYMENT;
         
         attente = millis();  
         LCD.clear();
         
      break;
      case MONEY_INSUFFICIENT : 
      
         display(state_machine, LCD); 
         delay(3000);
         
         state_machine = CHOICE_CAPSULE;
         
         LCD.clear();
         
      break;
      case CONFIRMATION_PAYMENT :
      
        display(state_machine, LCD); 
        
        switch_validation.is_pressed = digitalRead(switch_validation.pin);
        switch_reset.is_pressed = digitalRead(switch_reset.pin);
        
        if(switch_validation.is_pressed == 1)
        {
          state_machine = PAYMENT;  
          switch_validation.is_pressed = 0; 
        }
        else if((switch_reset.is_pressed == 1)||((millis() - attente) >= 90000))
        { 
          switch_reset.is_pressed = 0;
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
        //buy_capsule(50,&utilisateur_actif);
        delay(3000);
        
        state_machine = CATCHING_CAPSULE;
        
      break;
      case CATCHING_CAPSULE :
      
        display(state_machine, LCD);
        
        if((switch_choice_1.is_pressed == 1)||(switch_choice_2.is_pressed == 1))
        {
           order_servo_1.attach(servo_1.pin);
          
           rotate_servo(servo_1, order_servo_1, end_position);   
           servo_1.pos = end_position;
            order_servo_1.detach();
            delay(3000);
        }
        else if((switch_choice_3.is_pressed == 1)||(switch_choice_4.is_pressed == 1))
        {
           order_servo_2.attach(servo_2.pin);
           
           rotate_servo(servo_2, order_servo_2, end_position);
           servo_2.pos = end_position;   
           order_servo_2.detach(); 
           delay(3000);
                  
        }
        end_position = 90;//POS_REST;    
   
        state_machine = DROPPING_CAPSULE;  
        
      break;
      case DROPPING_CAPSULE :
       
        if((switch_choice_1.is_pressed == 1)||(switch_choice_2.is_pressed == 1))
        {
           order_servo_1.attach(servo_1.pin);
           
           rotate_servo(servo_1, order_servo_1, end_position);
            order_servo_1.detach();
            delay(3000);
           servo_1.pos = end_position;
           switch_choice_1.is_pressed = 0;
           switch_choice_2.is_pressed = 0;
        }
        else if((switch_choice_3.is_pressed == 1)||(switch_choice_4.is_pressed == 1))
        {
           order_servo_2.attach(servo_2.pin);
        
           rotate_servo(servo_2, order_servo_2, end_position);
            order_servo_2.detach();
            delay(3000);
           servo_2.pos = end_position;
           switch_choice_3.is_pressed = 0;
           switch_choice_4.is_pressed = 0;
        }
         
        state_machine = CAPSULE_DROPPED;
       
      break;
      case  CAPSULE_DROPPED :
      
        display(state_machine, LCD);  
        delay(3000);   
        
        state_machine = COLOR_LED;
        LCD.clear();
        logout(&utilisateur_actif);
      break;
      case  COLOR_LED:
      
     sensor_capsule_1 = digitalRead(IND_SENS_1);
    if(sensor_capsule_1 == 0)
    {
      leds_capsules(strip_leds, capsule_1, CRGB::Green);
      sensor_capsule_1 = 1;
    }
    else
    {
      leds_capsules(strip_leds, capsule_1, CRGB::Red);
    }

    sensor_capsule_2 = digitalRead(IND_SENS_2);
    if(sensor_capsule_2 == 0)
    {
      leds_capsules(strip_leds, capsule_2, CRGB::Green);
      sensor_capsule_2 = 1;
    }
    else
    {
      leds_capsules(strip_leds, capsule_2, CRGB::Red);
    }

    sensor_capsule_3 = digitalRead(IND_SENS_3);
    if(sensor_capsule_3 == 0)
    {
      leds_capsules(strip_leds, capsule_3, CRGB::Green);
      sensor_capsule_3 = 1;
    }
    else
    {
      leds_capsules(strip_leds, capsule_3, CRGB::Red);
    }

    sensor_capsule_4 = digitalRead(IND_SENS_4);
    if(sensor_capsule_4 == 0)
    {
      leds_capsules(strip_leds, capsule_4, CRGB::Green);
      sensor_capsule_4 = 1;
    }
    else
    {
      leds_capsules(strip_leds, capsule_4, CRGB::Red);
    }
    
        state_machine = CHOICE_CAPSULE;
       
      break;
      default :
      break;
    }
}
    
   
//-------------------------------------------------------------------------------------------

//----|Interrupts|-------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------

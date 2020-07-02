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

#ifndef _NESPRESSO_H_
#define _NESPRESSO_H_

//--|Include systeme|------------------------------------------------------------------------
#include <Adafruit_LiquidCrystal.h>  
#include <Servo.h>    
#include <stdbool.h>     
#include <Arduino.h>  
//-------------------------------------------------------------------------------------------

//--|Include user|---------------------------------------------------------------------------
#include "my_LCD.h"  
#include "my_servomoteur.h"   
#include "sensors_functions.h"
#include "utility.h"
#include "led_functions.h"

//-------------------------------------------------------------------------------------------

//--|Preprocesseur symbol|-------------------------------------------------------------------
//pin arduino
#define PIN_D2  2
#define PIN_D3  3
#define PIN_D4  4
#define PIN_D5  5
#define PIN_D6  6
#define PIN_D7  7
#define PIN_D8  8
#define PIN_D9  9
#define PIN_D10  10
#define PIN_D11  11
#define PIN_D12  12
#define PIN_D13  13
#define PIN_D14  14
#define PIN_D15  15
#define PIN_D16  16
#define PIN_D17  17
#define PIN_D18  18
#define PIN_D19  19
#define PIN_D20  20
#define PIN_D21  21

#define POS_REST  90

#define POS_CAPSULE_1  180
#define POS_CAPSULE_2  0
#define POS_CAPSULE_3  180
#define POS_CAPSULE_4  0

#define COLUMN_LCD 16
#define ROW_LCD 2

#define DELAY_RESET 90000


//-------------------------------------------------------------------------------------------

//--|Macro|----------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------

//--|Enumerate type|-------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------

//--|Structured type|------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------

//--|Union type|-----------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------

//--|Prototype|------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------

//--|External|-------------------------------------------------------------------------------
/*----------------Sensor-----------------------*/
////detection capsule
//int sensor_capsule;
//IND_SENS_INPUT num_sensor;
//
///*----------------Leds----------------------*/
//CRGB strip_leds[NUM_LEDS];
//const unsigned int capsule_1 = 0;
//const unsigned int capsule_2 = 1;
//const unsigned int capsule_3 = 2;
//const unsigned int capsule_4 = 3;
//
//
///*----------------Switch-----------------------*/
////Switch choix 1
//sSwitch switch_choice_1;  
//
////Switch choix 2
//sSwitch switch_choice_2;  
//
////Switch choix 3
//sSwitch switch_choice_3; 
//
////Switch choix 4
//sSwitch switch_choice_4;
//
////Switch validation
//sSwitch switch_validation;   
//
////Switch reset
//sSwitch switch_reset;
//
///*----------------Servomoteur-----------------------*/
////servo 1
//sServo servo_1;
//Servo order_servo_1;
//
////servo 2
//sServo servo_2;
//Servo order_servo_2;
//
////Fin de course
//uint8_t end_position;
//
///*----------------LCD-----------------------*/
//Adafruit_LiquidCrystal LCD(50, 51, 39, 37, 
//                              35, 33);
//
///*----------------State Machine-----------------------*/
//eState state_machine;
//
///*----------------capsule-----------------------*/
//bool capsule_pick ;
//
///*---------------Attente-----------------------*/
//uint32_t attente;
//
//uint8_t capteurCapsuleDispo;
//uint8_t rfid;
//uint8_t argentSuffisant;
//-------------------------------------------------------------------------------------------
#endif /* _NESPRESSO_H_ */

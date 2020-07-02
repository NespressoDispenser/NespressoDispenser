//--|Informations|---------------------------------------------------------------------------
//--HEIG - VD, Haute Ecole d'Ingenierie et de Gestion du canton de Vaud
//--
//--Fichier       : my_servomoteur.cpp
//--Description   : 
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
//--1.0        LFR      10.06.2020     
//--                                      
//-------------------------------------------------------------------------------------------

//--|Include user|---------------------------------------------------------------------------
#include "my_servomoteur.h"
//-------------------------------------------------------------------------------------------

void rotate_servo(sServo servo, Servo order_servo, uint16_t end_pos)
{
   if(end_pos > servo.pos)
   { 
      for(servo.pos = servo.pos; servo.pos < end_pos; servo.pos++)
      {
         order_servo.write(servo.pos);
         delay(10);   
      }  
      //delay(3000);        
   }
   else if(end_pos < servo.pos)
   { 
      for(servo.pos = servo.pos; servo.pos > end_pos; servo.pos--)
      {
         order_servo.write(servo.pos);
         delay(10);   
      }  
     // delay(3000);      
   }
   
}

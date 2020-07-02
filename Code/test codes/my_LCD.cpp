//--|Informations|---------------------------------------------------------------------------
//--HEIG - VD, Haute Ecole d'Ingenierie et de Gestion du canton de Vaud
//--
//--Fichier       : my_LDC.cpp
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
#include "my_LCD.h"  
//-------------------------------------------------------------------------------------------

void display(eState state, Adafruit_LiquidCrystal my_LCD)
{
  switch(state)
  {
    case  CHOICE_CAPSULE : 
      my_LCD.setCursor(0, 0);
      my_LCD.print("Bienvenue");      
      my_LCD.setCursor(0, 1);
      my_LCD.print("Choisissez cafe");            
    break;
    case  CAPSULE_UNAVAILABLE: 
      my_LCD.clear();
      my_LCD.setCursor(0, 0);
      my_LCD.print("Capsule");
      my_LCD.setCursor(0, 1);
      my_LCD.print("Indisponible");                
    break;
    case   READ_RFID : 
      my_LCD.setCursor(0, 0);
      my_LCD.print("Prix : 0.5 CHF");
      my_LCD.setCursor(0, 1);
      my_LCD.print("Carte SVP");                
    break;
    case  MONEY_SUFFICIENT : 
      my_LCD.clear();
      my_LCD.setCursor(0, 0);
      my_LCD.print("Prix : 0.5 CHF");
      my_LCD.setCursor(0, 1);
      my_LCD.print("Solde : 1 CHF");                
    break;
    case  MONEY_INSUFFICIENT : 
      my_LCD.clear();
      my_LCD.setCursor(0, 0);
      my_LCD.print("Solde");
      my_LCD.setCursor(0, 1);
      my_LCD.print("Insuffisante");                
    break;
    case  CONFIRMATION_PAYMENT : 
      my_LCD.setCursor(0, 0);
      my_LCD.print("Presser bouton 1");
      my_LCD.setCursor(0, 1);
      my_LCD.print("pour valider");                
    break;
    case  PAYMENT : 
      my_LCD.clear();
      my_LCD.setCursor(0, 0);
      my_LCD.print("Payement ok");
      my_LCD.setCursor(0, 1);
      my_LCD.print("Solde: ");       
    break;
    case  CATCHING_CAPSULE : 
      my_LCD.clear();
      my_LCD.setCursor(0, 0);
      my_LCD.print("Distribution");
      my_LCD.setCursor(0, 1);
      my_LCD.print("En cours");                
    break;
    case  CAPSULE_DROPPED : 
      my_LCD.clear();
      my_LCD.setCursor(0, 0);
      my_LCD.print("Ramassez");
      my_LCD.setCursor(0, 1);
      my_LCD.print("Votre capsule");              
    break;
    case  COLOR_LED : 
    break;
    default :
    break;
  }
}
//-----------------------------------------------------------------------------------------------

//--|Include user|---------------------------------------------------------------------------
#include "my_LCD.h"
void display(eState state, Adafruit_LiquidCrystal my_LCD)
{
  switch (state)
  {
    case  CHOICE_CAPSULE :
      my_LCD.setCursor(LINE_ONE);
      my_LCD.print("Choisissez");
      my_LCD.setCursor(LINE_TWO);
      my_LCD.print("Capsule");
      break;
    case  CAPSULE_UNAVAILABLE:
      my_LCD.clear();
      my_LCD.setCursor(LINE_ONE);
      my_LCD.print("Capsule");
      my_LCD.setCursor(LINE_TWO);
      my_LCD.print("Indisponible");
      break;
    case   READ_RFID :
      my_LCD.setCursor(LINE_ONE);
      my_LCD.print("Bienvenue");
      my_LCD.setCursor(LINE_TWO);
      my_LCD.print("Carte SVP");
      break;
    case  MONEY_SUFFICIENT :
      my_LCD.clear();
      my_LCD.setCursor(LINE_ONE);
      my_LCD.print("Prix : 0.50 CHF");

      break;
    case  MONEY_INSUFFICIENT :
      my_LCD.clear();
      my_LCD.setCursor(LINE_ONE);
      my_LCD.print("Solde");
      my_LCD.setCursor(LINE_TWO);
      my_LCD.print("insuffisant");
      break;
    case  CONFIRMATION_PAYMENT :
      my_LCD.setCursor(LINE_ONE);
      my_LCD.print("Bouton vert");
      my_LCD.setCursor(LINE_TWO);
      my_LCD.print("pour valider");
      break;
    case  PAYMENT :
      my_LCD.clear();
      my_LCD.setCursor(LINE_ONE);
      my_LCD.print("Paiement");
      my_LCD.setCursor(LINE_TWO);
      my_LCD.print("Effectue");
      break;
    case  CATCHING_CAPSULE :
      my_LCD.clear();
      my_LCD.setCursor(LINE_ONE);
      my_LCD.print("Distribution");
      my_LCD.setCursor(LINE_TWO);
      my_LCD.print("En cours");
      break;
    case   DROPPING_CAPSULE:
      my_LCD.clear();
      my_LCD.setCursor(LINE_ONE);
      my_LCD.print("Ramassez");
      my_LCD.setCursor(LINE_TWO);
      my_LCD.print("Votre capsule");
      break;
    default :
      break;
  }
}

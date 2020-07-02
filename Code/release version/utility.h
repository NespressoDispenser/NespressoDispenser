#ifndef _UTILITY_H_
#define _UTILITY_H_
//--|Include systeme|------------------------------------------------------------------------
#include <Arduino.h>
//--|Constants|------------------------------------------------------------------------------
#define CAPSULE_PRICE 50
//--|Enumerate type|-------------------------------------------------------------------------
typedef enum {
  CHOICE_CAPSULE = 0,
  CHECK_CAPSULE_AVAILABLE,
  CAPSULE_AVAILABLE,
  CAPSULE_UNAVAILABLE,
  READ_RFID,
  RFID_RECOGNIZED,
  CHECK_MONEY_SUFFICIENT,
  MONEY_SUFFICIENT,
  MONEY_INSUFFICIENT,
  CONFIRMATION_PAYMENT,
  PAYMENT,
  CATCHING_CAPSULE,
  CAPSULE_CATCHED,
  DROPPING_CAPSULE,
  CAPSULE_DROPPED,
  COLOR_LED
} eState;
//-------------------------------------------------------------------------------------------
#endif /* _UTILITY_H_ */

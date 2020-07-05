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
  CHECK_MONEY_SUFFICIENT,
  MONEY_SUFFICIENT,
  MONEY_INSUFFICIENT,
  CONFIRMATION_PAYMENT,
  PAYMENT,
  DROPPING_CAPSULE,
  CAPSULE_DROPPED,
  TURN_OFF_LED
} eState;
//-------------------------------------------------------------------------------------------
#endif /* _UTILITY_H_ */

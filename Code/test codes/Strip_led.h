/* Tested on:
 *  Board: Arduino MEGA 2650
 *  Registers emulation: ATMega 2650
 *  Arduino 1.8.12
 *
 *  Strip LED : WS2812b 
 *
 *	Author : Rosselli Jasmine
 */

#ifndef _HEADERFILE__STRIP_LED_H
#define _HEADERFILE__STRIP_LED_H

#include <Adafruit_NeoPixel.h>
#include "Arduino.h"

// Definition pins strip LED
#define STRIP_LED			11
// Definition number of LEDs
#define LED_NUMBER			15

// Definition of colored light intensity (between 0 and 250) 
#define COLOR_INTENSTITY	10

// Definition of wite light intensity (between 0 and 250) 
#define WITE_INTENSITY		100

// Definition of LEDs type
#define TYPE_LED 			(NEO_GRB + NEO_KHZ800)

// Colors definition
typedef enum {
	RED = 0,
	GREEN,
	BLUE,
	YELLOW,
	CYAN,
	VIOLET,
	WITE
} COLORS;

/* This function allows to controle one LED of the strip LED
 *
 * Input parameters:
 *  sate		state of LED (0 when light off, 1 when light on)
 *	led			LED to control
 *  max_leds	number of strips LED
 *  color		color of LED
 *
 *	Returns:
 *	0	-> wehn success
 *	-1	-> when error
 */
int one_led(bool state, int led, int max_leds, COLORS color);

/* This function allows to blink one LED of the strip LED for
 * a period time of T ms
 * Blocking function
 *
 * Input parameters:
 *	led			LED to control
 *  max_leds	number of strips LED
 *  color		color of LED
 *	T			time period [ms]
 *
 *	Returns:
 *	0	-> wehn success
 *	-1	-> when error
 */
int blink_one_led_blocking(int led, int max_leds, COLORS color, int T);

// todo
// not blocking function

// Pins initialization function
void init_strip_led();

#endif //_HEADERFILE__STRIP_LED_H

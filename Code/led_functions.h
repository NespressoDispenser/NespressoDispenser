#pragma once
#include <FastLED.h>
#include <Arduino.h>
#define LED_PIN     2   //Led strip data pin 
#define NUM_LEDS    52
#define INTERVALLE_LEDS 26  // Led X + intervalle = parallel leds
#define NB_LEDS_BACKLIGHT 18
const int TAB_BACKLIGHT[] = {0, 1, 2, 5, 6, 7, 8, 11, 12, 13, 14, 17, 18, 19, 20, 23, 24, 25}; //backlight leds
const int LED_CAP[][4] = {{3, 4, 47, 48}, {9, 10, 41, 42}, {15, 16, 35, 36}, {21, 22, 29, 30}}; //leds under capsule
//turn on backlight
void turn_on_light(CRGB* leds);
//turn off backlight
void turn_off_light(CRGB* leds);
//turn on backlight with specified color
void turn_on_color_light(CRGB* leds, CRGB led_color);
//turn on leds under chosen capsule (0-3) with chosen color
void leds_capsules(CRGB* leds, unsigned int capsule_number, CRGB led_color = CRGB::Black);

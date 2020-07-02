#pragma once
#include <FastLED.h>
#include <Arduino.h>
#define LED_PIN     2   //Pin Data du ruban led
#define NUM_LEDS    52 
#define INTERVALLE_LEDS 26  // Led X + intervalle = led parallèle
#define NB_LEDS_ECLAIRAGE 18
const int TAB_ECLAIRAGE[] = {0,1,2,5,6,7,8,11,12,13,14,17,18,19,20,23,24,25}; //leds en blanc
const int LED_CAP[][4] = {{3,4,47,48},{9,10,41,42},{15,16,35,36},{21,22,29,30}}; //leds sous capsules

//enclenche les leds d'éclairage en blanc
void turn_on_light(CRGB* leds);

//éteint les leds d'éclairage
void turn_off_light(CRGB* leds);

//enclenche les leds d'éclairage avec la couleur choisie
void turn_on_color_light(CRGB* leds, CRGB led_color);//couleur en param

//enclenche les leds sous la capsule et de la couleur souhaitée 
void leds_capsules(CRGB* leds, unsigned int capsule_number, CRGB led_color = CRGB::Black); //N° capsule en param (0-3) et couleur

 

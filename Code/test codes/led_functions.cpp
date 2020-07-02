
#include "led_functions.h"

void turn_on_light(CRGB* leds){
  unsigned int led_index;
  for(unsigned int i = 0; i<  NB_LEDS_ECLAIRAGE; i++){
    led_index = TAB_ECLAIRAGE[i];
    leds[led_index] = CRGB(80,80,80);//blanc attenué
    leds[led_index+ INTERVALLE_LEDS] = CRGB(80,80,80); 
  }
  FastLED.show();
}
void turn_off_light(CRGB* leds){
  unsigned int led_index;
  for(unsigned int i = 0; i<  NB_LEDS_ECLAIRAGE; i++){
    led_index = TAB_ECLAIRAGE[i];
    leds[led_index] = CRGB(0,0,0);
    leds[led_index+ INTERVALLE_LEDS] = CRGB(0,0,0);
  }
  FastLED.show();
}
void turn_on_color_light(CRGB* leds, CRGB led_color){//couleur en param
  unsigned int led_index;
  for(unsigned int i = 0; i<  NB_LEDS_ECLAIRAGE; i++){
    led_index = TAB_ECLAIRAGE[i];
    leds[led_index] = led_color;
    leds[led_index+ INTERVALLE_LEDS] = led_color;
  }
  FastLED.show();
}

void leds_capsules(CRGB* leds, unsigned int capsule_number, CRGB led_color = CRGB::Black){ //N° capsule en param (0-3) et couleur
  unsigned int led_index;
  for(unsigned int i = 0; i<4;i++){
    led_index = LED_CAP[capsule_number][i];
    leds[led_index] = led_color;
  }
    FastLED.show(); 
  }

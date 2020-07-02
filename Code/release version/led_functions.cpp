#include "led_functions.h"
void turn_on_light(CRGB* leds) {
  unsigned int led_index;
  for (unsigned int i = 0; i <  NB_LEDS_BACKLIGHT; i++) {
    led_index = TAB_BACKLIGHT[i];
    leds[led_index] = CRGB(80, 80, 80); //softened white
    leds[led_index + INTERVALLE_LEDS] = CRGB(80, 80, 80);
  }
  FastLED.show();
}
void turn_off_light(CRGB* leds) {
  unsigned int led_index;
  for (unsigned int i = 0; i <  NB_LEDS_BACKLIGHT; i++) {
    led_index = TAB_BACKLIGHT[i];
    leds[led_index] = CRGB::Black;
    leds[led_index + INTERVALLE_LEDS] = CRGB::Black;
  }
  FastLED.show();
}
void turn_on_color_light(CRGB* leds, CRGB led_color) {
  unsigned int led_index;
  for (unsigned int i = 0; i <  NB_LEDS_BACKLIGHT; i++) {
    led_index = TAB_BACKLIGHT[i];
    leds[led_index] = led_color;
    leds[led_index + INTERVALLE_LEDS] = led_color;
  }
  FastLED.show();
}

void leds_capsules(CRGB* leds, unsigned int capsule_number, CRGB led_color = CRGB::Black) {
  unsigned int led_index;
  for (unsigned int i = 0; i < 4; i++) { //4 leds under each coffee capsule
    led_index = LED_CAP[capsule_number][i];
    leds[led_index] = led_color;
  }
  FastLED.show();
}

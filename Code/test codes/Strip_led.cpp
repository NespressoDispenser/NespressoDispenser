#include "Strip_led.h"

Adafruit_NeoPixel pixels(LED_NUMBER, STRIP_LED, TYPE_LED);

int one_led(bool state, int led, int max_leds, COLORS color){
	if(led > (max_leds-1) || COLOR_INTENSTITY > 250 || WITE_INTENSITY > 250){
		return -1;
	}

	if(state == 0){
		pixels.setPixelColor(led, pixels.Color(0, 0, 0));
	} else {
		switch(color){
			case RED:
				pixels.setPixelColor(led, pixels.Color(COLOR_INTENSTITY, 0, 0));
			break;
			case GREEN:
				pixels.setPixelColor(led, pixels.Color(0, COLOR_INTENSTITY, 0));
			break;
			case BLUE:
				pixels.setPixelColor(led, pixels.Color(0, 0, COLOR_INTENSTITY));
			break;
			case YELLOW:
				pixels.setPixelColor(led, pixels.Color(COLOR_INTENSTITY, COLOR_INTENSTITY, 0));
			break;
			case CYAN:
				pixels.setPixelColor(led, pixels.Color(0, COLOR_INTENSTITY, COLOR_INTENSTITY));
			break;
			case VIOLET:
				pixels.setPixelColor(led, pixels.Color(COLOR_INTENSTITY, 0, COLOR_INTENSTITY));
			break;
			case WITE:
				pixels.setPixelColor(led, pixels.Color(WITE_INTENSITY, WITE_INTENSITY, WITE_INTENSITY));
			break;
			default:
				return -1;
			break;	
		}
	}
  pixels.show();
	return 0;
}

int blink_one_led_blocking(int led, int max_leds, COLORS color, int T){
	int error = 0;

	error = one_led(1,led,max_leds,color);

	if(error != 0){
		return -1;
	}

	delay(T);

	error = one_led(0,led,max_leds,color);

	if(error != 0){
		return -1;
	}

	delay(T);
	return 0;
}

void init_strip_led(){
	pixels.begin();
	pixels.clear();
}
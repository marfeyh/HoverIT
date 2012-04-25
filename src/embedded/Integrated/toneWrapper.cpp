#include <Arduino.h>
#include <searduino.h>
#include "toneWrapper.h"

void my_tone(uint8_t pin, uint8_t frequency) {
	tone(pin,frequency);
}

void my_noTone(uint8_t pin) {
	noTone(pin);
}
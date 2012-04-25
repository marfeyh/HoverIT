#include <Arduino.h>
#include <searduino.h>
#include "toneWrapper.h"

void my_tone(int pin, int frequency) {
	tone(pin,frequency);
}

void my_noTone(int pin) {
	noTone(pin);
}
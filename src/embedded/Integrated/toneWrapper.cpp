#include <Arduino.h>
#include <searduino.h>
#include "toneWrapper.h"

void my_tone(int pin, int frequency) {
	//tone(pin,frequency);
    /* for searduino test*/
    digitalWrite(pin, HIGH);
}

void my_noTone(int pin) {
    //noTone(pin);
    /* for searduino test*/
    digitalWrite(pin, LOW);
}
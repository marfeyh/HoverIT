 /*!
 @file toneWrapper.cpp
 @headerfile toneWrapper.h
 @headerfile Arduino.h 
 @headerfile searduino.h
 @headerfile Tone.h
 @details The Wrapper functuion is use tone and noTone can use in c environment
 @author Neda MOhammadian
 @author Mahsa MIrtalebi
 @Date   18 april 2012
 @version 1
 */
 
 
#include <Arduino.h>
#include <searduino.h>
#include <toneWrapper.h>

void my_tone(int pin, int frequency) {
	tone(pin,frequency,2);
}

void my_noTone(int pin) {
	noTone(pin);
}


#ifdef SEARDUINO_STUB

void tone(uint8_t _pin, unsigned int frequency, unsigned long duration) {

	printf("Tone on pin %d, freq: %u\n", _pin, frequency);	
}
void noTone(uint8_t _pin) {
	printf("No tone on pin %d\n", _pin);
}



#endif
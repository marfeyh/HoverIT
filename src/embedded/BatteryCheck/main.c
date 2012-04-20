/*
 ============================================================================
 Name        : batteryLevel.c
 Author      : Kuhan Loh, Aran Gerami, Denir Leric
 Version     : v 0.1
 Copyright   : Your copyright notice
 Description : Battery Check in C
 ============================================================================
 */


#include <Arduino.h>
#include <searduino.h>
#include <pins_arduino.h>
#include <batteryLevel.h>

void setup(){
	pinMode(LED_PIN, OUTPUT);
}

int main(void) {

	init();
	setup();
	for(;;){
		batteryLevel:check();
	}
	return 0;
}

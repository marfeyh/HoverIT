/*
 ============================================================================
 Name        : main.c
 Author      : Kuhan Loh, Aran Gerami, Denir Leric
 Version     : v 0.2
 Copyright   : Copyright (C) 2011, 2012 Denir Leric
 Description : Battery Check in C
 ============================================================================
 */


#include <Arduino.h>
#include <searduino.h>
#include "batteryLevel.h"

void setup(){
	pinMode(13, OUTPUT);
}

uint8_t main(void) {

	init();
	setup();
	for(;;)
	{
		check(13);
	}
}

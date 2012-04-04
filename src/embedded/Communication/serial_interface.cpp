/*
 * serial_input.cpp
 * Following code is saved as c++ extension because it has to be compiled by c++ compiler since
 * it is using serial libraries of searduino
 *  Created on: Apr 03, 2012
 */
#include <stdio.h>
#include <Arduino.h>
#include <searduino.h>
#include <HardwareSerial.h>



/**
 * API function which is called by scheduler
 * Basically when this function is called the bluetooth gets the resources of CPU and
 * it should check if there is anything sent to the bluetooth
 */
unsigned char serial_read() {
	printf("Module serial_interface.cpp: function serial_read is working...\n");

	// check serial input if there is anything available
	if (Serial.available()){
		return Serial1.read();
		//		putjobInque(findMessage(data));
	}
	return 255;
}

/**
 *
 */
unsigned char* serial_binary_write(unsigned char* binary) {
	printf("Module serial_interface.cpp: function serial_binary_write is working...\n");
	Serial.write(*binary);
	unsigned char temp= 255;
	return &temp;
}


/**
 *
 */
unsigned char* serial_string_write(char* string) {
	printf("Module serial_interface.cpp: function serial_string_write is working...\n");
	for ( ;string != '\o'; string++ ){
		Serial.print(*string);
	}
	unsigned char temp= 255;
	return &temp;
}

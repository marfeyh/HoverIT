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
#include <serial_interface.h>

/**
 * API function which is called by scheduler
 * Basically when this function is called the bluetooth gets the resources of CPU and
 * it should check if there is anything sent to the bluetooth
 */
unsigned char serial_read() {
	//	printf("Module serial_interface.cpp: function serial_read is working...\n");

	// Check serial input if there is anything available
	if (Serial1.available() > 0) {
		unsigned char input = Serial1.read();
		debug_print(&input);
		return input;
		//		putjobInque(findMessage(data));
	}
	return 255;
}

/**
 *
 */
void serial_binary_write(unsigned char* binary) {
	//	printf("Module serial_interface.cpp: function serial_binary_write is working...\n");
	Serial1.write(*binary);
}

/**
 *
 */
void serial_string_write(char* string) {
	//	printf("Module serial_interface.cpp: function serial_string_write is working...\n");
	for (; string != '\0'; string++) {
		Serial1.print(*string);
	}
}

void serial_setup(void) {
	Serial.begin(9600);
	Serial1.begin(9600);
}

void debug_print(unsigned char* character) {
	Serial.print(*character, HEX);
}

void debug_write(unsigned char* character) {
	Serial.write(*character);
}

void debug_print_string(char* character) {
	for (; *character != '\0'; character++) {
		Serial.print(*character);
	}
	Serial.print("\n");
}

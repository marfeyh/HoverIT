/*
 * bluetooth_command.c
 * In this module, the bluetooth gets the
 *
 *  Created on: Apr 03, 2012
 */

#include "serial_interface.cpp"
#include "API_bluetooth_controler.h"
#include "conventions.h"

/*
 * ===========================================================
 * API functions
 * ===========================================================
 */

void check_serial_input() {
	// check the serial input if there is anything input on the serial pin
	unsigned char result =0;
	do {
		printf(
				"Module bluetooth_controler.c, function check_serial_input: serial input is checked...\n");
		result = serial_read();
		switch (*parseBinary(&result)) {
			case 0:
				printf("put Fan Forward Speed in queue\n");
				break;
			case 1:
				printf("put Fan Hover Speed in queue\n");
				break;
			case 2:
				printf("put Ruder Direction in queue\n");
				break;
			}
	} while (result!= 255);
	printf(
			"Module bluetooth_controler.c, function check_serial_input: serial input no more input...\n");
	return;
}

/**
 * API function to create fan forward speed message
 * message argument is followed by hovercraft protocol available on wiki
 */
unsigned char fan_forward_speed(unsigned char message) {
	printf("Module bluetooth_controler, function fan_forward_speed: working\n");
	return create_fan_forward_speed(&message);
}

/**
 * API function to create fan hovering speed message
 * message argument is followed by hovercraft protocol available on wiki
 */
unsigned char fan_hovering_speed(unsigned char message) {
	printf("Module bluetooth_controler, function fan_hovering_speed: working\n");
	return create_fan_hovering_speed(&message);
}

/**
 * API function to create ruder direction message
 * message argument is followed by hovercraft protocol available on wiki
 */
unsigned char ruder_direction(unsigned char message) {
	printf("Module bluetooth_controler, function ruder_direction: working\n");
	return create_ruder_direction(&message);
}

/**
 * API function to create hovercraft speed (measured by sensor) message
 * message argument is followed by hovercraft protocol available on wiki
 */
unsigned char hovercraft_speed(unsigned char message) {
	printf("Module bluetooth_controler, function hovercraft_speed: working\n");
	return create_hovercraft_speed(&message);
}

/**
 * API function to create hovercraft pressure (measured by sensor) message
 * message argument is followed by hovercraft protocol available on wiki
 */
unsigned char hovercraft_pressure(unsigned char message) {
	printf("Module bluetooth_controler, function hovercraft_pressure: working\n");
	return create_hovercraft_pressure(&message);
}

/**
 * API function to create hovercraft battery level (measured by sensor) message
 * message argument is followed by hovercraft protocol available on wiki
 */
unsigned char battery_level(unsigned char message) {
	printf("Module bluetooth_controler, function battery_level: working\n");
	return create_battery_level(&message);
}

/*
 * ===========================================================
 * Internal  functions
 * ===========================================================
 */

unsigned char send_serial_string(char* string) {
	if (serial_string_write(string) == 255) {
		printf(
				"Module bluetooth_controler.c, function send_serial_string: error from serial_interface module\n");
		return 255;
	}
	printf(
			"Module bluetooth_controler.c, function send_serial_string: string message is sent to serial_interface module\n");
	return 0;
}

unsigned char send_serial_binary(unsigned char* binary) {
	if (serial_binary_write(binary) == 255) {
		printf(
				"Module bluetooth_controler.c, function send_serial_binary: error from serial_interface module\n");
	}
	printf(
			"Module bluetooth_controler.c, function send_serial_binary: binary message is sent to serial_interface module\n");
	return 0;
}


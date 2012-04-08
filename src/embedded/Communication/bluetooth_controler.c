/*
 * bluetooth_command.c
 * In this module, the bluetooth gets the
 *
 *  Created on: Apr 03, 2012
 */

#include <serial_interface.h>
#include <API_bluetooth_controler.h>
#include <bluetooth_controler.h>
#include <conventions.h>

/*
 * ===========================================================
 * API functions
 * ===========================================================
 */

/**
 * A function to check the serial pins.
 * If there is any data available then the data would be parsed.
 */
void check_serial_input() {
	unsigned char result = 255;
	do {
		//		debug_print_string("check_serial_input");
		//		printf(
		//				"Module bluetooth_controler.c, function check_serial_input: serial input is checked...\n");
		result = serial_read();
		//		debug_println(result);
		if (result != 255) {
			unsigned char messageType = parseBinary(result);
			if (messageType != 255) {
				//			debug_println(temp);
				switch (messageType) {
				case FAN_FORWARD_SPEED:
					if (is_increase(&result) == 1) {
						switch (getValue_fan_speed(&result)) {
						case 0:
							// int increase_hover();
							debug_print_string(
									"put Fan Forward increasing Speed in queue\n");
							break;
						case 1:
							// int decrease_hover();
							debug_print_string(
									"put Fan Forward decreasing Speed in queue\n");
							break;
						default:
							debug_print_string("put Fan Forward Speed ERROR\n");
							break;
						}
					} else {
//						is_increase(&result) == 0
						debug_print_string("put exact speed value\n");
					}
					break;
				case RUDER_DIRECTION: {
					switch (get_direction(&result)) {
					case HARD_LEFT:
						debug_print_string("put go_right in queue\n");
						break;
					case 5:
						debug_print_string("put go_left in queue\n");
						break;
					default:
						debug_print_string("direction ERROR\n");
						break;
					}
				}
					break;
				case FAN_HOVERING_SPEED:
					debug_print_string("put Fan_Hovering_Speed in queue\n");
					break;
				}
			}
		}
	} while (result != 255);
//	printf(
//			"Module bluetooth_controler.c, function check_serial_input: serial input no more input...\n");
	return;
}

/**
 * API function to create fan forward speed message
 * message argument is followed by hovercraft protocol available on wiki
 */
unsigned char fan_forward_speed(unsigned char message) {
//	printf("Module bluetooth_controler, function fan_forward_speed: working\n");
	debug_print_string("fan_forward_speed called\n");

	// instead of return send_serial_binary should be called
	return create_fan_forward_speed(&message);
}

/**
 * API function to create fan hovering speed message
 * message argument is followed by hovercraft protocol available on wiki
 */
unsigned char fan_hovering_speed(unsigned char message) {
//	printf(
//			"Module bluetooth_controler, function fan_hovering_speed: working\n");
	debug_print_string("fan_hovering_speed called\n");

	// instead of return send_serial_binary should be called
	return create_fan_hovering_speed(&message);
}

/**
 * API function to create ruder direction message
 * message argument is followed by hovercraft protocol available on wiki
 */
unsigned char ruder_direction(unsigned char message) {
//	printf("Module bluetooth_controler, function ruder_direction: working\n");
	debug_print_string("ruder_direction called\n");

	// instead of return send_serial_binary should be called
	return create_ruder_direction(&message);
}

/**
 * API function to create hovercraft speed (measured by sensor) message
 * message argument is followed by hovercraft protocol available on wiki
 */
unsigned char hovercraft_speed(unsigned char message) {
//	printf("Module bluetooth_controler, function hovercraft_speed: working\n");
	debug_print_string("hovercraft_speed called\n");

	// instead of return send_serial_binary should be called
	return create_hovercraft_speed(&message);
}

/**
 * API function to create hovercraft pressure (measured by sensor) message
 * message argument is followed by hovercraft protocol available on wiki
 */
unsigned char hovercraft_pressure(unsigned char message) {
//	printf(
//			"Module bluetooth_controler, function hovercraft_pressure: working\n");
	debug_print_string("hovercraft_pressure called\n");


	// instead of return send_serial_binary should be called
	return create_hovercraft_pressure(&message);
}

/**
 * API function to create hovercraft battery level (measured by sensor) message
 * message argument is followed by hovercraft protocol available on wiki
 */
unsigned char battery_level(unsigned char message) {
//	printf("Module bluetooth_controler, function battery_level: working\n");
	debug_print_string("battery_level called\n");

	// instead of return send_serial_binary should be called
	return create_battery_level(&message);
}

/*
 * ===========================================================
 * Internal  functions
 * ===========================================================
 */

void send_serial_string(char* string) {
	serial_string_write(string);
//	printf(
//			"Module bluetooth_controler.c, function send_serial_string: string message is sent to serial_interface module\n");
}

void send_serial_binary(unsigned char* binary) {
	serial_binary_write(binary);
//	printf(
//			"Module bluetooth_controler.c, function send_serial_binary: binary message is sent to serial_interface module\n");
}


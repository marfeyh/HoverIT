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
#include <stdio.h> // because of using NULL
//Scheduler
#include <job.h>
#include <jobpriority.h>
#include <jobtype.h>
#include<hover_api_stub.h>


// Motor
#include <propulsion_api.h>

//Rudder direction
#include <steering.h>

/*
 * ===========================================================
 * API functions
 * ===========================================================
 */

void bluetooth_serial_setup() {
	serial_setup();

}

/**
 * A function to check the serial pins.
 * If there is any data available then the data would be parsed.
 */
void check_serial_input() {
	unsigned char result = 255;
	do {
		result = serial_read();
		// If there is any data available on serial input
		if (result != 255) {
			unsigned char messageType = parseBinary(result);
			if (messageType != 255) {
				//It should be free somewhere!
				int (*func_ptr)(); // declaration of pointer to function
				struct Job* job_ptr = (struct Job*) malloc(
						sizeof(struct Job) * 1);
				if (job_ptr == NULL) {
					debug_print_string("Unable to get memory\n");
					return;
				}
				// call the api functions based on message type
				switch (messageType) {
				case FAN_FORWARD_SPEED:
					if (is_increase(&result) == 1) {
						unsigned char res_value = getValue_fans(&result);
						switch (res_value) {
						case 0:
							func_ptr = increase_propulsion;
							job_ptr->task_p2 = func_ptr;
							job_ptr->job_num = 1;
							job_ptr->prio = RIGHT_NOW;
							job_ptr->type = MOVEMENT;
							putJobInQueue(*job_ptr);
							debug_print_string(
									"put Fan Forward increasing Speed in queue\n");
							break;
						case 1:
							func_ptr = decrease_propulsion; //blink; //increase_hover; // int increase_hover();
							job_ptr->task_p2 = func_ptr;
							job_ptr->job_num = 1;
							job_ptr->prio = RIGHT_NOW;
							job_ptr->type = MOVEMENT;
							putJobInQueue(*job_ptr);
							debug_print_string(
									"put Fan Forward decreasing Speed in queue\n");
							break;
						default:
							debug_print_string("put Fan Forward Speed ERROR\n");
							break;
						}
					} else {
						debug_print_string("put exact Forward speed value\n");
					}
					break;
				case FAN_HOVERING_SPEED:
					if (is_increase(&result) == 1) {
						unsigned char res_value = getValue_fans(&result);
						switch (res_value) {
						case 0:
							func_ptr = increase_hover;
							job_ptr->task_p2 = func_ptr;
							job_ptr->job_num = 1;
							job_ptr->prio = RIGHT_NOW;
							job_ptr->type = MOVEMENT;
							putJobInQueue(*job_ptr);
							debug_print_string(
									"put Fan Hovering increasing \n");
							break;
						case 1:
							func_ptr = decrease_hover;
							job_ptr->task_p2 = func_ptr;
							job_ptr->job_num = 1;
							job_ptr->prio = RIGHT_NOW;
							job_ptr->type = MOVEMENT;
							putJobInQueue(*job_ptr);
							debug_print_string("put Fan Hovering decreasing\n");
							break;
						default:
							debug_print_string(
									"put Fan Hovering Speed ERROR\n");
							break;
						}
					} else {
						//						control_rudder(0); // hard left
						debug_print_string("put exact FAN_HOVERING_SPEED \n");
					}
					break;
				case RUDER_DIRECTION: {
					unsigned char res_direction = get_direction(&result);
					switch (res_direction) {
					case STRAIGHT:
						control_rudder(STRAIGHT);
						debug_print_string("STRAIGHT\n");
						break;
					case HARD_LEFT:
						control_rudder(HARD_LEFT);
						debug_print_string("HARD_LEFT\n");
						break;
					case HARD_RIGHT:
						control_rudder(HARD_RIGHT);
						debug_print_string("HARD_RIGHT\n");
						break;
					case SOFT_RIGHT:
						control_rudder(SOFT_RIGHT);
						debug_print_string("SOFT_RIGHT\n");
						break;
					case SOFT_LEFT:
						control_rudder(SOFT_LEFT);
						debug_print_string("SOFT_LEFT\n");
						break;
					case BRAKE:
						control_rudder(BRAKE);
						debug_print_string("BRAKE\n");
						break;
					default:
						debug_print_string("direction ERROR\n");
						break;
					}
					break;
				}
				}
			}
		}
	} while (result != 255);
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


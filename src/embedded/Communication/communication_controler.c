/*!
 @file communication_controler.c
 @headerfile API_communication_controler.h
 @headerfile communication_controler.h
 @details This module is the brain of the bluetooth which controls it's functionalities
 @author Amir Almasi
 @author Retta Shiferaw
 @version 0.7
 @note All the aruguments and returns of the functions are unsigned char
 @bug pointer to function should be free somewhere
 @todo pointer to job struct should be get free
 */

#include <serial_interface.h>
#include <API_communication_controler.h>
#include <communication_controler.h>
#include <conventions.h>
#include <stdio.h> // because of using NULL
#include <external.h>

/*
 * ======================================================================
 * API functions
 * ======================================================================
 */

/*!
 @brief Initializing bluetooth serial pins on Arduino
 */
void bluetooth_serial_setup() {
	serial_setup();
}

/*!
 @brief When this function is called, by Scheduler, the bluetooth gets the resources of
 the board and it should check if there is anything available on serial input or not
 If there is any data available then the data would be parsed.
 */
void check_serial_input() {
	// result variable shows the available data on serial pin.
	unsigned char result = 255;
	do {
		result = serial_read();
		if (result != 255) { // If there is any data available on serial input
			// variable message_type shows the message received
			unsigned char message_type = parse_binary(result);
			if (message_type != 255) {
				int (*func_ptr)(); // declaration of pointer to function
				struct Job* job_ptr = (struct Job*) malloc(
						sizeof(struct Job) * 1); // declaration of pointer to job struct
				if (job_ptr == NULL) {
					debug_print_string("Unable to get memory\n");
					// we should call log_error in here
					return;
				} // if there was no memory to be allocated
				switch (message_type) { // call the API functions based on message type
				case FAN_FORWARD_SPEED:
					/* message type is 0000 */
					if (1 == increase_decrease(&result)) { // first bit is 1 then either increasing or decreasing
						unsigned char res_value = get_value_fans(&result); // check the last bits
						switch (res_value) {
						case INCREASING:
							/* value was 00001000 */
							/**
							 func_ptr = increase_propulsion;
							 job_ptr->task_p2 = func_ptr;
							 job_ptr->job_num = 1;
							 job_ptr->prio = PRIO_HIGH;
							 job_ptr->type = MOVEMENT;
							 putJobInQueue(*job_ptr);
							 */
							send_information("amir almasi");
							debug_print_string(
									"put Fan Forward increasing Speed in queue\n");
							break;
						case DECREASING:
							/* value was 00001001 */
							/**
							 func_ptr = decrease_propulsion;
							 job_ptr->task_p2 = func_ptr;
							 job_ptr->job_num = 1;
							 job_ptr->prio = PRIO_HIGH;
							 job_ptr->type = MOVEMENT;
							 putJobInQueue(*job_ptr);
							 */
							debug_print_string(
									"put Fan Forward decreasing Speed in queue\n");
							break;
						default:
							debug_print_string("put Fan Forward Speed ERROR\n");
							break;
						}
					} // first bit is 1 then either increasing or decreasing
					else {
						unsigned char res_value = get_value_fans(&result); // check the last bits
						switch (res_value) {
						case STOP:
							/* value was 00000000 */
							// Call the stop api function of fan forward
							debug_print_string(
									"put Fan Forward STOP in queue\n");
							break;
						case TURBO:
							/* value was 00000111 */
							// Call the turbo api function of fan forward
							debug_print_string(
									"put Fan Forward TURBO in queue\n");
							break;
						default:
							debug_print_string(
									"Fan Forward not implemented commands ERROR\n");
							break;
						}
						debug_print_string("put exact Forward speed value\n");
					} // The message was exact fan forwarding speed value
					break;
				case FAN_HOVERING_SPEED:
					/* message type is 0001 */
					if (increase_decrease(&result) == 1) { // first bit is 1 then either increasing or decreasing
						unsigned char res_value = get_value_fans(&result); // check the last bits
						switch (res_value) {
						case INCREASING:
							/* value was 00011000 */
							/**
							 func_ptr = increase_hover_auto;
							 job_ptr->task_p2 = func_ptr;
							 job_ptr->job_num = 1;
							 job_ptr->prio = PRIO_HIGH;
							 job_ptr->type = MOVEMENT;
							 putJobInQueue(*job_ptr);
							 */
							debug_print_string(
									"put Fan Hovering increasing \n");
							break;
						case DECREASING:
							/* value was 00011001 */
							/**
							 func_ptr = decrease_hover_auto;
							 job_ptr->task_p2 = func_ptr;
							 job_ptr->job_num = 1;
							 job_ptr->prio = PRIO_HIGH;
							 job_ptr->type = MOVEMENT;
							 putJobInQueue(*job_ptr);
							 */
							debug_print_string("put Fan Hovering decreasing\n");
							break;
						default:
							debug_print_string(
									"put Fan Hovering Speed ERROR\n");
							break;
						} // first bit is 1 then either increasing or decreasing
					} else {
						unsigned char res_value = get_value_fans(&result); // check the last bits
						switch (res_value) {
						case STOP:
							/* value was 00010000 */
							// Call the stop api function of hovering
							debug_print_string(
									"put Fan Hovering STOP in queue\n");
							break;
						case TURBO:
							/* value was 00010111 */
							// Call the turbo api function of hovering
							debug_print_string(
									"put Fan Hovering TURBO in queue\n");
							break;
						default:
							debug_print_string(
									"Fan Hovering not implemented commands ERROR\n");
							break;
						}
						debug_print_string("put exact FAN_HOVERING_SPEED \n");
					} // The message was exact fan hovering speed value
					break;
				case RUDER_DIRECTION: {
					/* message type is 0010 */
					unsigned char res_direction = get_direction(&result); // To get the direction
					switch (res_direction) {
					case STRAIGHT:
						/* value is 0000 */
//						 control_rudder(STRAIGHT);
						debug_print_string("STRAIGHT\n");
						break;
					case HARD_LEFT:
						/* value is 0001 */
//						 control_rudder(HARD_LEFT);
						debug_print_string("HARD_LEFT\n");
						break;
					case HARD_RIGHT:
						/* value is 0010 */
//						 control_rudder(HARD_RIGHT);
						debug_print_string("HARD_RIGHT\n");
						break;
					case SOFT_RIGHT:
						/* value is 0011 */
//						 control_rudder(SOFT_RIGHT);
						debug_print_string("SOFT_RIGHT\n");
						break;
					case SOFT_LEFT:
						/* value is 0100 */
//						 control_rudder(SOFT_LEFT);
						debug_print_string("SOFT_LEFT\n");
						break;
					case BRAKE:
						/* value is 0101 */
//						 control_rudder(BRAKE);
						debug_print_string("BRAKE\n");
						break;
					default:
						debug_print_string("direction ERROR\n");
						break;
					} // end of switch case of rudder direction value
					break;
				} // end of switch case of rudder direction message type
				} //  end of the switch case of message type
			} // end of if message received is based on protocol
		} // end of if there is any data available on serial input
	} while (255 != result);
	return;
}

/*!
 @brief The function creates fan forward speed message.
 message argument is followed by hovercraft protocol available on wiki
 @see http://hoveritu.com/projects/semb2012/wiki
 @param unsigned char of the value to be sent to pc
 @return unsigned char containing value and message type
 */
unsigned char fan_forward_speed(unsigned char message) {
	debug_print_string("fan_forward_speed called\n");

	// instead of return send_serial_binary should be called
	return create_fan_forward_speed(&message);
}

/*!
 @brief The function creates fan hovering speed message.
 message argument is followed by hovercraft protocol available on wiki
 @see http://hoveritu.com/projects/semb2012/wiki
 @param unsigned char of the value to be sent to pc
 @return unsigned char containing value and message type
 */
unsigned char fan_hovering_speed(unsigned char message) {
	debug_print_string("fan_hovering_speed called\n");

	// instead of return send_serial_binary should be called
	return create_fan_hovering_speed(&message);
}

/*!
 @brief The function creates ruder direction message.
 message argument is followed by hovercraft protocol available on wiki
 @see http://hoveritu.com/projects/semb2012/wiki
 @param unsigned char of the value to be sent to pc
 @return unsigned char containing value and message type
 */
unsigned char ruder_direction(unsigned char message) {
	debug_print_string("ruder_direction called\n");

	// instead of return send_serial_binary should be called
	return create_ruder_direction(&message);
}

/*!
 @brief The function creates hovercraft speed (measured by sensor) message.
 message argument is followed by hovercraft protocol available on wiki
 @see http://hoveritu.com/projects/semb2012/wiki
 @param unsigned char of the value to be sent to pc
 @return unsigned char containing value and message type
 */
unsigned char hovercraft_speed(unsigned char message) {
	debug_print_string("hovercraft_speed called\n");

	// instead of return send_serial_binary should be called
	return create_hovercraft_speed(&message);
}

/*!
 @brief The function creates hovercraft pressure (measured by sensor) message.
 message argument is followed by hovercraft protocol available on wiki
 @see http://hoveritu.com/projects/semb2012/wiki
 @param unsigned char of the value to be sent to pc
 @return unsigned char containing value and message type
 */
unsigned char hovercraft_pressure(unsigned char message) {
	debug_print_string("hovercraft_pressure called\n");

	// instead of return send_serial_binary should be called
	return create_hovercraft_pressure(&message);
}

/*!
 @brief The function creates hovercraft battery level message.
 message argument is followed by hovercraft protocol available on wiki
 @see http://hoveritu.com/projects/semb2012/wiki
 @param unsigned char of the value to be sent to pc
 @return unsigned char containing value and message type
 */
unsigned char battery_level(unsigned char message) {
	debug_print_string("battery_level called\n");

	// instead of return send_serial_binary should be called
	return create_battery_level(&message);
}

unsigned char send_information (char* information){
	stream_data(information);
	return 0;
}

/*
 * ===========================================================
 * Internal  functions
 * ===========================================================
 */

/*!
 @brief The function sends string to the serial to show on monitoring on arduino
 @param pointer to char of the string
 */
void send_serial_string(char* string) {
	serial_string_write(string);
}

/*!
 @brief The function sends unsigned char which is binary to the serial to show on monitoring on arduino
 @param pointer to char of the string
 */
void send_serial_binary(unsigned char* binary) {
	serial_binary_write(binary);
}

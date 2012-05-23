/*
 This file is part of Hoverit.

 Hoverit is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 Hoverit is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with Hoverit.  If not, see <http://www.gnu.org/licenses/>.
 */

/*!
 @file communication_controler.c
 @headerfile API_communication_controler.h
 @headerfile communication_controler.h
 @details This module is the controller of the bluetooth.
 @author Amir Almasi
 @author Retta Shiferaw
 @version 0.9
 @warning <b> Do not try this code at home! </b>
 */

#include "serial_interface.h"
#include "API_communication_controler.h"
#include "communication_controler.h"
#include "conventions.h"
#include <stdio.h> // because of using NULL
#include "external.h"
#include "job.h"
#include "jobpriority.h"
#include "jobtype.h"

//struct authentication* login = NULL;
/*
 * ======================================================================
 * API functions
 * ======================================================================
 */

/*!
 @brief The function checks the bluetooth connection.
 @return unsigned char 1 if there is connection on bluetooth, 0 if there is no connection
 */
unsigned char connection_status() {
	// For checking the connection status
	return check_connection();
}

/*!
 @brief Initializing bluetooth serial pins on Arduino
 */
void communication_serial_setup() {
	serial_setup();
	serial_switch(); // This setting was in earlier architecture.
}

/*!
 @brief When this function is called, by Scheduler, the bluetooth gets the resources of
 the board and it should check if there is anything available on serial input or not
 If there is any data available then the data would be parsed.
 */
void check_serial_input() {
//	stream_information("Amir");
//	debug_write(&temp);
	unsigned char result = 255;
	do {
		loop_GSM(); // checking GSM
		check_bluetooth(&result);
//		if (254 == result) { // If there is any data available on serial input
//			check_wifi(&result);
//			debug_print_string("fun1");
//		}
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
	debug_print_string("fan_forward_speed called");

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
	debug_print_string("fan_hovering_speed called");

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
	debug_print_string("ruder_direction called");

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
unsigned char hovercraft_speed(int message) {
	if (1 == connection_status()) {
		unsigned char tag = 0b00111110;
		send_serial_binary(&tag); // start streaming and send the starting tag
		send_serial_binary_speed(&message);
		tag = 0b00111111;
		send_serial_binary(&tag);
	}
//	debug_print3(message);
//	debug_print_string("hovercraft_speed called");

	// instead of return send_serial_binary should be called
//	return create_hovercraft_speed(&message);
	return 255;
}

/*!
 @brief The function creates hovercraft pressure (measured by sensor) message.
 message argument is followed by hovercraft protocol available on wiki
 @see http://hoveritu.com/projects/semb2012/wiki
 @param unsigned char of the value to be sent to pc
 @return unsigned char containing value and message type
 */
unsigned char hovercraft_pressure(unsigned int message) {
	debug_print2(&message);
	debug_print_string("R");
//	debug_write(message);

// instead of return send_serial_binary should be called
	return create_hovercraft_pressure(&message);
}

/*!
 @brief The function creates hovercraft battery level message.
 message argument is followed by hovercraft protocol available on wiki
 @see http://hoveritu.com/projects/semb2012/wiki
 @param unsigned char of the battery number
 @param unsigned char of the value to be sent to pc
 @return unsigned char containing value and message type
 */
unsigned char battery_level(unsigned char battery_num, unsigned char message) {
	if (1 == connection_status()) {
//	debug_print(&message);
//	debug_print_string("battery_level1 called");
		unsigned char binary_message = create_battery_level(&battery_num,
				&message);
		send_serial_binary(&binary_message);
	}
//	debug_print(&message);
	//	debug_print_string("battery_level1 called");
	// instead of return send_serial_binary should be called
	return create_battery_level(&battery_num, &message);
}

/*!
 @brief A function to send stream of information to serial pin by sending character by character.
 @param pointer to first char of the stream string to be sent
 @return unsigned char 1 if the function was called
 */
unsigned char stream_information(char* information) {
	unsigned char tag = 0b01111110;
	send_serial_binary(&tag); // start streaming and send the starting tag
	send_serial_string(information); // send the actual message
	tag = 0b01111110;
	send_serial_binary(&tag); // send the finishing tag
	return 1;
}


/*!
 @brief A function to parse the data received
 @param pointer to unsigned char of serial read data
 @return unsigned char of result of  serial read
 */
unsigned char parse_input(unsigned char* result) {
	// variable message_type shows the message received
	unsigned char message_type = parse_binary(result);
	if (message_type != 255) {
		switch (message_type) { // call the API functions based on message type
		case FAN_FORWARD_SPEED:
			/* message type is 0000 */
			fan_forward_speed_handler(result);
			return FAN_FORWARD_SPEED;
			break;
		case FAN_HOVERING_SPEED:
			/* message type is 0001 */
			fan_hovering_speed_handler(result);
			return FAN_HOVERING_SPEED;
			break;
		case RUDER_DIRECTION:
			/* message type is 0010 */
			ruder_direction_handler(result);
			return RUDER_DIRECTION;
			break;
		case BACKWARD:
			/* message type is 0010 */
			backward_handler();
			return BACKWARD;
			break;
		case HOVERCRAFTOFF:
			/* message type is 0010 */
			off_handler(result);
			return HOVERCRAFTOFF;
			break;
		default:
			/* If something is not based on protocol */
			debug_print_string("Something not based on protocol is received");
			break;
		} //  end of the switch case of message type
		return 255;
	} // end of if message received is based on protocol
	return 255;
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
 @brief The function sends unsigned char
 @param pointer to char of the string
 */
void send_serial_binary(unsigned char* binary) {
	serial_binary_write(binary);
}

/*!
 @brief The function sends int which is hovercraft speed
 @param pointer to int hovercraft speed
 */
void send_serial_binary_speed(int* binary) {
	serial_binary_write_speed(binary);
}

/*!
 @brief A function to check bluetooth input if there is any or not
 @param unsigned char of serial read data
 @return unsigned char of result of  serial read
 255 there was no data available for bluetooth, 254 there is no connection for bluetooth
 */
unsigned char check_bluetooth(unsigned char* result) {
	*result = serial_read();
	if (254 > (*result)) {
		parse_input(result);
	}
	return *result;
}

/*!
 @brief A function to check wifi input if there is any or not
 @param unsigned char of serial read data
 @return unsigned char of result of  serial read
 255 there was no data available for wifi, 254 there is no connection for wifi
 */
unsigned char check_wifi(unsigned char* result) {
	*result = wifi_read();
	if (255 != *result) {
		parse_input(result);
	}
	return *result;
}

/*!
 @brief A function to be called when the message tag is off
 @param pointer to unsigned char of serial read data
 @return unsigned char of value of serial read result
 255 if something was wrong with massage value
 */
unsigned char off_handler(unsigned char* command) {
	struct Job job;
	unsigned char hovercraft_off = get_value_off(command);
	switch (hovercraft_off) {
	case HOVERINGOFF:
		/* value is 0000 */
		// hovering off
		job.task_p2 = stop_hover;
		job.job_num = 1;
		job.prio = PRIO_HIGH;
		job.type = MOVEMENT;
		putJobInQueue(job);
		return HOVERINGOFF;
		break;
	case TOTALLOFF:
		/* value is 0001 */
		// hovering off
		job.task_p2 = stop_hover;
		job.job_num = 1;
		job.prio = PRIO_HIGH;
		job.type = MOVEMENT;
		putJobInQueue(job);
		// set fan forwarding to zero
		job.task_p1 = set_propulsion_fan;
		job.job_num = 0;
		job.arg1 = 0;
		job.prio = PRIO_HIGH;
		job.type = MOVEMENT;
		putJobInQueue(job);
		// set rudder to close for parking style :D
		job.task_p3 = control_rudder;
		job.job_num = 2;
		job.arg1 = BRAKE;
		job.prio = PRIO_HIGH;
		job.type = MOVEMENT;
		putJobInQueue(job);
		return TOTALLOFF;
		break;
	default:
		debug_print_string("Off handler error");
		break;
	} // end of switch case of rudder direction value
	return 255;
}

/*!
 @brief A function to be called when the message tag is changing rudder direction
 @param pointer to unsigned char of serial read data
 @return unsigned char of value of serial read result
 255 if something was wrong with massage value
 */
unsigned char ruder_direction_handler(unsigned char* command) {
	struct Job job;
	unsigned char res_direction = get_direction(command); // To get the direction
	switch (res_direction) {
	case STRAIGHT:
		/* value is 0000 */
		// set the ruder to STRAIGHT
		job.task_p3 = control_rudder;
		job.job_num = 2;
		job.arg1 = STRAIGHT;
		job.prio = PRIO_HIGH;
		job.type = MOVEMENT;
		putJobInQueue(job);
//		control_rudder(STRAIGHT);
		debug_print_string("STRAIGHT");
		return STRAIGHT;
		break;
	case HARD_LEFT:
		/* value is 0001 */
		// set the rudder to hard left
		job.task_p3 = control_rudder;
		job.job_num = 2;
		job.arg1 = HARD_LEFT;
		job.prio = PRIO_HIGH;
		job.type = MOVEMENT;
		putJobInQueue(job);
//		control_rudder(HARD_LEFT);
		debug_print_string("HARD_LEFT");
		return HARD_LEFT;
		break;
	case HARD_RIGHT:
		/* value is 0010 */
		job.task_p3 = control_rudder;
		job.job_num = 2;
		job.arg1 = HARD_RIGHT;
		job.prio = PRIO_HIGH;
		job.type = MOVEMENT;
		putJobInQueue(job);
//		control_rudder(HARD_RIGHT);
		debug_print_string("HARD_RIGHT");
		return HARD_RIGHT;
		break;
	case SOFT_RIGHT:
		/* value is 0011 */
		job.task_p3 = control_rudder;
		job.job_num = 2;
		job.arg1 = SOFT_RIGHT;
		job.prio = PRIO_HIGH;
		job.type = MOVEMENT;
		putJobInQueue(job);
//		control_rudder(SOFT_RIGHT);
		debug_print_string("SOFT_RIGHT");
		return SOFT_RIGHT;
		break;
	case SOFT_LEFT:
		/* value is 0100 */
		job.task_p3 = control_rudder;
		job.job_num = 2;
		job.arg1 = SOFT_LEFT;
		job.prio = PRIO_HIGH;
		job.type = MOVEMENT;
		putJobInQueue(job);
//		control_rudder(SOFT_LEFT);
		debug_print_string("SOFT_LEFT");
		return SOFT_LEFT;
		break;
	case BRAKE:
		/* value is 0101 */
		job.task_p3 = control_rudder;
		job.job_num = 2;
		job.arg1 = BRAKE;
		job.prio = PRIO_HIGH;
		job.type = MOVEMENT;
		putJobInQueue(job);
//		control_rudder(BRAKE);
		debug_print_string("BRAKE");
		return BRAKE;
		break;
	default:
		debug_print_string("direction ERROR");
		break;
	} // end of switch case of rudder direction value
	return 255;
}

/*!
 @brief A function to be called when the message tag is about hovering fan
 @param pointer to unsigned char of serial read data
 @return unsigned char of value of serial read result
 255 if something was wrong with massage value
 */
unsigned char fan_hovering_speed_handler(unsigned char* command) {
	struct Job job;
	if (increase_decrease(command) == 1) { // first bit is 1 then either increasing or decreasing
		unsigned char res_value = get_value_fans(command); // check the last bits
		switch (res_value) {
		case INCREASING:
			/* value was 00011000 */
			job.task_p2 = increase_hover_auto;
			job.job_num = 1;
			job.prio = PRIO_HIGH;
			job.type = MOVEMENT;
			putJobInQueue(job);
			debug_print_string("put Fan Hovering increasing");
			return INCREASING;
			break;
		case DECREASING:
			/* value was 00011001 */
			job.task_p2 = decrease_hover_auto;
			job.job_num = 1;
			job.prio = PRIO_HIGH;
			job.type = MOVEMENT;
			putJobInQueue(job);
			debug_print_string("put Fan Hovering decreasing");
			return DECREASING;
			break;
		default:
			debug_print_string("put Fan Hovering Speed ERROR");
			break;
		} // first bit is 1 then either increasing or decreasing
		return 255;
	} else {
		unsigned char res_value = get_value_fans(command); // check the last bits
		switch (res_value) {
		case STOP:
			/* value was 00010000 */
			// Call the stop api function of hovering
			debug_print_string("put Fan Hovering STOP in queue");
			return STOP;
			break;
		case TURBO:
			/* value was 00010111 */
			// Call the turbo api function of hovering
			debug_print_string("put Fan Hovering TURBO in queue");
			return TURBO;
			break;
		default:
			debug_print_string("Fan Hovering not implemented commands ERROR");
			break;
		}
		debug_print_string("put exact FAN_HOVERING_SPEED");
	} // The message was exact fan hovering speed value
	return 255;
}

/*!
 @brief A function to be called for going backward and changing relay
 @return unsigned char of 1 if the function was called
 */
unsigned char backward_handler() {
	struct Job job;
	job.task_p2 = change_polarity;
	job.job_num = 1;
	job.prio = PRIO_HIGH;
	job.type = MOVEMENT;
	putJobInQueue(job);
	debug_print_string("Backward");
//	change_polarity();
	return 1;
}


/*!
 @brief A function to be called when the message tag is about forwarding fan
 @param pointer to unsigned char of serial read data
 @return unsigned char of value of serial read result
 255 if something was wrong with massage value
 */
unsigned char fan_forward_speed_handler(unsigned char* command) {
	struct Job job;
	if (1 == increase_decrease(command)) { // first bit is 1 then either increasing or decreasing
		unsigned char res_value = get_value_fans(command); // check the last bits
		int temp = 0;
		switch (res_value) {
		case INCREASING:
			/* value was 00001000 */
			job.task_p2 = increase_propulsion;
			job.job_num = 1;
			job.prio = PRIO_HIGH;
			job.type = MOVEMENT;
			putJobInQueue(job);
			debug_print_string("put Fan Forward increasing Speed in queue");
			return INCREASING;
			break;
		case DECREASING:
			/* value was 00001001 */
			job.task_p2 = decrease_propulsion;
			job.job_num = 1;
			job.prio = PRIO_HIGH;
			job.type = MOVEMENT;
			putJobInQueue(job);
			debug_print_string("put Fan Forward decreasing Speed in queue");
			return DECREASING;
			break;
		default:
			debug_print_string("put Fan Forward Speed ERROR");
			break;
		}
		return 255;
	} // first bit is 1 then either increasing or decreasing
	else {
		unsigned char res_value = get_value_fans(command); // check the last bits
		switch (res_value) {
		case STOP:
			/* value was 00000000 */
			// set fan forward to zero
			job.task_p1 = set_propulsion_fan;
			job.arg1 = 0;
			job.job_num = 0;
			job.prio = PRIO_HIGH;
			job.type = MOVEMENT;
			putJobInQueue(job);
//			set_propulsion_fan(0);

			// decrease the hovering for smooth stop
			job.task_p2 = decrease_hover_auto;
			job.job_num = 1;
			job.prio = PRIO_HIGH;
			job.type = MOVEMENT;
			putJobInQueue(job);
//			decrease_hover_auto();

			// decrease the hovering for smooth stop ;D
			job.task_p2 = decrease_hover_auto;
			job.job_num = 1;
			job.prio = PRIO_HIGH;
			job.type = MOVEMENT;
			putJobInQueue(job);
//			decrease_hover_auto();

			// Set the control to straght
			job.task_p3 = control_rudder;
			job.job_num = 2;
			job.arg1 = STRAIGHT;
			job.prio = PRIO_HIGH;
			job.type = MOVEMENT;
			putJobInQueue(job);
//			control_rudder(STRAIGHT);
			debug_print_string("put Fan Forward STOP in queue");
			return STOP;
			break;
		case TURBO:
			/* value was 00000111 */
			// set forwarding fan to 7, maximum
			job.task_p1 = set_propulsion_fan;
			job.arg1 = 120;
			job.job_num = 0;
			job.prio = PRIO_HIGH;
			job.type = MOVEMENT;
			putJobInQueue(job);
//			set_propulsion_fan(120);

			// set hovering fan to 7, maximum
			job.task_p2 = hover_max;
			job.job_num = 1;
			job.prio = PRIO_HIGH;
			job.type = MOVEMENT;
			putJobInQueue(job);
			debug_print_string("put Fan Forward TURBO in queue");
			return TURBO;
			break;
		default:
			debug_print_string("Fan Forward not implemented commands ERROR");
			break;
		}
		debug_print_string("put exact Forward speed value");
	} // The message was exact fan forwarding speed value
	return 255;
}

/*
 * Implementation of setting and checking password on the hovercraft
 * Not used in the final code.
 */
//unsigned char init_login() {
//	login = (struct authentication*) malloc(sizeof(struct authentication) * 1);
//	if (login == NULL) {
//		return 255;
//	}
//	login->user_login = 0; // 0 stands for not login
//	login->pass = (char*) malloc(sizeof(char) * (PASSSIZE + 1));
//	if (login->pass == NULL) {
//		return 254;
//	}
//	login->pass_size = 0;
//	return 1;
//}
//
//unsigned char add_pass(char* pass_ch) {
//	if (login == NULL) {
//		return 255;
//	}
//	if ((login->pass) == NULL) {
//		return 254;
//	}
//	*(login->pass) = *pass_ch;
//	login->pass++;
//	login->pass = '\0';
//	login->pass_size++;
//
//	check_global_password();
//	return 1;
//}
//unsigned char check_global_password() {
//	if (login->pass_size == (PASSSIZE - 1)) {
//		//		check the password if it is correct
//		//		debug_print_string(login->pass);
//		//		if pass is correct then
//		//		login->user_login=1;
//	}
//	return 255;
//
//}
//
//unsigned char distroy_pointer() {
//	if (login == NULL) {
//		return 255;
//	}
//	free(login);
//	return 1;
//}

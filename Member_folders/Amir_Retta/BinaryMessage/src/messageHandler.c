/*
 * massageHandler.c
 *
 *  Created on: Mar 28, 2012
 *
 *  Mar 28, 2012 :
 *   implemented of some functions. To name the functions:
 *  parseBinary, findMessage, create_fan_forward_speed, create_fan_hovering_speed,
 *  create_ruder_direction, create_hovercraft_speed, create_hovercraft_pressure,
 *  create_battery_level, check_number_limit
 *
 *  Mar 29, 2012 :
 *  changes in the return value of the create functions. Basically for the
 *  first implementation, only message was cared!. In the latest implementation, value is
 *  cared also which is the correct one.
 *  Apr 1, 2012 :
 *  Implemented api functions. To name the implemented functions:
 *  bluetooth_working, fan_forward_speed, fan_hovering_speed, ruder_direction, hovercraft_speed,
 *  hovercraft_pressure, battery_level
 *
 *  Apr 3, 2012 :
 *  bluetooth_working() will be located in another module because, in this function, the serial.availale
 *  is in used which should be compiled by c++ library. The function will be in serial_input.c
 *
 *
 *  Todo: Because of the continuously changes in value in the protocol, the value, when the binary
 *  is received, is missed which should be the first task.
 *
 */
#include <stdio.h>
#include "messageHandler.h"

#define Fan_Forward_Speed 0;
#define Fan_Hovering_Speed 1;
#define Ruder_Direction 2;
#define Hovercraft_Speed 3;
#define Hovercraft_Pressure 4;
#define Battery_Level 5;
#define Connection 6;



/**
 * A function which is called when there is binary received on serial.
 * When binary argument is based on protocol the return of the function is: 0 - 5
 * When binary argument is not based on anything on protocol the
 * return of the function is 255
 *
 */
unsigned char parseBinary(unsigned char message) {
	//	printf("The message is: %x\n", message);
	return findMessage(&message);
}

/**
 * A function to find the type of the message based on the received binary
 * The function returns 0 - 5 if the binary message is based on the protocol
 * The function returns 255 when the binary message is not based on the protocol.
 */
unsigned char findMessage(unsigned char* message) {
	switch ((*message & (15 << 4)) >> 4) {
	case 0:
		return Fan_Forward_Speed
				;
		break;
	case 1:
		return Fan_Hovering_Speed
				;
		break;
	case 2:
		return Ruder_Direction
				;
		break;
	case 3:
		return Hovercraft_Speed
				;
		break;
	case 4:
		return Hovercraft_Pressure
				;
		break;
	case 5:
		return Battery_Level
				;
		break;
	}
	return 255;
}

/**
 * A function to create fan forward speed based on protocol
 * Function returns 255 if the value is bigger the limit
 * Function returns the fan forward speed binary message with the value
 */
unsigned char create_fan_forward_speed(unsigned char* message) {
	if (check_number_limit(message) == 255) {
		return 255;
	}
	return *message;
}

/**
 * A function to create fan hovering speed based on protocol
 * Function returns 255 if the value is bigger the limit
 * Function returns the fan hovering speed binary message with the value
 */
unsigned char create_fan_hovering_speed(unsigned char* message) {
	if (check_number_limit(message) == 255) {
		return 255;
	}
	return (1 << 4) | *message;
}

/**
 * A function to create ruder direction based on protocol
 * Function returns 255 if the value is bigger the limit
 * Function returns the ruder direction binary message with the value
 */
unsigned char create_ruder_direction(unsigned char* message) {
	if (check_number_limit(message) == 255) {
		return 255;
	}
	return (1 << 5) | *message;
}

/**
 * A function to create hover craft speed based on protocol
 * Function returns 255 if the value is bigger the limit
 * Function returns the ruder direction binary message with the value
 */
unsigned char create_hovercraft_speed(unsigned char* message) {
	if (check_number_limit(message) == 255) {
		return 255;
	}
	return (3 << 4) | *message;
}

/**
 * A function to create hover craft pressure based on protocol
 * Function returns 255 if the value is bigger the limit
 * Function returns the pressure binary message with the value
 */
unsigned char create_hovercraft_pressure(unsigned char* message) {
	if (check_number_limit(message) == 255) {
		return 255;
	}
	return (1 << 6) | *message;
}

/**
 * A function to create battery level based on protocol
 * Function returns 255 if the value is bigger the limit
 * Function returns the battery level binary message with the value
 */
unsigned char create_battery_level(unsigned char* message) {
	if (check_number_limit(message) == 255) {
		return 255;
	}
	return (5 << 4) | *message;
}

/**
 * A function to check the limit of the value of the message
 * The limit of the message is 15 ( 4 bits )
 * Function returns 255 if the value is bigger the limit
 * Function returns 1 if the message is in the range
 */
unsigned char check_number_limit(unsigned char* message) {
	if ((*message > 15) || *message < 0) {
		return 255;
	}
	return 1;
}


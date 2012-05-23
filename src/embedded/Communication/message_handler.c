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
 @file message_handler.c
 @headerfile message_handler.h
 @details This module is the brain of the bluetooth which controls it's functionalities
 @author Amir Almasi
 @author Retta Shiferaw
 @version 0.5
 */

#include <message_handler.h>
#include <conventions.h>

/*!
 @brief A function which is called when there is binary received on serial.
 When binary argument is based on protocol the return of the function is: 0 - 5
 When binary argument is not based on anything on protocol the
 return of the function is 255
 @param pointer to unsigned char of the message which is received
 @return unsigned char containing a number
 */
unsigned char parse_binary(unsigned char* message) {
	return find_message(message);
}

/*!
 @brief A function to find out message contains increasing and decreasing or not.
 @param pointer to unsigned char of the message which is received
 @return unsigned char containing a number
 1 if increase or decrease message
 255 if something is wrong
 */
unsigned char increase_decrease(unsigned char* value) {
	return (((*value) & 0b00001000) >> 3);
}
/*!
 @brief A function to find out about the direction.
 @param pointer to unsigned char of the message which is received
 @see http://hoveritu.com/projects/semb2012/wiki
 @return unsigned char containing a number
 return number is in the range of 0 to 5
 */
unsigned char get_direction(unsigned char* direction) {
	return ((*direction) & 0b00000111);
}

/*!
 @brief A function to find out about exact data of value in binary received.
 @param pointer to unsigned char of the message
 @return unsigned char containing a number
 return number is in the range of 0 to 7
 */
unsigned char get_value_fans(unsigned char* value) {
	return (0b00000111 & (*value));
}

unsigned char get_value_off(unsigned char* value) {
	return (0b00000001 & (*value));
}

/*!
 @brief A function to find the type of the message of the received binary
 The function returns 0 - 5 if the binary message is based on the protocol
 The function returns 255 when the binary message is not based on the protocol.
 @see http://hoveritu.com/projects/semb2012/wiki
 @param pointer to unsigned char of the message
 @return number is in the range of 0 to 5
 return number 255 for expressing error
 */
unsigned char find_message(unsigned char* message) {
	switch ((*message & (15 << 4)) >> 4) {
	case FAN_FORWARD_SPEED:
		return FAN_FORWARD_SPEED;
		break;
	case FAN_HOVERING_SPEED:
		return FAN_HOVERING_SPEED;
		break;
	case RUDER_DIRECTION:
		return RUDER_DIRECTION;
		break;
	case HOVERCRAFT_SPEED:
		return HOVERCRAFT_SPEED;
		break;
	case HOVERCRAFT_PRESSURE:
		return HOVERCRAFT_PRESSURE;
		break;
	case BATTERY_LEVEL:
		return BATTERY_LEVEL;
		break;
	case BACKWARD:
		return BACKWARD;
		break;
	case HOVERCRAFTOFF:
		return HOVERCRAFTOFF;
		break;
	default:
		return 255;
	}
	return 255;
}

/*!
 @brief A function to create fan forward speed message based on protocol
 @see http://hoveritu.com/projects/semb2012/wiki
 @param pointer to unsigned char of the message
 @return number based on the message type
 return 255 if the value is bigger the limit
 */
unsigned char create_fan_forward_speed(unsigned char* message) {
	if (check_number_limit(message) == 255) {
		return 255;
	}
	return *message;
}

/*!
 @brief A function to create fan hovering speed based on protocol
 @see http://hoveritu.com/projects/semb2012/wiki
 @param pointer to unsigned char of the message
 @return number based on the message type
 return 255 if the value is bigger the limit
 */
unsigned char create_fan_hovering_speed(unsigned char* message) {
	if (check_number_limit(message) == 255) {
		return 255;
	}
	return (1 << 4) | *message;
}

/*!
 @brief A function to create ruder direction message based on protocol
 @see http://hoveritu.com/projects/semb2012/wiki
 @param pointer to unsigned char of the message
 @return number based on the message type
 return 255 if the value is bigger the limit
 */
unsigned char create_ruder_direction(unsigned char* message) {
	if (check_number_limit(message) == 255) {
		return 255;
	}
	return (1 << 5) | *message;
}

/*!
 @brief A function to create hover craft speed message based on protocol
 @see http://hoveritu.com/projects/semb2012/wiki
 @param pointer to unsigned char of the message
 @return number based on the message type
 return 255 if the value is bigger the limit
 */
unsigned char create_hovercraft_speed(unsigned char* message) {
	if (check_number_limit(message) == 255) {
		return 255;
	}
	return (3 << 4) | *message;
}

/*!
 @brief A function to create hover craft pressure message based on protocol
 @see http://hoveritu.com/projects/semb2012/wiki
 @param pointer to unsigned char of the message
 @return number based on the message type
 return 255 if the value is bigger the limit
 */
unsigned char create_hovercraft_pressure(unsigned char* message) {
	if (check_number_limit(message) == 255) {
		return 255;
	}
	return (1 << 6) | *message;
}

/*!
 @brief A function to create battery level message based on protocol
 @see http://hoveritu.com/projects/semb2012/wiki
 @param pointer to unsigned char of the message
 @return number based on the message type
 return 255 if the value is bigger the limit
 */
unsigned char create_battery_level(unsigned char* battery_num,
		unsigned char* message) {
	if (check_number_limit(message) == 255) {
		return 255;
	}
	return ((5 + (*battery_num - 1)) << 4) | *message;
}

/*!
 @brief A function to check the limit of the value of the message
 @note The limit of the message is from 0 to 15 ( 4 bits )
 @see http://hoveritu.com/projects/semb2012/wiki
 @param pointer to unsigned char of the message
 @return 1 if the message is in the range
 return 255 if the value is bigger the limit
 */
unsigned char check_number_limit(unsigned char* message) {
	if ((*message > 15) || *message < 0) {
		return 255;
	}
	return 1;
}


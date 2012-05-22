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
 @file communication_controler.h
 @details This header file contains internal functions
 @author Amir Almasi
 @author Retta Shiferaw
 @version 0.2
 */

#ifndef BLUETOOTH_CONTROLER_H_
#define BLUETOOTH_CONTROLER_H_

/*!
 @brief The function sends an string to the monitoring of Arduino for the purpose of debugging
 @param pointer to character which keeps the first character address.
 */
void send_serial_string(char*);

/*!
 @brief A function to be called for going backward and changing relay
 @return unsigned char of 1 if the function was called
 */
unsigned char backward_handler (void);

/*!
 @brief The function sends unsigned char
 @param pointer to char of the string
 */
void send_serial_binary(unsigned char*);
/*!
 @brief The function sends int which is hovercraft speed
 @param pointer to int hovercraft speed
 */
void send_serial_binary_speed(int*);

/*!
 @brief A function to check bluetooth input if there is any or not
 @param unsigned char of serial read data
 @return unsigned char of result of  serial read
 255 there was no data available for bluetooth, 254 there is no connection for bluetooth
 */
unsigned char check_bluetooth(unsigned char*);

/*!
 @brief A function to check wifi input if there is any or not
 @param unsigned char of serial read data
 @return unsigned char of result of  serial read
 255 there was no data available for wifi, 254 there is no connection for wifi
 */
unsigned char check_wifi(unsigned char*);

/*!
 @brief A function to be called when the message tag is changing rudder direction
 @param pointer to unsigned char of serial read data
 @return unsigned char of value of serial read result
 255 if something was wrong with massage value
 */
unsigned char ruder_direction_handler(unsigned char*);

/*!
 @brief A function to be called when the message tag is about hovering fan
 @param pointer to unsigned char of serial read data
 @return unsigned char of value of serial read result
 255 if something was wrong with massage value
 */
unsigned char fan_hovering_speed_handler(unsigned char*);

/*!
 @brief A function to be called when the message tag is about forwarding fan
 @param pointer to unsigned char of serial read data
 @return unsigned char of value of serial read result
 255 if something was wrong with massage value
 */
unsigned char fan_forward_speed_handler(unsigned char*);

/*!
 @brief A function to be called when the message tag is off
 @param pointer to unsigned char of serial read data
 @return unsigned char of value of serial read result
 255 if something was wrong with massage value
 */
unsigned char off_handler(unsigned char*);

#endif /* BLUETOOTH_CONTROLER_H_ */

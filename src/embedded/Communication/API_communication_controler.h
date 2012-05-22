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
 @file API_communication_controler.h
 @details This header file contains all API functions
 @author Amir Almasi
 @author Retta Shiferaw
 @version 0.3
 @note All the aruguments and returns of the functions are unsigned char
 */

#ifndef API_BLUETOOTH_CONTROLER_H_
#define API_BLUETOOTH_CONTROLER_H_

unsigned char connection_status();

/*!
 @brief Initializing bluetooth serial pins on Arduino
 */
void communication_serial_setup();

/*!
 @brief When this function is called, by Scheduler, the bluetooth gets the resources of
 the board and it should check if there is anything available on serial input or not
 */
void check_serial_input();

/*!
 @brief The function creates fan forward speed message.
  message argument is followed by hovercraft protocol available on wiki
 @see http://hoveritu.com/projects/semb2012/wiki
 @param unsigned char of the value to be sent to pc
 @return unsigned char containing value and message type
 */
unsigned char fan_forward_speed(unsigned char message);

/*!
 @brief The function creates fan hovering speed message.
  message argument is followed by hovercraft protocol available on wiki
 @see http://hoveritu.com/projects/semb2012/wiki
 @param unsigned char of the value to be sent to pc
 @return unsigned char containing value and message type
 */
unsigned char fan_hovering_speed(unsigned char message);

/*!
 @brief The function creates ruder direction message.
  message argument is followed by hovercraft protocol available on wiki
 @see http://hoveritu.com/projects/semb2012/wiki
 @param unsigned char of the value to be sent to pc
 @return unsigned char containing value and message type
 */
unsigned char ruder_direction(unsigned char message);

/*!
 @brief The function creates hovercraft speed (measured by sensor) message.
  message argument is followed by hovercraft protocol available on wiki
 @see http://hoveritu.com/projects/semb2012/wiki
 @param unsigned char of the value to be sent to pc
 @return unsigned char containing value and message type
 */
unsigned char hovercraft_speed(int message);

/*!
 @brief The function creates hovercraft pressure (measured by sensor) message.
  message argument is followed by hovercraft protocol available on wiki
 @see http://hoveritu.com/projects/semb2012/wiki
 @param unsigned char of the value to be sent to pc
 @return unsigned char containing value and message type
 */
unsigned char hovercraft_pressure(unsigned int message);

/*!
 @brief The function creates hovercraft battery level message.
  message argument is followed by hovercraft protocol available on wiki
 @see http://hoveritu.com/projects/semb2012/wiki
 @param unsigned char of the value to be sent to pc
 @return unsigned char containing value and message type
 */
unsigned char battery_level(unsigned char, unsigned char);


unsigned char stream_information (char* information);


unsigned char parse_input(unsigned char* result);

#endif /* API_BLUETOOTH_CONTROLER_H_ */

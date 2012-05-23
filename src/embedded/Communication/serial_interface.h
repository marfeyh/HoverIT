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
 @file serial_interface.h
 @details This header file contains function prototypes of serial_interface.c
 @author Amir Almasi
 @author Retta Shiferaw
 @author Viktor Green
 @author Peter Myllykoski
 @version 0.3
 @note This header file is written by the help of Viktor and Peter
 @see http://hoveritu.com/projects/semb2012/wiki for more information
 */
#ifndef SERIAL_INTERFACE_H
#define SERIAL_INTERFACE_H

#define BLUETOOTH
//#define WIFI
//#define GSM

#ifdef __cplusplus
extern "C" {
#endif

/*!
 @brief When this function is called the bluetooth gets the resources of CPU, Arduino,
 and it should check if there is anything available or not
 @return unsigned char containing the binary message
 return 255 if there was nothing availble
 */
unsigned char serial_read();

/*!
 @brief A function to send the data to serial pins
 @param pointer to unsigned char of the binary to be sent
 */
void serial_binary_write(unsigned char*);

/*!
 @brief A function to send string to bluetooth character by character to be sent
 @param pointer to first char of the string to be sent
 */
void serial_string_write(char*);

/*!
 @brief A function to initialize pins
 */
void serial_setup (void);

/*!
 @brief A function to send data to serial for the use monitoring
 @param pointer to unsigned char of first char of the string to be sent
 */
void debug_print (unsigned char*);

/*!
 @brief A function to send data to serial for the use monitoring
 @param pointer to unsigned int of first char of the string to be sent
 */
void debug_print2(unsigned int* data);

/*!
 @brief A function to send data to serial for the use monitoring
 @param int value to be sent to monitoring
 */
void debug_print3(int);

/*!
 @brief A function to send speed data
 @param pointer to int value to be sent via Bluetooth
 */
void serial_binary_write_speed(int*);

/*!
 @brief A function to send data to serial for the use monitoring IN BINARY
 @param pointer to unsigned char of first char of the string to be sent
 */
void debug_write (unsigned char*);

/*!
 @brief A function to send string to serial pin character by character
 @param pointer to first char of the string to be sent
 */
void debug_print_string (char*);

/*!
 @brief A function to change the communication connection.
 This function was implemented when changing request should have been made before
 compiling which was in earlier architecture. In the latest architecture and implementation
 this is not effecting and in used anymore.
 */
void serial_switch(void);

/*!
 @brief A function to check if the connection is established or not
 */
unsigned char check_connection(void);

#ifdef __cplusplus
}
#endif
#endif

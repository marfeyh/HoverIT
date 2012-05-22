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
void send_serial_string(char* string);

unsigned char backward_handler (void);
unsigned char init_login(void);
unsigned char add_pass(char*);
unsigned char check_global_password(void);
unsigned char distroy_pointer (void);

/*!
 @brief The function sends one binary to the monitoring of Arduino for the purpose of debugging
 @param pointer to unsigned character which keeps the address of unsigned character.
 */
void send_serial_binary(unsigned char*);
void send_serial_binary_speed(int*);
unsigned char check_bluetooth(unsigned char*);
unsigned char check_wifi(unsigned char*);
unsigned char ruder_direction_handler(unsigned char*);
unsigned char fan_hovering_speed_handler(unsigned char*);
unsigned char fan_forward_speed_handler(unsigned char*);
unsigned char off_handler(unsigned char*);

#endif /* BLUETOOTH_CONTROLER_H_ */

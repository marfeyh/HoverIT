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
 @file bluetooth_command.h
 @details This is the header file of internal settings functions for bluetooth
 @author Amir Almasi
 @author Retta Shiferaw
 @version 0.2
 @note All the aruguments and returns of the functions are unsigned char
 */

#ifndef BLUETOOTH_COMMAND_H_
#define BLUETOOTH_COMMAND_H_

#define CONCATINATION(dist, source) strcat(dist, source)
#define SPACE " "

char* set_discoverable_mode(char* mode);
char* set_escape_character(char* parameter);
char* set_flow_control(char* parameter);
char* set_link_timeout(char* timeout);
char* set_baud_rate(char* rate);
char* return_data_mode();
char* get_address();
char* get_connectable_mode();
char* get_discoverable_mode();
char* get_scape_character();
char* get_flow_control();
char* get_link_timeout();
char* help();
char* list();
char* version();
char* connect_timeout(char* mac_adress, char* time_out);
char* connect(char* mac_adress);
char* new_string(unsigned char size);
unsigned char append_string(char* head_ptr, char* string_ptr);
char* disconnect();
unsigned char distroy_command(char* ptr);
unsigned char check_ptr (char* ptr);

#endif /* BLUETOOTH_COMMAND_H_ */

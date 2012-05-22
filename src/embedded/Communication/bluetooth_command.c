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
 @file bluetooth_command.c
 @headerfile bluetooth_controler.h
 @details This module is only for the eBT500 commands based on the manual
 @see http://www.parallax.com/dl/docs/prod/comm/eb500.pdf
 @author Amir Almasi
 @author Retta Shiferaw
 @version 0.2
 @todo only one command, set connetable to true, is implemented. Also commenting
 the functions is left.
 @todo the header file of this module is missing now! missing!
 @warning malloc is used to get required memory. There can be some failure
 */
// test the functions. write free function
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bluetooth_command.h"

char* set_discoverable_mode(char* mode) {
	char* str_command = new_string(12);
	if (255 == check_ptr(str_command)) {
		return NULL;
	}
	append_string(str_command, "set dis ");
	append_string(str_command, mode);
	append_string(str_command, "\r");
	return str_command;
}

char* set_escape_character(char* parameter) {
	char* str_command = new_string(17);
	if (255 == check_ptr(str_command)) {
		return NULL;
	}
	append_string(str_command, "set flow ");
	append_string(str_command, parameter);
	append_string(str_command, "\r");
	return str_command;

}

char* set_flow_control(char* parameter) {
	char* str_command = new_string(20);
	if (255 == check_ptr(str_command)) {
		return NULL;
	}
	append_string(str_command, "set flow ");
	append_string(str_command, parameter);
	append_string(str_command, "\r");
	return str_command;
}

char* set_link_timeout(char* timeout) {
	char* str_command = new_string(20);
	if (255 == check_ptr(str_command)) {
		return NULL;
	}
	append_string(str_command, "set linktimeout ");
	append_string(str_command, timeout);
	append_string(str_command, "\r");
	return str_command;
}

char* set_baud_rate(char* rate) {
	char* str_command = new_string(20);
	if (255 == check_ptr(str_command)) {
		return NULL;
	}
	append_string(str_command, "set baud ");
	append_string(str_command, rate);
	append_string(str_command, "\r");
	return str_command;
}

char* return_data_mode() {
	char* str_command = new_string(5);
	if (255 == check_ptr(str_command)) {
		return NULL;
	}
	append_string(str_command, "ret\r");
	return str_command;
}

char* get_address() {
	char* str_command = new_string(10);
	if (255 == check_ptr(str_command)) {
		return NULL;
	}
	append_string(str_command, "get addr\r");
	return str_command;
}

char* get_connectable_mode() {
	char* str_command = new_string(9);
	if (255 == check_ptr(str_command)) {
		return NULL;
	}
	append_string(str_command, "get con\r");
	return str_command;
}
char* get_discoverable_mode() {
	char* str_command = new_string(9);
	if (255 == check_ptr(str_command)) {
		return NULL;
	}
	append_string(str_command, "get dis\r");
	return str_command;
}
char* get_scape_character() {
	char* str_command = new_string(13);
	if (255 == check_ptr(str_command)) {
		return NULL;
	}
	append_string(str_command, "get escchar\r");
	return str_command;
}
char* get_flow_control() {
	char* str_command = new_string(10);
	if (255 == check_ptr(str_command)) {
		return NULL;
	}
	append_string(str_command, "get flow\r");
	return str_command;
}
char* get_link_timeout() {
	char* str_command = new_string(17);
	if (255 == check_ptr(str_command)) {
		return NULL;
	}
	append_string(str_command, "get linktimeout\r");
	return str_command;
}

char* help() {
	char* str_command = new_string(5);
	if (255 == check_ptr(str_command)) {
		return NULL;
	}
	append_string(str_command, "hlp\r");
	return str_command;
}

char* list() {
	char* str_command = new_string(5);
	if (255 == check_ptr(str_command)) {
		return NULL;
	}
	append_string(str_command, "lst\r");
	return str_command;
}

char* version() {
	char* str_command = new_string(9);
	if (255 == check_ptr(str_command)) {
		return NULL;
	}
	append_string(str_command, "ver all\r");
	return str_command;
}

char* connect_timeout(char* mac_adress, char* time_out) {
	char* str_command = new_string(27);
	if (255 == check_ptr(str_command)) {
		return NULL;
	}
	append_string(str_command, "con ");
	append_string(str_command, mac_adress);
	append_string(str_command, " ");
	append_string(str_command, time_out);
	append_string(str_command, "\r");
	return str_command;
}

char* connect(char* mac_adress) {
	char* str_command = new_string(23);
	if (255 == check_ptr(str_command)) {
		return NULL;
	}
	append_string(str_command, "con ");
	append_string(str_command, mac_adress);
	append_string(str_command, "\r");
	return str_command;
}

char* new_string(unsigned char size) {
	char* str_ptr = (char*) malloc(sizeof(char) * size);
	if (str_ptr == NULL) {
		// something went wrong
		return NULL;
	}
	*str_ptr = '\0';
	return str_ptr;
}

unsigned char append_string(char* head_ptr, char* string_ptr) {
	strcat(head_ptr, string_ptr);
	return 0;
}

char* disconnect() {
	char* str_command = new_string(5);
	if (255 == check_ptr(str_command)) {
		return NULL;
	}
	append_string(str_command, "dis\r");
	return str_command;
}
unsigned char check_ptr(char* ptr) {
	if (ptr == NULL) {
		return 255;
	}
	return 1;
}

unsigned char distroy_command(char* ptr) {
	if (255 == check_ptr(ptr)) {
		return 255;
	}
	free(ptr);
	return 1;

}

int main(void) {
//	printf("%s", connect("00:0C:84:00:07:D7"));
//	printf("%d", strlen(connect("00:0C:84:00:07:D7")));

//	printf("%s", disconnect());
//	printf("%d", strlen(disconnect()));

//	printf("%s", disconnect());
//	printf("%d", strlen(disconnect()));
	return 0;
}

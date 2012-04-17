/*!
 @file bluetooth_controler.c
 @headerfile API_bluetooth_controler.h
 @headerfile bluetooth_controler.h
 @details This module is the brain of the bluetooth which controls it's functionalities
 @author Amir Almasi
 @author Retta Shiferaw
 @version 0.7
 @note All the aruguments and returns of the functions are unsigned char
 @bug pointer to function should be free somewhere
 @todo pointer to job struct should be get free
 */

#include <stdio.h>
#include<bluetooth_controler.h>

#define CONCATINATION(dist, source) strcat(dist, source)
#define SPACE " "

unsigned char* set_discoverable_mode() {
	unsigned char temp = 255;
	return &temp;
}

unsigned char* set_escape_character() {
	unsigned char temp = 255;
	return &temp;

}

unsigned char* set_flow_control() {
	unsigned char temp = 255;
	return &temp;
}

unsigned char* set_link_timeout() {
	unsigned char temp = 255;
	return &temp;
}

unsigned char* switch_command_mode() {
	unsigned char temp = 255;
	return &temp;
}

unsigned char* set_baud_rate() {
	unsigned char temp = 255;
	return &temp;
}

unsigned char* return_data_mode() {
	unsigned char temp = 255;
	return &temp;
}

unsigned char* get_address() {
	unsigned char temp = 255;
	return &temp;
}

unsigned char* get_connectable_mode() {
	unsigned char temp = 255;
	return &temp;
}
unsigned char* get_discoverable_mode() {
	unsigned char temp = 255;
	return &temp;
}
unsigned char* get_scape_character() {
	unsigned char temp = 255;
	return &temp;
}
unsigned char* get_flow_control() {
	unsigned char temp = 255;
	return &temp;
}
unsigned char* get_link_timeout() {
	unsigned char temp = 255;
	return &temp;
}

unsigned char* help() {
	unsigned char temp = 255;
	return &temp;
}

unsigned char* list() {
	unsigned char temp = 255;
	return &temp;
}

unsigned char* version() {
	unsigned char temp = 255;
	return &temp;
}

void connect(char* mac_adress, unsigned char* time_out) {
	char connect_string[27] = "con";
	if (*time_out == 255) {
		CONCATINATION(connect_string, SPACE);
		CONCATINATION(connect_string, mac_adress);
	} else {
		CONCATINATION(connect_string, SPACE);
		CONCATINATION(connect_string, mac_adress);
		CONCATINATION(connect_string, SPACE);
		CONCATINATION(connect_string, time_out);
	}
	CONCATINATION(connect_string, "\r");
	printf("%s", connect_string);
}

unsigned char* disconnect() {
	unsigned char temp = 255;
	return &temp;
}

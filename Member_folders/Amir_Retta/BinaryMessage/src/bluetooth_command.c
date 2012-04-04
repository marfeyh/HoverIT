/*
 * bluetooth_command.c
 * In this module, the bluetooth gets the
 *
 *  Created on: Apr 03, 2012
 */


//#include <util/delay.h>
#include "serial_interface.cpp"
#include <stdio.h>

#define CONCATINATION(dist, source) strcat(dist, source)
#define SPACE " "


unsigned char* set_discoverable_mode(){
	return &(255);
}


unsigned char* set_escape_character(){
	return &(255);
}



unsigned char* set_flow_control(){
	return &(255);
}



unsigned char* set_link_timeout(){
	return &(255);
}




unsigned char* switch_command_mode(){
	return &(255);
}



unsigned char* set_baud_rate(){
	return &(255);
}


unsigned char* return_data_mode(){
	return &(255);
}


unsigned char* get_address(){
	return &(255);
}
unsigned char* get_connectable_mode(){
	return &(255);
}
unsigned char* get_connectable_mode(){
	return &(255);
}
unsigned char* get_discoverable_mode(){
	return &(255);
}
unsigned char* get_scape_character(){
	return &(255);
}
unsigned char* get_flow_control(){
	return &(255);
}
unsigned char* get_link_timeout(){
	return &(255);
}


unsigned char* help(){
	return &(255);
}

unsigned char* list(){
	return &(255);
}

unsigned char* version(){
	return &(255);
}

void connect(char* mac_adress, unsigned char* time_out){
	char connect_string[27] = "con";
	if (*time_out == 255){
		CONCATINATION(connect_string, SPACE);
		CONCATINATION(connect_string, mac_adress);
	}
	else{
		CONCATINATION(connect_string, SPACE);
		CONCATINATION(connect_string, mac_adress);
		CONCATINATION(connect_string, SPACE);
		CONCATINATION(connect_string, time_out);
	}
	CONCATINATION(connect_string , "\r");
	printf("%s", connect_string);
}

unsigned char* disconnect(){
	return &(255);
}

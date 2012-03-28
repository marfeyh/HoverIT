/*
 * massageHandler.c
 *
 *  Created on: Mar 28, 2012
 */
#include<stdio.h>
#include "messageHandler.h"

#define Fan_Forward_Speed 0;
#define Fan_Hovering_Speed 1;
#define Ruder_Direction 2;
#define Hovercraft_Speed 3;
#define Hovercraft_Pressure 4;
#define Battery_Level 5;
#define Connection 6;

unsigned char parseBinary(unsigned char message) {

	printf("The message is: %x\n", message);
	findMessage(&message);
	return 1;
}

unsigned char findMessage(unsigned char* message) {
	switch ((*message & (15 << 4)) >> 4) {
	case 0:
		return Fan_Forward_Speed;
		break;
	case 1:
		return Fan_Hovering_Speed;
		break;
	case 2:
		return Ruder_Direction;
		break;
	case 3:
		return Hovercraft_Speed;
		break;
	case 4:
		return Hovercraft_Pressure;
		break;
	case 5:
		return Battery_Level;
		break;
	}
	return 255;
}

unsigned char create_fan_forward_speed(unsigned char* message) {
	if (check_number_limit(message) == 255){
		return 255;
	}
	return 0;

}

unsigned char create_fan_hovering_speed(unsigned char* message) {
	if (check_number_limit(message) == 255){
		return 255;
	}
	return 1<<4;
}

unsigned char create_ruder_direction(unsigned char* message) {
	if (check_number_limit(message) == 255){
			return 255;
		}
		return 1<<5;
}
unsigned char create_hovercraft_speed(unsigned char* message) {
	if (check_number_limit(message) == 255){
			return 255;
		}
		return 3<<4;
}
unsigned char create_hovercraft_pressure(unsigned char* message) {
	if (check_number_limit(message) == 255){
			return 255;
		}
		return 1<<6;
}
unsigned char create_battery_level(unsigned char* message) {
	if (check_number_limit(message) == 255){
			return 255;
		}
		return 5<<4;
}

unsigned char check_number_limit(unsigned char* message){
	if ((*message > 15) || *message<0){
		return 255;
	}
	return 1;
}


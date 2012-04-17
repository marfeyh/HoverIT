/*
 * main.c
 *
 *  Created on: Mar 28, 2012
 */


/*!
 @file main.c
 @headerfile stdio.h
 @headerfile Arduino.h
 @headerfile searduino.h
 @headerfile API_bluetooth_controler.h
 @headerfile Theta-API.h
 @headerfile hover_api_stub.h
 @headerfile propulsion_api.h
 @headerfile steering.h
 @details This module is the brain of the bluetooth which controls it's functionalities
 @author Amir Almasi
 @author Retta Shiferaw
 @version 0.3
 @note All the aruguments and returns of the functions are unsigned char
 @bug pointer to function should be free somewhere
 @todo pointer to job struct should be get free
 */
#include <stdio.h>
#include <Arduino.h>
#include <searduino.h>
#include <API_bluetooth_controler.h>
//#include <Theta-API.h>
//#include <hover_api_stub.h>
//#include <propulsion_api.h>
//#include <steering.h>

int main (int argc, char** argv){
  init();
        pinMode(13, OUTPUT); // This is for testing to simulate small scheduler
        bluetooth_serial_setup();
//        start_propulsion_fan();
//        start_hover();
//        control_rudder(0);

	for(;;){
		control();
//		check_serial_input();
//		digitalWrite(13, HIGH);
//		delay(500);
//		digitalWrite(13, LOW);
//		delay(500);
	}
  return 0;
}

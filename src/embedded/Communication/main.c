/*
 * main.c
 *
 *  Created on: Mar 28, 2012
 */

#include <stdio.h>
#include <Arduino.h>
#include <searduino.h>
#include <messageHandler.h>
#include <API_bluetooth_controler.h>
#include <serial_interface.h>
int main (int argc, char** argv){
  init();
        pinMode(13,OUTPUT);
        serial_setup();
	for(;;){
		//Serial.print("test\n");
		check_serial_input();
		digitalWrite(13, HIGH);
		delay(500);
		digitalWrite(13, LOW);
		delay(500);
	}

  //run();
  return 0;
}

//void init(void) {
  //  initTimerInterrupt();
//}

//void run(void) {
  
  
//  return 0;
//}

/*
 * main.c
 *
 *  Created on: Mar 28, 2012
 */

#include <stdio.h>
#include <Arduino.h>
#include <searduino.h>
#include <API_bluetooth_controler.h>
#include <Theta-API.h>
#include <hover_api_stub.h>


#include <propulsion_api.h>
#include <steering.h>

int main (int argc, char** argv){
  init();
        pinMode(13,OUTPUT);
        bluetooth_serial_setup();
        start_propulsion_fan();
        start_hover();
        control_rudder(0);

	for(;;){
		control();
		//Serial.print("test\n");
//		check_serial_input();
//		digitalWrite(13, HIGH);
//		delay(500);
//		digitalWrite(13, LOW);
//		delay(500);
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

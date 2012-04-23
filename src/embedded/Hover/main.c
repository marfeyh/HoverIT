/*
Author: Eva-Lisa Kedborn, Jing Liu
Date: 2012-03-19
Description: the main to execute pressure_loop
*/

/* Includes */
#include "Arduino.h"
#include <hover_api.h>
#include <hovering_motor.h>
#include <hovering_control.h>

int main(void) {
        init();
	//for (;;) {	
		start_hover();
		hover_min();
		delay(1000);
		//hover_max();
		delay(2000);
		increase_hover();
		delay(2000);
		stop_hover();
	//}
	return 0;
}

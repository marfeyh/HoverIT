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
	//}
	return 0;
}

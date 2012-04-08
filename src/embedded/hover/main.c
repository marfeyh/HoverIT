/*
 * @ Module name:  main.c
 * @ Description:  Contains the functions that controls the hovering fan speed.
 *
 * @ Author names :Seyed Ehsan Mohajerani, Navid Amiriarshad
 * @ Release      :20 March 2012
 * @ Version      :1.0
 * @ Refrences    :Arduino.cc, http://www.sandklef.com
 * http://www.dreamincode.net/forums/topic/34861-functions-stored-in-structure/
 * Turnigy_Plush_and_Sentry_ESC user manual
 */

/* Includes */
#include <hovering_motor.h>
#include <hovering_control.h>
#include <hovering_init_fix.h>

// should'nt have prototype

/* Main method */
int main(void){
	initialize(USING_PIN);
	return 0;
}


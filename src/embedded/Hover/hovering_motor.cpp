/*
 * @ Module name:  hovering_motor.cpp
 * @ Description:  Contains the functions that
 *   control the hovering fan speed.
 *
 * @ Author names : Seyed Ehsan Mohajerani, Navid Amiriarshad
 * @ Release      : 20 March 2012
 * @ Version      : 1.0
 * @ References    : Arduino.cc, sandklef.com
 * dreamincode.net/forums/topic/34861-functions-stored-in-structure
 * Turnigy_Plush_and_Sentry_ESC user manual
 */

/* Includes */
#include "Arduino.h" /* Header for Arduino */ 
#include <searduino.h> /* Header for Searduino */
#include <hovering_motor.h>
#include <hovering_control.h>

/* Functions */

/* Function that gets arguments for start or stop the motor */
int hover_func(int (*func)(int),int using_pin){
	func(using_pin);
	return 0;
	}

/* Fucntion that gets arguments for change the speed of motor */
int hover_func(int (*climb_decesnd)(int,int), int using_pin, int level){
	climb_decesnd(using_pin, level);
	return 0;
}

/* Loop for motor */
int hover_loop(FUNCS funcs_in, int using_pin ,int throttle_stick_level){
	while(1){
		funcs_in.func1(funcs_in.level);
		funcs_in.func2(funcs_in.delay_time);
	}
	return 0;
}

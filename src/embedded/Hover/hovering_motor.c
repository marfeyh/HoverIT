/*
 * @ Module name:  hovering_motor.c
 * @ Description:  Contains the functions that start the hovering fan speed.
 *
 * @ Author names : Seyed Ehsan Mohajerani, Navid Amiriarshad
 * @ Release      : 20 March 2012
 * @ Version      : 1.0
 * @ Refrences    : Arduino.cc, sandklef.com
 * dreamincode.net/forums/topic/34861-functions-stored-in-structure
 * Turnigy_Plush_and_Sentry_ESC user manual
 */

/* Includes */
#include <Arduino.h> /* Header for Arduino */ 
#include <searduino.h> /* Header for Searduino */
#include <hovering_motor.h>
#include <hovering_control.h>
#include "searduino.h"

/* Functions */

/* Ardunio initiation */
int ard_init(int using_pin){
	/* Initialize the Arduino */
	init();
	/* Assign using pin to output */ 	
	pinMode(using_pin,OUTPUT);
	/* Test code */
	return 0;
}

/* Set the Arduino active pin for using */
int pin_program(int using_pin,int level) {	
	analogWrite(using_pin,level);
	return 0;
	/* Test code */
	#ifdef STUB
		printf("		Test analog write \n");
	#endif
	return 0;
}

/* Function that gets arguments for start or stop the motor */
int hover_func(int (*func)(int),int using_pin){
	/* Test code */
	#ifdef STUB
		printf("\n\n -- hover_func  %p  %d\n\n\n",func,using_pin);
	#endif
	func(using_pin);
	return 0;
	/* Test code */
	#ifdef STUB
		printf("		Test function OK\n");
	#endif
}

/* Fucntion that gets arguments for change the speed of motor */
int hover_change(int (*climb_decesnd)(int,int), int using_pin, int level){
	climb_decesnd(using_pin, level);
	return 0;
}

/* Loop for motor */
int hover_loop(FUNCS funcs_in, int using_pin ,int throttle_stick_level){
	while(1){
		funcs_in.func1(funcs_in.level);
		funcs_in.func2(funcs_in.delay_time);
		/* Test code */		
		#ifdef STUB
			printf("		Test Loop OK    L: %d\n",
			throttle_stick_level);
		#endif
	}
	return 0;
}

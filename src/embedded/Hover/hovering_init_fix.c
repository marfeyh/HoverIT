/*
 * @ Module name:  hovering_init_fix.c
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
#include <hovering_init_fix.h>
#include <print_audible_test.h>

/* Functions */

/* Initiations */
int initialize (int using_pin){
	ard_init (using_pin);
	hover_func (start,using_pin);	
	delay (1000);
	hover_func (normal,using_pin);	
	/*FUNCS funcs;
	funcs.func1=set_level;
	funcs.func2=delay;
	funcs.level=254;
	funcs.delay_time=1000;
	hover_loop(funcs);*/
	return 0;
}

/* Ardunio initiation */
int ard_init (int using_pin){
	/* Initialize the Arduino */
	init ();
	/* Assign using pin to output */ 	
	pinMode (using_pin,OUTPUT);
	return 0;
}

/* Set the Arduino active pin for using */
int pin_program(int using_pin,int level) {
	analogWrite(using_pin,level);
	/* Test code */
	test_analogwrite ();
	return 0;
}

/* This function prevents the motor from stop (Check boundary values)*/
int check_and_fix_level (int using_pin,int throttle_stick_level){
	if (throttle_stick_level < LOWEST_LEVEL){
		test_Too_low ();
		normal (using_pin);
	}
	if (throttle_stick_level > HIGHEST_LEVEL){
		test_Too_high ();		
		turbo (using_pin);
	}
	return 0;
}

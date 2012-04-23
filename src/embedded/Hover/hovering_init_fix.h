/*
 * @ Module name:  hovering_init_fix.h
 * @ Description:  Header file for the functions that 
 *   initiates the hovering fan
 *
 * @ Author names : Seyed Ehsan Mohajerani, Navid Amiriarshad
 * @ Release      : 20 March 2012
 * @ Version      : 1.0
 * @ References    : Arduino.cc, sandklef.com
 * dreamincode.net/forums/topic/34861-functions-stored-in-structure
 * Turnigy_Plush_and_Sentry_ESC user manual
 */

/* Make sure this header file is included one time */
#if !defined HOVERING_INIT_FIX_H
	#define HOVERING_INIT_FIX_H
	
	/* Defines */
	#define HIGHEST_LEVEL 254
	#define LOWEST_LEVEL 143
	#define STOP_LEVEL 120
	
	/* Function prototype */
	
	/* Arduino and motor initiation */
	int initialize(int using_pin);
	/* This function prevents the motor from stop
	 (Check boundary values)*/
	int check_and_fix_level(int using_pin, int throttle_stick_level);
	/* Set the Arduino active pin for using */	
	int pin_program(int using_pin, int level);
	
	#endif

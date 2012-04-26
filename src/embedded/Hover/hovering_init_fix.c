/*
 * @ Module name:  hovering_init_fix.c
 * @ Description:  Contains the functions that start the hovering fan speed.
 *
 * @ Author names : Seyed Ehsan Mohajerani, Navid Amiriarshad
 * @ Release      : 20 March 2012
 * @ Version      : 1.0
 * @ References    : Arduino.cc, sandklef.com
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

/* 	Setting using_pin and test pin and start the motor */
int initialize (int using_pin, int test_pin){
	pinMode (test_pin, OUTPUT);
	pinMode (using_pin, OUTPUT);
	hover_func (start, using_pin, test_pin);
	delay (1000);
	return 0;
}

/* Set the Arduino active pin for using */
int pin_program (int using_pin, int test_pin, int level) {
	analogWrite (using_pin, level);
	/* Test code */
	test_analogwrite (test_pin);
	return 0;
}


/* This function prevents the motor from stop (Check boundary values) */
int check_and_fix_level (int using_pin,int test_pin, \
int throttle_stick_level){
	if (throttle_stick_level < LOWEST_LEVEL){
		test_Too_low (test_pin);
		normal (using_pin, test_pin);
	}
	if (throttle_stick_level > HIGHEST_LEVEL){
		test_Too_high (test_pin);		
		turbo (using_pin, test_pin);
	}
	return 0;
}

/* This function prevents the motor from stop (Check boundary values)
and also prevent increase to function when the motor is stopped */
int check_and_fix_level_increase (int using_pin, int test_pin, \
int throttle_stick_level, int level){
	//if (throttle_stick_level < LOWEST_LEVEL){
	//	test_Too_low (test_pin);
	//	return throttle_stick_level;
//	}else 
	if (throttle_stick_level > HIGHEST_LEVEL){
			test_Too_high (test_pin);		
			turbo (using_pin, test_pin);
			return throttle_stick_level;	
	}else {
		return throttle_stick_level + level;}
}


/* This function prevents the motor from stop (Check boundary values)
and also prevent decrease to function when the motor is stopped */
int check_and_fix_level_decrease (int using_pin,int test_pin, \
int throttle_stick_level,int level){
	/* If the motor is stopped then nothing should be done */
	if (throttle_stick_level < LOWEST_LEVEL){		
		test_Too_low (test_pin);
		return throttle_stick_level;
	}
	return throttle_stick_level - level;
}

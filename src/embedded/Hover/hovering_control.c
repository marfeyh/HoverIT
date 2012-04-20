/*
 * @ Module name:  hovering_control.c
 * @ Description:  Contains the functions that control
 *   the hovering fan speed.
 *
 * @ Author names : Seyed Ehsan Mohajerani, Navid Amiriarshad
 * @ Release      : 20 March 2012
 * @ Version      : 1.0
 * @ Refrences    : Arduino.cc, sandklef.com
 * dreamincode.net/forums/topic/34861-functions-stored-in-structure
 * Turnigy_Plush_and_Sentry_ESC user manual
 */

/* Includes */
#include "Arduino.h" /* Arduino header */
#include <hovering_motor.h>
#include <hovering_control.h>
#include <hovering_init_fix.h>
#include <print_audible_test.h>

/* Definition */
/* The minimum PWM value that is possible to send to ESC from Arduino pin 
   and it is for initiating the motor */
#define THROTTLE_STICK_BOTTOM_LEVEL 100

/* Variable */
/* The PWM value which is sent to ESC from Arduino and represents the motor 
rotating power it can be between 143 (for lowest rotating speed) and 254
(for the highest rotating speed */
int throttle_stick_level = 0;

/* Functions */	

/* Start the motor */
int start(int using_pin){
	/* Set the throttle stick is in the buttom position if the motor
	   has not been started */
	if (throttle_stick_level < THROTTLE_STICK_BOTTOM_LEVEL){
		throttle_stick_bottom(using_pin);
	}
	/* Test code */
	test_start ();
	return 0;
}

/* Set the output signal to minimum acceptable for ESC */
int throttle_stick_bottom (int using_pin){
	pin_program(using_pin, THROTTLE_STICK_BOTTOM_LEVEL);
	delay(1000);
	/* Test code */
	test_throttle_Stick_is_bottom ();
	return 0;
}

/* Set the motor to lowest rotating speed */
int normal (int using_pin){
	throttle_stick_level = LOWEST_LEVEL;
	pin_program(using_pin,throttle_stick_level);
	/* Test code */
	test_normal ();	
	return 0;
}

/* Set the motor to highest rotating speed */
int turbo (int using_pin){
	throttle_stick_level = HIGHEST_LEVEL;
	pin_program(using_pin, throttle_stick_level);
	/* Test code */
	test_turbo ();	
	return 0;
}

/* stop the motor */
int stop (int using_pin){
	throttle_stick_level = STOP_LEVEL;
	pin_program(using_pin, throttle_stick_level);
	/* Test code */
	test_stop ();
	return 0;
}

/* Increase the motor rotating speed level times */
int increase (int using_pin, int level){
	throttle_stick_level += level;
	check_and_fix_level(using_pin, throttle_stick_level);
	pin_program(using_pin, throttle_stick_level);
	/* Test code */
	test_increase (throttle_stick_level);
	return 0;
}

/* decrease the motor rotating speed level times */
int decrease (int using_pin, int level){
	throttle_stick_level -= level;
	check_and_fix_level(using_pin, throttle_stick_level);
	pin_program(using_pin, throttle_stick_level);
	/* Test code */
	test_decrease (throttle_stick_level);
	return 0;
}

/* set the motor rotating speed to specified level */
int set_level (int using_pin, int level){
	throttle_stick_level = level;
	check_and_fix_level(using_pin, throttle_stick_level);
	pin_program(using_pin, throttle_stick_level);
	/* Test code */
	test_set_level (throttle_stick_level);
	return 0;
}

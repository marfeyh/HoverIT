/*
 * @ Module name:  hoveing_control.h
 * @ Description:  Header file for the functions that control the hovering
 * 		   fan speed.
 *
 * @ Author names : Seyed Ehsan Mohajerani, Navid Amiriarshad
 * @ Release      : 20 March 2012
 * @ Version      : 1.0
 * @ Refrences    : Arduino.cc, sandklef.com
 * dreamincode.net/forums/topic/34861-functions-stored-in-structure
 * Turnigy_Plush_and_Sentry_ESC user manual
 */

/* Make sure this header file is included one time */
#ifndef HOVERING_CONTROL_H
	#define HOVERING_CONTROL_H

	/* Defines */
	#define HIGHEST_LEVEL 254
	#define LOWEST_LEVEL 133
	#define STOP_LEVEL 120

	/* Function protoypes */

	/* Start the hovering motor*/
	int start(int using_pin);
	/* Set the throttle stick
	 is in the buttom position if the motor has not been started */
	int throttle_stick_bottom(int using_pin);
	/* Set the motor to lowest rotating speed */
	int normal(int using_pin);
	/* Set the motor to highest rotating speed */
	int turbo(int using_pin);
	/* stop the motor */
	int stop(int using_pin);
	/* set the motor rotating speed to specified level */
	int set_level(int using_pin, int level);
	/* Increase the motor rotating speed level times */
	int increase(int using_pin, int level);
	/* decrease the motor rotating speed level times */
	int decrease(int using_pin, int level);

	#endif

/* 
 * @ Module name:  hovering_motor.h
 * @ Description:  Header file for controlling hovering motor by
 *                 hovering_motor.c hover_api.c
 *
 * @ Author names : Seyed Ehsan Mohajerani, Navid Amiriarshad
 * @ Release      : 20 March 2012
 * @ Version      : 1.0
 * @ Refrences    : Arduino.cc, sandklef.com
 * dreamincode.net/forums/topic/34861-functions-stored-in-structure
 * Turnigy_Plush_and_Sentry_ESC user manual
 */

#define BLINK_PIN 11
#define BLINKER(delay_time) { int i; pinMode(BLINK_PIN,OUTPUT); digitalWrite(BLINK_PIN,HIGH);delay(delay_time);digitalWrite(BLINK_PIN,LOW);delay(delay_time);}

/* Make sure this header file is included one time */
#ifndef HOVERING_MOTOR_H
	#define HOVERING_MOTOR_H
	
	/* Struct to be used in hover_loop */
	typedef struct {
		int (*func1)(int);
		void (*func2)(long unsigned int);
		int level;
		int delay_time;
	} FUNCS;

	/* Function prototypes */
	
	/* Function that gets arguments for start or stop the motor */
	int hover_func(int (*func)(int), int using_pin);
	/* Fucntion that gets arguments for change the speed of motor */	
	int hover_change(int (*climb_decesnd)(int,int),
	int using_pin, int level);
	/* Loop for motor */
	int hover_loop(FUNCS funcs_in, int using_pin,
	 int throttle_stick_level);

	#endif

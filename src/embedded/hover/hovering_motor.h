/* 
 * @ Module name:  hovering_motor.h
 * @ Description:  Header file for controlling hovering motor by
 *                 hovering_motor.c hover_api.c pressure_loop.c
 *
 * @ Author names :Seyed Ehsan Mohajerani, Navid Amiriarshad
 * @ Release      :20 March 2012
 * @ Version      :1.0
 * @ Refrences    :Arduino.cc, http://www.sandklef.com
 * http://www.dreamincode.net/forums/topic/34861-functions-stored-in-structure/
 * Turnigy_Plush_and_Sentry_ESC user manual
 */

#ifndef HOVERING_MOTOR_H
#define HOVERING_MOTOR_H

/* Includes */  
#include <Arduino.h>
#include <searduino.h>

/* Struct to be used in hover_loop */
typedef struct {
	int (*func1)(int);
	void (*func2)(long unsigned int);
	int level;
	int delay_time;
} FUNCS;
/* Function prototypes */
int ard_init(int using_pin);
int hover_func(int (*func)(int), int using_pin);
int hover_change(int (*climb_decesnd)(int,int), int using_pin, int level);
int hover_loop(FUNCS funcs_in, int using_pin, int throttle_stick_level);
int pin_program(int using_pin, int level);

#endif

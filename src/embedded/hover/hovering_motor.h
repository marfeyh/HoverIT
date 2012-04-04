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
 */

#ifndef HOVERING_MOTOR_H
#define HOVERING_MOTOR_H

/* Includes */
#include <Arduino.h>
#include <searduino.h>

/* Definition */

#define throttle_stick_bottom_level 100

/* Struct to be used in hover_loop */
typedef struct {
	int (*func1)(int);
	void (*func2)(long unsigned int);
	int level;
	int delay_time;
} FUNCS;

/* Variables */
int throttle_stick_level;
int using_pin;
boolean loop_need;
boolean start_check;

/* Function prototypes */
int ard_init(int using_pin);
int hover_func(int (*func)(void));
int hover_change(int (*climb_decesnd)(int),int level);
int hover_loop(FUNCS funcs_in);
int pin_program(int level);
int check_and_fix_level(void);
int check_loop_need(void);

#endif

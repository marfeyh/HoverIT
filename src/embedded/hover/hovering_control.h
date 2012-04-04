/*
 * @ Module name:  hovering_control.c
 * @ Description:  Header file for the functions that control the hovering
 * 		   fan speed.
 *
 * @ Author names :Seyed Ehsan Mohajerani, Navid Amiriarshad
 * @ Release      :20 March 2012
 * @ Version      :1.0
 * @ Refrences    :Arduino.cc, http://www.sandklef.com
 * http://www.dreamincode.net/forums/topic/34861-functions-stored-in-structure/
 */
/*
#ifndef HOVERING_MOTOR_H
#define HOVERING_MOTOR_H
*/
int initialize(void);
int start(void);
int throttle_stick_bottom(void);
int normal(void);
int turbo(void);
int stop(void);
int set_level(int level);
int increase(int level);
int decrease(int level);

//#endif

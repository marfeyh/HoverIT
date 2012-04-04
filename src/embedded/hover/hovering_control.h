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
int initialize(int using_pin);
int start(int using_pin);
int throttle_stick_bottom(int using_pin);
int normal(int using_pin);
int turbo(int using_pin);
int stop(int using_pin);
int set_level(int using_pin, int level);
int increase(int using_pin, int level);
int decrease(int using_pin, int level);

//#endif

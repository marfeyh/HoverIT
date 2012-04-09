/*
 * @ Module name:  hoveing_control.h
 * @ Description:  Header file for the functions that control the hovering
 * 		   fan speed.
 *
 * @ Author names :Seyed Ehsan Mohajerani, Navid Amiriarshad
 * @ Release      :20 March 2012
 * @ Version      :1.0
 * @ Refrences    :Arduino.cc, http://www.sandklef.com
 * http://www.dreamincode.net/forums/topic/34861-functions-stored-in-structure/
 * Turnigy_Plush_and_Sentry_ESC user manual
 */

#ifndef HOVERING_CONTROL_H
#define HOVERING_CONTROL_H

/* Defines */
#define HIGHEST_LEVEL 254
#define LOWEST_LEVEL 133
#define STOP_LEVEL 120
#define USING_PIN 11

/* Function protoypes */
int initialize(int using_pin);
int start(int using_pin);
int throttle_stick_bottom(int using_pin);
int normal(int using_pin);
int turbo(int using_pin);
int stop(int using_pin);
int set_level(int using_pin, int level);
int increase(int using_pin, int level);
int decrease(int using_pin, int level);
int check_and_fix_level(int using_pin, int throttle_stick_level);

#endif

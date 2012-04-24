/*
 * @ Module name  :batteryLevel.h
 * @ Description  :Header file for batteryLevel.c
 * @ Author names :Nahid Vafaie,Kuhan Loh, Aran Gerami, Denir Leric
 * @ Release      :24 April 2012
 * @ Version      :3
 * @ Refrences    : Arduino.cc, sandklef.com
 */

#ifndef BATTERY_LEVEL_H
#define BATTERY_LEVEL_H
#define ledPin1 2
#define ledPin2  4
#define ledPin3  7
#define ledPin4  8
#define timer1  500



void init_leds(void);
void run_leds(void);
void check(void);

#endif

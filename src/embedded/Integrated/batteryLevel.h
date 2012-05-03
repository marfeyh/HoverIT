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
#define SENSOR_PIN 5

uint8_t check(void);
uint8_t get_sensor_value(void);
int init_battery_check(void);

#endif

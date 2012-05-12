/*
 * @ Module name  :percentage.h
 * @ Description  :Header file for percentage.c
 * @ Author names :Denir Leric
 * @ Release      :04 May 2012
 * @ Version      :1
 * @ Refrences    :Arduino.cc, sandklef.com
 */

#ifndef PERCENTAGE_H
#define PERCENTAGE_H

/*
 * These pins stands for the analog pins where all the batteries are connected
 */
#define BATTERY_PIN1 1
#define BATTERY_PIN2 2
#define BATTERY_PIN3 3

int getPercentage(int);
int getFirstBatteryLevel(void);
int getSecondBatteryLevel(void);
int getThirdBatteryLevel(void);

#endif

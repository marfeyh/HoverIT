/*
 * @ Module name:  batteryMeter.c
 * @ Description:  the API of the battery meter
 * @ Author names : Bruce Yinhe
 * @ Release      : 26 April 2012
 * @ Version      : 2
 * @ Refrences    : 
 */

#include <Arduino.h>
#include <searduino.h>
#include "batteryLevel.h"
#include "alarm.h"
#include "fourLedsOn.h"

int init_battery_meter() {
    /* init the leds */
    init_leds();
    /* init the alarm*/
    init_alarm();
    return 1;
}

int setup_battery_meter() {
    /* get the percentage from the battery*/
    uint8_t percentage = check();
    /* send the percentage to the alarm */
    setup_alarm(percentage);
    /* send the percentage to the leds*/
    display_percentage(percentage);
    
    return 1;
}



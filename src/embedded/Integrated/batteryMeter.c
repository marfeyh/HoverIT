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

int currentButton = LOW;
int lastButton = LOW;
int percentage = 0;

int init_battery_meter() {
   // pinMode(0, INPUT);
    
    /*init the battery check pin*/
    init_battery_check();
    /* init the leds */
    init_leds();
    /* init the alarm*/
    init_alarm();
    return 0;
}


// Denir changed this method to be able to applicable in real world
int setup_battery_meter() {
  /*  currentButton = digitalRead(13);

    if (lastButton == LOW && currentButton == HIGH)
        percentage += 5;
    
    lastButton = currentButton;
    
    if (percentage > 100)
        percentage = 0;*/
    
    
//    /* get the percentage from the battery*/
     uint8_t percentage = check();
    /* send the percentage to the alarm */
    setup_alarm(percentage);
    /* send the percentage to the leds*/
    display_percentage(percentage);
    
    return percentage;
}



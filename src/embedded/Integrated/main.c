/*
 * @ Module name:  main.c
 * @ Description:  a simple control loop
 * @ Author names : Bruce Yinhe
 * @ Release      : 25 April 2012
 * @ Version      : 1
 * @ Refrences    : 
 */

#include <Arduino.h>
#include <searduino.h>
#include "batteryLevel.h"
#include "alarm.h"
#include "fourLedsOn.h"

int main(void)
{
    /* arduino init */
    init();
    /* init the leds */
    init_leds();
    /* init the alarm*/
    init_alarm();    

    /* enter the simple control loop*/
    for(;;){
        /* get the percentage from the battery*/
        uint8_t percentage = check();
        /* send the percentage to the alarm */
        setup_alarm(percentage);
        /* send the percentage to the leds*/
        display_percentage(percentage);
        /* delay 0.1 s */
        delay(100);
    }
}

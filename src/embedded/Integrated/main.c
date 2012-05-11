/*
 * @ Module name:  main.c
 * @ Description:  a simple control loop that stubs the scheduler
 * @ Author names : Bruce Yinhe
 * @ Release      : 26 April 2012
 * @ Version      : 1
 * @ Refrences    : 
 */

#include <Arduino.h>
#include <searduino.h>
#include "batteryMeter.h"

int main(void) {
    /* arduino init */
    init();
    /* init all */
    init_battery_meter();
    
    /* enter the simple control loop, this will be the scheduler*/
    for(;;){
        int percentage = setup_battery_meter();
//        printf("\nPercentage: %d\n", percentage);
    }
}
/*
 * @ Module name:  main.c
 * @ Description:  main file to run functions in fourLedson.c
 * @ Author names :Nahid Vafaie, Kuhan Loh, Aran Gerami, Denir Leric
 * @ Release      :13 April 2012
 * @ Version      : 3
 * @ Refrences    : Arduino.cc, sandklef.com
 */

#include <Arduino.h>
#include <searduino.h>
#include "batteryLevel.h"
#include "alarm.h"
#include "fourLedsOn.h"

int main(void)
{
    init();
    init_leds();
    init_alarm();    

    for(;;){
        uint8_t percentage = check();
        setup_alarm(percentage);
        display_percentage(percentage);
        delay(100);
    }
}

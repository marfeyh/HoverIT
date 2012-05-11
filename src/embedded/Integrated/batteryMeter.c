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
   // pinMode(0, INPUT);
    
    /* init the leds */
    init_leds();
    /* init the alarm*/
    init_alarm();
    return 0;
}

uint8_t translateLevel(uint16_t percentage) {
    if (percentage == 0) {
        return 0x0;
    } else if (percentage < 7) {
        return 0x1;
    } else if (percentage < 14){
        return 0x2;
    } else if (percentage < 20){
        return 0x3;
    } else if (percentage < 27){
        return 0x4;
    } else if (percentage < 34){
        return 0x5;
    } else if (percentage < 40){
        return 0x6;
    } else if (percentage < 47){
        return 0x7;
    } else if (percentage < 53){
        return 0x8;
    } else if (percentage < 60){
        return 0x9;
    } else if (percentage < 67){
        return 0xA;
    } else if (percentage < 73){
        return 0xB;
    } else if (percentage < 80){
        return 0xC;
    } else if (percentage < 86){
        return 0xD;
    } else if (percentage < 93){
        return 0xE;
    } else if (percentage <= 100){
        return 0xF;
    }
}

uint16_t makeMsg(percentage) {
    uint16_t msg = 0x50 + translateLevel(percentage);
    return msg;
}

uint16_t setup_battery_meter() {    
    /* get the percentage from the battery*/
    uint16_t percentage = check();
//    printf(" ahaper: %d ", percentage);

    /* send the percentage to the alarm */
    setup_alarm(percentage);
    /* send the percentage to the leds*/
    display_percentage(percentage);
    
    uint16_t binMsg = makeMsg(percentage);
    
    return binMsg;
}







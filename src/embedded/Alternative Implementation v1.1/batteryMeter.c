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
//#include "batteryLevel.h"
#include "batteryMeter.h"
#include "percentage.h"
#include "alarm.h"
#include "fourLedsOn.h"

int init_battery_meter() {    
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

uint16_t get_battery_meter() {    
    /* get the percentage from the battery*/
//    uint16_t percentage = check(); //old

    uint16_t percentage1 = getPercentage(FIRST_BATTERY);
    uint16_t percentage2 = getPercentage(SECOND_BATTERY);
    uint16_t percentage3 = getPercentage(THIRD_BATTERY);
    
    /* send the percentage to the alarm */
    //TODO, two new batteries added 
    setup_alarm(percentage1);
    /* send the percentage to the leds*/
    //TODO, two new batteries added 
    display_percentage(percentage1);
    
    /* the new bin msg protocol needs to be negotiated with Scheduler*/
    //TODO
    uint16_t binMsg1 = makeMsg(percentage1);
//    uint16_t binMsg2 = makeMsg(percentage2);
//    uint16_t binMsg3 = makeMsg(percentage3);
    
    return binMsg1;
}







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

/*
 * initialize all 
 */
int init_battery_meter() {    
    /* init the leds */
    init_leds();
    /* init the alarm*/
    init_alarm();
    return 0;
}

/*
 * The battery level goes from level 1(0x0) to 16(0xE). This function taks input of 0 - 100, and gives output of a binary message
 */
uint8_t translate_level(uint16_t percentage) {
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

/*
 * This function takes the battery number and percentage as input, and returns a binary message according to the protocol as output
 */
uint8_t make_msg(batteryNumber, percentage) {
    uint8_t msg = 0;
    switch (batteryNumber) {
        case 1:
            msg = FIRST_BATTERY_ID + translate_level(percentage);
            break;
        case 2:
            msg = SECOND_BATTERY_ID + translate_level(percentage);
            break;
        case 3:
            msg = THIRD_BATTERY_ID + translate_level(percentage);
            break;
        default:
            break;
    }    
    return msg;
}

/*
 * This functions will be called by the Scheduler. It takes the battery number as input, and returns a binary message as output
 */
uint8_t get_battery_level(int batteryNumber) {    
    /* get the percentage from the battery*/
//    uint16_t percentage = check(); //old code

    uint16_t percentage = getPercentage(batteryNumber);
    
    /* send the percentage to the alarm */
    //TODO, two new batteries added 
    setup_alarm(percentage);
    /* send the percentage to the leds*/
    //TODO, two new batteries added 
    display_percentage(percentage);
    
    /* the new bin msg protocol needs to be negotiated with Scheduler*/
    //TODO
    uint8_t binMsg = make_msg(batteryNumber, percentage);
    
    return binMsg;
}







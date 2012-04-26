/*
 * @ Module name : batteryMeter.c
 * @ Description :  
 * @ Author names: Bruce Yinhe
 * @ Release     : 17 April 2012
 * @ Version     : 1
 * @ Refrences   : 
 */

#include <stdio.h>
#include "../LedsOn/src/fourLedsOn.h"

int batteryPerc; /* from 0x0 to 0xF */
int* ptrPerc;
int batteryLow; /* 0x0 or 0x1 */
int* ptrLow;

void setPercentage(int i) {
    *ptrPerc = i;
}

int getPercentage() {
    return *ptrPerc;
}

int getBatteryLevel() {
    if (*ptrPerc == 0) {
        return 0x0;
    } else if (*ptrPerc < 7) {
        return 0x1;
    } else if (*ptrPerc < 14){
        return 0x2;
    } else if (*ptrPerc < 20){
        return 0x3;
    } else if (*ptrPerc < 27){
        return 0x4;
    } else if (*ptrPerc < 34){
        return 0x5;
    } else if (*ptrPerc < 40){
        return 0x6;
    } else if (*ptrPerc < 47){
        return 0x7;
    } else if (*ptrPerc < 53){
        return 0x8;
    } else if (*ptrPerc < 60){
        return 0x9;
    } else if (*ptrPerc < 67){
        return 0xA;
    } else if (*ptrPerc < 73){
        return 0xB;
    } else if (*ptrPerc < 80){
        return 0xC;
    } else if (*ptrPerc < 86){
        return 0xD;
    } else if (*ptrPerc < 93){
        return 0xE;
    } else if (*ptrPerc <= 100){
        return 0xF;
    }
}

void setBatteryLow (int b) {
    *ptrLow = b;
}

int getBatteryLow () {
    return *ptrLow;
}

void init() {
    ptrPerc = &batteryPerc;
    ptrLow = &batteryLow;
}

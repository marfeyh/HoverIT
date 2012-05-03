/*
 * @ Module name:  batteryLevel.c
 * @ Description:  Contains the functions that reads the voltage of the battery and
 *                  turns on four leds to show how much battery left
 * @ Author names :Kuhan Loh, Aran Gerami, Denir Leric
 * @ Release      :24 April 2012
 * @ Version      :4
 * @ Refrences    : Arduino.cc, sandklef.com
 */



#include <Arduino.h>
#include <searduino.h>
#include "batteryLevel.h"


// This function reads from the analog pin and stores a value between 0-1023
uint8_t get_sensor_value() {
    uint8_t SENSOR_VALUE = analogRead(SENSOR_PIN);
//    uint8_t SENSOR_VALUE = 200;
    return SENSOR_VALUE;
}
// This function is run in main and returns the sensor_value that we read in get_sensor_value() function.
uint8_t check() {

//		const static uint8_t SENSOR_PIN = 19;
    uint8_t SENSOR_VALUE = 0;

    /* value from 0 to 1023 */
    SENSOR_VALUE = get_sensor_value(); 
    return (SENSOR_VALUE / 2.56);
//		  if (SENSOR_VALUE >  0 && SENSOR_VALUE < 204.7){
//              return 20;
//              //1Volt Remaining
//		  } else if (SENSOR_VALUE >  204.6 && SENSOR_VALUE < 409.3){
//              return 40;
//              //2Volts Remaining
//		  } else if (SENSOR_VALUE >  409.2 && SENSOR_VALUE < 613.9){
//              return 60;
//              //3Volts Remaining
//		  } else if (SENSOR_VALUE >  613.8 && SENSOR_VALUE < 818.5){
//              return 80;
//              //4Volts Remaining
//		  } else if (SENSOR_VALUE > 818.4){
//              return 100;
//              //5Volts remaining
//		  }
//
//	return 0;
}



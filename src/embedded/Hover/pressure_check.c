/* 
@file pressure_check.c
@headerfile pressure_check.h
@author Eva-Lisa Kedborn
@author Jing Liu
@date: 2012-03-20
@details continuously read air pressure inside the hovercraft
         skirt and adjust the speed of the hovering fan accordingly
@version 0.1
*/

#include <stdio.h>
#include "pressure.h"   /* file from pressure sensor group */
//#include <hovering_motor.h>    /* file from our own group */
#include "pressure_check.h"
#define PROPER_GAP 50
#define MAX_GAP_RANGE 60
#define MIN_GAP_RANGE 40


/*!
@brief Function to get pressure data from the pressure sensor
@param takes no parameters
@returns integer 0 if successful
*/
int start_sensor_reading() {
    handle_pressure(get_pressure());
    return 0;
}

/*!
@brief Function to evaluate the pressure data
@param the pressure difference inside and outside the skirt
@returns integer 1 if the pressure should be increased,
         interger -1 if the pressure should be decreased,
	 integer 0 if no adjustment needs to be made
*/
int handle_pressure(int gap){
  
  if(gap > MAX_GAP_RANGE){
    // increase(10);   /* function from hovering_motor.c to increase fan speed */
    return 1;
  }
 
  if(gap < MIN_GAP_RANGE){
    // decrease(10);   /* function from hovering_motor.c to decrease fan speed */
    return -1;
  }
  return 0;
}


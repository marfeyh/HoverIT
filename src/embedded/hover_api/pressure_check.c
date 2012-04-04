/* 
Author: Eva-Lisa Kedborn, Jing Liu
Date: 2012-03-20
Description: Loop to continuously read air pressure inside the hovercraft
             skirt and adjust the speed of the hovering fan accordingly
*/

#include <stdio.h>
#include <pressure_sensor.h>   /* file from pressure sensor group */
#include <hovering_motor.h>    /* file from our own group */
#include <pressure_loop.h>
#define PROPER_GAP 50
#define MAX_GAP_RANGE 60
#define MIN_GAP_RANGE 40

int start_sensor_reading(){
    handle_pressure(get_pressure());
    return 0;
}

int handle_pressure(float gap){
  
  if(gap > MAX_GAP_RANGE){
    increase(10);   /* function from hovering_motor.c to increase fan speed */
    return 1;
  }
 
  if(gap < MIN_GAP_RANGE){
    decrease(10);   /* function from hovering_motor.c to decrease fan speed */
    return -1;
  }
  return 0;
}


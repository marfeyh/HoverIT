/* 
Author: Eva-Lisa Kedborn, Jing Liu
Date: 2012-03-20
Description: Loop to continuously read air pressure inside the hovercraft
             skirt and adjust the speed of the hovering fan accordingly
*/

#include <stdio.h>
#include "pressure_sensor.h"   /* file from pressure sensor group */
#include "hovering_motor.h"        /* file from our own group */
#include "pressure_loop.h"
#define PROPER_PRESSURE 50.1
#define MAX_GAP_RANGE 10
#define MIN_GAP_RANGE -10

int loop(){
  while(1){                    /* forever loop */
    handle_pressure(get_gap());
    sleep(1);                  /* check every one second */
  }
  return 0;
}

float get_gap(){
  float pressure;              /* the real air pressure in cushion */
  float gap;                   /* difference between real pressure and
				  preferred pressure */
  float proper_p;              /* the preferred pressure */           
  
  pressure = get_pressure();
  if(pressure == 0){           /* if the sensor is not working it returns 0 */
     return 0;
  }
  proper_p = PROPER_PRESSURE;
  gap = proper_p - pressure;    
  
  return gap;
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


/******************************************
 * Embedded project - Determining Speed
 * Calculating the speed of the object
 *
 * Copyright (c) Whatever, no warranty.
 *
 * Author: Nena Stojova
 * Date: 3/20/12
 * Edited by: Sorush Arefipour on 4/11/12
 * Integrator: Sorush Arefipour
 * Edited by: Viktor Green on 2012-04-19
 ******************************************/

#include <stdlib.h>
#include "calculateSpeed.h"
#include "bma180.h"

Speed* create_speed(void) {
  
  Speed* struct_adress;
  struct_adress = (Speed*) malloc (sizeof (Speed));
  if(NULL == struct_adress) {
    /* Error */
    return NULL;
  }

  bma_initialize();

  struct_adress -> bias = calcXBias();
  struct_adress -> speed = 0;
  struct_adress -> time = millis();
}

void calculate_speed(Speed* st_speed){
	
  unsigned long deltaTime;
  unsigned long time;

  time = millis();
  deltaTime = time - st_speed->time;
  
  st_speed->speed += getXAccel(st_speed->bias) * deltaTime;
  st_speed->time = time;

} 

int get_speed(Speed* st_speed){

return st_speed->speed;

}

int get_time(Speed* st_speed){

return st_speed->time;

}

void speed_free (Speed* st_speed)
{
  free (st_speed);
}








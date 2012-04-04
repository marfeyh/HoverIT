/*
Author: Xinran He, Khatereh Khosravianarab
Date: 2012-03-26
Description: test functions for propulsion api
*/

#include <propulsion.h>
#include <stdio.h>

/* get speed level and return speed level */
int getSpeedLevel(){
  int spLevel=0;
  spLevel = level;
  printf("getSPeedLEvel = %d\n", spLevel);
  return spLevel;
  
}

/* stop propulsion fan*/
int stop_pro_fan(){
  level = 0;
  printf("Stop = 0\n",level);
  return level;
}

/* set propulsion fan speed */
void change_pro_speed(int change_level){
  level = change_level;
  printf("change_pro_speed= %d\n", level);
}

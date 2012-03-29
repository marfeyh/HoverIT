#include <stdio.h>
#include "../src/propelsion.h"

#define LEVEL 41
#define MAXSPEED 122

int increase_speed(){
  int speedLevel = getSpeedLevel();
  if(speedLevel >= MAXSPEED - 3){
    change_pro_speed(MAXSPEED);
  }
  if( speedLevel < 119){
    change_pro_speed(speedLevel + LEVEL);
  }
  return speedLevel+LEVEL;
}

int decrease_speed(){
  int speedLevel = getSpeedLevel();
  if(speedLevel <= 3){
    stop_pro_fan();
  }
  else{
    change_pro_speed(speedLevel - LEVEL);
  }
  return speedLevel - LEVEL;
}

int stop_speed(){
  stop_pro_fan();
}

int get_fan_level(){
  int newprospeed;
  newprospeed = getSpeedLevel();
  
  return newprospeed;
}

int get_hav_speed(){

}


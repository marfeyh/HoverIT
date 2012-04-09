/*
Author: Xinran He, Khatereh Khosravianarab
Date: 2012-03-25
Description: control fan speed api
*/

#include <propulsion.h>
#include <propulsion_api.h>

int start_propulsion_fan()
{
  initialise_propulsion();
  init_motor();
  return 0;
}
/* increase propulsion fan speed */
int increase_propulsion(){
  int speed = getSpeedLevel();
  if(speed >= MAXSPEED - 3){
    change_pro_speed(PERSPEED*3);
     return PERSPEED*3;
  }
  else if( speed < MAXSPEED){
    change_pro_speed(speed + PERSPEED);
     return speed+PERSPEED;
  }
  return -1;
}

/* decrease propulsion fan speed */
int decrease_propulsion(){
  int speed = getSpeedLevel();
  if(speed <= 0){
    stop_pro_fan();
    return 0;
  }
  else if(speed > 0){
    change_pro_speed(speed - PERSPEED);
    return speed - PERSPEED;
  }
  return -1;
}

/* stop propulsion fan speed*/
int stop_propulsion_fan(){
  stop_pro_fan();
  return 0;
}

/* specify the propulsion fan level*/
int get_propulsion_level(){
  int speed = getSpeedLevel();
  if(speed == 0){
    //printf("get_fan_level() ========= 0\n");
    return 0;
  }
  else if(speed > 0 && speed <= PERSPEED){
    //printf("get_fan_level() ========= 1\n");
    return 1;
  }
  else if(speed > PERSPEED && speed <= PERSPEED * 2){
    //printf("get_fan_level() ========= 2\n");
    return 2;
  }
  else if(speed >PERSPEED *2 ){
    //printf("get_fan_level() ========= 3\n");
    return 3;
  }
  return -1;
}



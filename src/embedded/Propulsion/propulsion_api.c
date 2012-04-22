/*
  @AUTHOR - Xinran He, Khatereh Khosravianarab
  @Description: This file is the propulsion fan speed API and use        		propulsion file to stop,increase or decrease the speed.
  @ Version : 2.0
  @Date : 2012-03-25
*/

#include <propulsion.h>
#include <propulsion_api.h>

//initialise propulsion fan speed
int start_propulsion_fan(){
  initialise_propulsion();
  init_motor();
  return 0;
}
/* increase propulsion fan speed */
int increase_propulsion(){
  int fan_speed = get_speed_level();
  if( fan_speed >= MAXSPEED - 3 ){
    change_pro_speed(PERSPEED * 3);
    return PERSPEED * 3;
  }
  else if( fan_speed < MAXSPEED ){
    change_pro_speed(fan_speed + PERSPEED);
    return fan_speed + PERSPEED;
  }
  return -1;
}

/* decrease propulsion fan speed */
int decrease_propulsion(){
  int fan_speed = get_speed_level();
  if( fan_speed <= 0 ){
    stop_pro_fan();
    return 0;
  }
  else if( fan_speed > 0 ){
    change_pro_speed(fan_speed - PERSPEED);
    return fan_speed - PERSPEED;
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
  int fan_speed = get_speed_level();
  if( fan_speed == 0 ){
    return 0;
  }
  else if( fan_speed > 0 && fan_speed <= PERSPEED ){
    return 1;
  }
  else if( fan_speed > PERSPEED && fan_speed <= PERSPEED * 2 ){
    return 2;
  }
  else if( fan_speed > PERSPEED * 2 ){
    return 3;
  }
  return -1;
}



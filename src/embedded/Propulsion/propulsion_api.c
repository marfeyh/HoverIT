/** 
* @file propulsion_api.c 
* @headerfile propulsion.h
* @headerfile propulsion_api.h
* @Description: This file is the propulsion fan speed API 
                and use propulsion file to stop,increase or decrease the speed. 
* @author Xinran He, Khatereh Khosravianarab
* @version 0.6
* @date 2012-03-25
*/

/*	
 * ======================================================================
 * API functions
 * ======================================================================
 */

#include <propulsion.h>
#include <propulsion_api.h>


/**
 * @brief initialise propulsion fan
 */
int start_propulsion_fan()
{
  initialise_propulsion();
  init_motor();
  return 0;
}

/**
 * @brief increase propulsion fan speed
 */
int increase_propulsion(){
  int speed = get_speed_level();
  if( speed >= MAXSPEED - 3 ){
    change_pro_speed(PERSPEED*3);
    return PERSPEED * 3;
  }
  else if( speed < MAXSPEED ){
    change_pro_speed(speed + PERSPEED);
    return speed + PERSPEED;
  }
  return -1;
}

/**
 * @brief decrease propulsion fan speed
 */
int decrease_propulsion(){
  int speed = get_speed_level();
  if( speed <= 0 ){
    stop_pro_fan();
    return 0;
  }
  else if( speed > 0 ){
    change_pro_speed(speed - PERSPEED);
    return speed - PERSPEED;
  }
  return -1;
}

/**
 * @brief stop propulsion fan speed
 */
int stop_propulsion_fan(){
  stop_pro_fan();
  return 0;
}

/**
 * @brief specify the propulsion fan level
 */
int get_propulsion_level(){
  int speed = get_speed_level();
  if( speed == 0 ){
    return 0;
  }
  else if( speed > 0 && speed <= PERSPEED ){
    return 1;
  }
  else if( speed > PERSPEED && speed <= PERSPEED * 2 ){
    return 2;
  }
  else if( speed > PERSPEED *2 ){
    return 3;
  }
  return -1;
}



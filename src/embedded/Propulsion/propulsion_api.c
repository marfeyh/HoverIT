/*!
  @copyright This program is free software: you can redistribute it and/or
  modify it under the terms of the GNU General Public License as published
  by the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  @file propulsion_api.c 
  @headerfile propulsion.h
  @headerfile propulsion_api.h
  @Description: This file is the propulsion fan speed API to stop,
                increase or decrease and get the current level of propulsion 
                fan, and set the specific number of propulsion fan speed. 
  @author Xinran He, Khatereh Khosravianarab
  @version 1.0
  @date 2012-03-25
*/

#include <propulsion.h>
#include <propulsion_api.h>
#include <brake_propulsion.h>
#include <pin.h>
#include <searduino.h>
#include <Arduino.h>
#include <stdio.h>

static int fan_level;

/*!
@brief initialise propulsion fan
 */
int start_propulsion_fan()
{
  initialize_relay();
  initialise_propulsion();
  return 0;
}

/*!
@brief increase propulsion fan speed
 */
int increase_propulsion(){
  int motor_speed = get_speed_level();
  fan_level++;
  if( fan_level == 0 ){
    set_propulsion_fan(0);
    digitalWrite(RELAYPIN, LOW);
    return 0;
  }
  else if( fan_level > 0 && motor_speed >= MAXSPEED ){
    change_pro_speed(PERSPEED * 20);
    if( fan_level > 0 ){
      fan_level = 20;
    }
    return PERSPEED * 20;
  }
  else if( fan_level > 0 && motor_speed < MAXSPEED ){
    digitalWrite(RELAYPIN, LOW);
    change_pro_speed(motor_speed + PERSPEED);
    return motor_speed + PERSPEED;
  }
  else if( fan_level < 0){
    change_pro_speed(motor_speed - PERSPEED);
    return motor_speed - PERSPEED;
  }
  return -1;
}

/*!
@brief decrease propulsion fan speed
 */
int decrease_propulsion(){
  int motor_speed = get_speed_level();
  fan_level--;
  if( fan_level == 0 ){
    set_propulsion_fan(0);
    digitalWrite(RELAYPIN, HIGH);
    return 0;
  }
  else if( fan_level > 0 && motor_speed >= PERSPEED ){
    digitalWrite(RELAYPIN, HIGH);
    change_pro_speed(motor_speed - PERSPEED);
    return motor_speed - PERSPEED;
  }
  else if( fan_level < 0 && motor_speed >= MAXSPEED ){
    change_pro_speed(PERSPEED * 20);
    fan_level = -20;
    return PERSPEED * 20;
  }
  else if( fan_level < 0 && motor_speed < MAXSPEED ){
    change_pro_speed(motor_speed + PERSPEED);
    return motor_speed + PERSPEED;
  }
  return -1;
}

/*!
@brief set a specific speed number
 */
int set_propulsion_fan(int set_speed){
  if( set_speed < 0 || set_speed > 120 ){
     stop_pro_fan();
     return -1;
  }
  else{
    change_pro_speed(set_speed);
    return set_speed;
  }
}

/*!
@brief stop propulsion fan speed
 */
int stop_propulsion_fan(){
  stop_pro_fan();
  set_propulsion_fan(0);
  digitalWrite(RELAYPIN, LOW);
  return 0;
}

/*!
@brief specify the propulsion fan level
 */
int get_propulsion_level(){
  return fan_level;
}

/*!
@brief stop propulsion fan speed by using brake
 */
int brake_hovercraft(){
  stop_propulsion_fan();
  delay(1500);
  reverse_prop_motor();
  return 0;
}

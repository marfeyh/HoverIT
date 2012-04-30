
/*!
 * @file brake_propulsion.c
 * @headerfile brake_propulsion.h
 * @headerfile hover_speed.h
 * @headerfile propulsion.h 
 * @headerfile pin.h
 * @headerfile searduino.h
 * @description: This functions is billed for reversing the propulsion fan
   direction of the hovercraft. More descriptions are still in offing.
 * @author: Ezeh Prince Anthony Anayo
 * @author: Xinran He
 * @version: 0.2
 * @date: 2012-04-26
 * @reference: Arduino.cc
 * @reference: sandklef.com
 * @reference: hoveritu.com
 */

#include <brake_propulsion.h>
#include <hover_speed.h>
#include <propulsion.h>
#include <Arduino.h>
#include <pin.h>
#include <searduino.h>

static int hover_speed = 0;

void init_brake_propulsion(void){

}

int reverse_motor(int current_hover_speed){
  

  change_pro_speed(current_hover_speed - 20);
  break_pro();
  return 0;
}

int brake_pro(void){
  for(;;){
    hover_speed = get_hover_speed();
    if(hover_speed < 10){
      stop_pro_fan();
      break;
    }
  }
  return 0;
}

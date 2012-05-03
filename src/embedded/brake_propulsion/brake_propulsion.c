/***************************************************************************
 * Copyright (C) 2012  Ezeh Prince Anthony Anayo
 *                     Xinran He
 * 
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 ****************************************************************************/
 
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
   pinMode(RelayPin, OUTPUT);
   digitalWrite(PIN, HIGH);
   digitalWrite(PIN, LOW);
   delay(SPEED_DELAY_TIME);

}
/*!
 * @brief: More modifications in offing
 */
int reverse_prop_motor(int current_hover_speed){
   if((current_hover_speed + MIN_DUTY_CYCLE ) < 0){ //not yet fanlised on the implementation
   digitalWrite(RelayPin, HIGH);
   delay(SPEED_DELAY_TIME);
   current_hover_speed = -current_hover_speed + MIN_DUTY_CYCLE; //still subject to be changed
   return -1;
   }
   else if((current_hover_speed + MIN_DUTY_CYCLE) < MAX_DUTY_CYCLE){
   digitalwrite(RelayPin, LOW);
   delay(SPEED_DELAY_TIME);
   current_hover_speed = current_hover_speed + MIN_DUTY_CYCLE;
   return 1;
   }
   //analogWrite(PIN, current_hover_speed + MIN_DUTY_CYCLE); //not yet finalised
   change_pro_speed(current_hover_speed - 20);
   brake_pro();
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

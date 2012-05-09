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

/*!
 * @brief: reverse rotation 
 */
int reverse_prop_motor(){
   digitalWrite(RelayPin, HIGH);
   delay(2000);
   analogWrite(PIN, 100);
   delay(2000);
   digitalWrite(RelayPin, LOW);
   delay(2000);
   analogWrite(PIN, 100);
   delay(2000);
   change_pro_speed(MAXSPEED);
   brake_pro();
   return 0;
}


/*!
 * @brief: get hovercraft speed. If the speed is less than
 * 10, then the propulsion fan is stopped.
 */
int brake_pro(void){
  for(;;){
    hover_speed = get_hover_speed();
    if(hover_speed < 10){ //need test
      stop_pro_fan();
      break;
    }
  }
  return 0;
}

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

 @file brake_propulsion.c
 @headerfile brake_propulsion.h
 @headerfile hover_speed_stub.h
 @headerfile propulsion_api.h
 @headerfile Arduino.h
 @headerfile pin.h
 @headerfile searduino.h
 @brief This module contains the functions for the main reversal of the 
  propulsion fan motor in order to brake the hovercraft
 @author Ezeh Prince Anthony Anayo
 @author Xinran He
 @date 2012- 05 - 10
 @version 3.0
 @refrence Arduino.cc
 @refrence sandklef.com
 @refrence hoveritu.com
 @refrence dreamincode.net/forums/topic/34861-functions-stored-in-structure
 @refrence Turnigy_Plush_and_Sentry_ESC user manual
 @refrence for Coding standard ece.cmu.edu/~eno/coding/CCodingStandard.html
 @refrence for commenting stack.nl/~dimitri/doxygen/commands.html#cmdparam
*/
 
#include <brake_propulsion.h>
#include <hover_speed_stub.h>
#include <propulsion_api.h>
#include <Arduino.h>
#include <pin.h>
#include <searduino.h>

/*!
 *@brief Function is responsible for reversing the direction of the rotation
  of the propulsion fan. 
 */
int reverse_prop_motor(){
   int hover_speed = 0;
   digitalWrite(RELAYPIN,HIGH);
   set_propulsion_fan(MAXSPEED);
  for(;;){
    hover_speed = get_hover_speed();
    if(hover_speed < 10){ //need test
      stop_propulsion_fan();
      break;
    }
  // delay(1000);
   }
   return 0;
}

/*!
 *@brief Function that initializes the relaypin
 */
int initialize_relay(){
#if !defined(GLOBAL_MAIN)
   init();
#endif
   /* sets PIN as output pin */
   pinMode(RELAYPIN, OUTPUT);
  // digitalWrite(RELAYPIN, HIGH);
   return 0;
}

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
 @file main.c
 @headerfile propulsion.h
 @headerfile propulsion_api.h
 @headerfile brake_propulsion.h
 @headerfile Arduino.h
 @headerfile searduino.h
 @brief This module is the main function for braḱing the hovercraft
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

#include <propulsion.h>
#include <propulsion_api.h>
#include <brake_propulsion.h>
#include <Arduino.h>
#include <searduino.h>

int main(void){
  initialize_relay();
  start_propulsion_fan();
  increase_propulsion();
  delay(2000);
  increase_propulsion();
  delay(2000);
  brake_hovercraft();
}

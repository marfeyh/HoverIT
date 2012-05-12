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
 @file hover_speed_stub.c
 @brief This module is used as a stub to fake the assumed speed data from the
  get current hovering speed module
 @headerfile hover_speed_stub.h
 @headerfile stdio.h
 @headerfile Arduino.h
 @author Ezeh Prince Anthony Anayo
 @author Xinran He
 @date 10 May 2012
 @version 3.0
 @reference Arduino.cc
 @reference sandklef.com
 @reference hoveritu.com
 @reference dreamincode.net/forums/topic/34861-functions-stored-in-structure
 @reference Turnigy_Plush_and_Sentry_ESC user manual
 @reference for Coding standard ece.cmu.edu/~eno/coding/CCodingStandard.html
 @reference for commenting stack.nl/~dimitri/doxygen/commands.html#cmdparam
 */ 
 
#include <hover_speed_stub.h>
#include <stdio.h>
#include <Arduino.h>

/*!
 @brief Function that fetches the current hovering speed
*/
int speed = 100;
int get_hover_speed(){ 
  speed  -= 25;
  return speed;
}


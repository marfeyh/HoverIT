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
 @file brake_propulsion.h
 @brief This module is the headerfile for hovering_control.c
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
 
#ifndef BRAKE_PROPULSION_H
#define BRAKE_PROPULSION_H

/*!
 @brief Function to reverse the hovercraft brake and automate the rotation of 
  the propulsion fan via using digitalWrite
 @param takes no parameter
 @returns 0
*/
int reverse_prop_motor();

/*!
 @brief Function to initialize the relay pin as output
 @param takes no parameter
 @return 0
*/
int initialize_relay();

#endif



/***************************************************************************
 * Copyright (C) 2012  Seyed Ehsan Mohajerani
 *                     Navid Amiriarshad
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
 @file hovering_motor.c
 @headerfile hovering_motor.h
 @brief This module contains function pointers for calling hovering_control.c
 @author Seyed Ehsan Mohajerani
 @author Navid Amiriarshad
 @version 0.9
 @date 20 March 2012
 @see Arduino.cc
 @see sandklef.com
 @see hoveritu.com
 @see dreamincode.net/forums/topic/34861-functions-stored-in-structure
 @see Turnigy_Plush_and_Sentry_ESC user manual
 @see reference for Coding standard ece.cmu.edu/~eno/coding/CCodingStandard
 .html
 @see reference for commenting stack.nl/~dimitri/doxygen/commands
 .html#cmdparam
 */

/*
  For using Arduino
*/
#include <Arduino.h>
/*
  Header of this file
*/
#include <hovering_motor.h>

/*!
@brief Function pointer for calling functions for start, normal, turbo and 
stop the hovering motor.
@param[in] using_pin This parameter is the Arduino pin number which is used
for sending PWM signal for driving the motor.
@param[in] test_pin This parameter is the Arduino pin number which is used
for audible testing. This parameter is set but not used when using stub.
@param[out] *func This parameter is a pointer to function that should be
called
@return 0 on succes
*/
int hover_func (int (*func)(int,int), int using_pin, int test_pin){
	func (using_pin, test_pin);
	return 0;
	}

/*!
@brief Function pointer for calling functions for changing the speed of
hovering motor.
@param[in] using_pin This parameter is the Arduino pin number which is used
for sending PWM signal for driving the motor.
@param[in] test_pin This parameter is the Arduino pin number which is used
for audible testing. This parameter is set but not used when using stub.
@param[in] level This paratmer is the level of changing speed
@param[out] *climb_decesnd This parameter is a pointer to function
that should be called.
@return 0 on succes
*/
int hover_change (int (*climb_decesnd)(int, int, int), int using_pin, \
int test_pin, int level){
	climb_decesnd (using_pin, test_pin, level);
	return 0;
}

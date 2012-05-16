
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
 @file hovering_control.h
 @brief This module is the headerfile for hovering_control.c
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

#if !defined HOVERING_CONTROL_H
	#define HOVERING_CONTROL_H
	/*
	  The minimum PWM value that is possible to send to ESC from Arduino pin
	  and it is for initiating the motor
	*/
	#define THROTTLE_STICK_BOTTOM_LEVEL 100

	/*
	  The Arduino PWM output value which is sent to ESC and represents the motor
	  rotating level. It can be between 155 (for lowest rotating speed) and 254
	  (for the highest rotating speed)- It is a Global variable.
	*/
	extern int g_throttle_stick_level;

	int start(int using_pin, int test_pin);
	int throttle_stick_bottom(int using_pin, int test_pin);
	int normal(int using_pin, int test_pin);
	int turbo(int using_pin, int test_pin);
	int stop(int using_pin, int test_pin);
	int increase(int using_pin, int test_pin, int level);
	int decrease(int using_pin, int test_pin, int level);
	int set_level(int using_pin, int test_pin, int level);
	int set_fixed_level (int using_pin, int test_pin);
#endif


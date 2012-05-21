
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
 @file hovering_init_fix.h
 @brief This module is the headerfile for hovering_init_fix.c
 @author Seyed Ehsan Mohajerani
 @author Navid Amiriarshad
 @date 20 March 2012
 @version 1.0
 @refrence Arduino.cc
 @refrence sandklef.com
 @refrence hoveritu.com
 @refrence dreamincode.net/forums/topic/34861-functions-stored-in-structure
 @refrence Turnigy_Plush_and_Sentry_ESC user manual
 @refrence for Coding standard ece.cmu.edu/~eno/coding/CCodingStandard.html
 @refrence for commenting stack.nl/~dimitri/doxygen/commands.html#cmdparam
 */

#if !defined HOVERING_INIT_FIX_H
	#define HOVERING_INIT_FIX_H
	/*!
	  @def TEST_PIN
	  define the highest value on Arduino PWM output for rotating motor 
	*/
	#define HIGHEST_LEVEL 254
	/*!
	  @def TEST_PIN
	  define the lowest value on Arduino PWM output for rotating motor
	*/
	#define LOWEST_LEVEL 155
	/*!
	  @def TEST_PIN
	  define the value on Arduino PWM output for stopping motor 
	*/
	#define STOP_LEVEL 120
	int initialize(int using_pin, int test_pin);
	int pin_program(int using_pin, int test_pin, int level);
	int check_and_fix_level(int using_pin,int test_pin);
	int check_and_fix_level_increase (int using_pin, int test_pin, \
	int level);	
	int check_and_fix_level_decrease (int using_pin, int test_pin, \
	int level);
	#endif

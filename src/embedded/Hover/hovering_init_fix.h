
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
 @brief This module is the headerfile for hovering_init_fix.h
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

/* Make sure this header file is included one time */
#if !defined HOVERING_INIT_FIX_H
	#define HOVERING_INIT_FIX_H
	
	/* Defines */
	#define HIGHEST_LEVEL 254
	#define LOWEST_LEVEL 155
	#define STOP_LEVEL 120

	/* Function prototype */

	/* Arduino and motor initiation */
	int initialize(int using_pin, int test_pin);
	/* Set the Arduino active pin for using */	
	int pin_program(int using_pin, int test_pin, int level);
	/* This function prevents the motor from stop
	 (Check boundary values)*/
	int check_and_fix_level(int using_pin,int test_pin, \
	 int g_throttle_stick_level);
	/* This function prevent increase to function when the motor \
	 is stopped */
	int check_and_fix_level_increase (int using_pin, int test_pin, \
	int g_throttle_stick_level, int level);	
	/* This function prevents decrease to function when the motor \
	is stopped */
	int check_and_fix_level_decrease (int using_pin, int test_pin, \
	int g_throttle_stick_level, int level);

	
	#endif

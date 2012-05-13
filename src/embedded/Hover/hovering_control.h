
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

/* Make sure this header file is included one time */
#if !defined HOVERING_CONTROL_H
	#define HOVERING_CONTROL_H

	/* Function protoypes */

	/* Set the level to 100 or Start the hovering motor*/
	int start(int using_pin, int test_pin);
	/* Set the level to 100 or start the motor if the motor has not \
	 been started (The minimum acceptable value for ESC)*/
	int throttle_stick_bottom(int using_pin, int test_pin);
	/* Set the level to 143 or set the motor to lowest rotating speed */
	int normal(int using_pin, int test_pin);
	/* Set the level to 254 or set the motor to highest rotating speed */
	int turbo(int using_pin, int test_pin);
	/* Set the level to 120 or stop the motor */
	int stop(int using_pin, int test_pin);
	/* Increase the motor rotating speed level times */
	int increase(int using_pin, int test_pin, int level);
	/* decrease the motor rotating speed level times */
	int decrease(int using_pin, int test_pin, int level);
	/* set the motor rotating speed to specified level */
	int set_level(int using_pin, int test_pin, int level);
	/* set the motor rotating speed to specified to the level which
	fixed to be no higher than 254 and no lower than 143*/
	int set_fixed_level (int using_pin, int test_pin, int level);

	#endif

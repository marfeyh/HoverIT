
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
 @brief This module contains function pointers for calling hovering_control.c. 
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

/* Includes */
#include <Arduino.h> /* Header for Arduino */
#include <searduino.h> /* Header for Searduino */
#include <hovering_motor.h>
#include <hovering_control.h>
#include <print_audible_test.h>

unsigned char loop_need;


/* Functions */

/* Function that gets arguments for start or stop the motor */
int hover_func (int (*func)(int,int), int using_pin, int test_pin){
	func (using_pin, test_pin);
	return 0;
	}

/* Fucntion that gets arguments for change the speed of motor */
int hover_change (int (*climb_decesnd)(int, int, int), int using_pin, \
int test_pin, int level){
	climb_decesnd(using_pin, test_pin, level);
	return 0;
}

/* Loop for motor */
int hover_loop(FUNCS funcs_in, int using_pin){
	while(loop_need){
		funcs_in.func1(funcs_in.level);
		funcs_in.func2(funcs_in.delay_time);
	}
	return 0;
}

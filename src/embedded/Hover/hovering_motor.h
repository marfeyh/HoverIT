
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
 @file hovering_motor.h
 @brief This module is headerfile for hovering_motor.c
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
  @def BLINK_PIN 11
  define for testing Arduino
*/
#define BLINK_PIN 11
#define BLINKER(delay_time) { int i; pinMode(BLINK_PIN,OUTPUT); \
		digitalWrite(BLINK_PIN,HIGH);delay(delay_time); \
		digitalWrite(BLINK_PIN,LOW);delay(delay_time);}

#if !defined HOVERING_MOTOR_H
	#define HOVERING_MOTOR_H
	int hover_func(int (*func)(int,int), int using_pin, int test_pin);
	int hover_change(int (*climb_decesnd)(int,int,int),
	int using_pin,int test_pin, int level);

	#endif

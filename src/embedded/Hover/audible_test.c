
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
 @file audible_test.c
 @headerfile print_audible_test.h
 @brief This module contain the functions for audible test when using 
	Arduino.
 @author Seyed Ehsan Mohajerani
 @author Navid Amiriarshad
 @date 20 April 2012
 @version 1.0
 @refrence Arduino.cc
 @refrence sandklef.com
 @refrence hoveritu.com
 @refrence dreamincode.net/forums/topic/34861-functions-stored-in-structure
 @refrence Turnigy_Plush_and_Sentry_ESC user manual
 @refrence for Coding standard ece.cmu.edu/~eno/coding/CCodingStandard.html
 @refrence for commenting stack.nl/~dimitri/doxygen/commands.html#cmdparam
 */

#include <Arduino.h>
#include <searduino.h>
#include <print_audible_test.h>

#define BEEP 254
#define SILENCE 0
#define SILENT_DELAY_TIME 50

int beep_time;
int silence_time;
int loop_count;
int loop_number;
int beep_delay_time;
int silence_delay_time;

/*!
@brief audible test for start hovering, beep(100 ms)silent(50 ms) *8 +
	silent(50 ms)
 */
int test_start (int test_pin) {
	beep_time = 100;
	silence_time = 50;
	loop_number = 8;
	for (loop_count = 0; loop_count < loop_number; loop_count++){
		digitalWrite (test_pin, HIGH);
		delay (beep_time);
		digitalWrite (test_pin, LOW);
		delay (silence_time);
	}
	silent_delay(test_pin);
	return 0;
}

/*!
@brief audible test for stop hovering motor, beep(100 ms)silent(300 ms) *4 +
	beep(500 ms)silent(50 ms)
 */
int test_stop (int test_pin) {
	beep_time = 100;
	silence_time = 300;
	loop_number = 4;
	for (loop_count = 0; loop_count < loop_number; loop_count++){
		analogWrite (test_pin, BEEP);
		delay (beep_time);
		analogWrite (test_pin, SILENCE);
		delay (silence_time);
	}
	analogWrite (test_pin, BEEP);
	delay (500);
	silent_delay(test_pin);
	return 0;
}

/*!
@brief audible test for motor lowers speed, beep(200 ms)silent(50 ms) * 6 +
	silent(50 ms)
 */
int test_normal (int test_pin){
	beep_time = 200;
	silence_time = 50;
	loop_number = 6;
	for (loop_count = 0; loop_count < loop_number; loop_count++){
		analogWrite (test_pin, BEEP);
		delay (beep_time);
		analogWrite (test_pin, SILENCE);
		delay (silence_time);
	}
	silent_delay(test_pin);
	return 0;
}

/*!
@brief audible test for motor highest speed, beep(50 ms)silent(50 ms) *8 +
	silent(50 ms)
 */
int test_turbo (int test_pin) {
	beep_time = 50;
	silence_time = 50;
	loop_number = 8;
	for (loop_count = 0; loop_count < loop_number; loop_count++){
		analogWrite (test_pin, BEEP);
		delay (beep_time);
		analogWrite (test_pin, SILENCE);
		delay (silence_time);
	}
	silent_delay(test_pin);
	return 0;
}

/*!
@brief audible test for arduino pin programming, beep(10 ms)silent(50 ms) *2 
	+ silent(50)
 */
int test_analogwrite (int test_pin){
	beep_time = 10;
	silence_time = 50;
	loop_number = 2;
	for (loop_count = 0; loop_count < loop_number; loop_count++){
		digitalWrite (test_pin, HIGH);
		delay (beep_time);
		digitalWrite (test_pin, LOW);
		delay (silence_time);
	}
	silent_delay(test_pin);
	return 0;
}

/*!
@brief audible test for started motor, beep(100 ms)silent(50 ms) *4 +
	silent(50 ms)
 */
int test_motor_already_started (int test_pin){
	beep_time = 100;
	silence_time = 50;
	loop_number = 4;
	for (loop_count = 0; loop_count < loop_number; loop_count++){
		analogWrite (test_pin, BEEP);
		delay (beep_time);
		analogWrite (test_pin, SILENCE);
		delay (silence_time);
	}
	analogWrite (test_pin, BEEP);
	delay (50);
	silent_delay(test_pin);
	return 0;
}

/*!
@brief audible test for too low value for motor, beep(200 ms)silent(200 ms) 
	*3 + silent(50 ms)
 */
int test_Too_low (int test_pin){
	beep_time = 200;
	silence_time = 200;
	loop_number = 3;
	for (loop_count = 0; loop_count < loop_number; loop_count++){
		analogWrite (test_pin, BEEP);
		delay (beep_time);
		analogWrite (test_pin, SILENCE);
		delay (silence_time);
	}
	analogWrite (test_pin, BEEP);
	delay (50);
	silent_delay(test_pin);
	return 0;
}

/*!
@brief audible test for too high value for motor, beep(200 ms)silent(200 ms) 
	*3 + silent(50 ms)
 */
int test_Too_high (int test_pin){
	test_Too_low (test_pin);
	return 0;
}

/*!
@brief standard silent time (50 ms)
 */
int silent_delay(int test_pin){
	analogWrite (test_pin, SILENCE);
	delay (SILENT_DELAY_TIME);
	return test_pin;
}

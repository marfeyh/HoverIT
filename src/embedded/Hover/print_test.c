
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
 @file print_test.h
 @headerfile print_audible_test.h
 @brief This module contain the functions for print on screen test when using 
 stub.
 @author Seyed Ehsan Mohajerani
 @author Navid Amiriarshad
 @version 0.9
 @date 20 April 2012
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
  For using serduino
*/
#include <searduino.h>
/*
  For using print
*/
#include <stdio.h>
/*
  Header of this file
*/
#include <print_audible_test.h>
/*
  For g_throttle_Stick_level
*/
#include <hovering_control.h>

/*!
@brief Print test after starting the motor
@param[in] test_pin This parametere is the pin number which is used to send
the beep for testing (here just sent but not used).
@return 0 on succes
*/
int test_start (int test_pin) {
	printf("		Test motor started \n");	
	return 0;
}

/*!
@brief Print test after stoping the motor 
@param[in] test_pin This parametere is the pin number which is used to send
the beep for testing (here just sent but not used).
@return 0 on succes
*/
int test_stop (int test_pin) {
	printf("		Test motor stopped \n");
	return 0;
}

/*!
@brief Print test after setting the motor to normal 
@param[in] test_pin This parametere is the pin number which is used to send
the beep for testing (here just sent but not used).
@return 0 on succes
*/
int test_normal (int test_pin){
	printf("		Test level is normal \n");
	return 0;
}

/*!
@brief Print test after setting the motor to turbo
@param[in] test_pin This parametere is the pin number which is used to send
the beep for testing (here just sent but not used).
@return test_pin on succes
*/
int test_turbo (int test_pin) {
	printf("		Test level is turbo \n");
	return 0;
}

/*!
@brief Print test after analogwrite on Arduino simiulator 
@param[in] test_pin This parametere is the pin number which is used to send
the beep for testing (here just sent but not used).
@return 0 on succes
*/
int test_analogwrite (int test_pin){
	printf("		Test analog write \n");
	return 0;
}

/*!
@brief Print test for too low value for motor
@param[in] test_pin This parametere is the pin number which is used to send
the beep for testing (here just sent but not used).
@return 0 on succes
*/
int test_Too_low (int test_pin){
	printf("		Test Too low \n");
	return 0;
}

/*!
@brief Print test for too high value for motor
@param[in] test_pin This parametere is the pin number which is used to send
the beep for testing (here just sent but not used).
@return 0 on succes
*/
int test_Too_high (int test_pin){
	printf("		Test Too high \n");
	return 0;
}

/*!
@brief Print test after the setting throttle Stick at bottom or the 
Arduino PWM output is 100. 
@param[in] test_pin This parametere is the pin number which is used to send
the beep for testing (here just sent but not used).
@return 0 on succes
*/
int test_throttle_Stick_is_bottom (int test_pin){
	printf("		Test T S is bottom \n");
	return 0;
}

/*!
@brief Print test if the setting throttle Stick has been already set to 
bottom. 
@param[in] test_pin This parametere is the pin number which is used to send
the beep for testing (here just sent but not used).
@return test_pin on succes
*/
int test_motor_already_started (int test_pin){
	printf("		Test motor has already been started \n" \
	);
	return 0;
}

/*!
@brief Print test for increase motor level
@param[in] none
@return 0 on succes
*/
int test_increase (void){
	printf("		Test INC New    L: %d \n", \
	g_throttle_stick_level);
	return 0;
}

/*!
@brief Print test for decrease motor level
@param[in] none
@return 0 on succes
*/
int test_decrease (void){
	printf("		Test DEC New    L: %d \n", \
	g_throttle_stick_level);
	return 0;
}

/*!
@brief Print test for set motor level
@param[in] void
@return 0 on succes
*/
int test_set_level (void){
	printf("		Test set New    L: %d \n", \
	g_throttle_stick_level);
	return 0;
}

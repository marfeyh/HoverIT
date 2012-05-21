
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
 @file hovering_init_fix.c
 @headerfile hovering_init_fix.h
 @brief This module contains the functions that initialize the hovering 
 motor and fix any wrong value which is being sent to hovering motor.
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
  For using Serduino
*/
#include <searduino.h>
/*
  Header of this file
*/
#include <hovering_init_fix.h>
/*
  For using functions
  normal
  turbo
  set_fixed_level
*/
#include <hovering_control.h>
/*
  For audible or print testing
*/
#include <print_audible_test.h>

/*!
@brief Set the output pin in Arduino and make the motor ready before roatating
@param[in] using_pin This parameter is the Arduino pin number which is used
for sending PWM signal for driving the motor.
@param[in] test_pin This parameter is the Arduino pin number which is used
for audible testing. This parameter is set but not used when using stub.
@return 0 on succes
*/
int initialize (int using_pin, int test_pin){
	/*
	  Set pin for audible testing
	*/
	pinMode (test_pin, OUTPUT);
	/*
	  Set pin for driving motor
	*/	
	pinMode (using_pin, OUTPUT);
	/*
	  make the motor ready before roatating
	*/	
	hover_func (start, using_pin, test_pin);
	return 0;
}

/*!
@brief Set the PWM value on the activated output pin of Arduino 
@param[in] using_pin This parameter is the Arduino pin number which is used
for sending PWM signal for driving the motor.
@param[in] test_pin This parameter is the Arduino pin number which is used
for audible testing. This parameter is set but not used when using stub.
@return 0 on succes
*/
int pin_program (int using_pin, int test_pin, int level) {
	analogWrite (using_pin, level);
	/*
	  Test code
	*/
	#if defined AUDIBLE_TEST
		test_analogwrite (test_pin);
	#endif	
	return 0;
}

/*!
@brief Prevent the motor from unexpected stop due to violate boundary values
in PWM signal.  
@param[in] using_pin This parameter is the Arduino pin number which is used
for sending PWM signal for driving the motor.
@param[in] test_pin This parameter is the Arduino pin number which is used
for audible testing. This parameter is set but not used when using stub.
@return 0 on correct value
@return 1 on too high value
@return 2 on too low value
*/
int check_and_fix_level (int using_pin,int test_pin){
	/*
	  If the setting value is less than the lowest level for rotating
	  (155) then sets the level to 155
	*/
	if (g_throttle_stick_level < LOWEST_LEVEL){
		normal (using_pin, test_pin);
		/*
		  Test code
		*/
		#if defined AUDIBLE_TEST
			test_Too_low (test_pin);
		#endif
		return 2;
	/*
	  If the setting value is higher than the highest level for rotating
	  (254) then sets the level to 254
	*/
	}else if (g_throttle_stick_level > HIGHEST_LEVEL){		
		turbo (using_pin, test_pin);
		/*
		  Test code
		*/
		#if defined AUDIBLE_TEST
			test_Too_high (test_pin);
		#endif
		return 1;
	/*
	  If the setting value is between 155 and 254 then this function
	  does nothing.
	*/	
	}else {
		return 0;
	}
}

/*!
@brief Prevent the motor from unexpected stop due to violate boundary values
in PWM signal when using increase function.  
@param[in] using_pin This parameter is the Arduino pin number which is used
for sending PWM signal for driving the motor.
@param[in] test_pin This parameter is the Arduino pin number which is used
for audible testing. This parameter is set but not used when using stub.
@return added level on correct value
@return 254 on too high value
@return pervious level plus added level on correct value
*/

int check_and_fix_level_increase (int using_pin, int test_pin, \
int level){
	/*
	  If the value after increasing is higher than the highest level for 
	  rotating (254) then sets the level to 254
	*/
	if (g_throttle_stick_level + level > HIGHEST_LEVEL){
		turbo (using_pin, test_pin);	
		/*
		  Test code
		*/
		#if defined AUDIBLE_TEST
		test_Too_high (test_pin);	
		#endif
		return 1;	
	/*
	  If the value after increasing is between 155 and 254 then this 
	  function adds the increasing value to the previous level.
	*/
	}else if (g_throttle_stick_level + level < LOWEST_LEVEL){
		normal (using_pin, test_pin);	
		/*
		  Test code
		*/
		#if defined AUDIBLE_TEST
\		test_Too_low (test_pin);
		#endif
		return 2;
	}else 	{
		g_throttle_stick_level =g_throttle_stick_level + level;		
		set_fixed_level (using_pin, test_pin);
		return 0;
	}
}

/*!
@brief Prevent the motor from unexpected stop due to violate boundary values
in PWM signal when using decrease function. And also prevent decrease to 
work when the motor is stopped.
@param[in] using_pin This parameter is the Arduino pin number which is used
for sending PWM signal for driving the motor.
@param[in] test_pin This parameter is the Arduino pin number which is used
for audible testing. This parameter is set but not used when using stub.
@return previous level when decrease is used before starting motor
@return decreased level when decrease is used correctly
*/
int check_and_fix_level_decrease (int using_pin,int test_pin, \
int level){
	/*
	  If the motor is stopped or value after decreasing is less than 155
	  then nothing should be done
	*/
	if (g_throttle_stick_level < LOWEST_LEVEL || \
	   g_throttle_stick_level-level < LOWEST_LEVEL){		
		/*
		  Test code
		*/
		#if defined AUDIBLE_TEST
		test_Too_low (test_pin);
		#endif
		return 1;
	/*
	  If the value after decreasing is between 155 and 254 then this 
	  function reduces the decreasing value from the previous level.
	*/
	} else {
		g_throttle_stick_level = g_throttle_stick_level-level;
		set_fixed_level (using_pin, test_pin);
		return 0;
	}
}

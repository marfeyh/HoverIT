
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
 @file hovering_control.c
 @headerfile hovering_control.h
 @brief This module contains the functions that control the hovering fan
 speed.
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
#include <hovering_control.h>
/*
  For using functions
  pin_program
  check_and_fix_level_increase
  check_and_fix_level_decrease
  check_and_fix_level
*/
#include <hovering_init_fix.h>
/*
  For audible or print testing
*/
#include <print_audible_test.h>

/*
  The Arduino PWM output value which is sent to ESC and represents the motor
  rotating level. It can be between 155 (for lowest rotating speed) and 254
  (for the highest rotating speed)- It is a Global variable.
*/
int g_throttle_stick_level=0;

/*!
@brief Start motor and make the motor ready before roatating
@param[in] using_pin This parameter is the Arduino pin number which is used
for sending PWM signal for driving the motor.
@param[in] test_pin This parameter is the Arduino pin number which is used
for audible testing. This parameter is set but not used when using stub.
@return 0 on succes
@return 0 if the motor is started before
*/
int start(int using_pin, int test_pin) {
	/*
	  If the Arduino PWM output value is less than 100 , this function
	  Set the value to 100 or Starts the hovering motor.
	*/
	if (g_throttle_stick_level < THROTTLE_STICK_BOTTOM_LEVEL){
		throttle_stick_bottom(using_pin, test_pin);
		/*
		  Test code
		*/
		#if defined AUDIBLE_TEST
			test_start (test_pin);
		#endif
		return 0;
	} else {
		/*
		  Test code
		*/
		#if defined AUDIBLE_TEST
			test_motor_already_started (test_pin);
		#endif
		return 1;
	}
}

/*!
@brief set the Set Arduino PWM output value to 100 or start the motor before
rotating (The minimum acceptable value for ESC).
@param[in] using_pin This parameter is the Arduino pin number which is used
for sending PWM signal for driving the motor.
@param[in] test_pin This parameter is the Arduino pin number which is used
for audible testing. This parameter is set but not used when using stub.
@return 0 on succes
*/
int throttle_stick_bottom (int using_pin, int test_pin) {
	set_level (using_pin, test_pin, THROTTLE_STICK_BOTTOM_LEVEL);
	/*
	  Test code this function has not valid audible test so it is used
	  just in stub mode.
 	*/
	#if defined STUB_TEST
		test_throttle_Stick_is_bottom (test_pin);
	#endif
	return 0;
}

/*!
@brief Set the Arduino PWM output value to 155 or set the motor to lowest
rotating speed.
@param[in] using_pin This parameter is the Arduino pin number which is used
for sending PWM signal for driving the motor.
@param[in] test_pin This parameter is the Arduino pin number which is used
for audible testing. This parameter is set but not used when using stub.
@return 0 on succes
*/
int normal (int using_pin,int test_pin){
	set_level (using_pin, test_pin, LOWEST_LEVEL);
	/*
	  Test code
	*/
	#if defined AUDIBLE_TEST
		test_normal (test_pin);
	#endif
	return 0;
}

/*!
@brief Set the Arduino PWM output value to 254 or set the motor to highest
rotating speed.
@param[in] using_pin This parameter is the Arduino pin number which is used
for sending PWM signal for driving the motor.
@param[in] test_pin This parameter is the Arduino pin number which is used
for audible testing. This parameter is set but not used when using stub.
@return 0 on succes
*/
int turbo (int using_pin,int test_pin){
	set_level (using_pin, test_pin, HIGHEST_LEVEL);
	/*
	  Test code
	*/
	#if defined AUDIBLE_TEST
		test_turbo (test_pin);
	#endif
	return 0;
}

/*!
@brief Set the Arduino PWM output value to 120 or set the motor to stop.
@param[in] using_pin This parameter is the Arduino pin number which is used
for sending PWM signal for driving the motor.
@param[in] test_pin This parameter is the Arduino pin number which is used
for audible testing. This parameter is set but not used when using stub.
@return 0 on succes
*/
int stop (int using_pin, int test_pin){
	set_level (using_pin, test_pin, STOP_LEVEL);
	/*
	  Test code
	*/
	#if defined AUDIBLE_TEST
		test_stop (test_pin);
	#endif	
	return 0;
}

/*!
@brief Increase the Arduino PWM output value or start motor rotating or
increase the motor rotating speed when to the motor is rotating.
@param[in] using_pin This parameter is the Arduino pin number which is used
for sending PWM signal for driving the motor.
@param[in] test_pin This parameter is the Arduino pin number which is used
@param[in] level This parameter is the desired value to be increased.
for audible testing. This parameter is set but not used when using stub.
@return 0 on succes
*/
int increase (int using_pin, int test_pin, int level){
	/*
	  Function check_and_fix_level_increase prevents the PWM value to
	  violate highest value (254).
	*/
	check_and_fix_level_increase(using_pin, test_pin, level);
	/*
	  Test code this function has not valid audible test so it is used
	  just in stub mode.
 	*/
	#if defined STUB_TEST
		test_increase (0);
	#endif
	return 0;
}

/*!
@brief Decrease the Arduino PWM output value or decrease the motor rotating
speed.
@param[in] using_pin This parameter is the Arduino pin number which is used
for sending PWM signal for driving the motor.
@param[in] test_pin This parameter is the Arduino pin number which is used
@param[in] level This parameter is the desired value to be decreased.
for audible testing. This parameter is set but not used when using stub.
@return 0 on succes
*/
int decrease (int using_pin, int test_pin, int level){
	/*
	  Function check_and_fix_level_decrease prevents the PWM value to
	  violate lowest value (155) and also prevent the decrease function
	  to start rotating the motor.
	*/
	check_and_fix_level_decrease (using_pin, \
	test_pin, level);
	/*
	  Test code this function has not valid audible test so it is used
	  just in stub mode.
 	*/
	#if defined STUB_TEST
		test_decrease (0);
	#endif
	return 0;
}

/*!
@brief Set the Arduino PWM output value to a desired value or set the motor
rotating speed to a desired level.
@param[in] using_pin This parameter is the Arduino pin number which is used
for sending PWM signal for driving the motor.
@param[in] test_pin This parameter is the Arduino pin number which is used
@param[in] g_throttle_stick_level This parameter is the desired value
to be set.
for audible testing. This parameter is set but not used when using stub.
@return 0 on succes
*/
int set_level(int using_pin, int test_pin, int level){
	g_throttle_stick_level = level;
	pin_program (using_pin, test_pin, g_throttle_stick_level);
	/*
	  Test code this function has not valid audible test so it is used
	  just in stub mode.
 	*/
	#if defined STUB_TEST
		test_set_level (0);
	#endif
	return 0;
}

/*!
@brief Set the Arduino PWM output value to a desired value or set the motor
rotating speed to a desired level. This value is fixed to be no higher than
254 and no lower than 155.
@param[in] using_pin This parameter is the Arduino pin number which is used
for sending PWM signal for driving the motor.
@param[in] test_pin This parameter is the Arduino pin number which is used
@param[in] g_throttle_stick_level This parameter is the desired value
to be set.
for audible testing. This parameter is set but not used when using stub.
@return 0 on succes
*/
int set_fixed_level (int using_pin, int test_pin){
	pin_program (using_pin, test_pin, g_throttle_stick_level);
//	check_and_fix_level (using_pin, test_pin);
	/*
	  Test code this function has not valid audible test so it is used
	  just in stub mode.
 	*/
	#if defined STUB_TEST
		test_set_level (0);
	#endif
	return 0;
}

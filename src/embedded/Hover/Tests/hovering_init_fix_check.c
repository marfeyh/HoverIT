
/***************************************************************************
 * Copyright (C) 2012  Seyed Ehsan Mohajerani
 *		       Navid Amiriarshad
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
 @brief Contains the functions that check the hovering_init_fix.c functions.
 @author Seyed Ehsan Mohajerani
 @author Navid Amiriarshad
 @version 0.9
 @date 2012-05-15
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

#include <Arduino.h>
#include <searduino.h>
#include <check.h>
#include <pin.h>
#include <stdlib.h>
#include <generate_random.h>
#include "../hovering_motor.h"
#include "../hovering_control.h"
#include "../hovering_init_fix.h"
#include "hovering_control_check.h"

/*!
  def LEVEL
  define a value that motor rotates in a low speed by getting that value.
*/ 
#define LEVEL 160

/*!
@brief Preparation for the tests that need Arduino initialization (Fixture)
@param void 
@returns void
*/
void setup2(void) {
	init();
	initialize(USING_PIN, TEST_PIN);
}

/*!
@brief Finalize for the tests that initilized the Arduino at setup function
@param void
@returns void
*/
void teardown2(void) {
}

/*!
@brief Id/Title: EN1/Test Motor initiation 
       Purpose: Test correct implementation of motor initiation functions. 
                This function is in file hovering_fix_init.c.
       Prerequisites: init(); should be called in the main
       Expected results: The motor should be initiated
       Pass/Fail criteria: When check is run response is 100%: Checks: 16,
                           Failures: 0, Errors: 0/any other results
*/
START_TEST(test_initialize) {
	fail_unless((initialize(USING_PIN, TEST_PIN) == 0), \
	"ard init failed");
}END_TEST

/*!
@brief Id/Title: EN2/Test pin programming on Arduino board 
       Purpose: Check the function that gets a value and sets this value on
                an output pin on Arduino.
       Prerequisites: init(); should be called in the main
       Expected results: The value should be set on the pin
       Pass/Fail criteria: When check is run response is 100%: Checks: 16,
                           Failures: 0, Errors: 0/any other results
*/
START_TEST(test_pin_program) {
	fail_unless((pin_program(USING_PIN, TEST_PIN, LEVEL) \
	== 0),"pin test failed\n");
}END_TEST

/*!
@brief Id/Title: EN3/Test Check and fix level 
       Purpose: Check the function which tests the value sending from the 
		set_fix_level in file function to Arduino pin and fix it 
                in the case of violating boundary values.
       Prerequisites: 
       Expected results: 
       Pass/Fail criteria: When check is run response is 100%: Checks: 16,
                           Failures: 0, Errors: 0/any other results
*/
START_TEST(test_check_and_fix_level) {
	/*
	  Generate a random value between 255 and 1255 which is higher than
	  legal range and assign that value to motor level.
	*/
	int throttle_illegel_high_level = generate_random_number(255,1255);
	g_throttle_stick_level = throttle_illegel_high_level;
	/*
	  Test check_and_fix_level with param throttle illegel high level.
	*/	
	fail_unless((check_and_fix_level(USING_PIN, TEST_PIN ) == 1), \
	"fail check and fix illegal high level \n");	
	/*
	  Generate a random value between 0 and 132 which is lower
	  than legal range and assign that value to motor level.
	*/
	int throttle_illegel_low_level = generate_random_number(0,132);
	g_throttle_stick_level = throttle_illegel_low_level;
	/*
	  Test check_and_fix_level with param throttle illegal low level.
	*/	
	fail_unless((check_and_fix_level(USING_PIN, TEST_PIN) == 2),\
	"fail check and fix illegal low level \n");
	/*
	  Generate a random value between 155 and 254 which is within
	  the legal range and assign thta value to motor level.
	*/
	int throttle_ok_level = generate_random_number(155,254);
	g_throttle_stick_level = throttle_ok_level;
	/*
	  Test check_and_fix_level with param throttle ok level.
	*/	
	fail_unless((check_and_fix_level(USING_PIN, TEST_PIN) == 0), \
	"fail check and fix ok level \n");	
}END_TEST

START_TEST(test_check_and_fix_level_increase) {
	/*
	  Generate a random value for motor level between 100 and 254
	  assign that value to motor level.
	*/
	int throttle_ok_level = generate_random_number(100,254);
	g_throttle_stick_level = throttle_ok_level;
	/*
	  Generate a random value for increasing motor level between 155 and 
	255 assign throttle_illegal_increaseing_level to that value.
	This value is added to throttle_stick_level and generate an illegal 
	high level for motor
	*/
	int throttle_illegal_increaseing_level = \
	generate_random_number(155,255);
	/*
	  Test check_and_fix_level_increase with param illegal increasing.
	*/
	fail_unless((check_and_fix_level_increase (USING_PIN, TEST_PIN, \
	throttle_illegal_increaseing_level) == 254), \
	"fail check and fix increase illegal high level \n");
	
	/*
	  Generate a random value for motor level between 100 and 254
	  assign that value to motor level.
	*/
	throttle_ok_level = generate_random_number(100,254);
	g_throttle_stick_level = throttle_ok_level;
	
	/*
	  Generate a random value for increasing motor level between 1 and 
	254 - throttle_ok_level assign throttle_ok_increaseing_level to that 
	value. So the value won't be illegal. 
	This value is added to throttle_stick_level and generate an
	illegal	high level for motor
	*/
	int throttle_ok_increaseing_level = \
	generate_random_number(1,254-throttle_ok_level);
	g_throttle_stick_level = throttle_ok_increaseing_level;
	/*
	  Test check_and_fix_level_increase with param illegal increasing.
	*/
	fail_unless((check_and_fix_level_increase (USING_PIN, TEST_PIN, \
	throttle_illegal_increaseing_level) == throttle_ok_increaseing_level \
	+ throttle_illegal_increaseing_level), \
	"fail check and fix increase illegal high level \n");
}END_TEST

/*!
@brief Adds test cases to test suite
*/
Suite * hovering_control_suite(void) {
	Suite *s_hovering_control = \
	suite_create("Hovering motor controlling test");
	TCase *tc_with_fixture = tcase_create("Core with fixture");
	//TCase *tc_with_fixture2 = tcase_create("Core with fixture2");
	TCase *tc_without_fixture = tcase_create("Core without fixture");

	tcase_add_checked_fixture(tc_with_fixture, setup2, teardown2);
	//tcase_add_checked_fixture(tc_with_fixture2, setup2, teardown2);
	tcase_add_test(tc_without_fixture, test_initialize);
	tcase_add_test(tc_with_fixture, test_pin_program); 
	tcase_add_test(tc_with_fixture, test_check_and_fix_level);
	tcase_add_test(tc_with_fixture, test_check_and_fix_level_increase);

	//suite_add_tcase(s_hovering_control, tc_with_fixture);  
	//suite_add_tcase(s_hovering_control, tc_without_fixture);

	return s_hovering_control;
}

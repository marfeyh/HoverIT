
/***************************************************************************
 * Copyright (C) 2012  Eva-Lisa Kedborn
 * 		       Jing Liu
 *		       Seyed Ehsan Mohajerani
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
 @file hovering_check.c
 @brief Contains the functions that check the hovering control files.
 @author Eva-Lisa Kedborn
 @author Jing Liu
 @author Seyed Ehsan Mohajerani
 @author Navid Amiriarshad
 @version 0.4
 @date 2012-04-09
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
#include "../pressure_check.h"
#include "../pressure_stub.h"
#include "../hovering_motor.h"
#include "../hovering_control.h"
#include "../hovering_init_fix.h"

/*!
@brief Preparation for the tests that need Arduino initialization (Fixture)
@param void 
@returns void
*/
void setup(void) {
	init();
	initialize(USING_PIN, TEST_PIN);
}

/*!
@brief Finalize for the tests that initilized the Arduino at setup function
@param void
@returns void
*/
void teardown(void) {
}

/*!
@brief Test correct implementation of hoverfan functions; if the
       air pressure is to low the hover fan speed should increas
@par Test id: \n
 * EJ1 \n
@par Testname: \n
 * Test random air pressure \n
@par Preconditions: \n 
 * None \n
@par Outcome: \n
 * The correct hoverfan function has been called \n
*/

START_TEST(test_random) {
	int gap = get_pressure();
	int value = handle_pressure(gap);
	if (gap < 40 && value != -1) {
		fail("the value must be -1!");
	}
	if (gap > 60 && value != 1) {
		fail("the value must be 1!");
	}
	if ((gap >= 40 && gap <= 60) && value != 0) {
		fail("the value must be 0!");
	}
}END_TEST

/*!
@brief  Make sure the hoverfan decreases speed when the air
        pressure inside the skirt is too high
@par Test id: \n
 * EJ2 \n
@par Testname: \n
 * Test air pressure higher than the preferred value \n
@par Preconditions: \n 
 * None \n
@par Outcome: \n
 * The decrease speed function has been called \n
*/

START_TEST(test_positive) {
	int value = handle_pressure(get_positive());
	fail_unless(value == 1, "1 should be returned!");
}END_TEST

/*!
@brief Make sure the hoverfan increases speed when the air
       pressure inside the skirt is too low
@par Test id: \n
 * EJ3 \n
@par Testname: \n
 * Test air pressure lower than the preferred value \n
@par Preconditions: \n 
 * None \n
@par Outcome: \n
 * The increase speed function has been called \n
*/

START_TEST(test_negative) {
	int value = handle_pressure(get_negative());
	fail_unless(value == -1, "-1 should be returned!");
}END_TEST

/*!
@brief Make sure the hoverfan keeps the same speed if we have 
       a satisfying air pressure inside the skirt
@par Test id: \n
 * EJ4 \n
@par Testname: \n
 * Test air pressure equal to the the preferred value \n
@par Preconditions: \n 
 * None \n
@par Outcome: \n
 * The speed of the hovering fan is unchanged \n
*/

START_TEST(test_equal) {
	int value = handle_pressure(get_equal());
	fail_unless(value == 0, "0 should be returned!");
}END_TEST

/*!
@brief Make sure the API function for start hovering is working
@par Test id: \n
 * EJ5 \n
@par Testname: \n
 * Test API function to start hover\n
@par Preconditions: \n 
 * None \n
@par Outcome: \n
 * The return value from the API function is 1 \n
*/

START_TEST(test_api_start) {
	int value = start_hover();
	fail_unless(value == 1, "1 should be returned!");
}END_TEST

/*!
@brief Make sure the API function for stop hovering is working
@par Test id: \n
 * EJ6 \n
@par Testname: \n
 * Test API function to stop hover\n
@par Preconditions: \n 
 * The initialize function has been called \n
@par Outcome: \n
 * The return value from the API function is 2 \n
*/

START_TEST(test_api_stop) {
	int value = stop_hover();
	fail_unless(value == 2, "2 should be returned!");
}END_TEST

/*!
@brief Make sure the API function for minimizing the speed of the 
       hovering fan is working
@par Test id: \n
 * EJ7 \n
@par Testname: \n
 * Test API function to minimize speed \n
@par Preconditions: \n 
 * The initialize function has been called \n
@par Outcome: \n
 * The return value from the API function is 3 \n
*/

START_TEST(test_api_hover_min) {
	int value = hover_min();
	fail_unless(value == 3, "3 should be returned!");
}END_TEST

/*!
@brief Make sure the API function for maximizing the speed of the 
       hovering fan is working
@par Test id: \n
 * EJ8 \n
@par Testname: \n
 * Test API function to maximize speed \n
@par Preconditions: \n 
 * The initialize function has been called \n
@par Outcome: \n
 * The return value from the API function is 4 \n
*/

START_TEST(test_api_hover_max) {
	int value = hover_max();
	fail_unless(value == 4, "4 should be returned!");
}END_TEST

/*!
@brief Make sure the API function for increasing the speed manually 
       of the hovering fan is working. 
@par Test id: \n
 * EJ9 \n
@par Testname: \n
 * Test API function to increase fan speed \n
@par Preconditions: \n 
 * The initialize function has been called \n
@par Outcome: \n
 * The return value from the API function is 5 \n
*/

START_TEST(test_api_increase_hover_manual) {
	int value = increase_hover_manual();
	fail_unless(value == 5, "5 should be returned!");
}END_TEST

/*!
@brief Make sure the API function for decreasing the speed manually 
       of the hovering fan is working
@par Test id: \n
 * EJ10 \n
@par Testname: \n
 * Test API function decrease fan speed \n
@par Preconditions: \n 
 * The initialize function has been called \n
@par Outcome: \n
 * The return value from the API function is 6 \n
*/

START_TEST(test_api_decrease_hover_manual) {
	int value = decrease_hover_manual();
	fail_unless(value == 6, "6 should be returned!");
}END_TEST

/*!
@brief Make sure the API function for decreasing the speed manually 
       of the hovering fan is working
@par Test id: \n
 * EJ11 \n
@par Testname: \n
 * Test API function to decrease fan speed \n
@par Preconditions: \n 
 * The initialize function has been called \n
@par Outcome: \n
 * The return value from the API function is 7 \n
*/

START_TEST(test_api_decrease_hover_auto) {
	int value = decrease_hover_auto();
	fail_unless(value == 7, "7 should be returned!");
}END_TEST

/*!
@brief Make sure the API function for increasing the speed manually 
       of the hovering fan is working
@par Test id: \n
 * EJ12 \n
@par Testname: \n
 * Test API function to increase fan speed \n
@par Preconditions: \n 
 * The initialize function has been called \n
@par Outcome: \n
 * The return value from the API function is 8 \n
*/

START_TEST(test_api_increase_hover_auto) {
	int value = increase_hover_auto();
	fail_unless(value == 8, "8 should be returned!");
}END_TEST

/*!
@brief Make sure the API function for automatically controlling 
       the speed of the hovering fan is working
@par Test id: \n
 * EJ13 \n
@par Testname: \n
 * Test API function for automatic hover control \n
@par Preconditions: \n 
 * The initialize function has been called \n
@par Outcome: \n
 * The return value from the API function is 9 \n
*/

START_TEST(test_api_autocontrol) {
	int value = autocontrol();
	fail_unless(value == 9, "9 should be returned!");
}END_TEST

/*!
@brief Adds test cases to test suite
*/
Suite * hovering_suite(void) {
	Suite *s = suite_create("Hovering motor controlling test");
	TCase *tc_with_fixture = tcase_create("Core with fixture");
	TCase *tc_without_fixture = tcase_create("Core without fixture");

	tcase_add_checked_fixture(tc_with_fixture, setup, teardown);

	tcase_add_test(tc_without_fixture, test_random);
	tcase_add_test(tc_without_fixture, test_positive);
        tcase_add_test(tc_without_fixture, test_negative);
	tcase_add_test(tc_without_fixture, test_equal);

	tcase_add_test(tc_without_fixture, test_api_start); 
	tcase_add_test(tc_with_fixture, test_api_stop);
	tcase_add_test(tc_with_fixture, test_api_hover_min);
	tcase_add_test(tc_with_fixture, test_api_hover_max);
	tcase_add_test(tc_with_fixture, test_api_increase_hover_manual);
        tcase_add_test(tc_with_fixture, test_api_decrease_hover_manual);
	tcase_add_test(tc_with_fixture, test_api_decrease_hover_auto);
	tcase_add_test(tc_with_fixture, test_api_increase_hover_auto);
	tcase_add_test(tc_with_fixture, test_api_autocontrol);	 

	suite_add_tcase(s, tc_with_fixture);  
	suite_add_tcase(s, tc_without_fixture);

	return s;
}

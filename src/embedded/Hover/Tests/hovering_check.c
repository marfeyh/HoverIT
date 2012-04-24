/*!
@file hovering_check.c
@author Eva-Lisa Kedborn
@author Jing Liu
@author Seyed Ehsan Mohajerani
@author Navid Amiriarshad
@brief Contains the functions that check the hovering control files.
@version 0.4
@date 2012-04-09
*/

#include <check.h>
#include <pin.h> 
#include <stdlib.h> 
#include "../pressure_check.h"
#include "../pressure.h"
#include "../hovering_motor.h"
#include "../hovering_control.h"
#include "../hovering_init_fix.h"

/* Preparation for the tests that need Arduino initialization (Fixture) */
/*!
@brief Initialize Arduino board
@param
@returns
*/
void setup(void) {
	init();
	initialize(USING_PIN, TEST_PIN);
}

/* Finalize for the tests that initilized the Arduino at setoup */
/*!
@brief
@param
@returns
*/
void teardown(void) {
}

/* Id/Title: EN1/Test Motor initiation 
   Purpose: Test correct implementation of motor initiation functions.
   Prerequisites: init(); should be called in the main
   Expected results: The motor should be initiated
   Pass/Fail criteria: When check is run response is 100%: Checks: 4,
                       Failures: 0, Errors: 0/any other results
*/
/*!
@brief
@param
@returns
*/
START_TEST(test_initialize) {
	fail_unless((initialize(USING_PIN, TEST_PIN) == 0), "ard init failed");
}END_TEST

/* Id/Title: EN2/Test pin programming on Arduino board 
   Purpose: Check the function that gets a value and sets this value on
   an output pin on Arduino
   Prerequisites: init(); should be called in the main
   Expected results: The value should be set on the pin
   Pass/Fail criteria: When check is run response is 100%: Checks: 4,
                       Failures: 0, Errors: 0/any other results
*/

/*!
@brief
@param
@returns
*/
START_TEST(test_pin_program) {
	fail_unless((pin_program(using_pin, TEST_PIN, level) \
	== 0),"pin test failed\n");
}END_TEST

/* Id/Title: EN3/Test Check level and fix level 
   Purpose: Check the function which tests the value sending from the 
		set_fix_level function to Arduino pin and fix it in the case 
		of violating boundary values.
   Prerequisites: init(); ans initi
   Expected results: Motor shouldn't stop in the case of any power level 
					that is sent to motor.
   Pass/Fail criteria: When check is run response is 100%: Checks: 4,
                       Failures: 0, Errors: 0/any other results
/////////////////////////////////////////////////////////////////

/*!
@brief
@param
@returns
*/
START_TEST(test_check_and_fix_level) {
	/* A random value between 255 and 1255 which is higher than \
	legal range*/
	int throttle_illegel_high_level = random(1000) +255;
	/* A random value between 133 and 254 which is within the legal range*/
	int throttle_illegel_ok_level = random(111) +133;
	/* A random value between 0 and 132 which is lower than legal range*/
	int throttle_illegel_low_level = randon(132);
	fail_unless((check_and_fix_level(USING_PIN, TEST_PIN \
	throttle_illegel_high_level) == HIGHEST_LEVEL),"pin test failed\n");
	fail_unless((check_and_fix_level(USING_PIN, TEST_PIN, 
	throttle_ok_level) == throttle_ok_level),"pin test failed\n");
	fail_unless((check_and_fix_level(USING_PIN, TEST_PIN, 
	throttle_illegel_low_level) == LOWEST_LEVEL),"pin test failed\n");
}END_TEST



/* Id/Title: EN4/Test Check level and fix level for increase 
   Purpose: Check the function which tests the value sending from increase 
			function
		to Arduino pin and fix it in the case of violating boundary values.
   Prerequisites: init(); ans initi
   Expected results: Motor shouldn't stop in the case of any power level 
					that is sent to motor.
   Pass/Fail criteria: When check is run response is 100%: Checks: 4,
                       Failures: 0, Errors: 0/any other results
/////////////////////////////////////////////////////////////////

/*!
@brief
@param
@returns
*/
START_TEST(test_check_and_fix_level) {
	/* A random value between 255 and 1255 which is higher than \
	legal range*/
	int throttle_illegel_high_level = random(1000) +255;
	/* A random value between 133 and 254 which is within the legal range*/
	int throttle_illegel_ok_level = random(111) +133;
	/* A random value between 0 and 132 which is lower than legal range*/
	int throttle_illegel_low_level = randon(132);
	fail_unless((check_and_fix_level(USING_PIN, TEST_PIN \
	throttle_illegel_high_level) == HIGHEST_LEVEL),"pin test failed\n");
	fail_unless((check_and_fix_level(USING_PIN, TEST_PIN, 
	throttle_ok_level) == throttle_ok_level),"pin test failed\n");
	fail_unless((check_and_fix_level(USING_PIN, TEST_PIN, 
	throttle_illegel_low_level) == LOWEST_LEVEL),"pin test failed\n");
}END_TEST

/* Id/Title: EN5/Test Check level and fix level 
   Purpose: Check the function which tests the value sending from API 
		to Arduino pin and fix it in the case of violating boundary values.
   Prerequisites: init(); ans initi
   Expected results: Motor shouldn't stop in the case of any power level 
					that is sent to motor.
   Pass/Fail criteria: When check is run response is 100%: Checks: 4,
                       Failures: 0, Errors: 0/any other results
/////////////////////////////////////////////////////////////////

/*!
@brief
@param
@returns
*/
START_TEST(test_check_and_fix_level) {
	/* A random value between 255 and 1255 which is higher than \
	legal range*/
	int throttle_illegel_high_level = random(1000) +255;
	/* A random value between 133 and 254 which is within the legal range*/
	int throttle_illegel_ok_level = random(111) +133;
	/* A random value between 0 and 132 which is lower than legal range*/
	int throttle_illegel_low_level = randon(132);
	fail_unless((check_and_fix_level(USING_PIN, TEST_PIN \
	throttle_illegel_high_level) == HIGHEST_LEVEL),"pin test failed\n");
	fail_unless((check_and_fix_level(USING_PIN, TEST_PIN, 
	throttle_ok_level) == throttle_ok_level),"pin test failed\n");
	fail_unless((check_and_fix_level(USING_PIN, TEST_PIN, 
	throttle_illegel_low_level) == LOWEST_LEVEL),"pin test failed\n");
}END_TEST


/* 
   Id/Title: EJ1/test random air pressure
   Purpose: test correct implementation of hoverfan functions
   Prerequisites: none
   Expected results: the correct hoverfan function has been called
   Pass/Fail criteria: when check is run response is 100%: Checks: 4,
                       Failures: 0, Errors: 0/any other results
*/

/*!
@brief
@param
@returns
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

/* 
   Id/Title: EJ2/test air pressure higher than preferred value
   Purpose: test correct implementation of hoverfan functions
   Prerequisites: none
   Expected results: the decrease speed function has been called
   Pass/Fail criteria: when check is run response is 100%: Checks: 4,
                       Failures: 0, Errors: 0/any other results
*/

/*!
@brief
@param
@returns
*/
START_TEST(test_positive) {
	int value = handle_pressure(get_positive());
	fail_unless(value == 1, "1 should be returned!");
}END_TEST

/* 
   Id/Title: EJ3/test air pressure lower than preferred value
   Purpose: test correct implementation of hoverfan functions
   Prerequisites: none
   Expected results: the increase speed function has been called
   Pass/Fail criteria: when check is run response is 100%: Checks: 4,
                       Failures: 0, Errors: 0/any other results
*/

/*!
@brief
@param
@returns
*/
START_TEST(test_negative) {
	int value = handle_pressure(get_negative());
	fail_unless(value == -1, "-1 should be returned!");
}END_TEST

/* 
   Id/Title: EJ4/test air pressure equal to the preferred value
   Purpose: test correct implementation of hoverfan functions
   Prerequisites: none
   Expected results: the speed of the hovering fan is unchanged
   Pass/Fail criteria: when check is run response is 100%: Checks: 4, 
                       Failures: 0, Errors: 0/any other results
*/

/*!
@brief
@param
@returns
*/
START_TEST(test_equal) {
	int value = handle_pressure(get_equal());
	fail_unless(value == 0, "0 should be returned!");
}END_TEST

/*!
@brief Adds test cases and test suite
@param void
@returns
*/
Suite * hovering_suite(void) {
	Suite *s = suite_create("Hovering motor controlling test");
	TCase *tc = tcase_create("Core with fixture");
	TCase *tc2 = tcase_create("Core without fixture");
	tcase_add_checked_fixture(tc_with_fixture, setup, teardown);

	tcase_add_test(tc_without_fixture, test_ard_init);
	tcase_add_test(tc_with_fixture, test_pin_program);  
	tcase_add_test(tc_without_fixture, test_random);
	tcase_add_test(tc_without_fixture, test_positive);
	tcase_add_test(tc_without_fixture, test_negative);
	tcase_add_test(tc_without_fixture, test_equal);

	suite_add_tcase(s, tc_with_fixture);  
	suite_add_tcase(s, tc_without_fixture);

	return s;
}

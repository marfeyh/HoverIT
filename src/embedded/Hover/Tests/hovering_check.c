/*
 * @ Module name:  hovering_check.c
 * @ Description:  Contains the functions that check the hovering control files.
 *
 * @ Author names : Eva-Lisa Kedborn, Jing Liu
 * 		    Seyed Ehsan Mohajerani, Navid Amiriarshad
 * @ Release      : 9 April 2012
 * @ Version      : 1
 * @ Refrences    : Arduino.cc, sandklef.com, Check manual
 */

/* Includes */
#include <stdlib.h>
#include <check.h>
#include "../pressure_check.h"
#include "../pressure.h"
#include "../hovering_motor.h"
#include "../hovering_control.h"
#include "../hovering_init_fix.h"

void setup (void) {
  ard_init(11);
}

void teardown (void) {

}

/* id/title: EN1/test random air pressure
   purpose: test correct implementation of hoverfan functions
   prerequisites: none
   expected results: the correct hoverfan function has been called
   pass/fail criteria: when check is run response is 100%: Checks: 4,
                       Failures: 0, Errors: 0/any other results
*/
START_TEST(test_ard_init) {
	int using_pin=11;
	fail_unless((ard_init(using_pin) == 0),"ard init failed");
	// printf(" test 1 done");
}END_TEST

/* id/title: EN2/test random air pressure
   purpose: test correct implementation of hoverfan functions
   prerequisites: none
   expected results: the correct hoverfan function has been called
   pass/fail criteria: when check is run response is 100%: Checks: 4,
                       Failures: 0, Errors: 0/any other results
*/
START_TEST(test_pin_program) {
	
	int level=100;
	int using_pin=11;
	//printf(" test 2 done");
	fail_unless((pin_program(using_pin,level) == 0),"pin test failed\n");

}END_TEST

/* 
   Id/Title: EJ1/test random air pressure
   Purpose: test correct implementation of hoverfan functions
   Prerequisites: none
   Expected results: the correct hoverfan function has been called
   Pass/Fail criteria: when check is run response is 100%: Checks: 4,
                       Failures: 0, Errors: 0/any other results
*/

START_TEST(test_random) {
	int gap = get_pressure();
	int value = handle_pressure(gap);
	if(gap < 40 && value != -1){
		fail("the value must be -1!");
	}
	if(gap > 60 && value != 1){
		fail("the value must be 1!");
	}
	if((gap >= 40 && gap <= 60) && value != 0) {
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

START_TEST(test_positive) {
	int value = handle_pressure(get_positive());
	fail_unless(value == 1,"1 should be returned!");
}END_TEST

/* 
   Id/Title: EJ3/test air pressure lower than preferred value
   Purpose: test correct implementation of hoverfan functions
   Prerequisites: none
   Expected results: the increase speed function has been called
   Pass/Fail criteria: when check is run response is 100%: Checks: 4,
                       Failures: 0, Errors: 0/any other results
*/

START_TEST(test_negative) {
	int value = handle_pressure(get_negative());
	fail_unless(value == -1,"-1 should be returned!");
}END_TEST

/* 
   Id/Title: EJ2/test air pressure equal to the preferred value
   Purpose: test correct implementation of hoverfan functions
   Prerequisites: none
   Expected results: the speed of the hovering fan is unchanged
   Pass/Fail criteria: when check is run response is 100%: Checks: 4, 
                       Failures: 0, Errors: 0/any other results
*/

START_TEST(test_equal) {
	int value = handle_pressure(get_equal());
	fail_unless(value == 0,"0 should be returned!");
}END_TEST

Suite * hovering_suite(void) {
	Suite *s = suite_create("Hovering motor controlling test");
	TCase *tc = tcase_create("Core with fixture");
	TCase *tc2 = tcase_create("Core without fixture");
	tcase_add_checked_fixture(tc, setup, teardown);
	/* Add test cases */
	tcase_add_test(tc2, test_ard_init);
	tcase_add_test(tc, test_pin_program);  
	tcase_add_test(tc2, test_random);
	tcase_add_test(tc2, test_positive);
	tcase_add_test(tc2, test_negative);
	tcase_add_test(tc2, test_equal);
	
	/* Add to suite */
	suite_add_tcase(s, tc);  
	suite_add_tcase(s, tc2);
	return s;
}

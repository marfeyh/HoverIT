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
#include "../pressure_sensor.h"
#include "../hovering_motor.h"
#include "../hovering_control.h"
#include "../hovering_init_fix.h"

void setup (void) {

}

void teardown (void) {

}

/* Testcase 1 */
START_TEST(test_ard_init) {
	int using_pin=11;
	fail_unless((ard_init(using_pin) == 0),"ard init failed");
}END_TEST

/* Testcase 2 */
START_TEST(test_pin_program) {
	//init_motor();
	int level=100;
	int using_pin=11;
	fail_unless((pin_program(using_pin,level) == 0),"pin test failed\n");
}END_TEST

/* id/title: ej1/test random air pressure
   purpose: test correct implementation of hoverfan functions
   prerequisites: none
   expected results: the correct hoverfan function has been called
   pass/fail criteria: when check is run response is 100%: Checks: 4,
                       Failures: 0, Errors: 0/any other results
*/

START_TEST(test_random){
	float gap = get_pressure();
	int value = handle_pressure(gap);
	if(gap < 40 && value != -1){
		fail("the value must be -1!");
	}
	if(gap > 60 && value != 1){
		fail("the value must be 1!");
	}
	if((gap >= 40 && gap <= 60) && value != 0){
		fail("the value must be 0!");
	}
}END_TEST

/* id/title: ej2/test air pressure higher than preferred value
   purpose: test correct implementation of hoverfan functions
   prerequisites: none
   expected results: the decrease speed function has been called
   pass/fail criteria: when check is run response is 100%: Checks: 4,
                       Failures: 0, Errors: 0/any other results
*/

START_TEST(test_positive){
	int value = handle_pressure(get_positive());
	fail_unless(value==1,"1 should be returned!");
}END_TEST

/* id/title: ej3/test air pressure lowered than preferred value
   purpose: test correct implementation of hoverfan functions
   prerequisites: none
   expected results: the increase speed function has been called
   pass/fail criteria: when check is run response is 100%: Checks: 4,
                       Failures: 0, Errors: 0/any other results
*/

START_TEST(test_negative){
	int value = handle_pressure(get_negative());
	fail_unless(value==-1,"-1 should be returned!");
}END_TEST

/* id/title: ej2/test air pressure equal to the preferred value
   purpose: test correct implementation of hoverfan functions
   prerequisites: none
   expected results: the speed of the hovering fan is unchanged
   pass/fail criteria: when check is run response is 100%: Checks: 4, 
                       Failures: 0, Errors: 0/any other results
*/

START_TEST(test_equal){
	int value = handle_pressure(get_equal());
	fail_unless(value==0,"0 should be returned!");
}END_TEST

Suite * hovering_suite(void){
	Suite *s = suite_create("Hovering motor controlling test");
	TCase *tc = tcase_create("Core");
	tcase_add_checked_fixture(tc,setup,teardown);
	/* Add test cases */
	tcase_add_test(tc,test_ard_init);
	tcase_add_test(tc,test_pin_program);  
	tcase_add_test(tc,test_random);
	tcase_add_test(tc,test_positive);
	tcase_add_test(tc,test_negative);
	tcase_add_test(tc,test_equal);
	
	/* Add to suite */
	suite_add_tcase(s,tc);  
	return s;
}

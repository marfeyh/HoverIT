/*
 * @ Module name:  check_hovering.c
 * @ Description:  Contains the functions that check the hovering control files.
 *
 * @ Author names :Seyed Ehsan Mohajerani, Navid Amiriarshad
 * @ Release      :4 April 2012
 * @ Version      : 1
 * @ Refrences    : Arduino.cc, http://www.sandklef.com, Check manual
 */

/* Includes */
#include <check.h>
#include <stdlib.h>
#include <hovering_motor.h>
#include <hovering_control.h>

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

Suite * propulsion_suite(void) {
	Suite *s = suite_create("Hovering motor controlling test");
	TCase *tc = tcase_create("Core");
	tcase_add_checked_fixture(tc,setup,teardown);
	/* Add test case */
	tcase_add_test(tc,test_ard_init);
	tcase_add_test(tc,test_pin_program);
	/* Add to suite */
	suite_add_tcase(s,tc);
	return s;
}
/* int main or mains??????????????? */ 
int main(void) {
	int number_failed;
	Suite *s = propulsion_suite();
	SRunner *sr = srunner_create(s);
	srunner_run_all(sr, CK_NORMAL);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

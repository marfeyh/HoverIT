/*
Author: Xinran He, Khatereh Khosravianarab
Date: 2012-03-29
Description: check unit test
*/
#include <stdlib.h>
#include <check.h>
#include "../propulsion.h"
#include "../propulsion_api.h"
#define MAXSPEED 122
#define PERSPEED 40

/* This test case is for testing increase_speed function that is for increasing speed and it is passed */
START_TEST(Test_Pro){
	fail_if(increase_speed() != PERSPEED , "Expected 40");
	fail_if(increase_speed() != PERSPEED*2 , "Expected 80");
	fail_if(increase_speed() != PERSPEED*3 , "Expected 120");
	fail_if(increase_speed() != PERSPEED*3 , "Expected 120");
	 
}END_TEST

// This test case is for testing decrease_speed function that is for decreasing speed and it is passed */
START_TEST(test_dec){
	increase_speed();
    fail_if(decrease_speed() != 0 , "Expected 0");
	increase_speed();
	increase_speed();
fail_if(decrease_speed() != PERSPEED , "Expected 40");
	
}END_TEST

// This test case is for testing test_fanLevel function which test the current propulsion fan speed
//level and it is passed.
START_TEST(test_fanlevel){
	increase_speed();
    fail_if(get_fan_level() != 1 ,"Expected 1");
	increase_speed();
	increase_speed();
	fail_if(get_fan_level() != 3 ,"Expected 1");
	decrease_speed();
	fail_if(get_fan_level() != 2 ,"Expected 2");
}END_TEST

//This test case is for stop the propulsion fan speed and it is passed
START_TEST(test_stop){
    increase_speed();
    fail_if(stop_pro_fan() != 0, "Expected 0");
    increase_speed();
    increase_speed();
    fail_if(stop_pro_fan() != 0, "Expected 0");
}END_TEST



Suite * new_suite(void) {
  Suite *s = suite_create("New Suite");
  TCase *tc = tcase_create("New Test Case");
  tcase_add_test(tc, Test_Pro);
  tcase_add_test(tc, test_dec);
  tcase_add_test(tc, test_fanlevel);
  tcase_add_test(tc, test_stop);
  suite_add_tcase(s,tc);
  return s;
}

int main(void) {
  int number_failed;
  Suite *s = new_suite();
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr,CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
} 

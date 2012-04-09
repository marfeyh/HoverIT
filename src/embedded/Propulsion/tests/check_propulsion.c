/*
AUTHORS: Yohanes Kuma, Xinran He, Khatereh Khosravianarab
DATA :2012-04-05
DESCRIPTION: This file is the unit tests for the propulsion and propulsion API
functions. 
*/
#include <check.h>
#include <propulsion.h>
#include <propulsion_api.h>


void setup (void) {
  //nothing for the moment
}

void teardown (void) {
  //nothing for the moment
}

/* PROPULSION API UNIT TESTS */
START_TEST(Test_Pro){
	fail_if(increase_propulsion() != PERSPEED , "Expected 41");
	fail_if(increase_propulsion() != PERSPEED*2 , "Expected 82");
	fail_if(increase_propulsion() != PERSPEED*3 , "Expected 123");
	fail_if(increase_propulsion() != PERSPEED*3 , "Expected 123");
	 
}END_TEST


START_TEST(test_dec){
	increase_propulsion();
	fail_if(decrease_propulsion(), "Expected 0");
	increase_propulsion();
	increase_propulsion();
	fail_if(decrease_propulsion() != PERSPEED , "Expected 41");
	
}END_TEST


START_TEST(test_fanlevel){
	increase_propulsion();
    fail_if(get_propulsion_level() != 1 ,"Expected 1");
	increase_propulsion();
	increase_propulsion();
	fail_if(get_propulsion_level() != 3 ,"Expected 1");
	decrease_propulsion();
	fail_if(get_propulsion_level() != 2 ,"Expected 2");
}END_TEST


START_TEST(test_stop){
    increase_propulsion();
    fail_if(stop_propulsion_fan() != 0, "Expected 0");
    increase_propulsion();
    increase_propulsion();
    fail_if(stop_propulsion_fan() != 0, "Expected 0");
}END_TEST
 /* END OF PROPULSION API UNIT TESTS */


 /* PROPULSION UNIT TESTS */

START_TEST(test_init) {
  fail_unless((initialise_propulsion() == 0),NULL);
 
}END_TEST

START_TEST(test_prepare_motor) {
  init_motor();  
  fail_unless((manage_motor() == 0),NULL);
}END_TEST

START_TEST(test_stop_motor) {
  init_motor(); 
  stop_pro_fan();
  fail_unless((manage_motor() == 1),NULL);
}END_TEST

START_TEST(test_minimum_speed) {
  int level = 1;
  init_motor(); 
  change_pro_speed(level);
  fail_unless((manage_motor() == 2),NULL);
  fail_unless((getSpeedLevel() == 1),NULL);  
}END_TEST

START_TEST(test_maximum_speed) {
  int level = MAX_SPEED_LEVEL;
  init_motor(); 
  change_pro_speed(level);
  fail_unless((manage_motor() == 2),NULL);
  fail_unless((getSpeedLevel() == MAX_SPEED_LEVEL),NULL);  
}END_TEST

Suite * propulsion_suite(void) {
  Suite *s = suite_create("Propulsion_fan");
  TCase *tc = tcase_create("Core");
  tcase_add_checked_fixture(tc,setup,teardown);
  tcase_add_test(tc,test_init);
  tcase_add_test(tc,test_prepare_motor);
  tcase_add_test(tc,test_stop_motor);
  tcase_add_test(tc,test_minimum_speed);
  tcase_add_test(tc,test_maximum_speed);
  tcase_add_test(tc, Test_Pro);
  tcase_add_test(tc, test_dec);
  tcase_add_test(tc, test_fanlevel);
  tcase_add_test(tc, test_stop);
  suite_add_tcase(s,tc);
  return s;
}


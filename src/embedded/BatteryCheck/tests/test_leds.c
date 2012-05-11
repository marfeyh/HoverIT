/*
 * @ Module name:  test_leds.c
 * @ Description:  Contains test cases for testing the function in the certain circumstances
 * @ Author names : Nahid Vafaie
 * @ Release      : 24 April 2012
 * @ Version      : 3
 * @ Refrences    : Arduino.cc, sandklef.com, Check manual
 */

#include <Arduino.h>
#include <searduino.h>
#include <seasim.h>
#include <check.h>
#include "../batteryLevel.h"



void setup (void) {
  init();
  


}

void teardown (void) {
	//Nothing for now
}

/* BatteryMeter UNIT TESTS */




/* 
 Id/Title: tc-01 tests if the voltage of the batery be 818.5
 Purpose: tests if the voltage of the battery is 818.5 it should return value 100
 Prerequisites: Battery be connected to the arduino.
 Expected results: Return value 100
 Pass/Fail criteria: when check is run response is 100%: Checks: 10,
 Failures: 0, Errors: 0
 */


 START_TEST(test_loop_full) {
  
	 seasim_set_generic_input(5 , 818.5, INPUT);
  check();
	 uint16_t value;
	 fail_unless(value == 100);
 

}END_TEST



/* 
 Id/Title: tc-02 tests if the voltage of the batery be 1000
 Purpose: tests if the voltage of the battery is 1000 it should return value 100
 Prerequisites: Battery be connected to the arduino.
 Expected results: Return value 100
 Pass/Fail criteria: when check is run response is 100%: Checks: 10,
 Failures: 0, Errors: 0
 */


START_TEST(test_loop_full2) {
  
	seasim_set_generic_input(5 , 1000, INPUT);
  check();
	unit16_t value;

 
	fail_unless(value == 100);
	
}END_TEST


/* 
 Id/Title: tc-03 tests if the voltage of the batery be 818.3
 Purpose: tests if the voltage of the battery is 818.3 it should return value 80
 Prerequisites: Battery be connected to the arduino.
 Expected results: Return value 80
 Pass/Fail criteria: when check is run response is 100%: Checks: 10,
 Failures: 0, Errors: 0
 */


START_TEST(test_loop_half1) {
	
	seasim_set_generic_input(5 , 818.3, INPUT);
	check();
	unit16_t value;
	
	
	fail_unless(value == 80);
	

}END_TEST

/* 
 Id/Title: tc-04 tests if the voltage of the batery be 613.9
 Purpose: tests if the voltage of the battery is 613.9 it should return value 80
 Prerequisites: Battery be connected to the arduino.
 Expected results: Return value 80
 Pass/Fail criteria: when check is run response is 100%: Checks: 10,
 Failures: 0, Errors: 0
 */

START_TEST(test_loop_half2) {
	seasim_set_generic_input(5 , 613.9, INPUT);
	check();
	unit16_t value;
	fail_unless(value == 80);


}END_TEST


/* 
 Id/Title: tc-05 tests if the voltage of the batery be 613.8
 Purpose: tests if the voltage of the battery is 613.8 it should return value 60
 Prerequisites: Battery be connected to the arduino.
 Expected results: Return value 60
 Pass/Fail criteria: when check is run response is 100%: Checks: 10,
 Failures: 0, Errors: 0
 */

START_TEST(test_loop_lesshalf1) {
 seasim_set_generic_input(5, 613.8, INPUT);
  check();

	unit16_t value;
	fail_unless(value == 60);

}END_TEST


/* 
 Id/Title: tc-06 tests if the voltage of the batery be 409.3
 Purpose: tests if the voltage of the battery is 409.3 it should return value 60
 Prerequisites: Battery be connected to the arduino.
 Expected results: Return value 60
 Pass/Fail criteria: when check is run response is 100%: Checks: 10,
 Failures: 0, Errors: 0
 */

START_TEST(test_loop_lesshalf2) {
  seasim_set_generic_input(5 , 409.3, INPUT);
  check();

	unit16_t value;
	fail_unless(value == 60);

}END_TEST

/* 
 Id/Title: tc-07 tests if the voltage of the batery be 409.2
 Purpose: tests if the voltage of the battery is 409.2 it should return value 40
 Prerequisites: Battery be connected to the arduino.
 Expected results: Return value 40
 Pass/Fail criteria: when check is run response is 100%: Checks: 10,
 Failures: 0, Errors: 0
 */

START_TEST(test_loop_halfempty1) {
  seasim_set_generic_input(5, 409.2, INPUT);
  check();

	unit16_t value;
	fail_unless(value == 40);

}END_TEST

/* 
 Id/Title: tc-08 tests if the voltage of the batery be 204.7
 Purpose: tests if the voltage of the battery is 204.7 it should return value 40
 Prerequisites: Battery be connected to the arduino.
 Expected results: Return value 40
 Pass/Fail criteria: when check is run response is 100%: Checks: 10,
 Failures: 0, Errors: 0
 */

START_TEST(test_loop_halfempty2) {
  seasim_set_generic_input(5 , 204.7, INPUT);
  check();

	unit16_t value;
	fail_unless(value == 40);

}END_TEST


/* 
 Id/Title: tc-09 tests if the voltage of the batery be 204.6
 Purpose: tests if the voltage of the battery is 204.6 it should return value 20
 Prerequisites: Battery be connected to the arduino.
 Expected results: Return value 20
 Pass/Fail criteria: when check is run response is 100%: Checks: 10,
 Failures: 0, Errors: 0
 */

START_TEST(test_loop_empty1) {
  seasim_set_generic_input(5 , 204.6, INPUT);

	unit16_t value;
	fail_unless(value == 20);

}END_TEST

/* 
 Id/Title: tc-10 tests if the voltage of the batery be 1
 Purpose: tests if the voltage of the battery is 1 it should return value 20
 Prerequisites: Battery be connected to the arduino.
 Expected results: Return value 20
 Pass/Fail criteria: when check is run response is 100%: Checks: 10,
 Failures: 0, Errors: 0
 */

START_TEST(test_loop_empty2) {
  seasim_set_generic_input(5 , 1, INPUT);
  check();

	unit16_t value;
	fail_unless(value == 20);

}END_TEST

 


Suite * leds_suite(void) {
  Suite *s = suite_create("Leds");

  TCase *tc = tcase_create("Core");
  tcase_add_checked_fixture(tc,setup,teardown);

  tcase_add_test(tc,test_loop_full);
  //tcase_add_test(tc,test_loop_full2);
 // tcase_add_test(tc,test_loop_half1);
  //tcase_add_test(tc,test_loop_half2);
  //tcase_add_test(tc,test_loop_lesshalf1);
  //tcase_add_test(tc,test_loop_lesshalf2);
  //tcase_add_test(tc,test_loop_halfempty1);
  //tcase_add_test(tc,test_loop_halfempty2);
  //tcase_add_test(tc,test_loop_empty1);
  // tcase_add_test(tc,test_loop_empty2);
  tcase_set_timeout(tc,0);
  suite_add_tcase(s,tc);
  return s;
}

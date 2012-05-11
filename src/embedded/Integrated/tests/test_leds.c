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
 Id/Title: tc-01 tests the initial situation of the leds
 Purpose: tests if all the leds initially work and turn on
 Prerequisites: leds be connected
 Expected results: All the ledpins be in HIGH position
 Pass/Fail criteria: when check is run response is 100%: Checks: 11,
 Failures: 0, Errors: 0
 */

START_TEST(test_init) {

  init_leds();
	fail_unless(digitalRead(ledPin4) == HIGH);
	fail_unless(digitalRead(ledPin3) == HIGH);
    fail_unless(digitalRead(ledPin2) == HIGH);
    fail_unless(digitalRead(ledPin1) == HIGH);

}END_TEST

/* BatteryMeter UNIT TESTS */

/* 
 Id/Title: tc-02 tests if the voltage of the batery be 818.5
 Purpose: tests if the voltage of the battery is 818.5 there should be four leds on.
 Prerequisites: leds be connected, battery be connected to the arduino.
 Expected results: All the ledpins be in HIGH position
 Pass/Fail criteria: when check is run response is 100%: Checks: 11,
 Failures: 0, Errors: 0
 */


 START_TEST(test_loop_full) {
  init_leds();
	 seasim_set_generic_input(19 , 818.5, INPUT);
  check();

 
	fail_unless(digitalRead(ledPin1) == HIGH);
	fail_unless(digitalRead(ledPin2) == HIGH);
    fail_unless(digitalRead(ledPin3) == HIGH);
    fail_unless(digitalRead(ledPin4) == HIGH);

}END_TEST


/* 
 Id/Title: tc-03 tests if the voltage of the batery be 1000
 Purpose: tests if the voltage of the battery is 1000 there should be four leds on.
 Prerequisites: leds be connected, battery be connected to the arduino.
 Expected results: All the ledpins be in HIGH position
 Pass/Fail criteria: when check is run response is 100%: Checks: 11,
 Failures: 0, Errors: 0
 */


START_TEST(test_loop_full2) {
  init_leds();
	seasim_set_generic_input(19 , 1000, INPUT);
  check();

 
	fail_unless(digitalRead(ledPin1) == HIGH);
	fail_unless(digitalRead(ledPin2) == HIGH);
    fail_unless(digitalRead(ledPin3) == HIGH);
    fail_unless(digitalRead(ledPin4) == HIGH);

}END_TEST

/* 
 Id/Title: tc-04 tests if the voltage of the batery be 818.3
 Purpose: tests if the voltage of the battery is 818.3 there should be three leds on.
 Prerequisites: leds be connected, battery be connected to the arduino.
 Expected results: Ledpins 2,3and 4 be in HIGH position and ledpin 1 LOW
 Pass/Fail criteria: when check is run response is 100%: Checks: 11,
 Failures: 0, Errors: 0
 */


 START_TEST(test_loop_half1) {
  init_leds();
	 seasim_set_generic_input(19 , 818.3, INPUT);
  check();
	fail_unless(digitalRead(ledPin1) == LOW);
	fail_unless(digitalRead(ledPin2) == HIGH);
    fail_unless(digitalRead(ledPin3) == HIGH);
    fail_unless(digitalRead(ledPin4) == HIGH);

}END_TEST
/*
START_TEST(test_loop_half2) {
  init_leds();
  check();

 int  SENSOR_VALUE = 613.9;
	fail_unless(digitalRead(ledPin1) == LOW);
	fail_unless(digitalRead(ledPin2) == HIGH);
    fail_unless(digitalRead(ledPin3) == HIGH);
    fail_unless(digitalRead(ledPin4) == HIGH);

}END_TEST

START_TEST(test_loop_lesshalf1) {
  init_leds();
  check();

 int  SENSOR_VALUE = 613.8;
	fail_unless(digitalRead(ledPin1) == LOW);
	fail_unless(digitalRead(ledPin2) == LOW);
    fail_unless(digitalRead(ledPin3) == HIGH);
    fail_unless(digitalRead(ledPin4) == HIGH);

}END_TEST

START_TEST(test_loop_lesshalf2) {
  init_leds();
  check();

  int SENSOR_VALUE = 409.3;
	fail_unless(digitalRead(ledPin1) == LOW);
	fail_unless(digitalRead(ledPin2) == LOW);
    fail_unless(digitalRead(ledPin3) == HIGH);
    fail_unless(digitalRead(ledPin4) == HIGH);

}END_TEST

START_TEST(test_loop_halfempty1) {
  init_leds();
  check();

  int  SENSOR_VALUE = 409.2;
	fail_unless(digitalRead(ledPin1) == LOW);
	fail_unless(digitalRead(ledPin2) == LOW);
    fail_unless(digitalRead(ledPin3) == LOW);
    fail_unless(digitalRead(ledPin4) == HIGH);

}END_TEST

START_TEST(test_loop_halfempty2) {
  init_leds();
  check();

 int SENSOR_VALUE = 204.7;
	fail_unless(digitalRead(ledPin1) == LOW);
	fail_unless(digitalRead(ledPin2) == LOW);
    fail_unless(digitalRead(ledPin3) == LOW);
    fail_unless(digitalRead(ledPin4) == HIGH);

}END_TEST

START_TEST(test_loop_empty1) {
  init_leds();

  int SENSOR_VALUE = 204.6;
	fail_unless(digitalRead(ledPin1) == LOW);
	fail_unless(digitalRead(ledPin2) == LOW);
    fail_unless(digitalRead(ledPin3) == LOW);
    fail_unless(digitalRead(ledPin4) == LOW);

}END_TEST

START_TEST(test_loop_empty2) {
  init_leds();
  check();

 int SENSOR_VALUE = 1;
	fail_unless(digitalRead(ledPin1) == LOW);
	fail_unless(digitalRead(ledPin2) == LOW);
    fail_unless(digitalRead(ledPin3) == LOW);
    fail_unless(digitalRead(ledPin4) == LOW);

}END_TEST

 */
Suite * leds_suite(void) {
  Suite *s = suite_create("Leds");

  TCase *tc = tcase_create("Core");
  tcase_add_checked_fixture(tc,setup,teardown);
  tcase_add_test(tc,test_init);
  tcase_add_test(tc,test_loop_full);
  tcase_add_test(tc,test_loop_full2);
  tcase_add_test(tc,test_loop_half1);
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

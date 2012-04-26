/*
 * @ Module name:  checkmain.c
 * @ Description:  Contains the functions that tests the leds be on and off
 * @ Author names : Nahid Vafaie
 * @ Release      : 20 April 2012
 * @ Version      : 2
 * @ Refrences    : Arduino.cc, sandklef.com, Check manual
 */

#include <Arduino.h>
#include <searduino.h>
#include <check.h>
#include "../fourLedsOn.h"


void setup (void) {
  init();

}

void teardown (void) {

}

/* LedOn UNIT TESTS */

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

/* 
 Id/Title: tc-02 tests leds condition on 100 percentage
 Purpose: tests when battery percentage is 100 then all the leds should be on
 Prerequisites: leds be connected
 Expected results: All the ledpins be in HIGH position
 Pass/Fail criteria: when check is run response is 100%: Checks: 11,
 Failures: 0, Errors: 0
 */

 START_TEST(test_loop_full) {
  init_leds();

  display_percentage(100);
	fail_unless(digitalRead(ledPin1) == HIGH);
	fail_unless(digitalRead(ledPin2) == HIGH);
    fail_unless(digitalRead(ledPin3) == HIGH);
    fail_unless(digitalRead(ledPin4) == HIGH);

}END_TEST

/* 
 Id/Title: tc-03 tests leds condition on 81 percentage
 Purpose: tests when battery percentage is 81 then all the leds should be on
 Prerequisites: leds be connected
 Expected results: All the ledpins be in HIGH position
 Pass/Fail criteria: when check is run response is 100%: Checks: 11,
 Failures: 0, Errors: 0
 */

START_TEST(test_loop_full2) {
  init_leds();

  display_percentage(81);
	fail_unless(digitalRead(ledPin1) == HIGH);
	fail_unless(digitalRead(ledPin2) == HIGH);
    fail_unless(digitalRead(ledPin3) == HIGH);
    fail_unless(digitalRead(ledPin4) == HIGH);

}END_TEST

/* 
 Id/Title: tc-03 tests leds condition on 80 percentage
 Purpose: tests when battery percentage is 80 then leds 2, 3, 4 should be on and led 1 should be off
 Prerequisites: leds be connected
 Expected results: All the ledpins be in HIGH position
 Pass/Fail criteria: when check is run response is 100%: Checks: 11,
 Failures: 0, Errors: 0
 */

START_TEST(test_loop_half1) {
  init_leds();

  display_percentage(80);
	fail_unless(digitalRead(ledPin1) == LOW);
	fail_unless(digitalRead(ledPin2) == HIGH);
    fail_unless(digitalRead(ledPin3) == HIGH);
    fail_unless(digitalRead(ledPin4) == HIGH);

}END_TEST

/* 
 Id/Title: tc-03 tests leds condition on 61 percentage
 Purpose: tests when battery percentage is 61 then leds 2, 3, 4 should be on and led 1 should be off
 Prerequisites: leds be connected
 Expected results: All the ledpins be in HIGH position
 Pass/Fail criteria: when check is run response is 100%: Checks: 11,
 Failures: 0, Errors: 0
 */

START_TEST(test_loop_half2) {
  init_leds();

  display_percentage(61);
	fail_unless(digitalRead(ledPin1) == LOW);
	fail_unless(digitalRead(ledPin2) == HIGH);
    fail_unless(digitalRead(ledPin3) == HIGH);
    fail_unless(digitalRead(ledPin4) == HIGH);

}END_TEST

/* 
 Id/Title: tc-04 tests leds condition on 60 percentage
 Purpose: tests when battery percentage is 60 then leds 3, 4 should be on and leds 1,2 should be off
 Prerequisites: leds be connected
 Expected results: All the ledpins be in HIGH position
 Pass/Fail criteria: when check is run response is 100%: Checks: 11,
 Failures: 0, Errors: 0
 */

START_TEST(test_loop_lesshalf1) {
  init_leds();

  display_percentage(60);
	fail_unless(digitalRead(ledPin1) == LOW);
	fail_unless(digitalRead(ledPin2) == LOW);
    fail_unless(digitalRead(ledPin3) == HIGH);
    fail_unless(digitalRead(ledPin4) == HIGH);

}END_TEST

/* 
 Id/Title: tc-05 tests leds condition on 41 percentage
 Purpose: tests when battery percentage is 41 then leds 3, 4 should be on and leds 1,2 should be off
 Prerequisites: leds be connected
 Expected results: All the ledpins be in HIGH position
 Pass/Fail criteria: when check is run response is 100%: Checks: 11,
 Failures: 0, Errors: 0
 */

START_TEST(test_loop_lesshalf2) {
  init_leds();

  display_percentage(41);
	fail_unless(digitalRead(ledPin1) == LOW);
	fail_unless(digitalRead(ledPin2) == LOW);
    fail_unless(digitalRead(ledPin3) == HIGH);
    fail_unless(digitalRead(ledPin4) == HIGH);

}END_TEST

/* 
 Id/Title: tc-06 tests leds condition on 40 percentage
 Purpose: tests when battery percentage is 40 then led 4 should be on and leds 1,2,3 should be off
 Prerequisites: leds be connected
 Expected results: All the ledpins be in HIGH position
 Pass/Fail criteria: when check is run response is 100%: Checks: 11,
 Failures: 0, Errors: 0
 */

START_TEST(test_loop_halfempty1) {
  init_leds();

  display_percentage(40);
	fail_unless(digitalRead(ledPin1) == LOW);
	fail_unless(digitalRead(ledPin2) == LOW);
    fail_unless(digitalRead(ledPin3) == LOW);
    fail_unless(digitalRead(ledPin4) == HIGH);

}END_TEST

/* 
 Id/Title: tc-07 tests leds condition on 21 percentage
 Purpose: tests when battery percentage is 21 then led 4 should be on and leds 1,2,3 should be off Prerequisites: leds be connected
 Expected results: All the ledpins be in HIGH position
 Pass/Fail criteria: when check is run response is 100%: Checks: 11,
 Failures: 0, Errors: 0
 */

START_TEST(test_loop_halfempty2) {
  init_leds();

  display_percentage(21);
	fail_unless(digitalRead(ledPin1) == LOW);
	fail_unless(digitalRead(ledPin2) == LOW);
    fail_unless(digitalRead(ledPin3) == LOW);
    fail_unless(digitalRead(ledPin4) == HIGH);

}END_TEST

/* 
 Id/Title: tc-08 tests leds condition on 20 percentage
 Purpose: tests when battery percentage is 20 then all the leds should be off
 Prerequisites: leds be connected
 Expected results: All the ledpins be in HIGH position
 Pass/Fail criteria: when check is run response is 100%: Checks: 11,
 Failures: 0, Errors: 0
 */


START_TEST(test_loop_empty1) {
	init_leds();
	
	display_percentage(20);
	fail_unless(digitalRead(ledPin1) == LOW);
	fail_unless(digitalRead(ledPin2) == LOW);
    fail_unless(digitalRead(ledPin3) == LOW);
    fail_unless(digitalRead(ledPin4) == LOW);
	
}END_TEST

/* 
 Id/Title: tc-08 tests leds condition on 1 percentage
 Purpose: tests when battery percentage is 1 then all the leds should be off
 Prerequisites: leds be connected
 Expected results: All the ledpins be in HIGH position
 Pass/Fail criteria: when check is run response is 100%: Checks: 11,
 Failures: 0, Errors: 0
 */

START_TEST(test_loop_empty2) {
	init_leds();
	
	display_percentage(1);
	fail_unless(digitalRead(ledPin1) == LOW);
	fail_unless(digitalRead(ledPin2) == LOW);
    fail_unless(digitalRead(ledPin3) == LOW);
    fail_unless(digitalRead(ledPin4) == LOW);
	
}END_TEST

Suite * leds_suite(void) {
  Suite *s = suite_create("Leds");

  TCase *tc = tcase_create("Core");
  tcase_add_checked_fixture(tc,setup,teardown);
  tcase_add_test(tc,test_init);
  tcase_add_test(tc,test_loop_full);
  tcase_add_test(tc,test_loop_full2);
  tcase_add_test(tc,test_loop_half1);
  tcase_add_test(tc,test_loop_half2);
  tcase_add_test(tc,test_loop_lesshalf1);
  tcase_add_test(tc,test_loop_lesshalf2);
  tcase_add_test(tc,test_loop_halfempty1);
  tcase_add_test(tc,test_loop_halfempty2);
  tcase_add_test(tc,test_loop_empty1);
  tcase_add_test(tc,test_loop_empty2);
  tcase_set_timeout(tc,0);
  suite_add_tcase(s,tc);
  return s;
}

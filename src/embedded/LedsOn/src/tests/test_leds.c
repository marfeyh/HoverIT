/*
 * @ Module name:  checkmain.c
 * @ Description:  Contains the functions that tests the leds be on and off
 * @ Author names : Nahid Vafaie
 * @ Release      : 16 April 2012
 * @ Version      : 1
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

START_TEST(test_init_one) {

  init_leds();
	fail_unless(digitalRead(ledPin4) == HIGH);
	fail_unless(digitalRead(ledPin3) == LOW);

}END_TEST

START_TEST(test_loop) {

  run_leds();
	fail_unless(digitalRead(ledPin4) == LOW);
	fail_unless(digitalRead(ledPin3) == LOW);
    fail_unless(digitalRead(ledPin2) == LOW);
    fail_unless(digitalRead(ledPin1) == LOW);

}END_TEST


START_TEST(test_init_two) {

  init_leds();
	fail_unless(digitalRead(ledPin4) == HIGH);
	fail_unless(digitalRead(ledPin2) == LOW);


}END_TEST


START_TEST(test_init_third) {
  init_leds();
  fail_unless(digitalRead(ledPin4) == HIGH);
  fail_unless(digitalRead(ledPin1) == LOW);

}END_TEST


Suite * leds_suite(void) {
  Suite *s = suite_create("Leds");

  TCase *tc = tcase_create("Core");
  tcase_add_checked_fixture(tc,setup,teardown);
  tcase_add_test(tc,test_init_one);
  tcase_add_test(tc,test_init_two);
  tcase_add_test(tc,test_init_third);
  tcase_add_test(tc,test_loop);
  tcase_set_timeout(tc,0);
  suite_add_tcase(s,tc);
  return s;
}

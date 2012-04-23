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

START_TEST(test_init) {

  init_leds();
	fail_unless(digitalRead(ledPin4) == HIGH);
	fail_unless(digitalRead(ledPin3) == HIGH);
    fail_unless(digitalRead(ledPin2) == HIGH);
    fail_unless(digitalRead(ledPin1) == HIGH);

}END_TEST

 START_TEST(test_loop_full) {
  init_leds();

  display_percentage(100);
	fail_unless(digitalRead(ledPin1) == HIGH);
	fail_unless(digitalRead(ledPin2) == HIGH);
    fail_unless(digitalRead(ledPin3) == HIGH);
    fail_unless(digitalRead(ledPin4) == HIGH);

}END_TEST

START_TEST(test_loop_full2) {
  init_leds();

  display_percentage(90);
	fail_unless(digitalRead(ledPin1) == HIGH);
	fail_unless(digitalRead(ledPin2) == HIGH);
    fail_unless(digitalRead(ledPin3) == HIGH);
    fail_unless(digitalRead(ledPin4) == HIGH);

}END_TEST


START_TEST(test_loop_half1) {
  init_leds();

  display_percentage(80);
	fail_unless(digitalRead(ledPin1) == LOW);
	fail_unless(digitalRead(ledPin2) == HIGH);
    fail_unless(digitalRead(ledPin3) == HIGH);
    fail_unless(digitalRead(ledPin4) == HIGH);

}END_TEST

START_TEST(test_loop_half2) {
  init_leds();

  display_percentage(54);
	fail_unless(digitalRead(ledPin1) == LOW);
	fail_unless(digitalRead(ledPin2) == HIGH);
    fail_unless(digitalRead(ledPin3) == HIGH);
    fail_unless(digitalRead(ledPin4) == HIGH);

}END_TEST

START_TEST(test_loop_lesshalf1) {
  init_leds();

  display_percentage(53);
	fail_unless(digitalRead(ledPin1) == LOW);
	fail_unless(digitalRead(ledPin2) == LOW);
    fail_unless(digitalRead(ledPin3) == HIGH);
    fail_unless(digitalRead(ledPin4) == HIGH);

}END_TEST

START_TEST(test_loop_lesshalf2) {
  init_leds();

  display_percentage(28);
	fail_unless(digitalRead(ledPin1) == LOW);
	fail_unless(digitalRead(ledPin2) == LOW);
    fail_unless(digitalRead(ledPin3) == HIGH);
    fail_unless(digitalRead(ledPin4) == HIGH);

}END_TEST

START_TEST(test_loop_empty1) {
  init_leds();

  display_percentage(27);
	fail_unless(digitalRead(ledPin1) == LOW);
	fail_unless(digitalRead(ledPin2) == LOW);
    fail_unless(digitalRead(ledPin3) == LOW);
    fail_unless(digitalRead(ledPin4) == LOW);

}END_TEST

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
  tcase_add_test(tc,test_loop_empty1);
  tcase_add_test(tc,test_loop_empty2);
  tcase_set_timeout(tc,0);
  suite_add_tcase(s,tc);
  return s;
}

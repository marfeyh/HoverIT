/*
 * @ Module name:  checkmain.c
 * @ Description:  Test battery level alarm to see responses based on battery level
 * @ Author names : Neda MOhammadian,Mahsa Mirtalebi
 * @ Release      :2012.05.01
 * @ Version      : 1
 * @ Refrences    : Arduino.c, Check manual
 */
#include <Arduino.h>
#include <searduino.h>
#include <check.h>
#include "alarm.h"

void setup(void){
  init();
}

void teardown(void){}

START_TEST(test_init){
	init_alarm();
	fail_unless(loop_battery_level(100) == -1);
}END_TEST

START_TEST(test_high_battery){
	init_alarm();
	int i;// here i represents battery percentage
	for(i=100;i>LOW_BATTERY;i--){
		fail_unless(loop_battery_level(i) == -1);
	}
}END_TEST

START_TEST(test_low_battery){
	init_alarm();
	int i;//here i represents number of beeps
	for(i=0;i<LOW_BATTERY_DURATION;i++){
		fail_unless(loop_battery_level(LOW_BATTERY) == 1);
	}
	fail_unless(loop_battery_level(LOW_BATTERY) == -1);
}END_TEST

START_TEST(test_mid_battery){
	init_alarm();
	int i;
	for(i=LOW_BATTERY;i>EMPTY_BATTERY;i--)
		fail_unless(loop_battery_level(i) == -1);
}END_TEST

START_TEST(test_empty_battery){
	init_alarm();
	int i;
	for(i=EMPTY_BATTERY;i>-1;i--)
		fail_unless(loop_battery_level(i) == 0);
}END_TEST

Suite * alarm_suite(void) {
	Suite *s = suite_create("Alarm");
	TCase *tc = tcase_create("Core");
	tcase_add_checked_fixture(tc,setup,teardown);
	tcase_add_test(tc,test_init);
	tcase_add_test(tc,test_high_battery);
	tcase_add_test(tc,test_low_battery);
	tcase_add_test(tc,test_mid_battery);
	tcase_add_test(tc,test_empty_battery);
	tcase_set_timeout(tc,0);
	suite_add_tcase(s,tc);
	return s;
}

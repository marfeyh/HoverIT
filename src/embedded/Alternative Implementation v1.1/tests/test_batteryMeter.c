/*
 * @ Module name  : test_batteryLevel.c
 * @ Description  :  
 * @ Author names : Kuhan Loh Langxian
 * @ Release      : 10 May 2012
 * @ Version      : 1
 * @ Refrences    : Arduino.cc, sandklef.com, Check manual
 */

#include <Arduino.h>
#include <searduino.h>
#include <seasim.h>
#include <check.h>
#include "../batteryMeter.h"



void setup (void) {
  init();
  


}

void teardown (void) {
	
}

/* BatteryMeter UNIT TESTS */




/* 
 Id/Title: tc-01 Tests if the value is 1023 for first battery then will show 100 %
 Purpose: tests if the voltage of the battery is 1023 it should return value 100
 Prerequisites: Battery be connected to the arduino.
 Expected results: Return value 100
 Pass/Fail criteria: when check is run response is 100%: Checks: 10,
 Failures: 0, Errors: 0
 */


 START_TEST(test_loop_0) {
 
	uint8_t value = translate_level(0);
	fail_unless(value == 0x0); 

}END_TEST



/* 
 Id/Title: tc-02 Tests if the value is 843 for first battery then will show 0 %
 Purpose: tests if the voltage of the battery is 843 it should return value 0
 Prerequisites: Battery be connected to the arduino.
 Expected results: Return value 0
 Pass/Fail criteria: when check is run response is 100%: Checks: 10,
 Failures: 0, Errors: 0
 */


START_TEST(test_loop_6) {

	uint8_t value = translate_level(6);
	fail_unless(value == 0x1);
	
}END_TEST


/* 
 Id/Title: tc-03 Tests if value is below 843 for first battery then will show 0 %
 Purpose: tests if the voltage of the battery is 500 it should return value 0
 Prerequisites: Battery be connected to the arduino.
 Expected results: Return value 0
 Pass/Fail criteria: when check is run response is 100%: Checks: 10,
 Failures: 0, Errors: 0
 */


START_TEST(test_loop_13) {
  
	uint8_t value = translate_level(13);
	fail_unless(value == 0x2);
	
}END_TEST

/* 
 Id/Title: tc-04 Tests if the value is 1023 for second battery then will show 100 %
 Purpose: tests if the voltage of the battery is 1023 it should return value 100
 Prerequisites: Battery be connected to the arduino.
 Expected results: Return value 100
 Pass/Fail criteria: when check is run response is 100%: Checks: 10,
 Failures: 0, Errors: 0
 */


START_TEST(test_loop_19) {
  
	uint8_t value = translate_level(19);
	fail_unless(value == 0x3);
	
}END_TEST



/* 
 Id/Title: tc-05 Tests if the value is 843 for second battery then will show 0 %
 Purpose: tests if the voltage of the battery is 843 it should return value 0
 Prerequisites: Battery be connected to the arduino.
 Expected results: Return value 0
 Pass/Fail criteria: when check is run response is 100%: Checks: 10,
 Failures: 0, Errors: 0
 */


START_TEST(test_loop_26) {
  
	uint8_t value = translate_level(26);
	fail_unless(value == 0x4);
	
}END_TEST


/* 
 Id/Title: tc-06 Tests if value is below 843 for second battery then will show 0 %
 Purpose: tests if the voltage of the battery is 500 it should return value 0
 Prerequisites: Battery be connected to the arduino.
 Expected results: Return value 0
 Pass/Fail criteria: when check is run response is 100%: Checks: 10,
 Failures: 0, Errors: 0
 */


START_TEST(test_loop_33) {
  
	uint8_t value = translate_level(33);
	fail_unless(value == 0x5);
	
}END_TEST


/* 
 Id/Title: tc-07 Tests if the value is 1023 for third battery then will show 100 %
 Purpose: tests if the voltage of the battery is 1023 it should return value 100
 Prerequisites: Battery be connected to the arduino.
 Expected results: Return value 100
 Pass/Fail criteria: when check is run response is 100%: Checks: 10,
 Failures: 0, Errors: 0
 */


START_TEST(test_loop_39) {
  
	uint8_t value = translate_level(39);
	fail_unless(value == 0x6);
	
}END_TEST



/* 
 Id/Title: tc-08 Tests if the value is 843 for third battery then will show 0 %
 Purpose: tests if the voltage of the battery is 843 it should return value 0
 Prerequisites: Battery be connected to the arduino.
 Expected results: Return value 0
 Pass/Fail criteria: when check is run response is 100%: Checks: 10,
 Failures: 0, Errors: 0
 */


START_TEST(test_loop_46) {
  
	uint8_t value = translate_level(46);
	fail_unless(value == 0x7);
	
}END_TEST


/* 
 Id/Title: tc-09 Tests if value is below 843 for third battery then will show 0 %
 Purpose: tests if the voltage of the battery is 500 it should return value 0
 Prerequisites: Battery be connected to the arduino.
 Expected results: Return value 0
 Pass/Fail criteria: when check is run response is 100%: Checks: 10,
 Failures: 0, Errors: 0
 */


START_TEST(test_loop_52) {
  
	uint8_t value = translate_level(52);
	fail_unless(value == 0x8);
	
}END_TEST

START_TEST(test_loop_59) {
  
	uint8_t value = translate_level(59);
	fail_unless(value == 0x9);
	
}END_TEST

START_TEST(test_loop_66) {
  
	uint8_t value = translate_level(66);
	fail_unless(value == 0xA);
	
}END_TEST

START_TEST(test_loop_72) {
  
	uint8_t value = translate_level(72);
	fail_unless(value == 0xB);
	
}END_TEST

START_TEST(test_loop_79) {
  
	uint8_t value = translate_level(79);
	fail_unless(value == 0xC);
	
}END_TEST

START_TEST(test_loop_85) {
  
	uint8_t value = translate_level(85);
	fail_unless(value == 0xD);
	
}END_TEST

START_TEST(test_loop_92) {
  
	uint8_t value = translate_level(92);
	fail_unless(value == 0xE);
	
}END_TEST

START_TEST(test_loop_100) {
  
	uint8_t value = translate_level(100);
	fail_unless(value == 0xF);
	
}END_TEST


 


Suite * batteryMeter_suite(void) {
  Suite *s = suite_create("batteryMeter");

  TCase *tc = tcase_create("Core");
  tcase_add_checked_fixture(tc,setup,teardown);

  tcase_add_test(tc,test_loop_0);
  tcase_add_test(tc,test_loop_6);
  tcase_add_test(tc,test_loop_13);
  tcase_add_test(tc,test_loop_19);
  tcase_add_test(tc,test_loop_26);
  tcase_add_test(tc,test_loop_33);
  tcase_add_test(tc,test_loop_39);
  tcase_add_test(tc,test_loop_46);
  tcase_add_test(tc,test_loop_52);
  tcase_add_test(tc,test_loop_59);
  tcase_add_test(tc,test_loop_66);
  tcase_add_test(tc,test_loop_72);
  tcase_add_test(tc,test_loop_79);
  tcase_add_test(tc,test_loop_85);
  tcase_add_test(tc,test_loop_92);
  tcase_add_test(tc,test_loop_100);
  tcase_set_timeout(tc,0);
  suite_add_tcase(s,tc);
  return s;
}

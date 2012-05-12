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
#include "../batteryLevel.h"



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


 START_TEST(test_loop_full1) {
  
	 seasim_set_generic_input(1 , 1023, INPUT);
	 uint8_t value = get_sensor_value();
	 fail_unless(value == 100);
 

}END_TEST



/* 
 Id/Title: tc-02 Tests if the value is 843 for first battery then will show 0 %
 Purpose: tests if the voltage of the battery is 843 it should return value 0
 Prerequisites: Battery be connected to the arduino.
 Expected results: Return value 0
 Pass/Fail criteria: when check is run response is 100%: Checks: 10,
 Failures: 0, Errors: 0
 */


START_TEST(test_loop_empty1) {
  
	seasim_set_generic_input(843 , 0, INPUT);
	uint8_t value = get_sensor_value();
	fail_unless(value == 0);
	
}END_TEST


/* 
 Id/Title: tc-03 Tests if value is below 843 for first battery then will show 0 %
 Purpose: tests if the voltage of the battery is 500 it should return value 0
 Prerequisites: Battery be connected to the arduino.
 Expected results: Return value 0
 Pass/Fail criteria: when check is run response is 100%: Checks: 10,
 Failures: 0, Errors: 0
 */


START_TEST(test_loop_negative1) {
	
	seasim_set_generic_input(1 , 500, INPUT);
	uint8_t value = get_sensor_value();
	fail_unless(value == 0);
	

}END_TEST

/* 
 Id/Title: tc-04 Tests if the value is 1023 for second battery then will show 100 %
 Purpose: tests if the voltage of the battery is 1023 it should return value 100
 Prerequisites: Battery be connected to the arduino.
 Expected results: Return value 100
 Pass/Fail criteria: when check is run response is 100%: Checks: 10,
 Failures: 0, Errors: 0
 */


 START_TEST(test_loop_full2) {
  
	 seasim_set_generic_input(1 , 1023, INPUT);
	 uint8_t value = get_sensor_value();
	 fail_unless(value == 100);
 

}END_TEST



/* 
 Id/Title: tc-05 Tests if the value is 843 for second battery then will show 0 %
 Purpose: tests if the voltage of the battery is 843 it should return value 0
 Prerequisites: Battery be connected to the arduino.
 Expected results: Return value 0
 Pass/Fail criteria: when check is run response is 100%: Checks: 10,
 Failures: 0, Errors: 0
 */


START_TEST(test_loop_empty2) {
  
	seasim_set_generic_input(1 , 843, INPUT);
	uint8_t value = get_sensor_value();
	fail_unless(value == 0);
	
}END_TEST


/* 
 Id/Title: tc-06 Tests if value is below 843 for second battery then will show 0 %
 Purpose: tests if the voltage of the battery is 500 it should return value 0
 Prerequisites: Battery be connected to the arduino.
 Expected results: Return value 0
 Pass/Fail criteria: when check is run response is 100%: Checks: 10,
 Failures: 0, Errors: 0
 */


START_TEST(test_loop_negative2) {
	
	seasim_set_generic_input(1 , 500, INPUT);
	uint8_t value = get_sensor_value();
	fail_unless(value == 0);
	

}END_TEST


/* 
 Id/Title: tc-07 Tests if the value is 1023 for third battery then will show 100 %
 Purpose: tests if the voltage of the battery is 1023 it should return value 100
 Prerequisites: Battery be connected to the arduino.
 Expected results: Return value 100
 Pass/Fail criteria: when check is run response is 100%: Checks: 10,
 Failures: 0, Errors: 0
 */


 START_TEST(test_loop_full3) {
  
	 seasim_set_generic_input(1 , 1023, INPUT);
	 uint8_t value = get_sensor_value();
	 fail_unless(value == 100);
 

}END_TEST



/* 
 Id/Title: tc-08 Tests if the value is 843 for third battery then will show 0 %
 Purpose: tests if the voltage of the battery is 843 it should return value 0
 Prerequisites: Battery be connected to the arduino.
 Expected results: Return value 0
 Pass/Fail criteria: when check is run response is 100%: Checks: 10,
 Failures: 0, Errors: 0
 */


START_TEST(test_loop_empty3) {
  
	seasim_set_generic_input(1 , 843, INPUT);
	uint8_t value = get_sensor_value();
	fail_unless(value == 0);
	
}END_TEST


/* 
 Id/Title: tc-09 Tests if value is below 843 for third battery then will show 0 %
 Purpose: tests if the voltage of the battery is 500 it should return value 0
 Prerequisites: Battery be connected to the arduino.
 Expected results: Return value 0
 Pass/Fail criteria: when check is run response is 100%: Checks: 10,
 Failures: 0, Errors: 0
 */


START_TEST(test_loop_negative3) {
	
	seasim_set_generic_input(1 , 500, INPUT);
	uint8_t value = get_sensor_value();
	fail_unless(value == 0);
	

}END_TEST


 


Suite * batteryLevel_suite(void) {
  Suite *s = suite_create("batteryLevel");

  TCase *tc = tcase_create("Core");
  tcase_add_checked_fixture(tc,setup,teardown);

  tcase_add_test(tc,test_loop_full1);
  tcase_add_test(tc,test_loop_full2);
  tcase_add_test(tc,test_loop_full3);
  tcase_add_test(tc,test_loop_empty1);
  tcase_add_test(tc,test_loop_empty2);
  tcase_add_test(tc,test_loop_empty3);
  tcase_add_test(tc,test_loop_negative1);
  tcase_add_test(tc,test_loop_negative2);
  tcase_add_test(tc,test_loop_negative3);
  // tcase_add_test(tc,test_loop_empty2);
  tcase_set_timeout(tc,0);
  suite_add_tcase(s,tc);
  return s;
}

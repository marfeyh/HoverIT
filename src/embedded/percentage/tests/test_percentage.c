

#include <Arduino.h>
#include <searduino.h>
#include <seasim.h>
#include <check.h>
#include "../percentage.h"



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
	 int value = getPercentage(1);
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
  
	seasim_set_generic_input(1 , 843, INPUT);
	int value = getPercentage(1);
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
	int value = getPercentage(1);
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
  
	 seasim_set_generic_input(2 , 1023, INPUT);
	 int value = getPercentage(2);
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
  
	seasim_set_generic_input(2 , 843, INPUT);
	int value = getPercentage(2);
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
	
	seasim_set_generic_input(2 , 500, INPUT);
	int value = getPercentage(2);
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
  
	 seasim_set_generic_input(3 , 1023, INPUT);
	 int value = getPercentage(3);
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
  
	seasim_set_generic_input(3 , 843, INPUT);
	int value = getPercentage(3);
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
	
	seasim_set_generic_input(3 , 500, INPUT);
	int value = getPercentage(3);
	fail_unless(value == 0);
	

}END_TEST


/* 
 Id/Title: tc-10 Tests if value is 933 for first battery then will show 50 %
 Purpose: tests if the voltage of the battery is 933 it should return value 50
 Prerequisites: Battery be connected to the arduino.
 Expected results: Return value 50
 Pass/Fail criteria: when check is run response is 100%: Checks: 10,
 Failures: 0, Errors: 0
 */


START_TEST(test_loop_half1) {
	
	seasim_set_generic_input(1 , 933, INPUT);
	int value = getPercentage(1);
	fail_unless(value == 50);
	

}END_TEST


/* 
 Id/Title: tc-11 Tests if value is 933 for second battery then will show 50 %
 Purpose: tests if the voltage of the battery is 933 it should return value 50
 Prerequisites: Battery be connected to the arduino.
 Expected results: Return value 50
 Pass/Fail criteria: when check is run response is 100%: Checks: 10,
 Failures: 0, Errors: 0
 */


START_TEST(test_loop_half2) {
	
	seasim_set_generic_input(2 , 933, INPUT);
	int value = getPercentage(2);
	fail_unless(value == 50);
	

}END_TEST


/* 
 Id/Title: tc-12 Tests if value is 933 for third battery then will show 50 %
 Purpose: tests if the voltage of the battery is 933 it should return value 50
 Prerequisites: Battery be connected to the arduino.
 Expected results: Return value 50
 Pass/Fail criteria: when check is run response is 100%: Checks: 10,
 Failures: 0, Errors: 0
 */


START_TEST(test_loop_half3) {
	
	seasim_set_generic_input(3 , 933, INPUT);
	int value = getPercentage(3);
	fail_unless(value == 50);
	

}END_TEST


 /* 
 Id/Title: tc-13 Tests if value is 903 for first battery then will show 33 %
 Purpose: tests if the voltage of the battery is 903 it should return value 33
 Prerequisites: Battery be connected to the arduino.
 Expected results: Return value 33
 Pass/Fail criteria: when check is run response is 100%: Checks: 10,
 Failures: 0, Errors: 0
 */


START_TEST(test_loop_onethird1) {
	
	seasim_set_generic_input(1 , 903, INPUT);
	int value = getPercentage(1);
	fail_unless(value == 33);
	

}END_TEST


 /* 
 Id/Title: tc-14 Tests if value is 903 for second battery then will show 33 %
 Purpose: tests if the voltage of the battery is 903 it should return value 33
 Prerequisites: Battery be connected to the arduino.
 Expected results: Return value 33
 Pass/Fail criteria: when check is run response is 100%: Checks: 10,
 Failures: 0, Errors: 0
 */


START_TEST(test_loop_onethird2) {
	
	seasim_set_generic_input(2 , 903, INPUT);
	int value = getPercentage(2);
	fail_unless(value == 33);
	

}END_TEST


 /* 
 Id/Title: tc-15 Tests if value is 903 for third battery then will show 33 %
 Purpose: tests if the voltage of the battery is 903 it should return value 33
 Prerequisites: Battery be connected to the arduino.
 Expected results: Return value 33
 Pass/Fail criteria: when check is run response is 100%: Checks: 10,
 Failures: 0, Errors: 0
 */


START_TEST(test_loop_onethird3) {
	
	seasim_set_generic_input(3 , 903, INPUT);
	int value = getPercentage(3);
	fail_unless(value == 33);
	

}END_TEST


Suite * percentage_suite(void) {
  Suite *s = suite_create("Percentage");

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
  tcase_add_test(tc,test_loop_half1);
  tcase_add_test(tc,test_loop_half2);
  tcase_add_test(tc,test_loop_half3);
  tcase_add_test(tc,test_loop_onethird1);
  tcase_add_test(tc,test_loop_onethird2);
  tcase_add_test(tc,test_loop_onethird3);
  tcase_set_timeout(tc,0);
  suite_add_tcase(s,tc);
  return s;
}

/**
 * \file 		test_case_1_gps.c
 * \date 		24-04-2012
 * \version 	0.1 
 * \author 		Mozhan Soltani          
 * \attention 	Sections added/modified are as follow:
 * 				- The eight test cases, the test suite "gprmc_suite" and the main funtion were provided.  
 * 				- The correct gps data was borrowed from http://www.gpsinformation.org/dale/nmea.htm
 */

#include <check.h>
#include <stdlib.h>
#include "gps.h"

/**
 * Purpose: To check if a correct GPRMC data is recognized when it is passed to the function "is_GPRMC". 
 * Action: A standard GPRMC is passed to the function "is_GPRMC" 
 * Expected outcome: The function should return 0.
 */

START_TEST(test_case_1_1) {
  int ret = is_GPRMC("$GPRMC,123519,A,4807.038,N,01131.000,E,022.4,084.4,230394,003.1,W*6A");
  fail_unless( ret ==0);
}END_TEST /* test case GPRMC_test1 */

/**
 * Purpose: To check if a defective GPRMC data is recognized when it is passed to the function "is_GPRMC". 
 * Action: A defective GPRMC with the first argument as "GPRMC" is passed to the function "is_GPRMC" 
 * Expected outcome: The function should return 1.
 */

START_TEST(test_case_1_2) {
  int ret = is_GPRMC("GPRMC,123519,A,4807.038,N,01131.000,E,022.4,084.4,230394,003.1,W*6A");
  fail_if( ret != 1	, "The function is_GPRMC does not distinguish between \"$GPRMC\" and \"GPRMC\"!");
}END_TEST /* test case GPRMC_test2 */

/**
 * Purpose: To check if a defective GPRMC data is recognized when it is passed to the function "is_GPRMC". 
 * Action: A defective GPRMC data with the first argument as "$GPRM" is passed to the function "is_GPRMC" 
 * Expected outcome: The function should return 1.
 */

START_TEST(test_case_1_3) {
  int ret = is_GPRMC("$GPRM,123519,A,4807.038,N,01131.000,E,022.4,084.4,230394,003.1,W*6A");
  fail_if( ret != 1	, "The function is_GPRMC does not distinguish between \"$GPRMC\" and \"$GPRM\"!");
}END_TEST /* test case GPRMC_test3 */

/**
 * Purpose: To check if a defective GPRMC data is recognized when it is passed to the function "is_GPRMC". 
 * Action: A defective GPRMC data with the first argument as "$PRMC" is passed to the function "is_GPRMC" 
 * Expected outcome: The function should return 1.
 */

START_TEST(test_case_1_4) {
  int ret = is_GPRMC("$PRMC,123519,A,4807.038,N,01131.000,E,022.4,084.4,230394,003.1,W*6A");
  fail_if( ret != 1	, "The function is_GPRMC does not distinguish between \"$GPRMC\" and \"$PRMC\"!");
}END_TEST /* test case GPRMC_test4 */

/**
 * Purpose: To check if a defective GPRMC data is recognized when it is passed to the function "is_GPRMC". 
 * Action: A defective GPGGA data with the first argument as "$G" is passed to the function "is_GPRMC" 
 * Expected outcome: The function should return 1.
 */

START_TEST(test_case_1_5) {
  int ret = is_GPRMC("$G,123519,A,4807.038,N,01131.000,E,022.4,084.4,230394,003.1,W*6A");
  fail_if( ret != 1	, "The function is_GPRMC does not distinguish between \"$GPRMC\" and \"$G\"!");
}END_TEST /* test case GPRMC_test5 */

/**
 * Purpose: To check if a defective GPRMC data is recognized when it is passed to the function "is_GPRMC". 
 * Action: A defective GPRMC data with the first argument as "$" is passed to the function "is_GPRMC" 
 * Expected outcome: The function should return 1.
 */

START_TEST(test_case_1_6) {
  int ret = is_GPRMC("$,123519,A,4807.038,N,01131.000,E,022.4,084.4,230394,003.1,W*6A");
  fail_if( ret != 1	, "The function is_GPRMC does not distinguish between \"$GPRMC\" and \"$\"!");
}END_TEST /* test case GPRMC_test6 */

/**
 * Purpose: To check if a defective GPRMC data is recognized when it is passed to the function "is_GPRMC". 
 * Action: A defective GPRMC data with the first argument as "" is passed to the function "is_GPRMC" 
 * Expected outcome: The function should return 1.
 */

START_TEST(test_case_1_7) {
  int ret = is_GPRMC(",123519,A,4807.038,N,01131.000,E,022.4,084.4,230394,003.1,W*6A");
  fail_if( ret != 1	, "The function is_GPRMC does not distinguish between \"$GPRMC\" and \"\"!");
}END_TEST /* test case GPRMC_test7 */

/**
 * Purpose: To check if a defective GPRMC data is recognized when it is passed to the function "is_GPRMC". 
 * Action: A defective GPRMC data with the first argument as "123519" is passed to the function "is_GPRMC" 
 * Expected outcome: The function should return 1.
 */

START_TEST(test_case_1_8) {
  int ret = is_GPRMC("123519,A,4807.038,N,01131.000,E,022.4,084.4,230394,003.1,W*6A");
  fail_if( ret != 1	, "The function is_GPRMC does not distinguish between \"$GPRMC\" and \"123519\"!");
}END_TEST /* test case GPRMC_test8 */

/**
 * Returns a gprmc suite pointer containing the 8 defined test cases above.
 */

/*
 Suite * gprmc_suite(void) {

  Suite *suite = suite_create("GPRMC Suite");
  TCase *tc_limits = tcase_create ("Test case limits"); 
  
  tcase_add_test (tc_limits, GPRMC_test1);
  tcase_add_test (tc_limits, GPRMC_test2);
  tcase_add_test (tc_limits, GPRMC_test3);
  tcase_add_test (tc_limits, GPRMC_test4);
  tcase_add_test (tc_limits, GPRMC_test5);
  tcase_add_test (tc_limits, GPRMC_test6);
  tcase_add_test (tc_limits, GPRMC_test7);
  tcase_add_test (tc_limits, GPRMC_test8);
  
  suite_add_tcase (suite, tc_limits);
  return suite;


int main(void) {
  // will be used to get the number of the failed test cases.
  int failed_num;
  Suite *gprmc_s = gprmc_suite();
  
  //A suite runner object of SRunner is created using the suite returned from gprmc_suite.
  SRunner *gprmc_sr = srunner_create(gprmc_s); 
  //The suite is run and a summary and list of the occurred failures is printed out.
  srunner_run_all(gprmc_sr,CK_NORMAL); 
  //The number of the occurred failures is captured.
  failed_num = srunner_ntests_failed(gprmc_sr); 
  srunner_free(gprmc_sr);
  return (failed_num == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
} 
  */

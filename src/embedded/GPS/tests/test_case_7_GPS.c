/**
 * \file 		test_case_7_gps.c
 * \date 		24-04-2012
 * \version 	0.1 
 * \author 		Mozhan Soltani          
 * \attention 	Sections added/modified are as follow:
 * 				- The eight test cases, the test suite "gpgga_suite"  and the main funtion were provided.  
 * 				- The correct gps data was borrowed from http://www.gpsinformation.org/dale/nmea.htm
 */
 

#include <check.h>
#include <stdlib.h>
#include "gps.h"

/**
 * Purpose: To check if a correct GPGGA data is recognized when it is passed to the function "is_GPGGA". 
 * Action: A standard GPGGA is passed to the function "is_GPGGA" 
 * Expected outcome: The function should return 0.
 */

START_TEST(test_case_7_1) {
  int ret = is_GPGGA("$GPGGA,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47");
  fail_unless( ret ==0);
}END_TEST /* test case GPGGA_test1 */

/**
 * Purpose: To check if a defective GPGGA data is recognized when it is passed to the function "is_GPGGA". 
 * Action: A defective GPGGA with the first argument as "GPGGA" is passed to the function "is_GPGGA" 
 * Expected outcome: The function should return 1.
 */

START_TEST(test_case_7_2) {
  int ret = is_GPGGA("GPGGA,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47");
  fail_if( ret != 1	, "The function is_GPGGA does not distinguish between \"$GPGGA\" and \"GPGGA\"!");
}END_TEST /* test case GPGGA_test2 */

/**
 * Purpose: To check if a defective GPGGA data is recognized when it is passed to the function "is_GPGGA". 
 * Action: A defective GPGGA data with the first argument as "$GPGG" is passed to the function "is_GPGGA" 
 * Expected outcome: The function should return 1.
 */

START_TEST(test_case_7_3) {
  int ret = is_GPGGA("$GPGG,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47");
  fail_if( ret != 1	, "The function is_GPGGA does not distinguish between \"$GPGGA\" and \"$GPGG\"!");
}END_TEST /* test case GPGGA_test3 */

/**
 * Purpose: To check if a defective GPGGA data is recognized when it is passed to the function "is_GPGGA". 
 * Action: A defective GPGGA data with the first argument as "$PGGA" is passed to the function "is_GPGGA" 
 * Expected outcome: The function should return 1.
 */

START_TEST(test_case_7_4) {
  int ret = is_GPGGA("$PGGA,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47");
  fail_if( ret != 1	, "The function is_GPGGA does not distinguish between \"$GPGGA\" and \"$PGGA\"!");
}END_TEST /* test case GPGGA_test4 */

/**
 * Purpose: To check if a defective GPGGA data is recognized when it is passed to the function "is_GPGGA". 
 * Action: A defective GPGGA data with the first argument as "$G" is passed to the function "is_GPGGA" 
 * Expected outcome: The function should return 1.
 */
 
START_TEST(test_case_7_5) {
  int ret = is_GPGGA("$G,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47");
  fail_if( ret != 1	, "The function is_GPGGA does not distinguish between \"$GPGGA\" and \"$G\"!");
}END_TEST /* test case GPGGA_test5 */

/**
 * Purpose: To check if a defective GPGGA data is recognized when it is passed to the function "is_GPGGA". 
 * Action: A defective GPGGA data with the first argument as "$" is passed to the function "is_GPGGA" 
 * Expected outcome: The function should return 1.
 */

START_TEST(test_case_7_6) {
  int ret = is_GPGGA("$,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47");
  fail_if( ret != 1	, "The function is_GPGGA does not distinguish between \"$GPGGA\" and \"$\"!");
}END_TEST /* test case GPGGA_test6 */

/**
 * Purpose: To check if a defective GPGGA data is recognized when it is passed to the function "is_GPGGA". 
 * Action: A defective GPGGA data with the first argument as "" is passed to the function "is_GPGGA" 
 * Expected outcome: The function should return 1.
 */

START_TEST(test_case_7_7) {
  int ret = is_GPGGA(",123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47");
  fail_if( ret != 1	, "The function is_GPGGA does not distinguish between \"$GPGGA\" and \"\"!");
}END_TEST /* test case GPGGA_test7 */

/**
 * Purpose: To check if a defective GPGGA data is recognized when it is passed to the function "is_GPGGA". 
 * Action: A defective GPGGA data with the first argument as "123519" is passed to the function "is_GPGGA" 
 * Expected outcome: The function should return 1.
 */

START_TEST(test_case_7_8) {
  int ret = is_GPGGA("123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47");
  fail_if( ret != 1	, "The function is_GPGGA does not distinguish between \"$GPGGA\" and \"123519\"!");
}END_TEST /* test case GPGGA_test8 */

/**
 * Returns a gpgga suite pointer containing the 8 defined test cases above.
 */
/*
Suite * gpgga_suite(void) {

  Suite *suite = suite_create("GPGGA Suite");
  TCase *tc_limits = tcase_create ("Test case limits");
  
  tcase_add_test (tc_limits, GPGGA_test1);
  tcase_add_test (tc_limits, GPGGA_test2);
  tcase_add_test (tc_limits, GPGGA_test3);
  tcase_add_test (tc_limits, GPGGA_test4);
  tcase_add_test (tc_limits, GPGGA_test5);
  tcase_add_test (tc_limits, GPGGA_test6);
  tcase_add_test (tc_limits, GPGGA_test7);
  tcase_add_test (tc_limits, GPGGA_test8);
  
  suite_add_tcase (suite, tc_limits);
  return suite;
} 



int main(void) {
  //Will be used to get the number of the failed test cases.
  int failed_num;
  Suite *gpgga_s = gpgga_suite(); 
  
  //A suite runner object of SRunner is created using the suite returned from gpgga_suite.
  SRunner *gpgga_sr = srunner_create(gpgga_s); 
  //The suite is run and a summary and list of the occurred failures is printed out.
  srunner_run_all(gpgga_sr,CK_NORMAL);
  //The number of the occurred failures is captured.
  failed_num = srunner_ntests_failed(gpgga_sr);  
  srunner_free(gpgga_sr);
  return (failed_num == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
} 
  */

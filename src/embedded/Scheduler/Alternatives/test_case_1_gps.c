#include <check.h>
#include <stdlib.h>
#include "gps.h"

START_TEST(GPRMC_test1) {
  int ret = is_GPRMC("$GPRMC,123519,A,4807.038,N,01131.000,E,022.4,084.4,230394,003.1,W*6A");
  fail_unless( ret ==0);
}END_TEST

START_TEST(GPRMC_test2) {
  int ret = is_GPRMC("GPRMC,123519,A,4807.038,N,01131.000,E,022.4,084.4,230394,003.1,W*6A");
  fail_if( ret != 1	, "The function is_GPRMC does not distinguish between \"$GPRMC\" and \"GPRMC\"!");
}END_TEST

START_TEST(GPRMC_test3) {
  int ret = is_GPRMC("$GPRM,123519,A,4807.038,N,01131.000,E,022.4,084.4,230394,003.1,W*6A");
  fail_if( ret != 1	, "The function is_GPRMC does not distinguish between \"$GPRMC\" and \"$GPRM\"!");
}END_TEST

START_TEST(GPRMC_test4) {
  int ret = is_GPRMC("$PRMC,123519,A,4807.038,N,01131.000,E,022.4,084.4,230394,003.1,W*6A");
  fail_if( ret != 1	, "The function is_GPRMC does not distinguish between \"$GPRMC\" and \"$PRMC\"!");
}END_TEST

START_TEST(GPRMC_test5) {
  int ret = is_GPRMC("$G,123519,A,4807.038,N,01131.000,E,022.4,084.4,230394,003.1,W*6A");
  fail_if( ret != 1	, "The function is_GPRMC does not distinguish between \"$GPRMC\" and \"$G\"!");
}END_TEST

START_TEST(GPRMC_test6) {
  int ret = is_GPRMC("$,123519,A,4807.038,N,01131.000,E,022.4,084.4,230394,003.1,W*6A");
  fail_if( ret != 1	, "The function is_GPRMC does not distinguish between \"$GPRMC\" and \"$\"!");
}END_TEST

START_TEST(GPRMC_test7) {
  int ret = is_GPRMC(",123519,A,4807.038,N,01131.000,E,022.4,084.4,230394,003.1,W*6A");
  fail_if( ret != 1	, "The function is_GPRMC does not distinguish between \"$GPRMC\" and \"\"!");
}END_TEST

START_TEST(GPRMC_test8) {
  int ret = is_GPRMC("123519,A,4807.038,N,01131.000,E,022.4,084.4,230394,003.1,W*6A");
  fail_if( ret != 1	, "The function is_GPRMC does not distinguish between \"$GPRMC\" and \"123519\"!");
}END_TEST



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
}

int main(void) {
  int failed_num;
  Suite *gprmc_s = gprmc_suite();
  SRunner *gprmc_sr = srunner_create(gprmc_s);
  srunner_run_all(gprmc_sr,CK_NORMAL);
  failed_num = srunner_ntests_failed(gprmc_sr);
  srunner_free(gprmc_sr);
  return (failed_num == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
} 
  

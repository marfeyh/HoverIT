/*
 * @ Module name  : checkmain.c
 * @ Description  :  
 * @ Author names : Kuhan Loh
 * @ Release      : 11 May 2012
 * @ Version      : 1
 * @ Refrences    : Arduino.cc, sandklef.com, Check manual
 */

#include <stdlib.h>
#include "test_batteryMeter.c"

int main(void) {
  int number_failed;
  Suite *s = batteryMeter_suite();
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

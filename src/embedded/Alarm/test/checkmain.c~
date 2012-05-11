/*
 * @ Module name:  checkmain.c
 * @ Description:  Contains the functions that tests the Alarming system
 * @ Author names : Neda Mohammadian
 * @ Release      : 23 April 2012
 * @ Version      : 1
 
 */

#include <stdlib.h>
#include "test_alarm.c"

main(void) {
  int number_failed;
  Suite *s = alarm_suite();
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

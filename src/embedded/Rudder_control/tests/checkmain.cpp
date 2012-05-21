/*
 * @file checkmain.cpp
 * @brief: Description: main function for Check tests.
 * @author: Paulius Vysniauskas, David Giorgidze.
 * @date: 2012-04-04.
 */

#include <stdlib.h>
#include "check_RuddarControll.h"

main(void) {
  int number_failed;
  Suite *s = rudder_suite();
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
} 

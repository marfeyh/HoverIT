/*!
 @file check_propulsion.c
 @author Yohanes Kuma
 @author Xinran He
 @author Khatereh Khosravianarab
 @author Ezeh Prince Anthony Anayo
 @brief This file is main function for unit testing propulsion, propulsion
  API and brake propulsion functions.
 @date 2012-05-10
 @reference http://check.sourceforge.net/doc/check_html/index.html#SEC_Top
*/

#include <stdlib.h>
#include <check.h>
#include "check_propulsion.h"

int main(void) {
  int number_failed;
  Suite *s = propulsion_suite();
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

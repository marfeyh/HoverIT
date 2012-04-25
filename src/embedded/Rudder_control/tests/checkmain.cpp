/*
 * Author: Paulius Vysniauskas, David Giorgidze.
 * Date: 2012-04-04.
 * Test case main file.
 *
 */

#include <stdlib.h>
#include "ruddar_check.h"

main(void) {
  int number_failed;
  Suite *s = calc_suite();
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
} 

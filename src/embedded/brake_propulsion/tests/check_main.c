/*!
 * @author: Xinran He
 * @author: Ezeh Prince Anthony Anayo
 * @description: The main function for the unit tests of braking and reversing 
   the direction of the propulsion fan
 * @date: 2012-05-02
 * @version: 0.2
 * @reference:http://check.sourceforge.net/doc/check_html/index.html#SEC_Top
 */
 
#include <stdlib.h>
#include <check.h>
#include "check_propulsion.h"

int main(void) {
  int number_failed;
  Suite *s = brake_pro_suite();
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

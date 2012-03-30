#include <check.h>
#include "../../src/propelsion.h"

//CalcStatePtr calc = NULL;

void setup (void) {
  //initialise_propelsion();
}

void teardown (void) {
}

START_TEST(test_init) {
  fail_unless((initilalise_propelsion() == 0),
	      "Expected buffer content: ");
 
}END_TEST

Suite * propelsion_suite(void) {
  Suite *s = suite_create("Propelsion_fan");
  TCase *tc = tcase_create("Core");
  tcase_add_checked_fixture(tc,setup,teardown);
  tcase_add_test(tc,test_init);
  //tcase_add_test(tc,test_division);
  suite_add_tcase(s,tc);
  return s;
}
main(void) {
  int number_failed;
  Suite *s = propelsion_suite();
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

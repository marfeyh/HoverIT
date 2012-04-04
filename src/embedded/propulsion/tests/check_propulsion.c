#include <check.h>
#include <stdlib.h>
#include <propulsion.h>

//CalcStatePtr calc = NULL;

void setup (void) {
  //initialise_propulsion();
}

void teardown (void) {
}

START_TEST(test_init) {
  fail_unless((initialise_propulsion() == 0),NULL);
 
}END_TEST

START_TEST(test_prepare_motor) {
  init_motor();  
  fail_unless((get_motor_status() == 0),
	      "Initialisation failed\n");
}END_TEST

Suite * propulsion_suite(void) {
  Suite *s = suite_create("Propulsion_fan");
  TCase *tc = tcase_create("Core");
  tcase_add_checked_fixture(tc,setup,teardown);
  tcase_add_test(tc,test_init);
  //tcase_add_test(tc,test_division);
  suite_add_tcase(s,tc);
  return s;
}
main(void) {
  int number_failed;
  Suite *s = propulsion_suite();
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

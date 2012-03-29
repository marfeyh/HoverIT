#include <check.h>
#include "../src/propelsion.h"
#include "../src/pro_api.h"
#define MAXSPEED 122
#include <stdlib.h>
#define LEVEL 41

START_TEST(Test_Pro){
	fail_if(increase_speed() != 41 , "Expected 41"); 
}END_TEST


START_TEST(test_dec){
    fail_if(decrease_speed() != -41 , "Expected -41");
}END_TEST


START_TEST(test_fanlevel){
    fail_if(get_fan_level() != 0 ,"Expected 0");
}END_TEST


//START_TEST(test_stop){
//    fail_if(stop_pro_fan() != 0, "Expected 0");
//}END_TEST



Suite * new_suite(void) {
  Suite *s = suite_create("New Suite");
  TCase *tc = tcase_create("New Test Case");
  tcase_add_test(tc, Test_Pro);
  tcase_add_test(tc, test_dec);
  tcase_add_test(tc, test_fanlevel);
 // tcase_add_test(tc, test_stop);
  suite_add_tcase(s,tc);
  return s;
}

int main(void) {
  int number_failed;
  Suite *s = new_suite();
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr,CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
} 

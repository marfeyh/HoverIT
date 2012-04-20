#include <check.h>
#include "../src/pressure_loop.h"
#include "../src/pressure_sensor.h"
#include <stdlib.h>

START_TEST(test){
  float gap = get_gap();
  /* int value = handle_pressure(gap); */
  /* fail_unless(gap<-10&&value!=-1,"the value must be -1"); */
  /* fail_unless(gap>10&&value!=1,"the value must be 1"); */
  /* fail_unless((gap>=-10&&gap<=10)&&value!=0,"the value must be 0"); */
  fail_unless(gap==1,"whatever");

}END_TEST

Suite * new_suite(void){
  Suite *s = suite_create("NEW SUITE");
  TCase *tc = tcase_create("NEW Test Case");
  tcase_add_test(tc,test);
  suite_add_tcase(s,tc);
  return s;
}

int main(void){
  int number_failed;
  Suite *s = new_suite();
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr,CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed ==0)? EXIT_SUCCESS: EXIT_FAILURE;
}

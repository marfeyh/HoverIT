/*
Author: Eva-Lisa Kedborn, Jing Liu
Date: 2012-03-26
Description: test code written in check for pressure_loop.c
*/

#include <check.h>
#include "../src/pressure_check.h"
#include "../src/pressure_sensor.h"
#include <stdlib.h>

/* id/title: ej1/test random air pressure
   purpose: test correct implementation of hoverfan functions
   prerequisites: none
   expected results: the correct hoverfan function has been called
   pass/fail criteria: when check is run response is 100%: Checks: 4, 
                       Failures: 0, Errors: 0/any other results
*/

START_TEST(test_random){   
  float gap = get_gap();
  int value = handle_pressure(gap);
  if(gap<-10 && value!=-1){
    fail("the value must be -1!");
  }
  if(gap>10 && value!=1){
    fail("the value must be 1!");
  }
  if((gap>=-10 && gap<=10) && value!=0){
    fail("the value must be 0!");
  }

}END_TEST

/* id/title: ej2/test air pressure higher than preferred value
   purpose: test correct implementation of hoverfan functions
   prerequisites: none
   expected results: the decrease speed function has been called
   pass/fail criteria: when check is run response is 100%: Checks: 4, 
                       Failures: 0, Errors: 0/any other results
*/

START_TEST(test_positive){
  int value = handle_pressure(get_positive());
  fail_unless(value==1,"1 should be returned!");
}END_TEST

/* id/title: ej3/test air pressure lowered than preferred value
   purpose: test correct implementation of hoverfan functions
   prerequisites: none
   expected results: the increase speed function has been called
   pass/fail criteria: when check is run response is 100%: Checks: 4, 
                       Failures: 0, Errors: 0/any other results
*/

START_TEST(test_negative){
  int value = handle_pressure(get_negative());
  fail_unless(value==-1,"-1 should be returned!");
}END_TEST

/* id/title: ej2/test air pressure equal to the preferred value
   purpose: test correct implementation of hoverfan functions
   prerequisites: none
   expected results: the speed of the hovering fan is unchanged
   pass/fail criteria: when check is run response is 100%: Checks: 4, 
                       Failures: 0, Errors: 0/any other results
*/

START_TEST(test_equal){
  int value = handle_pressure(get_equal());
  fail_unless(value==0,"0 should be returned!");
}END_TEST

Suite * new_suite(void){
  Suite *s = suite_create("NEW SUITE");
  TCase *tc = tcase_create("NEW Test Case");
  tcase_add_test(tc,test_random);
  tcase_add_test(tc,test_positive);
  tcase_add_test(tc,test_negative);
  tcase_add_test(tc,test_equal);
  suite_add_tcase(s,tc);
  return s;
}


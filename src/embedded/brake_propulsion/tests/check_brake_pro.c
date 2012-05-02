/*
  AUTHORS: Xinran He, Ezeh Prince Anthony Anayo
  DATA :2012-05-02
  DESCRIPTION: This file is the unit tests for brakeing 
	       propulsion fan 
               check libraries are used as a tool for the unit tests. 
               check their manual for details.
  http://check.sourceforge.net/doc/check_html/index.html#SEC_Top
*/
#include <check.h>
#include <propulsion.h>
#include <propulsion_api.h>

void setup(void){
  //nothing for the moment
}

void teardown(void){
  //nothing for the moment
}

/* PROPULSION_API UNIT TESTS */

/* 
   Id/Title: XA1/
   Purpose: 
   Prerequisites: 
   Expected results: 
   Pass/Fail criteria: 
*/
START_TEST(test_reverse_prop){
  
}END_TEST


/* 
   Id/Title: XA1/
   Purpose: 
   Prerequisites: 
   Expected results: 
   Pass/Fail criteria: 
*/
START_TEST(test_brake_pro){

}END_TEST

 /* END OF PROPULSION UNIT TESTS*/


 /* Creates test suit for check. see check manual for details
    http://check.sourceforge.net/doc/check_html/index.html#SEC_Top
 */
Suite * brake_pro_suite(void) {
  Suite *s = suite_create("brake_pro_fan");
  TCase *tc = tcase_create("Core");
  tcase_add_checked_fixture(tc, setup, teardown);
  tcase_add_test(tc, test_reverse_prop);
  tcase_add_test(tc, test_brake_pro);
  suite_add_tcase(s, tc);
  return s;
}

/*!
 * @file: check_brake_pro.c
 * @description: This file is the unit testing for the brake 
    propulsion fan functions.Apparently, check libraries are 
    used as a tool for the unit testing.For more details, you 
    are obliged to check their manual for more clarifications.
 * @author: Xinran He
 * @author: Ezeh prince Anthony Anayo
 * @date:2012-05-02
 * @version: 0.2
 * @reference:http://check.sourceforge.net/doc/check_html/index.html#SEC_Top
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

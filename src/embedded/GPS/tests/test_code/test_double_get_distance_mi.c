/*
Author: Dmitry Igoshin	
*/

#include <check.h>
#include <stdlib.h>
#include "../../gps.h"

double get_distance_mi(struct position p1, struct position p2);

START_TEST(gps_test) {
  
  struct position* p1 = (struct position *) calloc(1,sizeof(struct position));
  struct position* p2 = (struct position *) calloc(1,sizeof(struct position)); 
  p1->longitude = 10.0;
  p1->latitude = 10.0;

  p2->longitude = 10.0;
  p2->latitude = 10.0;

  fail_unless(get_distance_mi(*p1, *p2) == 0);

}END_TEST



Suite * new_suite(void) { 

   Suite *suite = suite_create("test_double_get_distance_mi Suite");	 
   TCase *tcase = tcase_create("test_double_get_distance_mi Test Case"); 
   tcase_add_test(tcase, gps_test); 
   suite_add_tcase(suite,tcase); 
   return suite; 
 } 

 int main(void) { 

   int number_failed; 
   Suite *suite = new_suite(); 
   SRunner *suiter = srunner_create(suite); 
   srunner_run_all(suiter,CK_NORMAL); 
   number_failed = srunner_ntests_failed(suiter); 
   srunner_free(suiter); 
   return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE; 
 }  


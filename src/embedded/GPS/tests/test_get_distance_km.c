/*
Author: Kirill Blazhko
*/

#include <check.h>
#include <stdlib.h>

#include <gps.h>


START_TEST(GPS_test) {
	double distance = 0;

	struct Position *position_a = malloc(sizeof(struct Position));
	position_a->longitude = 0;
	position_a->latitude = 0;

	struct Position *position_a = malloc(sizeof(struct Position));
	position_b->longitude = 0;
	position_b->latitude = 0;
  
  	distance = get_distance_km(position_a, position_b);

  fail_unless( distance == 0);

}END_TEST



Suite * new_suite(void) { 

   Suite *suite = suite_create("GPS_test Suite");	 
   TCase *tcase = tcase_create("GPS_test Test Case"); 
   tcase_add_test(tcase, GPS_test); 
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


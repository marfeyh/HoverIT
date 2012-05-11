
/**
 * \file 		test_case_6_GPS.c
 * \date 		23-04-2012
 * \version 	0.1 
 * \author 		Fangzhou Cao          
 * \attention 	Sections added/modified are as follow:
 * 		 none
 */


#include <check.h>
#include <stdlib.h>
#include <stdio.h>
#include "../gps.h"



/**
 *ID:6
 *Purpose: to test get_positionA(char*).
 *Preparation: Get fake GPS data from GPS simulator.
 *Action: pass the fake GPS data to those two functions and check the return values.
 *Expected outcome: position is matched.
  
**/




START_TEST(test_case_6) {

char* linema;
char* time;
struct position* posi;

linema = read_rmc_data();
posi = get_positionA(linema);


fail_unless(posi->longitude ==0.000000," position is wrong");
fail_unless(posi->latitude == 8960.000000," position is wrong");
fail_unless(posi->ns == 'N'," position is wrong");
fail_unless(posi->ew == 'E'," position is wrong");

        

}END_TEST



/*
Suite * new_suite(void) { 

   Suite *suite = suite_create("GPS_test_suite");	 
   TCase *tcase = tcase_create("GPS_test_case_8"); 
   tcase_add_test(tcase, GPS_test_1); 
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
 */

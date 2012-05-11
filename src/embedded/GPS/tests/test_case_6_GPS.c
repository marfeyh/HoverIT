
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

#define LINEMA 300

/**
 *ID:6
 *Purpose: to test get_time(char*) and get_positionA(char*).
 *Preparation: Get fake GPS data from GPS simulator.
 *Action: pass the fake GPS data to those two functions and check the return values.
 *Expected outcome: time != NULL, position != NULL.
  
**/




START_TEST(test_case_6) {

char* linema;
char* time;
struct position* posi;
 
linema = "$GPRMC,123519,A,4807.038,N,01131.000,E,022.4,084.4,230394,003.1,W*6A";

time = get_time(linema);
printf("TIME: %s\n", time);

posi = get_positionA(linema);
printf("POSITION: %f, %f, %c, %c\n", posi->longitude, posi->latitude, posi->ns, posi->ew);
        
fail_unless(time == "123519","time is wrong");
fail_unless(posi-> longitude == "01131.000"," position is wrong");
fail_unless(posi-> Latitude == "4807.038"," position is wrong");
fail_unless(posi-> ns == "N"," position is wrong");
fail_unless(posi-> ew == "E"," position is wrong");
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

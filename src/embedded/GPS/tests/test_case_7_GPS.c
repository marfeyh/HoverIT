
/**
  Author: Fangzhou Cao
  Date: 23-04-2012     Version:0.1
**/


#include <check.h>
#include <stdlib.h>
#include <stdio.h>
#include "gps.h"


#define LINEMA 300


/**
 ID:7
 Purpose: Testing read_rmc_data() function.
 Preparation: Get fake GPS data from GPS simulator.
 Action: call this function and check the header of return value.
 Expected outcome: header = "$GPRMC".
  
**/



START_TEST(GPS_test_1) {

	char* linema;
     
        linema  = malloc(LINEMA*sizeof(char));

        linema = read_rmc_data(); 
          
    
        printf("linema: %s", linema);
    
        fail_unless(linema[0] == '8' && linema[1] == 'G' && linema[2] == 'P' && linema[3] == 'R' && linema[4] == 'M' && linema[5] == 'C', "Wrong data format."); 
        free(linema);
 

}END_TEST


Suite * new_suite(void) { 

   Suite *suite = suite_create("GPS_test_suite");	 
   TCase *tcase = tcase_create("GPS_test_case_7"); 
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

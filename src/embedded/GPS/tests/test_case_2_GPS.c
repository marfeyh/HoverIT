
/**
 * \file 		test_case_2_GPS.c
 * \date 		22-04-2012
 * \version 	0.1 
 * \author 		Fangzhou Cao          
 * \attention 	Sections added/modified are as follow:
 * 		 none
 */

#include <check.h>
#include <stdlib.h>
#include "gps.h"

/**
 * ID:2
 * Purpose: to test is_GPGSV(char[]) and is_GPGSA(char[]) functions.
 *Preparation: create two gpsDatas, "$GPGSV" and "$GPGSA".
 *Action: call those two functions with two gpsDatas as their arguments correspondingly and get their results.
 *Expected outcome: resultGPGSV == 0 , resultGPGSA == 0.
 *hereby the GPS_test_1 sccueed
  
**/


START_TEST(GPS_test_1) {

	char gpsData1[] = "$GPGSV";
        char gpsData2[] = "$GPGSA";

        int resultGPGSV;
        int resultGPGSA;
 
        resultGPGSV = is_GPGSV(gpsData1);
        resultGPGSA = is_GPGSA(gpsData2);
        

        fail_if(resultGPGSV == 1 || resultGPGSA == 1);
 

}END_TEST


/**
 *Purpose: to test is_GPGSV(char[]) and is_GPGSA(char[]) functions.
 *Preparation: create a gpsData, "$I_LOVE_POLAR_BEAR".
 *Action: call those two functions with gpsData as argument and get their results.
 *Expected outcome: resultGPGSV == 1 , resultGPGSA == 1.
 *                  hereby the GPS_test_2 succeed.
  
**/


START_TEST(GPS_test_2) {

        char gpsData3[] = "$I_LOVE_POLAR_BEAR";
        int resultGPGSV;
        int resultGPGSA;
 
        resultGPGSV = is_GPGSV(gpsData3);
        resultGPGSA = is_GPGSA(gpsData3);
        

        fail_if(resultGPGSV == 0 || resultGPGSA == 0);
 

}END_TEST


Suite * new_suite(void) { 

   Suite *suite = suite_create("GPS_test_suite");	 
   TCase *tcase = tcase_create("GPS_test_case_2"); 
   tcase_add_test(tcase, GPS_test_1); 
   tcase_add_test(tcase, GPS_test_2); 
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


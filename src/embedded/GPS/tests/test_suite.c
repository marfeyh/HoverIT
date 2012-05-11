/**
 * \file 		test_suite.c
 * \date 		09-05-2012
 * \version 	0.1 
 * \author 		Fangzhou Cao          
 * \attention 	write this test suite to collect GPS test cases
 * 		        
 */
/**
 * \file 		test_suite.c
 * \date 		10-05-2012
 * \version 	0.2 
 * \author 		Gokul S. Evuri          
 * \attention 	Sections added/modified are as follow:
 * 		      define gaurd __testingGPS__  
 */
/**
 * \file 		test_suite.c
 * \date 		11-05-2012
 * \version 	0.3
 * \author 		Gokul S. Evuri          
 * \attention 	Sections added/modified are as follow:
 * 		      return type in main and added test_case_12_GPS to the suite   
 */
#ifndef __testingGPS__
#define __testingGPS__
#endif

#include <stdlib.h>
#include <check.h>
#include "../gps.h"

 #include "test_case_1_GPS.c" 
 #include "test_case_2_GPS.c" 
 #include "test_case_3_GPS.c" 
/*#include "test_case_4_GPS.c" */
 #include "test_case_5_GPS.c" 
#include "test_case_6_GPS.c"
 #include "test_case_7_GPS.c" 
 #include "test_case_8_GPS.c" 
 #include "test_case_9_GPS.c" 
#include "test_case_10_GPS.c" 
#include "test_case_11_GPS.c" 
#include "test_case_12_GPS.c" 

Suite * test_suite(void){

	Suite *s=suite_create("Suite");
	TCase *tc1=tcase_create("test case 1"); 
	TCase *tc2=tcase_create("test case 2"); 
	TCase *tc3=tcase_create("test case 3");
/* 	TCase *tc4=tcase_create("test case 4"); */
	TCase *tc5=tcase_create("test case 5"); 
	TCase *tc6=tcase_create("test case 6");
	TCase *tc7=tcase_create("test case 7"); 
	TCase *tc8=tcase_create("test case 8"); 
	TCase *tc9=tcase_create("test case 9"); 
        TCase *tc10=tcase_create("test case 10"); 
	TCase *tc11=tcase_create("test case 11");
	TCase *tc12=tcase_create("test case 12");

	tcase_add_test(tc1, test_case_1_1); 
	tcase_add_test(tc1, test_case_1_2); 
	tcase_add_test(tc1, test_case_1_3); 
	tcase_add_test(tc1, test_case_1_4); 
	tcase_add_test(tc1, test_case_1_5); 
	tcase_add_test(tc1, test_case_1_6); 
 	tcase_add_test(tc1, test_case_1_7); 
	tcase_add_test(tc1, test_case_1_8); 

 	tcase_add_test(tc2, test_case_2_1); 
	tcase_add_test(tc2, test_case_2_2); 

 	tcase_add_test(tc3, test_case_3_1); 
	tcase_add_test(tc3, test_case_3_2); 
	tcase_add_test(tc3, test_case_3_3); 
	tcase_add_test(tc3, test_case_3_4); 

/* 	tcase_add_test(tc4, test_case_4); */
	
 	tcase_add_test(tc5, test_case_5); 
	
	tcase_add_test(tc6, test_case_6);

	 tcase_add_test(tc7, test_case_7_1); 
	 tcase_add_test(tc7, test_case_7_2); 
	 tcase_add_test(tc7, test_case_7_3); 
	 tcase_add_test(tc7, test_case_7_4); 
	 tcase_add_test(tc7, test_case_7_5); 
	 tcase_add_test(tc7, test_case_7_6); 
	 tcase_add_test(tc7, test_case_7_7); 
	 tcase_add_test(tc7, test_case_7_8); 

	 tcase_add_test(tc8, test_case_8); 

	 tcase_add_test(tc9, test_case_9); 

	 tcase_add_test(tc10, test_case_10); 
	
	 tcase_add_test(tc11, test_case_11); 

	 tcase_add_test(tc12, test_case_12) ;

	suite_add_tcase(s,tc1); 
 	suite_add_tcase(s,tc2); 
	suite_add_tcase(s,tc3); 
/* 	suite_add_tcase(s,tc4);  */
 	suite_add_tcase(s,tc5); 
	suite_add_tcase(s,tc6);
	 suite_add_tcase(s,tc7); 
	 suite_add_tcase(s,tc8); 
	 suite_add_tcase(s,tc9); 
	 suite_add_tcase(s,tc10); 
	 suite_add_tcase(s,tc11); 
	 suite_add_tcase(s,tc12); 
	return s;
}


int main(void) {
  int number_failed;
  Suite *s = test_suite();
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

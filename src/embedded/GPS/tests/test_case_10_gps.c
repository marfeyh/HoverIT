/**
 * \file 		test_case_10_GPS.c
 * \date 		20-04-2012
 * \version 	0.1 
 * \author 		Sebastian Hansson         
 * \attention 	Sections added/modified are as follow:
 * 				- The test cases, test suites and the main funtion were added. */

#include <check.h>
#include <stdlib.h>
#include "gps.h"
#include <math.h>

/**
 * Purpose: To compare the first 6 letters of two string and see if they are the same. 
 * Preparation: 
 *	 Two strings that is not the same prepared to be used with check_command.
 * Expected outcome: 1 should be returned.
 */

int check_command(char *, char *);

  char string[] = "svejsan";
  char string2[] = "hejsan";
  unsigned char result;

START_TEST(test_case_10) {
  /* fail criteria, test check_command with the strings provided*/
    fail_if(check_command(string, string2) != 1);
  
}END_TEST

/*
 Suite * new_suite(void) {
   Suite *p = suite_create("New Suite");
   TCase *tc_p = tcase_create("New Test check_command_test");
   tcase_add_test(tc_p, check_command_test);
   suite_add_tcase(p,tc_p);
   return p; 
 } 

int main(void) { 
   int number_failed; 
   Suite *p = new_suite();
   SRunner *sr_p = srunner_create(p);
   srunner_run_all(sr_p,CK_NORMAL);
   number_failed = srunner_ntests_failed(sr_p);
   srunner_free(sr_p);
   return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
} 

*/
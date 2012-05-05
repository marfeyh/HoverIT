/**
 * \date 		26-04-2012
 * \version 	0.1 
 * \author 		Yu Zhao
 * \attention   The gps data was borrowed from http://www.gpsinformation.org/dale/nmea.htm
 */

#include <check.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int* get_indices(char gpsData[]);


START_TEST(null_data_test) {
   int sample_list[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
   unsigned char flag = 1;
  
    if (0 != memcmp(sample_list ,get_indices(""), (size_t) 0 )){
	 flag = 0;
	} 
   fail_if(0 == flag, "The function \"get_indices\" failed to return 0 when empty data was passed to it."); 
}END_TEST


START_TEST(correct_data_test) {
   int sample_list[14] = {6,13,22,24,34,36,38,41,45,51,53,58,60,61};
   unsigned char flag = 1;
  
    if (0 != memcmp(sample_list ,get_indices("$GPGGA,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47"), (size_t) 14 )){
	 flag = 0;
	} 
	
   fail_if(0 == flag, "The function \"get_indices\" failed when correct gps data was passed to it." ); 
}END_TEST 

START_TEST(boundary_data_test) {
   int sample_list[9] = {0,4,8,0,0,0,0,0,0};
   unsigned char flag = 1;
  
    if (0 != memcmp(sample_list ,get_indices(",abg,dcf,"), (size_t) 9 )){
	 flag = 0;
	 printf ("done with the third one\n");
	} 
	
   fail_if(0 == flag, "The function \"get_indices\" failed when data with boundary commas was passed to it." ); 
}END_TEST 

START_TEST(noComma_data_test) {
   int sample_list[6] = {0,0,0,0,0,0};
   unsigned char flag = 1;
  
   if (0 != memcmp(sample_list ,get_indices("abgdcf"), (size_t) 6 )){
	 flag = 0;
	 printf ("done with the third one\n");
	} 
   fail_if(0 == flag, "The function \"get_indices\" failed when data with no comma was passed to it." ); 
}END_TEST 

/**
  Test suite for the four above test cases.
 */
Suite * dataTC_suite(void) {
  Suite *test_suite = suite_create("dataTC Suite");
  TCase *test_case = tcase_create ("test cases");
  tcase_add_test(test_case, null_data_test);
  tcase_add_test(test_case, correct_data_test);
  tcase_add_test(test_case, boundary_data_test);
  tcase_add_test(test_case, noComma_data_test);
  // adding test cases to the test_suite  
  suite_add_tcase(test_suite,test_case);
  return test_suite;
}

/**
 * Main function to execute the test cases
 */
int main(void) {
  int number_failed;
  Suite *s = dataTC_suite();
  SRunner *sr = srunner_create(s);
  // To execute the test cases
  srunner_run_all(sr,CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
} 
  

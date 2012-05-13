#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include <stdint.h>
//#include <searduino.h>
//#include <Arduino.h>
//#include <seasim.h>
#include "wifi_wrapper.h"

START_TEST (wifi_begin_test) {
	fail_if(wifi_begin() == 0);
}END_TEST

START_TEST (wifi_read_test) {
	int i;
	for(i=0;i<=10;i++){
		if(i%2 == 0){
				fail_unless(wifi_read() == 'E' );
			}else{
				fail_unless(wifi_read()=='O');
			}
		}
}END_TEST

START_TEST (wifi_available_test) {
	fail_unless(wifi_available() == 1);
}END_TEST

START_TEST (wifi_write_test) {
	char input;
	int j;
	for(j=0;j<=10;j++){
		input = (char)(((int)'0')+j);
		fail_unless(wifi_write(input) == input);
	}
}END_TEST

Suite* test_wifi_wrapper(void) {
  Suite* s = suite_create("Wifi");
  TCase* tc = tcase_create("Main Test");
  tcase_add_test(tc,wifi_available_test);
  tcase_add_test(tc,wifi_begin_test);
  tcase_add_test(tc,wifi_read_test);
  tcase_add_test(tc,wifi_write_test);
  suite_add_tcase(s, tc);
  return s;
}



int main(void) {
  int number_failed;
  Suite* suite = test_wifi_wrapper();
  SRunner* suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner,CK_NORMAL);
  number_failed = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}




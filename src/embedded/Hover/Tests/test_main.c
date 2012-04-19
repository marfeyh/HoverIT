/*
 * @ Module name:  test_main.c
 * @ Description:  Contains the functions that check the hovering control files.
 *
 * @ Author names : Eva-Lisa Kedborn, Jing Liu
 * 		    Seyed Ehsan Mohajerani, Navid Amiriarshad
 * @ Release      : 9 April 2012
 * @ Version      : 1
 * @ Refrences    : Arduino.cc, sandklef.com, Check manual
 */

/* Includes */
#include <stdlib.h>
#include <check.h>
#include "hovering_check.h"

/* Main function */
int main(void){
	int number_failed;
	Suite *s = hovering_suite();
	SRunner *sr = srunner_create(s);
	srunner_run_all(sr,CK_NORMAL);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed ==0)? EXIT_SUCCESS: EXIT_FAILURE;
}

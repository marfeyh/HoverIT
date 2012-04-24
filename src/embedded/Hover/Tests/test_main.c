/*!
@file test_main.c
@author Eva-Lisa Kedborn
@author Jing Liu
@author Seyed Ehsan Mohajerani
@author Navid Amiriarshad
@brief Contains the functions that check the hovering control files.
@version 0.4
@date 2012-04-09
*/

#include <stdlib.h>
#include <check.h>
#include "hovering_check.h"

/*!
@brief Main function to run hover unit tests
@param none
@returns 
*/
int main(void) {
	int number_failed;
	Suite *s = hovering_suite();
	SRunner *sr = srunner_create(s);
	srunner_run_all(sr, CK_NORMAL);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS: EXIT_FAILURE;
}

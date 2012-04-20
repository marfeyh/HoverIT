/*
 *  calculate_speed_test.c
 *  
 *
 *  Created by Nena Stojova on 3/22/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include <check.h>
#include "../src/calculateSpeed.h"

void
setup(void)
{
	create_speed(15,145);
}

teardown (void)
{
	speed_free ();
}

START_TEST(test_speed_create) {
	
	fail_unless(get_speed()==15,
				"Speed not set collerctlly on creation");
	fail_unless(get_time()==145,
				"Time not set collerctlly on creation");	
	
}END_TEST

START_TEST(check_new_speed) {
	calculate_speed(148);
	fail_unless(get_speed()==183,
				"Speed not set collerctlly on creation");
	fail_unless(get_time()==148,
				"Time not set collerctlly on creation");	
	
}END_TEST



Suite * speed_suite(void) {
	Suite *s = suite_create("Speed");
	
	TCase *tc = tcase_create("Core");
	tcase_add_checked_fixture (tc, setup, teardown);
	tcase_add_test(tc,test_speed_create);
	tcase_add_test(tc,check_new_speed);
	suite_add_tcase(s,tc);
	return s;
}

int
main (void)
{
	int number_failed;
	Suite *s = speed_suite ();
	SRunner *sr = srunner_create (s);
	srunner_run_all (sr, CK_NORMAL);
	number_failed = srunner_ntests_failed (sr);
	srunner_free (sr);
	return (number_failed == 0) ? 0 : 1;
}

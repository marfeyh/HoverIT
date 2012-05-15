/*******************************************
 * calculate_speed_test.c
 * This is a test code for the speed calculation module calculateSpeed.c
 *  
 * Copyright (c) Whatever, no warranty.
 *  
 * Author: Nena Stojova
 * Date: 3/22/12
 *******************************************/

#include <Arduino.h>
#include <searduino.h>
#include <check.h>
#include "calculateSpeed.h"

Speed* speed_ptr;

// Sets up the starting values of the variables of 
void setup(void){
	
	 speed_ptr = create_speed();
}

void teardown (void){
	speed_free (speed_ptr);
}

START_TEST(test_speed_create) {
	
	fail_unless(get_speed(speed_ptr)==0.0,
				"Speed not set collerctlly on creation");
	
}END_TEST

START_TEST(check_new_speed) {
	
	long it;
	long dt;
	
	int i = 0;
	int loop_num= 160;
	
	float speed = 0.0;
	
	while(i < loop_num){
		
		it = get_time(speed_ptr);
		
		calculate_speed(speed_ptr);
		
		dt = get_time(speed_ptr) - it;
		
		speed += 0.245*(i%10)*dt/1000;

		/*fprintf(stderr, "s1: %f\ts2: %f\n", speed, speed_ptr->speed); */
		fail_unless(get_speed(speed_ptr)==(int)speed,
					"Speed not updated properly");
			
		i++;
		delay(100);
	
	}
	
	
}END_TEST

Suite * speed_suite(void) {
	Suite *s = suite_create("Speed");
	
	TCase *tc = tcase_create("Core");
	tcase_add_checked_fixture (tc, setup, teardown);
	tcase_add_test(tc,test_speed_create);
	tcase_add_test(tc,check_new_speed);
	tcase_set_timeout(tc, 30);
	suite_add_tcase(s,tc);
	return s;
}

int
main (void)
{
	i2c_add_device (0x40, "./bma180stub.so");
	int number_failed;
	Suite *s = speed_suite ();
	SRunner *sr = srunner_create (s);
	srunner_run_all (sr, CK_NORMAL);
	number_failed = srunner_ntests_failed (sr);
	srunner_free (sr);
	return (number_failed == 0) ? 0 : 1;
}

/*
 * @ Module name:  audible_test.c
 * @ Description:  Contains the functions for testing hovering functions
 *   and show the result by voice
 *
 * @ Author names : Seyed Ehsan Mohajerani, Navid Amiriarshad
 * @ Release      : 20 April 2012
 * @ Version      : 1.0
 * @ Refrences    : Arduino.cc, sandklef.com
 * dreamincode.net/forums/topic/34861-functions-stored-in-structure
 * Turnigy_Plush_and_Sentry_ESC user manual
 */

/* Includes */
#include <Arduino.h> 
#include <searduino.h>
#include <print_audible_test.h>
#include <pin.h>

/* Defines */
#define BEEP 254;
#define SILENCE 0;
#define SILENT_DELAY_TIME 50
// I can not use defines
//should i declare  loop_ count and loop_number in each function?	

/* Variables */
int beep_time;
int silence_time;	
int loop_count;
int loop_number; 
int beep_delay_time;
int silence_delay_time;

/* Functions */

int test_start (void) {
	beep_time = 100;
	silence_time = 50;
	loop_number = 8;
	for (loop_count = 0; loop_count < loop_number; loop_count++){
		analogWrite (TEST_PIN, 254);
		delay (beep_time);
		analogWrite (TEST_PIN, 0);
		delay (silence_time);
	}
	silent_delay();
	return 0;
}

int test_stop (void) {
	beep_time = 100;
	silence_time = 300;
	loop_number = 4;
	for (loop_count = 0; loop_count < loop_number; loop_count++){
		analogWrite (TEST_PIN, 254);
		delay (beep_time);
		analogWrite (TEST_PIN, 0);
		delay (silence_time);
	}
	analogWrite (TEST_PIN, 254);
	delay (500);
	silent_delay();
	return 0;
}

int test_normal (void){
	beep_time=200;
	silence_time=50;
	loop_number=6;
	for (loop_count = 0; loop_count < loop_number; loop_count++){
		analogWrite (TEST_PIN, 254);
		delay (beep_time);
		analogWrite (TEST_PIN, 0);
		delay (silence_time);
	}
	silent_delay();
	return 0;
}


int test_turbo (void) {
	beep_time=50;
	silence_time=50;
	loop_number=8;
	for (loop_count = 0; loop_count < loop_number; loop_count++){
		analogWrite (TEST_PIN, 254);
		delay (beep_time);
		analogWrite (TEST_PIN, 0);
		delay (silence_time);
	}
	silent_delay();
	return 0;
}

int test_analogwrite (void){
	beep_time=10;
	silence_time=50;
	loop_number=2;
	for (loop_count = 0; loop_count < loop_number; loop_count++){
		analogWrite (TEST_PIN, 254);
		delay (beep_time);
		analogWrite (TEST_PIN, 0);
		delay (silence_time);
	}
	silent_delay();
	return 0;
}
int test_Too_low (void){
	beep_time=20;
	silence_time=50;
	loop_number=2;
	for (loop_count = 0; loop_count < loop_number; loop_count++){
		analogWrite (TEST_PIN, 254);
		delay (beep_time);
		analogWrite (TEST_PIN, 0);
		delay (silence_time);
	}
	silent_delay();
	return 0;
}

int test_Too_high (void){
	return 0;
}

int test_throttle_Stick_is_bottom (void){
	return 0;
}

int test_motor_already_started (void){
	return 0;
}

int test_increase (int throttle_stick_level){
	return throttle_stick_level;
}

int test_decrease (int throttle_stick_level){
	return throttle_stick_level;
}

int test_set_level (int throttle_stick_level){

	return throttle_stick_level;
}

int test_set_fixed_level (int throttle_stick_level){

	return throttle_stick_level;
}

int silent_delay(void){
	analogWrite (TEST_PIN, 0);
	delay (SILENT_DELAY_TIME);
	return 0;
}

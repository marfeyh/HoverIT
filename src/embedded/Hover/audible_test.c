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

/* Defines */
#define BEEP BEEP
#define SILENCE 0
#define SILENT_DELAY_TIME 50

/* Variables */
int beep_time;
int silence_time;	
int loop_count;
int loop_number; 
int beep_delay_time;
int silence_delay_time;

/* Functions */

int test_start (int test_pin) {
	beep_time = 100;
	silence_time = 50;
	loop_number = 8;
	for (loop_count = 0; loop_count < loop_number; loop_count++){
		analogWrite (test_pin, BEEP);
		delay (beep_time);
		analogWrite (test_pin, SILENCE);
		delay (silence_time);
	}
	silent_delay(test_pin);
	return 0;
}

int test_stop (int test_pin) {
	beep_time = 100;
	silence_time = 300;
	loop_number = 4;
	for (loop_count = 0; loop_count < loop_number; loop_count++){
		analogWrite (test_pin, BEEP);
		delay (beep_time);
		analogWrite (test_pin, SILENCE);
		delay (silence_time);
	}
	analogWrite (test_pin, BEEP);
	delay (500);
	silent_delay(test_pin);
	return 0;
}

int test_normal (int test_pin){
	beep_time = 200;
	silence_time = 50;
	loop_number = 6;
	for (loop_count = 0; loop_count < loop_number; loop_count++){
		analogWrite (test_pin, BEEP);
		delay (beep_time);
		analogWrite (test_pin, SILENCE);
		delay (silence_time);
	}
	silent_delay(test_pin);
	return 0;
}

int test_turbo (int test_pin) {
	beep_time = 50;
	silence_time = 50;
	loop_number = 8;
	for (loop_count = 0; loop_count < loop_number; loop_count++){
		analogWrite (test_pin, BEEP);
		delay (beep_time);
		analogWrite (test_pin, SILENCE);
		delay (silence_time);
	}
	silent_delay(test_pin);
	return 0;
}

int test_analogwrite (int test_pin){
	beep_time = 10;
	silence_time = 50;
	loop_number = 2;
	for (loop_count = 0; loop_count < loop_number; loop_count++){
		analogWrite (test_pin, BEEP);
		delay (beep_time);
		analogWrite (test_pin, SILENCE);
		delay (silence_time);
	}
	silent_delay(test_pin);
	return 0;
}

int test_motor_already_started (int test_pin){
	beep_time = 100;
	silence_time = 50;
	loop_number = 4;	
	for (loop_count = 0; loop_count < loop_number; loop_count++){
		analogWrite (test_pin, BEEP);
		delay (beep_time);
		analogWrite (test_pin, SILENCE);
		delay (silence_time);
	}
	analogWrite (test_pin, BEEP);
	delay (50);	
	silent_delay(test_pin);
	return 0;
}

int test_Too_low (int test_pin){
	beep_time = 200;
	silence_time = 200;
	loop_number = 3;
	for (loop_count = 0; loop_count < loop_number; loop_count++){
		analogWrite (test_pin, BEEP);
		delay (beep_time);
		analogWrite (test_pin, SILENCE);
		delay (silence_time);
	}
	analogWrite (test_pin, BEEP);
	delay (50);	
	silent_delay(test_pin);
	return 0;
}

int test_Too_high (int test_pin){
	test_Too_low (test_pin);
	return 0;
}

int silent_delay(int test_pin){
	analogWrite (test_pin, SILENCE);
	delay (SILENT_DELAY_TIME);
	return test_pin;
}

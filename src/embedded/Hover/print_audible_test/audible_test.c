#include <Arduino.h> 
#include <searduino.h>
#include <print_audible_test.h>
#include <pin.h>

#define BEEP 254;
#define SILENCE 0;
#define SILENT_DELAY_TIME 50
// I can not use defines

int beep_time;
int silence_time;	
int loop_count;
int loop_number=0; 
int beep_delay_time;
int silence_delay_time;

int test_stop () {
	beep_time = 100;
	silence_time = 300;
	loop_number = 4;
	for (loop_count; loop_count < loop_number; loop_count++){
		analogWrite (TONE_PIN, 254);
		delay (beep_time);
		analogWrite (TONE_PIN, 0);
		delay (silence_time);
	}
	analogWrite (TONE_PIN, 254);
	delay (500);
	silent_delay();
	return 0;
}

int test_start () {
	beep_time = 100;
	silence_time = 50;
	loop_number = 8;
	for (loop_count; loop_count < loop_number; loop_count++){
		analogWrite (TONE_PIN, 254);
		delay (beep_time);
		analogWrite (TONE_PIN, 0);
		delay (silence_time);
	}
	silent_delay();
	return 0;
}

int test_turbo () {
	beep_time=50;
	silence_time=50;
	loop_number=8;
	for (loop_count; loop_count < loop_number; loop_count++){
		analogWrite (TONE_PIN, 254);
		delay (beep_time);
		analogWrite (TONE_PIN, 0);
		delay (silence_time);
	}
	silent_delay();
	return 0;
}

int silent_delay(void){
	analogWrite (TONE_PIN, 0);
	delay (SILENT_DELAY_TIME);
}

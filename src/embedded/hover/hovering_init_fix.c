/*
 * @ Module name:  hoveing_init_fix.c
 * @ Description:  Contains the functions that controls the hovering fan
 * @ 		   and value error prevention.
 *
 * @ Author names :Seyed Ehsan Mohajerani, Navid Amiriarshad
 * @ Release      :20 March 2012
 * @ Version      : 1
 * @ Refrences    : Arduino.cc, http://www.sandklef.com
 */

/* Includes */
#include <hovering_motor.h>
#include <hovering_control.h>
#include <hovering_init_fix.h>
#define HIGHEST_LEVEL 254
#define LOWEST_LEVEL 133
#define USING_PIN 11

/* Main method */
int main(void){
	initialize(USING_PIN);
	return 0;
}

int initialize(){
	int using_pin = 11;
	loop_need=true;
	ard_init(using_pin);
	hover_func(start,using_pin);
	delay(1000);	
	delay(1000);
	hover_func(turbo,using_pin);
	delay(1000);
	hover_func(stop,using_pin);
	/* Test code */
	#ifdef STUB_TEST
		printf("		Test Main \n");
	#endif
	/*FUNCS funcs;
	funcs.func1=set_level;
	funcs.func2=delay;
	funcs.level=254;
	funcs.delay_time=1000;	
	hover_loop(funcs);*/	
	return 0;
}

/* This function prevents the motor from stop (Chekc boundary values)*/
int check_and_fix_level(int using_pin,int throttle_stick_level){
	if (throttle_stick_level<LOWEST_LEVEL){
		//int stop_loop(void);		
		normal(using_pin);		
		/* Test code */
		#ifdef STUB_TEST
			printf("		Test Too low \n");
		#endif
	}
	if (throttle_stick_level>HIGHEST_LEVEL){
		//int stop_loop(void);
		turbo(using_pin);
		/* Test code */
		#ifdef STUB_TEST
			printf("		Test Too high \n");
		#endif
	}
	return 0;
}

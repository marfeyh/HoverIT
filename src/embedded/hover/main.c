/*
 * @ Module name:  main.c
 * @ Description:  Contains the functions that controls the hovering fan speed.
 *
 * @ Author names :Seyed Ehsan Mohajerani, Navid Amiriarshad
 * @ Release      :20 March 2012
 * @ Version      : 1
 * @ Refrences    : Arduino.cc, http://www.sandklef.com
 */

/* Includes */
#include <hovering_motor.h>
#include <hovering_control.h>

// should'nt have prototype
int initialize(int using_pin);

/* Main method */
int main(void){
	initialize(11);
	return 0;
}

int initialize(int using_pin){
	//throttle_stick_level=100;
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

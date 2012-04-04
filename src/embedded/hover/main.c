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

/* Main method */
int main(void){

	initialize();
	return 0;
}

int initialize(void){
	//throttle_stick_level=100;
	loop_need=true;
	using_pin=11;
	ard_init(using_pin);
	//hover_func(throttle_stick_bottom);
	hover_func(start);
	hover_func(normal);
	/* Test code */
	#ifdef STUB_TEST
		printf("		Test Main Level: %d \n",
		throttle_stick_level);
	#endif
	FUNCS funcs;
	funcs.func1=set_level;
	funcs.func2=delay;
	funcs.level=200;
	funcs.delay_time=1000;	
	hover_loop(funcs);	
	return 0;
}

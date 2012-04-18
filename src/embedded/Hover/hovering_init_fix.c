/*
 * @ Module name:  hoveing_init_fix.c
 * @ Description:  Contains the functions that initiates the hovering fan
 *
 * @ Author names : Seyed Ehsan Mohajerani, Navid Amiriarshad
 * @ Release      : 20 March 2012
 * @ Version      : 1.0
 * @ Refrences    : Arduino.cc, sandklef.com
 * dreamincode.net/forums/topic/34861-functions-stored-in-structure
 * Turnigy_Plush_and_Sentry_ESC user manual
 */

/* Includes */
#include "Arduino.h"
#include <hovering_motor.h>
#include <hovering_control.h>
#include <hovering_init_fix.h>

/* Functions */

/* Initiations */
int initialize(using_pin){
	ard_init(using_pin);
	hover_func(start,using_pin);
//	delay(2000);
//	hover_func(turbo,using_pin);
//	BLINKER(300);    
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



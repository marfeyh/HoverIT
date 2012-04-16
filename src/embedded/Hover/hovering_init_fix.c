/*
 * @ Module name:  hovering_init_fix.c
 * @ Description:  Contains the functions that start the hovering fan speed.
 *
 * @ Author names : Seyed Ehsan Mohajerani, Navid Amiriarshad
 * @ Release      : 20 March 2012
 * @ Version      : 1.0
 * @ Refrences    : Arduino.cc, sandklef.com
 * dreamincode.net/forums/topic/34861-functions-stored-in-structure
 * Turnigy_Plush_and_Sentry_ESC user manual
 */

/* Includes */
#include <Arduino.h> /* Header for Arduino */ 
#include <searduino.h> /* Header for Searduino */
#include <hovering_motor.h>
#include <hovering_control.h>
#include <hovering_init_fix.h>
#include "searduino.h"

/* Functions */

/* Initiations */
int initialize(using_pin){
	ard_init(using_pin);
int i=0;
//for (i;i<10;i++){
//BLINKER(100);	
hover_func(start,using_pin);
delay(1000);
hover_func(normal,using_pin);
delay(3000);

hover_func(stop,using_pin);

//}
	/* Test code */
//	#ifdef STUB
//		printf("		Test init \n");
//	#endif
	return 0;
	/*FUNCS funcs;
	funcs.func1=set_level;
	funcs.func2=delay;
	funcs.level=254;
	funcs.delay_time=1000;	
	hover_loop(funcs);*/	
	return 0;
}


/*
 * @ Module name:  hovering_motor.c
 * @ Description:  Contains the functions that start the hovering fan speed.
 *
 * @ Author names :Seyed Ehsan Mohajerani, Navid Amiriarshad
 * @ Release      :20 March 2012
 * @ Version      :1.0
 * @ Refrences    :Arduino.cc, http://www.sandklef.com
 * http://www.dreamincode.net/forums/topic/34861-functions-stored-in-structure/
 */

/////refrence user guide motor

/* Includes */
#include <hovering_motor.h>
#include <hovering_control.h>

/* Internal functions */

int ard_init(int using_pin){
	/* Initialize the Arduino */
	init();
	/* Assign using pin to output */
	pinMode(using_pin,OUTPUT);
	/* The motor has not been started */
	start_check=true;
	/* Test code */
	#ifdef STUB_TEST
		printf("		Test output pin: %d OK \n",
		using_pin);
	#endif
	return 0;
}

int hover_func(int (*func)(void)){
	/* Start or stop the motor */
	func();
	/* Test code */
	#ifdef STUB_TEST
		printf("		Test function OK\n");
	#endif
	return 0;
}

/* Change the speed of motor */
int hover_change(int (*climb_decesnd)(int),int level){
	climb_decesnd(level);	
	return 0;
}

/* Loop for motor */
int hover_loop(FUNCS funcs_in){
	while(loop_need){
		funcs_in.func1(funcs_in.level);
		funcs_in.func2(funcs_in.delay_time);
		/* Test code */		
		#ifdef STUB_TEST
			printf("		Test Loop OK    L: %d\n",
			throttle_stick_level);
		#endif
	check_loop_need();
	}
	return 0;
}

/* Set the Arduino active pin for using */
int pin_program(int level) {
	analogWrite(using_pin,level);
	/* Test code */
		#ifdef STUB_TEST
		printf("		Test analog write \n");
	#endif
	return 0;
}

/* Check if necessary to stop the loop */
int check_loop_need(void){
	loop_need=true;
	/* Test code */
	#ifdef STUB_TEST
		printf("		Test loop stop  L: %d \n",
		throttle_stick_level);
	#endif	
	return 0;
}

/* This function never lets the motor to stop */
int check_and_fix_level(){
	if (throttle_stick_level<133){
		//int stop_loop(void);		
		normal();		
		/* Test code */
		#ifdef STUB_TEST
			printf("		Test Too low \n");
		#endif
	}
	if (throttle_stick_level>254){
		//int stop_loop(void);
		turbo();
		/* Test code */
		#ifdef STUB_TEST
			printf("		Test Too high \n");
		#endif
	}
	return 0;
}

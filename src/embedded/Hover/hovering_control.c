/*
 * @ Module name:  hovering_control.c
 * @ Description:  Contains the functions that control the hovering fan speed.
 *
 * @ Author names :Seyed Ehsan Mohajerani, Navid Amiriarshad
 * @ Release      :20 March 2012
 * @ Version      :1.0
 * @ Refrences    :Arduino.cc, http://www.sandklef.com
 * http://www.dreamincode.net/forums/topic/34861-functions-stored-in-structure/
 */

/* Includes */
#include <hovering_control.h>
#include <hovering_motor.h>
#include <hovering_init_fix.h>

/* Definition */
#define throttle_stick_bottom_level 100

/* Variable */
int throttle_stick_level=0;

/* Functions */	

/* Start the motor */
int start(int using_pin){
	/* Set the throttle stick is in the buttom position if the motor
	   has not been started */
	if (throttle_stick_level<throttle_stick_bottom_level){
		throttle_stick_bottom(using_pin);
	}
	else {
	/* Test code */
	#ifdef STUB_TEST
		printf("		Test motor has already been started \n"
		);
	#endif
	}
	return 0;
}

/* Set the output signal to minimum acceptable for ESC */
int throttle_stick_bottom(int using_pin){
	pin_program(using_pin, throttle_stick_bottom_level);
	delay(1000);
	/* Test code */
	#ifdef STUB_TEST
		printf("		Test T S is bottom \n");
	#endif
	return 0;
}

/* Set the motor to lowest rotating speed */
int normal(int using_pin){
	throttle_stick_level=LOWEST_LEVEL;
	pin_program(using_pin,throttle_stick_level);
	/* Test code */
	#ifdef STUB_TEST
		printf("		Test level is normal \n");
	#endif
	return 0;
}

/* Set the motor to highest rotating speed */
int turbo(int using_pin){
	throttle_stick_level=HIGHEST_LEVEL;
	pin_program(using_pin, throttle_stick_level);
	/* Test code */
	#ifdef STUB_TEST
		printf("		Test level is turbo \n");
	#endif
	return 0;
}

/* stop the motor */
int stop(int using_pin){
	throttle_stick_level=STOP_LEVEL;
	pin_program(using_pin, throttle_stick_level);
	/* Test code */
	#ifdef STUB_TEST
		printf("		Test motor stopped \n");
	#endif
	return 0;
}

/* Increase the motor rotating speed level times */
int increase(int using_pin, int level){
	throttle_stick_level+=level;
	check_and_fix_level(using_pin, throttle_stick_level);
	pin_program(using_pin, throttle_stick_level);
	/* Test code */
	#ifdef STUB_TEST
		printf("		Test INC New    L: %d \n",
		throttle_stick_level);
	#endif
	return 0;
}

/* decrease the motor rotating speed level times */
int decrease(int using_pin, int level){
	throttle_stick_level-=level;
	check_and_fix_level(using_pin, throttle_stick_level);
	pin_program(using_pin, throttle_stick_level);
	/* Test code */
	#ifdef STUB_TEST
		printf("		Test DEC New    L: %d \n",
		throttle_stick_level);
	#endif
	return 0;
}

/* set the motor rotating speed to specified level */
int set_level(int using_pin, int level){
	throttle_stick_level=level;
	check_and_fix_level(using_pin, throttle_stick_level);
	pin_program(using_pin, throttle_stick_level);
	/* Test code */
	#ifdef STUB_TEST
		printf("		Test set New    L: %d \n",
		throttle_stick_level);
	#endif
	return 0;
}

/* This function prevents the motor from stop (Check boundary values)*/
int check_and_fix_level(int using_pin,int throttle_stick_level){
	if (throttle_stick_level<LOWEST_LEVEL){
		normal(using_pin);		
		/* Test code */
		#ifdef STUB_TEST
			printf("		Test Too low \n");
		#endif
	}
	if (throttle_stick_level>HIGHEST_LEVEL){
		turbo(using_pin);
		/* Test code */
		#ifdef STUB_TEST
			printf("		Test Too high \n");
		#endif
	}
	return 0;
}

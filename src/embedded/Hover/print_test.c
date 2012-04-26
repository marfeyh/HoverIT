#include <Arduino.h> 
#include <searduino.h>
#include <print_audible_test.h>

int test_start (int test_pin) {
	printf("		Test motor started \n");	
	return test_pin;
}

int test_stop (int test_pin) {
	printf("		Test motor stopped \n");
	return test_pin;
}

int test_normal (int test_pin){
	printf("		Test level is normal \n");
	return test_pin;
}


int test_turbo (int test_pin) {
	printf("		Test level is turbo \n");
	return test_pin;
}

int test_analogwrite (int test_pin){
	printf("		Test analog write \n");
	return test_pin;
}
int test_Too_low (int test_pin){
	printf("		Test Too low \n");
	return test_pin;
}

int test_Too_high (int test_pin){
	printf("		Test Too high \n");
	return test_pin;
}

int test_throttle_Stick_is_bottom (int test_pin){
	printf("		Test T S is bottom \n");
	return 0;
}

int test_motor_already_started (int test_pin){
	printf("		Test motor has already been started \n" \
	);
	return test_pin;
}

int test_increase (int throttle_stick_level){
	printf("		Test INC New    L: %d \n", \
	throttle_stick_level);
	return throttle_stick_level;
}

int test_decrease (int throttle_stick_level){
	printf("		Test DEC New    L: %d \n", \
	throttle_stick_level);
	return throttle_stick_level;
}

int test_set_level (int throttle_stick_level){
	printf("		Test set New    L: %d \n", \
	throttle_stick_level);
	return throttle_stick_level;
}

int silent_delay(test_pin){
	return test_pin;
}

/*



printf("		Test init \n");
printf("\n\n -- hover_func  %p  %d\n\n\n",func,using_pin);
printf("		Test function OK\n");
printf("		Test Loop OK    L: %d\n",
throttle_stick_level);



*/

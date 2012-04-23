#include <Arduino.h> 
#include <searduino.h>
#include <print_audible_test.h>
#include <pin.h>

int test_start () {
	return 0;
}

int test_stop () {
	printf("		Test motor stopped \n");
	return 0;
}

int test_normal (void){
	printf("		Test level is normal \n");
	return 0;
}


int test_turbo () {
	printf("		Test level is turbo \n");
	return 0;
}

int test_analogwrite (void){
	printf("		Test analog write \n");
	return 0;
}
int test_Too_low (void){
	printf("		Test Too low \n");
	return 0;
}

int test_Too_high (void){
	printf("		Test Too high \n");
	return 0;
}

int test_throttle_Stick_is_bottom (void){
	printf("		Test T S is bottom \n");
	return 0;
}

int test_motor_already_started (void){
	printf("		Test motor has already been started \n" \
	);
	return 0;
}

int test_increase (int throttle_stick_level){
	printf("		Test INC New    L: %d \n", \
	throttle_stick_level);
	return 0;
}

int test_decrease (int throttle_stick_level){
	printf("		Test DEC New    L: %d \n", \
	throttle_stick_level);
	return 0;
}

int test_set_level (int throttle_stick_level){
	printf("		Test set New    L: %d \n", \
	throttle_stick_level);
	return 0;
}

int silent_delay(void){
	return 0;
}

/*



printf("		Test init \n");
printf("\n\n -- hover_func  %p  %d\n\n\n",func,using_pin);
printf("		Test function OK\n");
printf("		Test Loop OK    L: %d\n",
throttle_stick_level);



*/

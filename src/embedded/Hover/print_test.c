
/***************************************************************************
 * Copyright (C) 2012  Seyed Ehsan Mohajerani
 *                     Navid Amiriarshad
 * 
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 ****************************************************************************/

/*!
 @file print_test.h
 @headerfile print_audible_test.h
 @brief This module contain the functions for print on screen test when using 
 stub.
 @author Seyed Ehsan Mohajerani
 @author Navid Amiriarshad
 @version 0.9
 @date 20 April 2012
 @see Arduino.cc
 @see sandklef.com
 @see hoveritu.com
 @see dreamincode.net/forums/topic/34861-functions-stored-in-structure
 @see Turnigy_Plush_and_Sentry_ESC user manual
 @see reference for Coding standard ece.cmu.edu/~eno/coding/CCodingStandard
 .html
 @see reference for commenting stack.nl/~dimitri/doxygen/commands
 .html#cmdparam
 */

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

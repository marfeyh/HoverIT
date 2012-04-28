/*!
@file main.c
@author Eva-Lisa Kedborn
@author Jing Liu
@date 2012-03-19
@brief Main function to run the hover code separately from the
rest of the project
*/

#include "Arduino.h"
#include <hover_api.h>
#include "Arduino.h"
#include <hovering_motor.h>
#include <hovering_control.h>

/*!
@brief Main function to run manual tests
@param none
@returns integer 0 if successful
*/
int main(void) {

        init();
	start_hover();
	hover_min();
	delay(1000);
	hover_max();
	delay(2000);
	increase_hover_auto();
	delay(2000);

	return 0;
}

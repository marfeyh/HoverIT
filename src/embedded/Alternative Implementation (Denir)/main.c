/*
 * @ Module name  :main.c
 * @ Description  :
 * @ Author names :Denir Leric
 * @ Release      :04 May 2012
 * @ Version      :1
 * @ Refrences    :Arduino.cc, sandklef.com
 */

/* EXTRA NOTES: 
 * This is not anything finished. This is just an alternative implementation based on what
 * Rashid told us (Denir, Bruce and Nahid).
 *
 * code is based on that:
 *
 * 0 % = 843 in analogRead
 * 100 % = 1023 in analogRead
 *
 * aswell as that we will calculate battery level for three batteries and return
 * the value of them to the scheduler and they can send it to the andriod UI to display it
 * or whatever.
 */

#include <Arduino.h>
#include <searduino.h>
#include "percentage.h"

/*
 * This main function simulates the scheduler.
 * The scheduler calls getPercentage with an argument that is 1, 2 or 3.
 * Based on what argument they call they will get back the percentage of the first, second or third battery.
 * All variables in here at the moment are test variables.
 */
int main(void)
{

	init();
	
	int FIRST_BATTERY = 1;
	int SECOND_BATTERY = 2;
	int THIRD_BATTERY = 3;
	int testPercentage = 0;
	
	for(;;)
	{
		testPercentage = getPercentage(FIRST_BATTERY);
		testPercentage = getPercentage(SECOND_BATTERY);
		testPercentage = getPercentage(THIRD_BATTERY);
	}
	return 0;
}

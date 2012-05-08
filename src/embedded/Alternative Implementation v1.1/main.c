/*
 * @ Module name  :main.c
 * @ Description  :
 * @ Author names :Denir Leric. Integrated by Kuhan and Aran (Incomplete)
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
//#include "percentage.h"
#include "batteryMeter.h"

/*
 * This main function simulates the scheduler.
 * The scheduler calls getPercentage with an argument that is 1, 2 or 3.
 * Based on what argument they call they will get back the percentage of the first, second or third battery.
 * All variables in here at the moment are test variables.
 */
int main(void)
{

	init();
    init_battery_meter();
	
//	int FIRST_BATTERY = 1;
//	int SECOND_BATTERY = 2; //old code by denir
//	int THIRD_BATTERY = 3;
	int binMsg1 = 0;
//    int binMsg2 = 0;
//    int binMsg3 = 0; //TODO
	
	for(;;)
	{
//		testPercentage = getPercentage(FIRST_BATTERY);
//		testPercentage = getPercentage(SECOND_BATTERY); //old code by denir
//		testPercentage = getPercentage(THIRD_BATTERY);
        binMsg1 = get_battery_level(1);
//	    binMsg2 = get_battery_level(2);
//      binMsg3 = get_battery_level(3); //TODO
    }
	return 0;
}

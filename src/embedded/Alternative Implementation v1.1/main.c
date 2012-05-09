/*!
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as
 published by the Free Software Foundation, either version 3 of the
 License, or (at your option) any later version.
 
 This program is distodributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public
 License along with this program. If not, see
 <http://www.gnu.org/licenses/gpl-3.0.html>.
 */

/*!
 @file main.c
 @details 
 @authors Denir Leric. Integrated by Kuhan and Aran (Incomplete)
 @version 1, 04 May 2012
 @note this is a note about this module (optional)
 @todo if anything should be further developed on this module (optional)
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

/*!
 @brief The main function simulates the scheduler.* The scheduler calls getPercentage with an argument that is 1, 2 or 3.
 @ Based on what argument they call they will get back the percentage of the first, second or third battery.
 @ All variables in here at the moment are test variables.
 @param[in] 
 @param[in] 
 @return  
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

/*!
 *This program is free software: you can redistribute it and/or modify
 *it under the terms of the GNU General Public License as
 *published by the Free Software Foundation, either version 3 of the
 *License, or (at your option) any later version.
 *
 *This program is distodributed in the hope that it will be useful,
 *but WITHOUT ANY WARRANTY; without even the implied warranty of
 *MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *GNU General Public License for more details.
 *
 *You should have received a copy of the GNU General Public
 *License along with this program. If not, see
<http://www.gnu.org/licenses/gpl-3.0.html>.
*/

/*!
@file percentage.c
@details This module reads from analogpin and calculates the precentage left 
@authors Denir
@version 1.1
@note 
@todo 
*/

#include <Arduino.h>
#include <searduino.h>
#include "percentage.h"
#include "pin.h"

/*!
@brief This function checks for what battery the percentage should be calculated for
@param[in] batteryNo This argument is a identifier for what battery should be calculated
@return 0 to 100 if success
*/
int get_percentage(int battery_no)
{
	if(1 == battery_no)
	{
		return get_first_battery_level();
	} else if(2 == battery_no)
	{
		return get_second_battery_level();
	} else if(3 == battery_no)
	{
		return get_third_battery_level();
	}
}

/*!
@brief This function calculates the battery level for the first battery
@return 0 to 100 if success
*/
int get_first_battery_level()
{
	if(analogRead(BATTERY_PIN1) < 843)
	{
		return 0;
	} else
	{
		int percentage = 100 - (((1023 - analogRead(BATTERY_PIN1)) / 180.00 * 100));
		return percentage;
	}
}

/*!
@brief This function calculates the battery level for the second battery
@return 0 to 100 if success
*/
int get_second_battery_level()
{
	if(analogRead(BATTERY_PIN2) < 843)
	{
		return 0;
	} else
	{
		int percentage = 100 - (((1023 - analogRead(BATTERY_PIN2)) / 180.00 * 100));
		return percentage;
	}
}

/*!
@brief This function calculates the battery level for the third battery
@return 0 to 100 if success
*/
int get_third_battery_level()
{
	if(analogRead(BATTERY_PIN3) < 843)
	{
		return 0;
	} else
	{
		int percentage = 100 - (((1023 - analogRead(BATTERY_PIN3)) / 180.00 * 100));
		return percentage;
	}
}



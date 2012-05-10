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
@file percentage.c
@details This module reads from analogpin and calculates the precentage left 
@authors Denir
@version 0.9
@note 
@todo test it and integrate it
*/

#include <Arduino.h>
#include <searduino.h>
#include "percentage.h"




/*!
@brief This function checks for what battery the percentage should be calculated for
@see http://hoveritu.com/ (optional - if any additonal info is required)
@param[in] batteryNo This argument is a identifier for what battery should be calculated
@return 0 to 100 if success
*/
int getPercentage(int batteryNo)
{
	if(1 == batteryNo)
	{
		return getFirstBatteryLevel();
	} else if(2 == batteryNo)
	{
		return getSecondBatteryLevel();
	} else if(2 == batteryNo)
	{
		return getThirdBatteryLevel();
	}
}

/*!
@brief This function calculates the battery level for the first battery
@see http://hoveritu.com/ (optional - if any additonal info is required)
@return 0 to 100 if success
*/
int getFirstBatteryLevel()
{
	if(analogRead(BATTERY_PIN1) < 843)
	{
		return 0;
	} else
	{
		int PERCENTAGE = 100 - (((1023 - analogRead(BATTERY_PIN1)) / 180 * 100));
		return PERCENTAGE;
	}
}

/*!
@brief This function calculates the battery level for the second battery
@see http://hoveritu.com/ (optional - if any additonal info is required)
@return 0 to 100 if success
*/
int getSecondBatteryLevel()
{
	if(analogRead(BATTERY_PIN2) < 843)
	{
		return 0;
	} else
	{
		int PERCENTAGE = 100 - (((1023 - analogRead(BATTERY_PIN2)) / 180 * 100));
		return PERCENTAGE;
	}
}

/*!
@brief This function calculates the battery level for the third battery
@see http://hoveritu.com/ (optional - if any additonal info is required)
@return 0 to 100 if success
*/
int getThirdBatteryLevel()
{
	if(analogRead(BATTERY_PIN3) < 843)
	{
		return 0;
	} else
	{
		int PERCENTAGE = 100 - (((1023 - analogRead(BATTERY_PIN3)) / 180 * 100));
		return PERCENTAGE;
	}
}



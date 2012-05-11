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
@details This module is the main 
@authors Denir
@version 0.9
@note Not yet finishied
@todo test it and integrate it
*/



#include <Arduino.h>
#include <searduino.h>
#include "percentage.h"


/*!
@brief This function is the main that initiate everything
@see http://hoveritu.com/ (optional - if any additonal info is required)
@return 0 on success
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
		digitalWrite(13, HIGH);
		testPercentage = getPercentage(FIRST_BATTERY);
		testPercentage = getPercentage(SECOND_BATTERY);
		testPercentage = getPercentage(THIRD_BATTERY);
		delay(1000);
		digitalWrite(13, LOW);
	}
	return 0;
}

/*
 * @ Module name  :percentage.c
 * @ Description  :Gets what battery it should calculate the percentage of and then does it
 * @ Author names :Denir Leric
 * @ Release      :04 May 2012
 * @ Version      :1
 * @ Refrences    :Arduino.cc, sandklef.com
 */

#include <Arduino.h>
#include <searduino.h>
#include "percentage.h"
//#include "batteryLevel.h"
#include "alarm.h"
#include "fourLedsOn.h"

/* 
 * Variable where the percentage will be stored
 */
int PERCENTAGE;

/*
 * This method is called from the scheduler and checks which battery should be calculated.
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

/*
 * This function calculates the battery level for the first battery.
 */
int getFirstBatteryLevel()
{
	if(analogRead(BATTERY_PIN1) < 843)
	{
		return 0;
	} else
	{
		PERCENTAGE = 100 - (((1023 - analogRead(BATTERY_PIN1)) / 180 * 100));
//    		int percentage1 = check();
//    		setup_alarm(percentage1);
//    		display_percentage(percentage1); 
        /* these are done in BatteryMeter.c - bruce */
		return PERCENTAGE;
	}
}

/*
 * This function calculates the battery level for the second battery.
 */
int getSecondBatteryLevel()
{
	if(analogRead(BATTERY_PIN2) < 843)
	{
		return 0;
	} else
	{
		PERCENTAGE = 100 - (((1023 - analogRead(BATTERY_PIN2)) / 180 * 100));
//    		int percentage2 = check();
//    		setup_alarm(percentage2);
//    		display_percentage(percentage2);
        /* these are done in BatteryMeter.c - bruce */

		return PERCENTAGE;
	}
}

/*
 * This function calculates the battery level for the third battery.
 */
int getThirdBatteryLevel()
{
	if(analogRead(BATTERY_PIN3) < 843)
	{
		return 0;
	} else
	{
		PERCENTAGE = 100 - (((1023 - analogRead(BATTERY_PIN3)) / 180 * 100));
//    		int percentage3 = check();
//    		setup_alarm(percentage3);
//    		display_percentage(percentage3);
        /* these are done in BatteryMeter.c - bruce */

		return PERCENTAGE;
	}
}



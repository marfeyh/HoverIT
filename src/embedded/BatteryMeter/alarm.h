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
 *<http://www.gnu.org/licenses/gpl-3.0.html>.
 */

/*!
 @file alarm.h
 @details Header file for alarm.c
 @author Neda MOhammadian
 @Date   17 april 2012
 @version 3
 */
 
#ifndef ALARM_H
#define ALARM_H


	#define EMPTY_BATTERY 5
	#define LOW_BATTERY 80
	#define LOW_BATTERY_DURATION 20
	
	void init_alarm(void);
	void setup_alarm(uint8_t);
	int beep(int);
//	int getBattery(void);
	void setup_battery_level(void);
	int loop_battery_level(uint8_t);

#endif
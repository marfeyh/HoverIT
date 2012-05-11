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
 @file batteryMeter.h
 @details the API of the battery meter
 @authors Bruce Yinhe
 @version  26 Arpil 2012
 @Copyright (c) 2012__MyCompanyName__. All rights reserved.
 */



#ifndef _batteryMeter_h
#define _batteryMeter_h

//#define FIRST_BATTERY 1
//#define SECOND_BATTERY 2 //old code by denir
//#define THIRD_BATTERY 3
#define FIRST_BATTERY_ID 0x50
#define SECOND_BATTERY_ID 0x50 //TODO not 0x50
#define THIRD_BATTERY_ID 0x50 //TODO not 0x50

int init_battery_meter(void);
uint8_t get_battery_level(int);

#endif

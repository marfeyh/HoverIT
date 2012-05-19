/*!
 * @file battery_meter.h
 * @details the API of the battery meter
 * @author Bruce Yinhe
 * @version  26 Arpil 2012
 * @section LICENSE
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 * 
 * This program is distodributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *  
 * You should have received a copy of the GNU General Public
 * License along with this program. If not, see
 * <http://www.gnu.org/licenses/gpl-3.0.html>.
 */

#ifndef _batteryMeter_h
#define _batteryMeter_h

#define FIRST_BATTERY 1
#define SECOND_BATTERY 2
#define THIRD_BATTERY 3
#define FIRST_BATTERY_ID 0x50
#define SECOND_BATTERY_ID 0x60 
#define THIRD_BATTERY_ID 0x70

int init_battery_meter(void);
unsigned char get_battery_level(int);
unsigned char translate_level(int);
unsigned char make_msg(int, int);

#endif

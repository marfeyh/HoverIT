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
@details This module is the header file for percentage.c 
@authors Denir
@version 0.9
@note 
@todo test it and integrate it
*/

#ifndef PERCENTAGE_H
#define PERCENTAGE_H

#define BATTERY_PIN1 1
#define BATTERY_PIN2 2
#define BATTERY_PIN3 3

int getPercentage(int);
int getFirstBatteryLevel(void);
int getSecondBatteryLevel(void);
int getThirdBatteryLevel(void);

#endif

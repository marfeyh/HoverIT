/***************************************************************************
 * Copyright (C) 2012  Eva-Lisa Kedborn
 *                     Jing Liu
 * 
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 ****************************************************************************/

/*!
@file main.c
@author Eva-Lisa Kedborn
@author Jing Liu
@date 2012-03-19
@brief Main function to run the hover code separately from the
rest of the project
*/

#include "Arduino.h"
#include <hover_api.h>
#include "Arduino.h"
#include <hovering_motor.h>
#include <hovering_control.h>

/*!
@brief Main function to run manual tests
@param none
@returns integer 0 if successful
*/
int main(void) {
        init();
	start_hover();
	hover_min();	
	delay(1000);
	hover_max();
	delay(2000);
	increase_hover_auto();
	delay(2000);
	stop_hover();
	return 0;
}

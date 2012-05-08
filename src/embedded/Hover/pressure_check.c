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

/* 
@file pressure_check.c
@headerfile pressure_check.h
@headerfile pressure.h
@headerfile hovering motor.h
@author Eva-Lisa Kedborn
@author Jing Liu
@date: 2012-03-20
@details continuously read air pressure inside the hovercraft
         skirt and adjust the speed of the hovering fan accordingly
@version 0.1
*/

#include <stdio.h>
#include <pressure.h>
#include <hovering_motor.h> 
#include "pressure_check.h"
#include "hovering_control.h"
#include "pin.h"
#define PROPER_GAP 50
#define MAX_GAP_RANGE 60
#define MIN_GAP_RANGE 40
#define AUTO_GAP 10


/*!
@brief Function to get pressure data from the pressure sensor
@param takes no parameters
@returns integer 0 if successful
*/
int start_sensor_reading() {
    handle_pressure(get_pressure());
    return 0;
}

/*!
@brief Function to evaluate the pressure data
@param the pressure difference inside and outside the skirt
@returns integer 1 if the pressure should be increased,
         interger -1 if the pressure should be decreased,
	 integer 0 if no adjustment needs to be made
*/
int handle_pressure(int gap) {

  printf("Gap is %d", gap);
  
  if (gap > MAX_GAP_RANGE) {
    hover_change(increase, USING_PIN, TEST_PIN, AUTO_GAP);   
   /* function from hovering_motor.c to increase fan speed */
    printf("Speed is increased");
    return 1;
  }
 
  if (gap < MIN_GAP_RANGE) {
    hover_change(decrease, USING_PIN, TEST_PIN, AUTO_GAP);
    /* function from hovering_motor.c to decrease fan speed */
    printf("Speed is decreased");
    return -1;
  }
  return 0;
}


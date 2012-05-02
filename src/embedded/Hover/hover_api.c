
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
@file hover_api.c
@headerfile hover_api.h
@author Eva-Lisa Kedborn
@author Jing Liu
@date 2012-03-28
@version 0.2
@brief API for controling hovering fan
 */

#include <stdlib.h>
#include <hover_api.h>
#include <hovering_motor.h>
#include <hovering_control.h>
#include <pressure_check.h>
#include <pin.h>

#define HOVER_LEVEL_AUTO 10
#define HOVER_LEVEL_MANUAL 40

/*!
@brief start the hovering fan
 */
int start_hover() {
  initialize(USING_PIN, TEST_PIN);
  return 0;
}

/*!
@brief stop the hovering fan
 */
int stop_hover() {          
  hover_func(stop, USING_PIN, TEST_PIN);
  return 0;
}

/*!
@brief minimize the fan speed
 */
int hover_min() {
  hover_func(normal, USING_PIN, TEST_PIN);
  return 0;
}

/*!
@brief maximize the fan speed
 */
int hover_max() {
  hover_func(turbo, USING_PIN, TEST_PIN);
  return 0;
}

/*!
@brief increase the speed through manual control, in total 3 levels
 */
int increase_hover_manual() {
  hover_change(increase, USING_PIN, TEST_PIN, HOVER_LEVEL_MANUAL);
  return 0;
}

/*!
@brief decrease the speed through manual control, in total 3 levels
 */
int decrease_hover_manual() {       
  hover_change(decrease, USING_PIN, TEST_PIN, HOVER_LEVEL_MANUAL);
  return 0;
}


/*!
@brief decrease the fan speed automatically
 */
int decrease_hover_auto() {       
  hover_change(decrease, USING_PIN, TEST_PIN, HOVER_LEVEL_AUTO);
  return 0;
}

/*!
@brief increase the speed automatically
 */
int increase_hover_auto() {
  hover_change(increase, USING_PIN, TEST_PIN, HOVER_LEVEL_AUTO);
  return 0;
}

/*!
@brief fan speed cotrolled by pressure sensor automatically
 */
int autocontrol() {       
  start_sensor_reading();
  return 0;
}

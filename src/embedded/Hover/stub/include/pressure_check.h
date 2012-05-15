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
@file pressure_check.h
@details This file contains the functions for receiving and evaluating
 pressure data from the pressure sensor for the sake of automatic control
@author Eva-Lisa Kedborn
@author Jing Liu
@version 0.1
*/

/*!
@brief Function to initialize the fan. It needs to be done before it can
start to rotate.
@param takes no parameters
@returns integer 0 if successful
*/
int handle_pressure(int);

/*!
@brief Function to get pressure data from the pressure sensor
@param takes no parameters
@returns integer 0 if successful
*/
int start_sensor_reading();

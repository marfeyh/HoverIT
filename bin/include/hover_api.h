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
@file hover_api.h
@details This file contains the functions for controlling the speed of the 
hovering fan manually.
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
int initialize();

/*!
@brief Function to start rotating the fan at lowest speed
@param takes no parameters
@returns integer 0 if successful
*/		
int start_hover();

/*!
@brief Function to stop the rotation of the fan
@param takes no parameters
@returns integer 0 if successful
*/
int stop_hover();

/*!
@brief Function to rotate the fan at minimum speed.
@param takes no parameters
@returns integer 0 if successful
*/
int hover_min();

/*!
@brief Function to rotate the fan at maximum speed.
@param takes no parameters
@returns integer 0 if successful
*/
int hover_max();

/*!
@brief Function to decrease the rotation speed of the fan. Will decrease by
one level at a time. Three speed levels possible.
@param takes no parameters
@returns integer 0 if successful
*/
int decrease_hover_manual();

/*!
@brief Function to increase the rotation speed of the fan. Will increase by
one level at a time. Three speed levels possible.
@param takes no parameters
@returns integer 0 if successful
*/
int increase_hover_manual();

/*!
@brief Function to decrease the rotation speed of the fan used for automatic
control.
@param takes no parameters
@returns integer 0 if successful
*/
int decrease_hover_auto();

/*!
@brief Function to increase the rotation speed of the fan used for automatic
control.
@param takes no parameters
@returns integer 0 if successful
*/
int increase_hover_auto();

/*!
@brief Function for the rotation speed of the fan to be controlled 
automatically by sensing the air pressure inside the skirt.
@param takes no parameters
@returns integer 0 if successful
*/
int autocontrol();

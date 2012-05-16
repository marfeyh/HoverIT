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
@details This file contains the functions for receiving fake air pressure
inside hovercraft skirt. 
To be used for testing purposes.
@author Eva-Lisa Kedborn
@author Jing Liu
@version 0.1
*/

/*!
@brief Function to receive a random air pressure between 0 and 100
air pressure
@param takes no parameters
@returns integer between 0 and 100 representing a random air pressure
*/
int get_pressure();

/*!
@brief Function to receive fake air pressure higher than preferred
air pressure
@param takes no parameters
@returns integer 70
*/
int get_positive();

/*!
@brief Function to receive fake air pressure lower than preferred
air pressure
@param takes no parameters
@returns integer 30
*/
int get_negative();

/*!
@brief Function to receive fake air pressure equal to the preferred
air pressure
@param takes no parameters
@returns integer 50
*/
int get_equal();

/* int initialize(int using_pin, int test_pin); */
/* int hover_fun(int (*func)(int, int),int using_pin, int test_pin); */
/* int start(int using_pin, int test_pin); */
/* int stop(int using_pin, int test_pin); */

/*!
@copyright This program is free software: you can redistribute it and/or
modify it under the terms of the GNU General Public License as published
by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
@file propulsion_api.h
@brief This file contains the functions for controlling 
       the propulsion fan speed
@author: Xinran He & Khatereh Khosravianarab
@version 0.1
*/
#define MAXSPEED 122
#define PERSPEED 40

/*!
@brief Funtion to initialise propulsion fan
@param takes no parameters
@returns 0
*/
int start_propulsion_fan();

/*!
@brief Function to increase propulsion fan speed
@param takes no parameters
@returns current propulsion fan speed
*/
int increase_propulsion();

/*!
@brief Function to decrease propulsion fan speed
@param takes no parameters
@returns current propulsion fan speed
*/
int decrease_propulsion();

/*!
@brief Function to get current propulsion level(e.g. 0,1,2,3)
@param takes no parameters
@returns integer 0 or 1 or 2 or 3
*/
int get_propulsion_level();

/*!
@brief Function to stop propulsion fan
@param takes no parameters
@returns 0
*/
int stop_propulsion_fan();

/*!
@brief Function to set propulsion fan speed
@param integer between 0 and 122
@returns -1 for error or current fan speed
*/
int set_propulsion_fan(int set_speed);

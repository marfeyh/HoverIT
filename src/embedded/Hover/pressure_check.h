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

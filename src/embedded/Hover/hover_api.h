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
@brief Function to decrease the rotation speed of the fan
@param takes no parameters
@returns integer 0 if successful
*/
int decrease_hover();

/*!
@brief Function to increase the rotation speed of the fan
@param takes no parameters
@returns integer 0 if successful
*/
int increase_hover();

/*!
@brief Function for the rotation speed of the fan to be controlled 
automatically by sensing the air pressure inside the skirt.
@param takes no parameters
@returns integer 0 if successful
*/
int autocontrol();

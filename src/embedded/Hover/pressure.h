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

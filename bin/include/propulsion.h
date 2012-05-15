/*!
@file propulsion.h
@copyright This program is free software: you can redistribute it and/or
modify it under the terms of the GNU General Public License as published
by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
@author Yohanes Kuma
@details This file is ment for controlling the Propulsion fan motor. 
The code is responsible to controll the speed of the fan for
the movement of the Hovercraft. it is developed by using the 
Libraries of Arduino and Searduino. Refere to their manual for more 
information. 
@see http://arduino.cc/en/Reference/Libraries
@see http://itupw185.itu.chalmers.se/searduino/?page_id=16
@date 2012-04-05
*/


/* maximum duty cycle for Pulse width modulation **/
#define MAX_DUTY_CYCLE 254
/* Minimum duty cycle for Pulse width modulation **/
#define MIN_DUTY_CYCLE 132
/* 
   The maximum level of the speed. it is dependent on the type 
   of Microcontroller used and the range of duty cycles for PWM 	
   which can rotate the Motor 
*/
#define MAX_SPEED_LEVEL 122
/* Delay time **/
#define TIME_ELAPSE 100

unsigned char manage_motor();
int initialise_propulsion();
int get_speed_level();
void change_pro_speed(int level);
void stop_pro_fan();
unsigned char get_motor_status();

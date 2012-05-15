/*!
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as
 published by the Free Software Foundation, either version 3 of the
 License, or (at your option) any later version.
 
 This program is distodributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public
 License along with this program. If not, see
 <http://www.gnu.org/licenses/gpl-3.0.html>.
 */


/*!
 @file pin.h
 @details  Details all the pins used for the battery meter.
 @authors Jody Swartz
 @version  11 May 2012
 @References  Arduino.cc, sandklef.com 
 @Copyright (c) 2012__MyCompanyName__. All rights reserved.
 */

#define BATTERY_PIN1 1  //Analog pin 1
#define BATTERY_PIN2 2  //Analog pin 2
#define BATTERY_PIN3 3  //Analog pin 3
#define ledPin1  2     //Digital pin 2
#define ledPin2  4     //Digital pin 4 
#define ledPin3  7     //Digital pin 7
#define ledPin4  8     //Digital pin 8

/* This ugly hack is made to get around Henrik's stupid code
   keep it as a reminder so I see it when reviewing :(
*/ 
#ifdef SEADRDUINO_STUB
#define SPEAKER_PIN A0 //Analog 0
#else
#define SPEAKER_PIN 11 //Digital pin 11
#endif


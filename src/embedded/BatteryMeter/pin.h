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

#define BATTERY_PIN1 A13  //Analog pin 1 A15
#define BATTERY_PIN2 A14  //Analog pin 2 A14
#define BATTERY_PIN3 A15  //Analog pin 3 A13
#define ledPin1  53     //Digital pin 2 53
#define ledPin2  52     //Digital pin 4 52
#define ledPin3  51     //Digital pin 7 51
#define ledPin4  50     //Digital pin 8 50

/* This ugly hack is made to get around Henrik's stupid code
   keep it as a reminder so I see it when reviewing :(
*/ 
#ifdef SEADRDUINO_STUB
#define SPEAKER_PIN A0 //Analog 0
#else
#define SPEAKER_PIN 49 //Digital pin 11 49

#endif


 /*!
  * This program is free software: you can redistribute it and/or modify
  *it under the terms of the GNU General Public License as
  *published by the Free Software Foundation, either version 3 of the
  *License, or (at your option) any later version.
  *
  *This program is distodributed in the hope that it will be useful,
  *but WITHOUT ANY WARRANTY; without even the implied warranty of
  *MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  * GNU General Public License for more details.
  *
  *You should have received a copy of the GNU General Public
  *License along with this program. If not, see
  *<http://www.gnu.org/licenses/gpl-3.0.html>.
  **/  
/*!        
@file alarm.c
@headerfile Arduino.h
@headerfile searduino.h
@headerfile tonerWrapper.h
@headerfile alarm.h
@details Contains the functions that will send a tone to pin 11 (speakers)based on battery level it will generate different frequencies
@author Mahsa Mirtalebi
@author Neda Mohammadian
@date   17 april 2012
@version 3
*/	
 

#include <Arduino.h>
#include <searduino.h>
#include "toneWrapper.h"
#include "alarm.h"
#include "pin.h"

int battery_beep_duration;
/*
@brief the initial state of this function.
that call setup_battery_level
*/
void init_alarm() {
    setup_battery_level();
}
/* 
@brief the setup state of this function .in this state  
pinMOde are set to output (speaker).
*/

void setup_battery_level(){
    
	 // for searduino test.
	pinMode(SPEAKER_PIN, OUTPUT);
    battery_beep_duration = 0;
}

/* 
@brief the setup function is calling loop_battery_level 
that will be the loop file in main file
*/

void setup_alarm(uint8_t percentage) {
    loop_battery_level(percentage);
}
/* 
@brief the fuction that will be the loop of the file in main file 
@param int  8 integer number that representing the percentage
@return int integer number representing what kind of sound should be use.
*/

int loop_battery_level(uint8_t Battery){
	printf("Battery beep duration: %d\n", battery_beep_duration);
  if(Battery==LOW_BATTERY && battery_beep_duration<LOW_BATTERY_DURATION){
    beep(LOW_BATTERY);
    battery_beep_duration++;
	return 1;
  }else if(Battery<=EMPTY_BATTERY){
    beep(EMPTY_BATTERY);
	return 0;
  }else{
    my_noTone(SPEAKER_PIN);
	return -1;
  }
}

/*!	
 @brief this function make sound based on the argument 	
 @param int integer number representing the type of the sound         	
 @return int integer number representing what kind of sound function made         
*/

int beep(int beep){
  switch(beep){
    case LOW_BATTERY:
      my_tone(SPEAKER_PIN, 4500);
	  return 0;
      break;
    case EMPTY_BATTERY:
      my_tone(SPEAKER_PIN, 5000);
	  return -1;
      break;
  }
}
//int getBattery(){     
//  return 20;
//}


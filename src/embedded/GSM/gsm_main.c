/*
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
 @file blink_main.c
 @authors Bishare and Stepan
 @date 20120502
*/

#include <Arduino.h>
#include "gsm_setup.h"
#include "call_processor.h"

uint8_t gsm_loop_func(int bluetooth_pin){

	//if(digitalRead(bluetooth_pin) == LOW){
	
	loop_GSM();
	

	//}

}


/**
 *  Main funtion that calls the Arduino code
 */
uint8_t main(void) {

  
 
  init();
  gsm_setup();
  
  for (;;) {

  gsm_loop_func(9);	
  
  } 
  
}  
  
  
   



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
 @file blink.c
 @authors Bishare Sufi, Stepan Stepasyuk
 @date 20120502
*/
 
#include "blink.h"

/*!
 @brief This function makes pin blink rapidly when we have incoming all
 @return 0 on success
*/
uint8_t blinker(uint8_t pin){

  uint8_t i;
      
  for (i=0;i<=10;){
      digitalWrite(pin, HIGH);
      delay(10);
      digitalWrite(pin, LOW);
      delay(10);

      i++;
  }
  
      digitalWrite(pin, LOW);
      delay(80);
      
    return 0;
}

/*!
 @brief Function to light up the pin 
 @return 0 on success
*/
uint8_t set_led_On(uint8_t pin){
    
    digitalWrite(pin, HIGH);
    
    return 0;
    
}

/*!
 @brief Function turn off the pin
 @return 0 on success
*/
uint8_t isOff(uint8_t pin){
       
     digitalWrite(pin, LOW);
                       
     return 0;

}





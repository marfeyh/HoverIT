/*!
 *This program is free software: you can redistribute it and/or modify
 *it under the terms of the GNU General Public License as
 *published by the Free Software Foundation, either version 3 of the
 *License, or (at your option) any later version.
 *
 *This program is distodributed in the hope that it will be useful,
 *but WITHOUT ANY WARRANTY; without even the implied warranty of
 *MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *GNU General Public License for more details.
 *
 *You should have received a copy of the GNU General Public
 *License along with this program. If not, see
 *<http://www.gnu.org/licenses/gpl-3.0.html>.
 */

/*!
 @file fourLedsOn.c
 @details Contains the functions that turns on four leds to show how much battery left
 @authors Nahid Vafaie
 @version 4 May 9 2012
 @note this is a note about this module (optional)
 @todo if anything should be further developed on this module (optional)
 */



#include <Arduino.h>
#include<searduino.h>
#include "four_leds.h"
#include "pin.h"

int ledState = LOW;
unsigned long previousTimer = 0;


/*
 @brief The initial state of this funtion. In this state  
 pinsMode are set to OUTPUT and all the four ledping shoyuld
 be in HIGH state.
 @param takes no parameters
 @returns nothing
 */

void init_leds(void)
{

 pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  digitalWrite(ledPin1,HIGH);
  digitalWrite(ledPin2,HIGH);
  digitalWrite(ledPin3,HIGH);
  digitalWrite(ledPin4,HIGH);
  

}



/*
 @brief This function is specifying limits of the values to
 make the leds on and off accordingly.
 @param The value which is the percentage of the battery life
 @returns nothing
 */

void display_percentage(int value)

{
	
	unsigned long currentTimer = millis();
	
	// percentage of the battery life is between 100 and 81, four leds are on
	if(value <= 100 && value > 80)
    {
       digitalWrite(ledPin1,HIGH);
       digitalWrite(ledPin2,HIGH);
       digitalWrite(ledPin3,HIGH);
       digitalWrite(ledPin4,HIGH);
    }
	
	// percentage of the battery life is between 80 and 61, three leds are on
  else if (value <= 80 && value > 60 )
    {
       digitalWrite(ledPin1,LOW);
       digitalWrite(ledPin2,HIGH);
       digitalWrite(ledPin3,HIGH);
       digitalWrite(ledPin4,HIGH);
    }
	
	// percentage of the battery life is between 60 and 41, two leds are on
  else if (value <= 60 && value > 40 )
    {
      digitalWrite(ledPin1,LOW);
       digitalWrite(ledPin2,LOW);
       digitalWrite(ledPin3,HIGH);
       digitalWrite(ledPin4,HIGH);
    }
	// percentage of the battery life is between 40 and 21, one led are on
  else if (value <= 40 && value > 20 )
  {
      digitalWrite(ledPin1,LOW);
	  digitalWrite(ledPin2,LOW);
	  digitalWrite(ledPin3,LOW);
	  digitalWrite(ledPin4,HIGH);
	  
  }
	
	// percentage of the battery life is between 20 and 1, four leds are blinking
  else if (value <= 20 && value > 0)
         {
			
			 
			 //using millis() function for currentTimer instead of using delay since delay 
			 // can't be used because of the integration with the scheduler
			 
			 if(currentTimer - previousTimer > 500){
				 previousTimer = currentTimer ;
				 if (ledState == LOW)
					 ledState = HIGH;
				 else 
					 ledState = LOW;
				 
				 digitalWrite(ledPin1,ledState);
				 digitalWrite(ledPin2,ledState);
				 digitalWrite(ledPin3,ledState);
				 digitalWrite(ledPin4,ledState);

			 
			 }
		 }
	
	// percentage of the battery life is 0 , all four leds are off
	else if ( value == 0)
	{
		digitalWrite(ledPin1,LOW);
		digitalWrite(ledPin2,LOW);
		digitalWrite(ledPin3,LOW);
		digitalWrite(ledPin4,LOW);
	
	}
	
}
	
/*
 @brief This function is calling display_percentage that will be 
 the loop part in main file.
 */

void run_leds(void)
{
	int value;
	display_percentage(value);
	
}

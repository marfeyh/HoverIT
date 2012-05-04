/*
 * @ Module name:  fourLedsOn.c
 * @ Description:  Contains the functions that turns on four leds to show how much battery left
 * @ Author names :Nahid Vafaie , Jody Swartz
 * @ Release      :25 April 2012
 * @ Version      : 3
 * @ Refrences    : Arduino.cc, sandklef.com
 */

#include <Arduino.h>
#include<searduino.h>
#include "fourLedsOn.h"

uint8_t ledState = LOW; /******bruce added*****/
unsigned long previousTimer = 0; /*****bruce added*****/

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
    /***********this line was moved to line: 15 by bruce **********/

	// percentage of the battery life is between 100 and 81, four leds are on
	if(value <= 100 && value > 80)
    {
       digitalWrite(ledPin1,HIGH);
       digitalWrite(ledPin2,HIGH);
       digitalWrite(ledPin3,HIGH);
       digitalWrite(ledPin4,HIGH);
//        printf("\n***100 - 80\n");

    }
	
	// percentage of the battery life is between 80 and 61, three leds are on
  else if (value <= 80 && value > 60 )
    {
       digitalWrite(ledPin1,LOW);
       digitalWrite(ledPin2,HIGH);
       digitalWrite(ledPin3,HIGH);
       digitalWrite(ledPin4,HIGH);
//    printf("\n***80 - 60\n");

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
	  printf("\n***40 - 20\n");
  }
	
	// percentage of the battery life is between 20 and 1, four leds are blinking
  else if (value <= 20 && value > 0)
         {
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
 @brief This function is calling disply_percentage that will be 
 the loop part in main file.
 */

void run_leds(void)
{
	int value;
	display_percentage(value);
	
}

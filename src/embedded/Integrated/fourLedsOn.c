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
#include <fourLedsOn.h>
#include "../../BatteryMeter/batteryMeter.c"

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
  delay(timer1);

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

/*
 @brief This function is specifying limits of the values to
 make the leds on and off accordingly.
 @param The value which is the percentage of the battery life
 @returns nothing
 */

void display_percentage(int value)
{
	if(value <= 100 && value > 80)
    {
       digitalWrite(ledPin1,HIGH);
       digitalWrite(ledPin2,HIGH);
       digitalWrite(ledPin3,HIGH);
       digitalWrite(ledPin4,HIGH);
    }
  else if (value <= 80 && value > 60 )
    {
       digitalWrite(ledPin1,LOW);
       digitalWrite(ledPin2,HIGH);
       digitalWrite(ledPin3,HIGH);
       digitalWrite(ledPin4,HIGH);
    }
  else if (value <= 60 && value > 40 )
    {
      digitalWrite(ledPin1,LOW);
       digitalWrite(ledPin2,LOW);
       digitalWrite(ledPin3,HIGH);
       digitalWrite(ledPin4,HIGH);
    }
	
  else if (value <= 40 && value > 20 )
  {
      digitalWrite(ledPin1,LOW);
	  digitalWrite(ledPin2,LOW);
	  digitalWrite(ledPin3,LOW);
	  digitalWrite(ledPin4,HIGH);
	  
  }
	
	
  else if (value <= 20 && value > 0)
         {
           digitalWrite(ledPin1,HIGH);
           digitalWrite(ledPin2,HIGH);
           digitalWrite(ledPin3,HIGH);
           digitalWrite(ledPin4,HIGH);
           delay(timer1);
           digitalWrite(ledPin1,LOW);
           delay(timer1);
           digitalWrite(ledPin2,LOW);
           delay(timer1);
           digitalWrite(ledPin3,LOW);
           delay(timer1);
           digitalWrite(ledPin4,LOW);
           delay(timer1);
         }
}

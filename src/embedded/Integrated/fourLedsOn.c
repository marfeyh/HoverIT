/*
 * @ Module name:  fourLedsOn.c
 * @ Description:  Contains the functions that turns on four leds to show how much battery left
 * @ Author names :Nahid Vafaie , Jody Swartz
 * @ Release      :13 April 2012
 * @ Version      : 3
 * @ Refrences    : Arduino.cc, sandklef.com
 */

#include <Arduino.h>
#include <searduino.h>
#include "fourLedsOn.h"

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

void run_leds(void)
{
  int value;
  display_percentage(value);

}

void display_percentage(uint8_t value)
{
  if(value == 100)
    {
       digitalWrite(ledPin1,HIGH);
       digitalWrite(ledPin2,HIGH);
       digitalWrite(ledPin3,HIGH);
       digitalWrite(ledPin4,HIGH);
    }
  else if (value <= 80 && value > 53 )
    {
       digitalWrite(ledPin1,LOW);
       digitalWrite(ledPin2,HIGH);
       digitalWrite(ledPin3,HIGH);
       digitalWrite(ledPin4,HIGH);
    }
  else if (value <= 53 && value > 27 )
    {
      digitalWrite(ledPin1,LOW);
       digitalWrite(ledPin2,LOW);
       digitalWrite(ledPin3,HIGH);
       digitalWrite(ledPin4,HIGH);
    }
  else if (value <= 27 && value > 0)
         {
           digitalWrite(ledPin1,LOW);
           digitalWrite(ledPin2,LOW);
           digitalWrite(ledPin3,LOW);
           digitalWrite(ledPin4,HIGH);
           delay(timer1);
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

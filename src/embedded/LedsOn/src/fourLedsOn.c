/*
 * @ Module name:  fourLedsOn.c
 * @ Description:  Contains the functions that turns on four leds to show how much battery left
 * @ Author names :Nahid Vafaie
 * @ Release      :13 April 2012
 * @ Version      : 2
 * @ Refrences    : Arduino.cc, sandklef.com
 */

#include <Arduino.h>
#include<searduino.h>
#include <fourLedsOn.h>



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
  digitalWrite(ledPin1,LOW);
  delay(timer2);
  digitalWrite(ledPin2,LOW);
  delay(timer3);
  digitalWrite(ledPin3,LOW);
  delay(timer2);
}

void run_leds(void)
{
  digitalWrite(ledPin1,HIGH);
  digitalWrite(ledPin2,HIGH);
  digitalWrite(ledPin3,HIGH);
  digitalWrite(ledPin4,HIGH);
  delay(timer4);
  digitalWrite(ledPin1,LOW);
  delay(timer4);
  digitalWrite(ledPin2,LOW);
  delay(timer4);
  digitalWrite(ledPin3,LOW);
  delay(timer4);
  digitalWrite(ledPin4,LOW);
  delay(timer4);
}

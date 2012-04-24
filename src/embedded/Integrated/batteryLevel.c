/*
 * @ Module name:  batteryLevel.c
 * @ Description:  Contains the functions that reads the voltage of the battery and
 *                  turns on four leds to show how much battery left
 * @ Author names :Kuhan Loh, Aran Gerami, Denir Leric, Nahid Vafaie
 * @ Release      :24 April 2012
 * @ Version      :4
 * @ Refrences    : Arduino.cc, sandklef.com
 */



#include <Arduino.h>
#include <searduino.h>
#include "batteryLevel.h"

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

void check() {

		const static uint8_t SENSOR_PIN = 19;
		uint8_t SENSOR_VALUE = 0;

		SENSOR_VALUE = analogRead(SENSOR_PIN);

		  if (SENSOR_VALUE >  0 && SENSOR_VALUE < 204.7){
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
		        //1Volt Remaining
		  } else if (SENSOR_VALUE >  204.6 && SENSOR_VALUE < 409.3){
			   digitalWrite(ledPin1,LOW);
			   digitalWrite(ledPin2,LOW);
			   digitalWrite(ledPin3,LOW);
			   digitalWrite(ledPin4,HIGH);
		        //2Volts Remaining
		  } else if (SENSOR_VALUE >  409.2 && SENSOR_VALUE < 613.9){
			   digitalWrite(ledPin1,LOW);
			   digitalWrite(ledPin2,LOW);
			   digitalWrite(ledPin3,HIGH);
			   digitalWrite(ledPin4,HIGH);
		        //3Volts Remaining
		  } else if (SENSOR_VALUE >  613.8 && SENSOR_VALUE < 818.5){
			   digitalWrite(ledPin1,LOW);
			   digitalWrite(ledPin2,HIGH);
			   digitalWrite(ledPin3,HIGH);
			   digitalWrite(ledPin4,HIGH);
		        //4Volts Remaining
		  } else if (SENSOR_VALUE > 818.4){
			   digitalWrite(ledPin1,HIGH);
			   digitalWrite(ledPin2,HIGH);
			   digitalWrite(ledPin3,HIGH);
			   digitalWrite(ledPin4,HIGH);
		        //5Volts remaining
		  }

	return 0;
}

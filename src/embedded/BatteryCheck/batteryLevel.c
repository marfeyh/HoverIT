/*
 ============================================================================
 Name        : batteryLevel.c
 Author      : Kuhan Loh, Aran Gerami, Denir Leric
 Version     : v 0.1
 Copyright   : Your copyright notice
 Description : Battery Check in C
 ============================================================================
 */


#include <Arduino.h>
#include <searduino.h>
#include <pins_arduino.h>
#include <batteryLevel.h>


void check(void) {

		SENSOR_VALUE = analogRead(SENSOR_PIN);
		PERCENTAGE = (SENSOR_VALUE/1023*100) - 16.67;

		  if (SENSOR_VALUE >  0 && SENSOR_VALUE < 204.7){
		    digitalWrite(LED_PIN, 1);
		    delay(1000);
		    digitalWrite(LED_PIN, 0);
		    delay(1000);
		        //1Volt Remaining
		  } else if (SENSOR_VALUE >  204.6 && SENSOR_VALUE < 409.3){
		    digitalWrite(LED_PIN, 1);
		    delay(2000);
		    digitalWrite(LED_PIN, 0);
		    delay(2000);
		        //2Volts Remaining
		  } else if (SENSOR_VALUE >  409.2 && SENSOR_VALUE < 613.9){
		    digitalWrite(LED_PIN, 1);
		    delay(3000);
		    digitalWrite(LED_PIN, 0);
		    delay(3000);
		        //3Volts Remaining
		  } else if (SENSOR_VALUE >  613.8 && SENSOR_VALUE < 818.5){
		    digitalWrite(LED_PIN, 1);
		    delay(4000);
		    digitalWrite(LED_PIN, 0);
		    delay(4000);
		        //4Volts Remaining
		  } else if (SENSOR_VALUE > 818.4){
		    digitalWrite(LED_PIN, 1);
		        //5Volts remaining
		  }

}

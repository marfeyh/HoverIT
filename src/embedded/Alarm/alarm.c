/*!	
 @file alarm.c
 @headerfile Arduino.h
 @headerfile searduino.h
 @headerfile tonerWrapper.h
 @headerfile alarm.h
 @details Contains the functions that will send a tone to pin 11 (speakers)based on battery level it will generate different frequencies
 @author Mahsa Mirtalebi
 @author Neda Mohammadian
 @version 3
 */



#include <Arduino.h>
#include <searduino.h>
#include "toneWrapper.h"
#include "alarm.h"

int battery_beep_duration=0;

void setup() {
 setup_battery_level();
}

void setup_battery_level(){
//  Serial.begin(9600);
	pinMode(13,OUTPUT);
}

void exec(uint8_t percentage) {
//	for(;;){
		loop_battery_level(percentage);
		//digitalRead(13) ? digitalWrite(13,LOW) : digitalWrite(13,HIGH);
		// Delay will be removed in integrated version
//		delay(100);
//	}
}

int loop_battery_level(uint8_t Battery){
//  int Battery=getBattery();
  if(Battery==LOW_BATTERY && battery_beep_duration<LOW_BATTERY_DURATION){
    beep(LOW_BATTERY);
    battery_beep_duration++;
	return 1;
  }else if(Battery<=EMPTY_BATTERY){
    beep(EMPTY_BATTERY);
	return 0;
  }else{
      my_noTone(11);
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
      my_tone(11, 4500);
	  return 0;
      break;
    case EMPTY_BATTERY:
      my_tone(11, 5000);
	  return -1;
      break;
  }
}

//int getBattery(){     
//  return 20;
//}

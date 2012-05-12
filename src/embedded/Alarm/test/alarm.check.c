/*	
 * @ Module name:  main.c	
 * @ Description:  Contains the functions that will send a tone to pin 11 (speakers)based on battery level it will generate different frequencies 	
 * @ Author names :Neda Mohammadian	,mahsa mirtalebi
 * @ Release      :23 April 2012	(//first release in 17 april)
 * @ Version      : 2	
 */

#include <Arduino.h>
#include <searduino.h>
#include "toneWrapper.h"
#include "alarm.h"

int battery_beep_duration;

void init_alarm() {
    setup_battery_level();
}

void setup_battery_level(){
    /* for searduino test*/
    pinMode(11, OUTPUT);
    battery_beep_duration = 0;
}

void setup_alarm(uint8_t percentage) {
    loop_battery_level(percentage);
}

int loop_battery_level(uint8_t Battery){
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

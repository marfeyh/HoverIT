#include <Arduino.h>
#include <searduino.h>
#include <alarm.h>

int battery_beep_duration=0;

void setup() {
 setup_battery_level();
}

void setup_battery_level(){
//  Serial.begin(9600);
}

void exec() {
	for(;;){
		loop_battery_level();
		// Delay will be removed in integrated version
		delay(100);
	}
}

void loop_battery_level(){
  int Battery=getBattery();
  if(Battery==LOW_BATTERY && battery_beep_duration<LOW_BATTERY_DURATION){
    beep(LOW_BATTERY);
    battery_beep_duration++;
  }else if(Battery<=EMPTY_BATTERY){
    beep(EMPTY_BATTERY);
  }else{
      noTone(11);
  }
}


void beep(int beep){
  switch(beep){
    case LOW_BATTERY:
      tone(11, 4500);
      break;
    case EMPTY_BATTERY:
      tone(11, 5000);
      break;
  }
}

int getBattery(){     
  return 20;
}
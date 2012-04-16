#include <Arduino.h>
#include <searduino.h>

void setup() {

}

void exec() {
	for(;;){
		int Battery=getBattery();
		if(Battery<70 && Battery>30)
			beep(1);
		if(Battery<=30)
			beep(2);
		delay(3000);
	}
}




void beep(int beep){
  //noTone(11);
  switch(beep){
    case 1:
		digitalWrite(11,HIGH);
 //     tone(11, 500, 500);
      break;
    case 2:
		digitalWrite(12,HIGH);
 //     tone(11, 5000);
      break;
  }
}

int getBattery(){     
  return 20;
}
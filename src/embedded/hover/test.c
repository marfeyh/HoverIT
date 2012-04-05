//includes
#include <Arduino.h>
#include <searduino.h>

// Prototypes

// Variables
int pin=11;
int throttle_stick_level=100;

// Main
int main(void){
	// Initialize the Arduino	
	init();
	// Assign pin to output	
	pinMode(pin,OUTPUT);
	
	for(;;){
		analogWrite(pin,throttle_stick_level);
		delay(1000);
		throttle_stick_level=150;
	}
	return 1;
}	


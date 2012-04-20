#include <Arduino.h> 
#include <searduino.h>


int test_stop() {
	analogWrite(9,100);
	delay(1000);
	analogWrite(9,0);
	delay(1000);
	
return 0;
}

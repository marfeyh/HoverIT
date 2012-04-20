#include <Arduino.h> 
#include <searduino.h>


int test_stop() {
	analogWtite(9,100);
	dalay(1000);
	analogWtite(9,0);
	dalay(1000);
	
return 0;
}

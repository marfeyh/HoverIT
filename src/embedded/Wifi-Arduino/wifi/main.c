

#include <Arduino.h>
#include "searduino.h"
#include "wifi_wrapper.h"

#define led1 12
#define led2 13
unsigned char bw;
int main(void)
{
  
  init();
  //setup();
	
	wifi_begin();
	pinMode(led1, OUTPUT);
	pinMode(led2, OUTPUT);
	 
	for(;;)
    {
		while(wifi_available() >= 1){
			bw = wifi_read();
			digitalWrite(led2,HIGH);
			delay(1500);
			digitalWrite(led2,LOW);

			//if(bw == 12){
				//digitalWrite(led1,HIGH);
				//delay(1500);  
				//digitalWrite(led1,LOW);
			//}else if(bw == 13){			
				//digitalWrite(led2,HIGH);
				//delay(1500);  
				//digitalWrite(led2,LOW);
			//}
			//Serial.write(bw);
		}
		//if(Serial.available()){
		//	bs = Serial.read();
		//	wifi_write(bs);
		//}
	//	loop();
	}
}




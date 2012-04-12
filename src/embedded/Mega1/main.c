#include <stdio.h>
#include <Arduino.h>
#include <searduino.h>
#include <API_bluetooth_controler.h>
#include <Theta-API.h>
//#include <hover_api_stub.h>
//#include <propulsion_api.h>
//#include <RuddarControll.h>

int main (int argc, char** argv){
  init();
  pinMode(13,OUTPUT);
  bluetooth_serial_setup();
  //  start_propulsion_fan();
  //  start_hover();
  //  begin();
  
  for(;;){
    //control();
    
  }
  
  return 0;
}

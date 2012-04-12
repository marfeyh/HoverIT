#include <Arduino.h>
#include <searduino.h>
#include "gpos_sys.h"

int rxPin = 0;

 void setup() {
   pinMode(rxPin, INPUT);
   Serial.begin(57600);
 }

void loop(){
  char * read_D = read_data();
  char * get_time(read_D);
  Position * posi = get_position(read_D);
  /* Serial.println(); */
  free(read_D);
  free(get_time);
  free(posi);
}

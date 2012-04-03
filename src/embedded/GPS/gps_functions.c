/*Here goes all the functions*/
/*Include all the header files of all the functions*/
/*This will go to the production line*/

/* Pre Requests Serial port baud rate should be set to 57600 */

#include "nmea_datastructs.h"
#include <Arduino.h>
#include </opt/searduino/>
 int buffer = -1;
 char linea[300] = "";

 Position * read_data(void){
  
   for (int i=0;i<300;i++){
     linea[i]=' ';
   }   
   // if lines for everything ifdef mega serial pot 1 like wise
   buffer = Serial.read();
   
   if (buffer != -1){
   
   }
   
}



/*Here goes all the functions*/
/*Include all the header files of all the functions*/
/*This will go to the production line*/

/* Pre Requests Serial port baud rate should be set to 57600 */

#include "nmea_datastructs.h"
#include <Arduino.h>
#include <Searduino.h>
#include <string.h>
#include <ctype.h>

int buffer = -1;
char gprmc[7] = "$GPRMC"



 char* read_data(char *array){  
  char* linema = memalloc(300*sizeof(char));
   // if lines for everything ifdef mega serial pot 1 like wise
   int boolean = -1;
   int i = 0;
   int boolRMC = -1;
   while(boolean==-1){
   buffer = Serial.read();
   if (buffer != -1){
     if(buffer == 13){
       inc = 0;
        for (int i=1;i<7;i++){   
         if (linema[i]==comandoGPR[i-1]){
           boolRMC = 1;
         }       /*end if linema[i]*/
	 else {
	   boolean = -1;
	 } /*end else linema */
	} /*end for*/
     }/*end if buffer == 13*/
     else{
     linema[i] = buffer;
     i++;
     } /*end else buffer != -1*/
   }
   }
   return 0;
}


int get_time(int data,0){
  //returns time when passed with data integer and 0 "Zero"
  
}

float 

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
  
  
  
char* read_data(){  
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
     } /*end else buffer == 13*/
   }/*end else buffer != -1*/
   } /*end while boolean==-1*/
  return linema;
}/*end read_data(Char *array)*/
  
  
  char* get_time(char* data){
  //returns time when passed with data integer and 0 "Zero"
    return retrive_data(data, 0);
  }

struct Position * get_position(char* data){
  struct Position *pos = calloc(1,size_of(struct Position));
  char * temp1 = retrive_data (data,2);
  pos->latitude = atof(temp1);
  free(temp1);
  temp1 = retrive_data(data,2);
  pos->longitude = atof(temp1);
  free(temp1);
  temp1 = retrive_data(data,5);
  pos->nsew = temp1;
  free(temp1);
    return pos;
}


char* retrive_data(char* linema, int k){
  int cont = 0;
  char* value = malloc(20*size(char));
  
  for (int i=0;i<300;i++){
    if (linema[i]==','){    // check for the position of the  "," separator
      indices[cont]=i;
      cont++;
    }
    if (linema[i]=='*'){    // ... and the "*"
      indices[12]=i;
      cont++;
    }
    int i = 0;
    for (int j=indices[k];j<(indices[k+1]-1);j++){
      
      value[i] = linema[j+1]); 
    i++;
  }
  return value;
}

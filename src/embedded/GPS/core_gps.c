#include <stdio.h>
#include <stdlib.h>

#include "./tests/GPS_Simulator/emulator_GPS.h"
#include "gps.h"

#define LINEMA 300
#define WAITING_LOOP_VALUE 56

char gprmc[7] = "$GPRMC";

/* ADD COMMENT: GOKUL */  
char* read_rmc_data(){  
  char* linema  = malloc(LINEMA*sizeof(char));
  char buffer = -1;
  char boolean = 1;
  int index = 0;
  int death_counter = 1;
  while(boolean==1 && death_counter<WAITING_LOOP_VALUE){ 
    /*    buffer = Serial.read();*/
    buffer = serial_read(); /*TESTING*/
    if (buffer != -1){
      if(buffer == 13 || buffer == '\n'){ 
	index = 0;
	boolean = (char) is_GPRMC(linema);
      }/*end if buffer == 13*/ 
      else{  
	linema[index] = buffer;  
	/* printf("%c", (char)linema[index]);  */
	index++;  
      } /*end else buffer == 13 */
    }/*end else buffer != -1*/
    else{ 
      ++death_counter; 
    } 
  } /*end while boolean==-1*/
  return linema;
}/*end read_data(Char *array)*/
  
  
  /* ADD COMMENT: GOKUL */
char* retrive_data(char* linema, int k){
  int cont = 0;
  int indices[13];
  char* value = calloc(1,20*sizeof(char));
  int i;
  for (i=0;i<LINEMA;i++){
    if (linema[i]==','){    // check for the position of the  "," separator
      indices[cont]=i;
      cont++;
    }
    if (linema[i]=='*'){    // ... and the "*"
      indices[12]=i;
      cont++;
    }
  }
    int li = 0;
    int j;
    for (j=indices[k];j<(indices[k+1]-1);j++){
      value[li] = linema[j+1]; 
      li++;
    }
  return value;
}


/* 
 * Author: Johan
 * function used by the others to avoid duplicated code.
 * Iterates through both arrays and checks if the first 6 characters
 * are the same. Returns 0 if they are the same, 1 if not.
 */ 
 int check_command(char gpsData[], char gpr[]) { 
   int result = 0; 
   int i; 
   for (i = 0; i < 6; i++) { 
     if (!(gpsData[i] == gpr[i])) { 
       result = 1; 
     } 
   } 
   return result;
 } 


/* 
 * Author: Johan 
 * returns a pointer to an array of 13 integers, containing the indices
 * of commas in the gps char array. 
 * DONT FORGET TO FREE THE VARIABLE IN WHICH THE RESULT IS STORED!
 */
int* get_Indices(char gpsData[]) {
  int *indices = malloc(13*sizeof(int));
  int i;
  int j = 0;
  for (i = 0; i < LINEMA; i++) {
    if (gpsData[i] == ',') {
      indices[j] = i;
      j++;
    }
  }
  return indices;
}

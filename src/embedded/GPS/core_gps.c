/** 
 *  \file			core_gps.c	
 *	\details		This module is used to operate on basic GPS data.
 *				        It provides a data returning function which reads byte data from a serial port.
 *	\date			10-04-2012 
 *	\version		0.1
 *	\authors 		Gokul & Johan 
 */

#include <stdio.h>
#include <stdlib.h>
#ifdef __testingGPS__
#include "./tests/GPS_Simulator/emulator_GPS.h"
#endif
#include "gps.h"

#define LINEMA 300
#define WAITING_LOOP_VALUE 56

/** 
 * \brief      Gets an instance of Job struct and adds it to the g_taskList.
 * \param      job  The job that is to be added to the g_taskList.
 * \attention  This function is replaced here from its original module,"main.c". 
 */
char *read_rmc_data(){  
  char *linema  = malloc(LINEMA*sizeof(char));
  if (linema != NULL) {
    char buffer = -1;
    char boolean = 1;
    int index = 0;
    int death_counter = 1;
    while(boolean==1 && death_counter<WAITING_LOOP_VALUE){ 
#ifdef __testingGPS__
      buffer = serial_read(); /*TESTING*/
#else 
      buffer = Serial.read():
#endif
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
  }
  return NULL;
}/*end read_data(Char *array)*/
  
  
  /* ADD COMMENT: GOKUL */
char *retrive_data(char* linema, int data_position){
  char *value = calloc(1,20*sizeof(char));
  if (value != NULL) {
    int cont = 0;
    int indices[13];
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
    for (j=indices[data_position];j<(indices[data_position+1]-1);j++){
      value[li] = linema[j+1]; 
      li++;
    }
    return value;
  }
  return NULL;
}


/* 
 * Author: Johan
 * function used by the others to avoid duplicated code.
 * Iterates through both arrays and checks if the first 6 characters
 * are the same. Returns 0 if they are the same, 1 if not.
 */ 
 int check_command(char gpsData[], char gpr[]) {  
   int i; 
   for (i = 0; i < 6; i++) { 
     if (!(gpsData[i] == gpr[i])) { 
       return 1; 
     } 
   } 
   return 0;
 } 


/* 
 * Author: Johan 
 * returns a pointer to an array of 13 integers, containing the indices
 * of commas in the gps char array. 
 * DONT FORGET TO FREE THE VARIABLE IN WHICH THE RESULT IS STORED!
 */
int *get_indices(char gpsData[]) {
  int *indices = calloc(14, sizeof(int));
  if (indices != NULL) {
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
  return NULL;
}

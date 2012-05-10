/* $Id: core_gps.c WP21 20120410 $ */
/*! 
 *  @brief     A module for GPS core functions.
 *  @details   This module is used to operate on basic GPS data.
 *  @details   It provides a data returning function which reads byte data from a serial port.
 *  @author    Gokul S. Evuri
 *  @author    Johan
 *  @version   0.3
 *  @date      2012-04-10
 *  @pre       It is adviced to connect the GPS device to the embedded system.
 *  @bug       Do not have any known bugs.
 *  @warning   Improper use of the the function might cause memory leaks in the system.
 *  @copyright GNU Public License.
 */

#include <stdio.h>
#include <stdlib.h>
#include "gps.h"

#ifdef __testingGPS__
#include "./tests/GPS_Simulator/emulator_GPS.h"
#else
#include "searduino.h"
#endif

/*!
  @def LINEMA 300
*/
#define LINEMA 300

/*!
  @def WAITING_LOOP_VALUE 56
*/
#define WAITING_LOOP_VALUE 56

/**
 * For documentation refer to header file gps.h
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
      buffer = serial_read();
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
  
  
/**
 * For documentation refer to header file gps.h
*/
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
    free(linema);
    return value;
  }
  free(linema);
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

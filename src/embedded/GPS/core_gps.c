/*! 
This file is part of Hoveritu.

Hoveritu is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Hoveritu is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Hoveritu.  If not, see <http://www.gnu.org/licenses/>.
*/

/* $Id: core_gps.c WP21 20120410 $ */
/*! 
 *  @brief     A module for GPS core functions.
 *  @details   This module is used to operate on basic GPS data.
 *  @details   It provides a data returning function which reads byte data from a serial port.
 *  @author    Gokul S. Evuri
 *  @author    Johan Wikström Schützer
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
#include "setup.h"

#ifdef stub
#include "./tests/GPS_Stub/emulator_GPS.h"
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

/*!
 * @brief A function to read data from a serial connection to return a pointer to that, if incomming data is a valid $GPRMC tagged NMEA data.
 * @details The functions tries to get data from serial connection for WAITING_LOOP_VALUE times, if no data received a null will be returnes
 * @warning Serial read baud rate should match the GPS device connected to the avr.
 * @warning Function should be used carefully, in other case this might lead to a memory leakage
 * @return character pointer
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
      buffer = Serial.read(); 
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
  
  
/*!
 * @brief A function taking two arguments of data and position and returning a character pointer to the data specified.
 * @details int value and data {0,UTC_Time},{2,Latitude},{3,Orientiation_N/S},{4,longitude},{5,Orientation_E/W}
 * @param[in] data   the char pointer to a return value from 'read_rmc_data'
 * @param[in] position   a integer value to specify s position in a array
 * @see read_rmc_data()
 * @warning Function should be used carefully, in other case this might lead to a memory leakage
 * @return struct position
 */
char *retrive_data(char *linema, int data_position){
  char *value = calloc(20,sizeof(char));
  if (value != NULL) {
    int *indices = get_indices(linema);
    int li = 0;
    int j;
    for (j=indices[data_position];j<(indices[data_position+1]-1);j++){
      value[li] = linema[j+1]; 
      li++;
    }
    free(indices);
    free(linema);
    return value;
  }
  free(linema);
  return NULL;
}


/*!
@brief This function is used by the others to avoid duplicated code. Iterates through both arrays and checks if the first 6 characters are the same.
@param [in] gpsData The raw gps data character array
@param [in] gpr The gps command to be checked (GPRMC for example)
@return 0 if they are the same, 1 if not.
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


/*!
@brief Gets the indices of commas and the asterisk in the gps char array. DONT FORGET TO FREE THE VARIABLE IN WHICH THE RESULT IS STORED!
@param [in] gpsData The raw gps data char array
@return A pointer to an array of 14 integers, containing the indices
of commas in the gps char array.
*/
int *get_indices(char gpsData[]) {
  int *indices = calloc(15, sizeof(int));
  if (indices != NULL) {
    int i;
    unsigned char j = 0;
    for (i = 0; i < LINEMA; i++) {
      if (gpsData[i] == ',') {
	indices[j] = i;
	j++;
      }
      if (gpsData[i]=='*') {
	indices[j]=i;
	j++;
      }
    }
    return indices;
  }
  return NULL;
}

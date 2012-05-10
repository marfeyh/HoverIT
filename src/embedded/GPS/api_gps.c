/* $Id: api_gps.c WP21 20120410 $ */
/*! 
 *  @brief     A module for GPS api functions.
 *  @details   This module has all the functions needed to retrive data from a gps device(Model: Ref Doc GPS DOCUMENTATION).
 *  @author    Johan
 *  @author    Gokul S. Evuri
 *  @version   0.3
 *  @date      2012-04-10
 *  @pre       It is adviced to connect the GPS device to the embedded system.
 *  @bug       Do not have any known bugs.
 *  @warning   Improper use of the the function might cause memory leaks in the system.
 *  @copyright GNU Public License.
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "gps.h"

/* 
 * Author: Johan 
 * returns 0 if the given data starts with "$GPRMC", 1 if not 
 */
int is_GPRMC(char gpsData[]) {
  return check_command(gpsData, "$GPRMC");
}

/* 
 * Author: Johan
 * returns 0 if the given data starts with "$GPGGA", 1 if not 
 */
int is_GPGGA(char gpsData[]) {
  return check_command(gpsData, "$GPGGA");
}

/* 
 * Author: Johan 
 * returns 0 if the given data starts with "$GPGSV", 1 if not 
 */
int is_GPGSV(char gpsData[]) {
  return check_command(gpsData, "$GPGSV");
}

/* 
 * Author: Johan
 * returns 0 if the given data starts with "$GPGSA", 1 if not 
 */
int is_GPGSA(char gpsData[]) {
  return check_command(gpsData, "$GPGSA");
}
  

/**
 * For documentation refer to header file gps.h
*/
char *get_time(char *data){

  return retrive_data(data, 0);
}

/**
 * For documentation refer to header file gps.h
*/
struct position *get_position(){
  char *data = read_rmc_data(); 
  return get_positionA(data);
}

/**
 * For documentation refer to header file gps.h
*/
struct position *get_positionA(char *data){
  struct position *pos =(struct position *) calloc(1,sizeof(struct position));
  if (pos != NULL) {
    char *temp1 = retrive_data (data,4);
    pos->longitude = atof(temp1);
    free(temp1);
    temp1 = retrive_data (data,2);
    pos->latitude = atof(temp1);
    free(temp1);
    temp1 = retrive_data(data,3);
    pos->ns = *temp1;
    free(temp1);
    temp1 = retrive_data(data,5);
    pos->ew = *temp1;
    free(temp1);
    return pos;
  }
  return NULL;
}


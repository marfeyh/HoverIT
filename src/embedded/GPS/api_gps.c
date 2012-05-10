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
  
/* ADD COMMENT: GOKUL */
char *get_time(char *data){
//returns time when passed with data integer and 0 "Zero"
  return retrive_data(data, 0);
}

/* ADD COMMENT: GOKUL */
struct position *get_position(char *data){
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

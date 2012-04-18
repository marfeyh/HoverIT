#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/* #define M_PI 3.14159 */

#include "gps.h"


/* Radius of earth in kilometer and miles */
#define RADIUS_KM 6378.137
#define RADIUS_MI 3958.761



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



/* 
 * Author: Johan
 * Calculates the distance between the two given points in kilometers 
 */
/* double get_distance_km(struct position p1, struct position p2) { */
/*   double a = acos(sin(d2r(p1.latitude))*sin(d2r(p2.latitude)) + cos(d2r(p1.latitude))*cos(d2r(p2.latitude))*cos(d2r(p2.longitude-p1.longitude)));  */
/*   return a*RADIUS_KM; */
/* } */

/* /\*  */
/*  * Author: Johan */
/*  * Calculates the distance between the two given points in miles  */
/*  *\/ */
/* double get_distance_mi(struct position p1, struct position p2) { */
/*   double a = acos(sin(d2r(p1.latitude))*sin(d2r(p2.latitude)) + cos(d2r(p1.latitude))*cos(d2r(p2.latitude))*cos(d2r(p2.longitude-p1.longitude))); */
/*   return a*RADIUS_MI; */
/* } */



/* Parses decimal degrees to radians */
/* double d2r(double d) { */
/*   return (d/180*M_PI); */
/* }   */
  
/* ADD COMMENT: GOKUL */
char* get_time(char* data){
//returns time when passed with data integer and 0 "Zero"
  return retrive_data(data, 0);
}

/* ADD COMMENT: GOKUL */
struct position* get_position(char* data){
  struct position *pos =(struct position *) calloc(1,sizeof(struct position));
  char * temp1 = retrive_data (data,4);
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

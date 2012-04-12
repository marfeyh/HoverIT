/**
 * Author:  Johan Wikström Schützer & Gokul Reddy
 * Date:    2012-04-10
 * Version: 1.0 - 2012-04-03 - Johans code
 * Version: 1.1 - 2012-04-10 - Integrated Gokuls code
 **/
//#include <Serial.h>
#include "gps.h" 
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/* #include "nmea_datastructs.h" */
#include <Arduino.h>
#include <searduino.h>
#include <string.h>
#include <ctype.h>

int buffer = -1;
char gprmc[7] = "$GPRMC";

/* Radius of earth in kilometer and miles */
#define RADIUS_KM 6378.137
#define RADIUS_MI 3958.761

/* Parses decimal degrees to radians */
double d2r(double);

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
 * returns a pointer to an array of 13 integers, containing the indices
 * of commas in the gps char array. 
 * DONT FORGET TO FREE THE VARIABLE IN WHICH THE RESULT IS STORED!
 */
int* get_Indices(char gpsData[]) {
  int *indices = malloc(13*sizeof(int));
  int i;
  int j = 0;
  for (i = 0; i < 300; i++) {
    if (gpsData[i] == ',') {
      indices[j] = i;
      j++;
    }
  }
  return indices;
}

/* 
 * Author: Johan
 * Calculates the distance between the two given points in kilometers 
 */
double get_distance_km(struct Position p1, struct Position p2) {
  double a = acos(sin(d2r(p1.latitude))*sin(d2r(p2.latitude)) + cos(d2r(p1.latitude))*cos(d2r(p2.latitude))*cos(d2r(p2.longitude-p1.longitude))); 
  return a*RADIUS_KM;
}

/* 
 * Author: Johan
 * Calculates the distance between the two given points in miles 
 */
double get_distance_mi(struct Position p1, struct Position p2) {
  double a = acos(sin(d2r(p1.latitude))*sin(d2r(p2.latitude)) + cos(d2r(p1.latitude))*cos(d2r(p2.latitude))*cos(d2r(p2.longitude-p1.longitude)));
  return a*RADIUS_MI;
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

/* Parses decimal degrees to radians */
double d2r(double d) {
  return (d/180*M_PI);
}  

/* ADD COMMENT: GOKUL */  
char* read_data(){  
  char* linema = malloc(300*sizeof(char));
  // if lines for everything ifdef mega serial pot 1 like wise
  int boolean = -1;
  int i = 0;
  int boolRMC = -1;
  while(boolean==-1){
    buffer = Serial.read();
   if (buffer != -1){
     if(buffer == 13){
       int i;
       for (i=1;i<7;i++){   
	  if (linema[i]==gprmc[i-1]){
	    // boolRMC = 1;
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
  
/* ADD COMMENT: GOKUL */
char* get_time(char* data){
//returns time when passed with data integer and 0 "Zero"
  return retrive_data(data, 0);
}

/* ADD COMMENT: GOKUL */
struct Position* get_position(char* data){
  struct Position *pos = (struct Position)calloc(1,sizeof(struct Position));
  char * temp1 = retrive_data (data,2);
  pos->latitude = atof(temp1);
  free(temp1);
  temp1* = retrive_data(data,2);
  pos->longitude = atof(temp1);
  free(temp1);
  temp1* = retrive_data(data,5);
  pos->nsew = *temp1;
  free(temp1);
    return pos;
}

/* ADD COMMENT: GOKUL */
char* retrive_data(char* linema, int k){
  int cont = 0;
  int indices[20];
  char* value = calloc(1,20*sizeof(char));
  int i;
  for (i=0;i<300;i++){
    if (linema[i]==','){    // check for the position of the  "," separator
      indices[cont]=i;
      cont++;
    }
    if (linema[i]=='*'){    // ... and the "*"
      indices[12]=i;
      cont++;
    }
    int i = 0;
    int j;
    for (j=indices[k];j<(indices[k+1]-1);j++){
      
      value[i] = linema[j+1]; 
    i++;
  }
  }
  return value;
}

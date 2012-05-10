/*
 * Author: Johan Wikström Schützer
 * Date: 2012-05-07
 * Version: 1.0
 * This file contains code that was planned and designed, but after implementation
 * was decided to be left out of the project.
 * It contains functionality to calculate the distance between two given coordinates.
 */ 

#include <math.h>
#include "unused_gps.h"

/* Radius of earth in kilometer and miles */
#define RADIUS_KM 6378.137
#define RADIUS_MI 3958.761

/* 
 * Author: Johan
 * Calculates the distance between the two given points in kilometers 
 */
double get_distance_km(struct position p1, struct position p2) {
   double a = acos(sin(degrees_to_radians(p1.latitude))*sin(degrees_to_radians(p2.latitude)); 
   double b = cos(degrees_to_radians(p1.latitude))*cos(degrees_to_radians(p2.latitude));
   double c = cos(degrees_to_radians(p2.longitude-p1.longitude));
   return ((a+b)*c)*RADIUS_KM;
} 

 /*  
  * Author: Johan
  * Calculates the distance between the two given points in miles
  */
double get_distance_mi(struct position p1, struct position p2) {
   double a = acos(sin(degrees_to_radians(p1.latitude))*sin(degrees_to_radians(p2.latitude)); 
   double b = cos(degrees_to_radians(p1.latitude))*cos(degrees_to_radians(p2.latitude));
   double c = cos(degrees_to_radians(p2.longitude-p1.longitude));
   return ((a+b)*c)*RADIUS_MI; 
}



/* Parses decimal degrees to radians */
double degrees_to_radians(double d) { 
  return (d/180)*M_PI; 
}

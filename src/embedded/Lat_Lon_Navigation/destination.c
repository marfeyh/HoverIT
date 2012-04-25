/*
 * destination.c
 * This file is part of Lat Lon Navigation
 *
 * Copyright (C) 2012 - Epsilon
 *
 * Lat Lon Navigation is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Lat Lon Navigation is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Lat Lon Navigation.
 * If not, see <http://www.gnu.org/licenses/>. 
 */

/**
 * @file destination.c
 * @brief Description: Lat Lon Navigation API is able to receive two gps coordinates from the gps device. 
 * Calculate distance and Azimuth between the two coordinates and Ruddar Control API for hovercraft. 
 * The hovercraft is then moved according to the required distance and Azimuth
 * NOTE: Due to movement of the Hovercraft the value form the Compass and GPS might not be accurate 
 * @author: Zarif Jawad, Batbilig Bavuudorj.
 * @date: 2012-04-18.
 */


/*

  Point_1 = 50 03 59N, 005 42 53W
  Point_2 = 58 38 38N, 003 04 12W

  Distance:
  = 968.724 kilometers; 601.937 miles

  Azimuth from point 1 to point 2 
  = 9.12°

*/
#include "destination.h"
#include "coordinate_distance.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265358979323846 /**< Defining Default value for PI */
#define R 6371 /**< Defining Default value for Earth's radius in km */  


//double DEG_TO_RAD(double degree);
//double RAD_TO_DEG(double radian);

//void find_distance(double lat1, double lon1, double lat2, double lon2);
//void find_bearing(double lat1, double lon1, double lat2, double lon2);



/**
 * rudder
 */
void Rudder(int direction) {
}
/**
 *  get the current bearing or azimuth
 */
double current_heading() {
}
/**
 *  current_heading() wrapped
 */
double update_current() { 
  return current_heading();    
}
/**
 *  delay
 */ 
void delay(int t) {
}
/**
 *  move hovercraft
 */ 
void start_moving() {
}

/**
 *  change direction
 * @param int direction 
 * @return int direction reversed
 */
int change_dir(int direction) {

  return -1 * direction;
}

/**
 *  head clockwise or anticlockwise relative to magnetic north 
 * @param double current value of current heading
 * @param double destination value of destination
 * @return min degrees needed to go clockwise or anticlockwise 
 */
double turn_rudder(double current, double destination) {

  if ((current < 0) || (destination < 0)) {

    printf("current or destination can't be negative numbers..");
    exit(EXIT_FAILURE);
  }    

  int direction = 1; // 1 is clockwise, and -1 is anticlockwise

  double diff = destination - current;
  double abs_diff = fabs(destination - current);
  double min = 0.0;
    

  int print_dir; // for testing...

  if ((min = 360 - abs_diff) < abs_diff) {

    if (diff < 0) {      
      Rudder ( print_dir = change_dir(direction) ); // turn clockwise      
      printf("direction: %d\n", print_dir);
    }
    else {
      Rudder ( direction ); // turn anticlockwise  
      printf("direction: %d\n", direction);
    }

  }  
  else {    

    min = abs_diff;
    if (diff < 0) {

      Rudder ( print_dir = change_dir(direction) ); // turn anticlockwise
      printf("direction: %d\n", print_dir);
    } 
    else if (diff == 0) {
      Rudder(0);
      printf("direction center or 0\n");
    }
    else {      
      Rudder ( direction );    // turn clockwise  
      printf("direction: %d\n", direction);
    }
  }

  return min; // degrees needed to go clockwise or anticlockwise
}

/**
 *  head to destination bearing
 * @param double destination value of destination
 */
void align_pos(double destination) {

  double current = current_heading();
  double diff = turn_rudder(current, destination);

  start_moving(); // start the hovercraft moving

  while (diff > (update_current() - current) ) {     

    /*
    // stop hovercraft when it reaches the destination
    if(CURRENTGPSCOORD == DESTINATIONGPSCOOR) 
      {
	STOPFAN();
	BRAKE();
        return OK;
      }
    */

    delay(500); // wait half a second
  }

  Rudder(0); // center the rudder pos
}


/**
 * Main function which calls other necessary functions to rotate the    
 * hovercraft
 */
begin_main() {

  double lat1, lon1, lat2, lon2;   //two points
  //  double dLat, dLon, radLat1, radLat2;

  lon1 = -5.71472;
  lat1 = 50.06639;
  
  lon2 = -3.07;
  lat2 = 58.64389;

  //find_distance(dLat, dLon, radLat1, radLat2);
  find_distance(lat1, lon1, lat2, lon2);
  find_bearing(lat1, lon1, lat2, lon2);

 
  printf("\nTESTING turn_rudder\n");
  printf("---------------------\n\n");

  double degree = turn_rudder(5, 355);
  printf(" ... and %f degrees.\n", degree);
  printf(" ... and %f degrees.\n", turn_rudder(220, 60));
 
  
  printf(" ... and %f degrees.\n", turn_rudder(0, 0)); //boundary check
  printf(" ... and %f degrees.\n", turn_rudder(-1, 7)); //boundary check
  printf(" ... and %f degrees.\n", turn_rudder(-8, -8)); //boundary check  
}


/**
 * Find the distance between two GPS coordinates
 * @param double lat1 Current Latitude
 * @param double lon1 Current Longitude
 * @param double lat2 Destination Latitude
 * @param double lon2 Current Longitude 
 */
void find_distance(double lat1, double lon1, double lat2, double lon2) {

  //double a = sin(dLat/2) * sin(dLat/2) + sin(dLon/2) * sin(dLon/2) * cos(radLat1) * cos(radLat2);
  //double c = 2 * atan2(sqrt(a), sqrt(1-a));
  //double d = R * c;
  double result = haversine_km(lat1, lon1, lat2, lon2);
  printf("Distance: %f\n", result);
}

/**
 * Find Required Azimuth/bearing
 * @param double lat1 Current Latitude
 * @param double lon1 Current Longitude
 * @param double lat2 Destination Latitude
 * @param double lon2 Current Longitude 
 */
void find_bearing(double lat1, double lon1, double lat2, double lon2) {

  double dLat, dLon, radLat1, radLat2;

  dLat = DEG_TO_RAD(lat2-lat1); // dLat in radian
  dLon = DEG_TO_RAD(lon2-lon1); // dLon in radian
  radLat1 = DEG_TO_RAD(lat1);    // lat1 to radian
  radLat2 = DEG_TO_RAD(lat2);    // lat2 to radian

  double y = sin(dLon) * cos(radLat2);
  double x = cos(radLat1) * sin(radLat2) - sin(radLat1) * cos(radLat2) * cos(dLon);
  double bearing = RAD_TO_DEG(atan2(y, x));


  printf("Bearing: %f\n", bearing);
}

/**
 * Convert degree value to radian
 */
double DEG_TO_RAD (double degree) {

  return degree*PI/180;
} 

/**
 * Convert radian value to degree
 */
double RAD_TO_DEG (double radian) {

  return radian*180/PI;
} 





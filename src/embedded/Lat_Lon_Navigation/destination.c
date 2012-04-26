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

// rudder
void Rudder(int direction) {
}
// get the current bearing or azimuth
double current_heading() {
}
// current_heading() wrapped
double update_current() { 
  return current_heading();    
}
// delay
void delay(int t) {
}
// move hovercraft
void start_moving() {
}


int change_dir(int direction) {

  return -1 * direction;
}


// head clockwise or anticlockwise relative to magnetic north
double turn_rudder(double current, double destination) {

  if ((current < 0) || (destination < 0)) {

    printf("current or destination can't be negative numbers..");
    exit(-1);
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


// head to destination bearing
void align_pos(double destination) {

  double current = current_heading();
  double diff = turn_rudder(current, destination);

  start_moving(); // start the hovercraft moving

  while (diff > (update_current() - current) ) {     

    delay(500); // wait half a second
  }

  Rudder(0); // center the rudder pos
}


void begin_main() {

  double lat1, lon1, lat2, lon2;   //two points

  lon1 = -5.71472;
  lat1 = 50.06639;
  
  lon2 = -3.07;
  lat2 = 58.64389;

  find_distance(lat1, lon1, lat2, lon2);
  find_bearing(lat1, lon1, lat2, lon2);

  printf("\n");
  printf("\nTESTING turn_rudder\n");
  printf("---------------------\n\n");

  double degree = turn_rudder(355, 5);
  printf("cur = 355, dest = 5 ... and %f degrees.\n", degree);

  printf("cur = 5, dest = 355 ... and %f degrees.\n", turn_rudder(5, 355));

  printf("cur = 220, dest = 60 ... and %f degrees.\n", turn_rudder(220, 60));
  
  printf("cur = 0, dest = 0 ... and %f degrees.\n", turn_rudder(0, 0)); //boundary check
  printf("cur = -1, dest = 7 ... and %f degrees.\n", turn_rudder(-1, 7)); //boundary check
  printf("cur = -8, dest = -8 ... and %f degrees.\n", turn_rudder(-8, -8)); //boundary check  
}


double find_distance(double lat1, double lon1, double lat2, double lon2) {

  double result = haversine_km(lat1, lon1, lat2, lon2);
  printf("Distance: %f\n", result);
  return result;
}


double find_bearing(double lat1, double lon1, double lat2, double lon2) {

  double dLat, dLon, radLat1, radLat2;

  dLat = DEG_TO_RAD(lat2-lat1); // dLat in radian
  dLon = DEG_TO_RAD(lon2-lon1); // dLon in radian
  radLat1 = DEG_TO_RAD(lat1);    // lat1 to radian
  radLat2 = DEG_TO_RAD(lat2);    // lat2 to radian

  double y = sin(dLon) * cos(radLat2);
  double x = cos(radLat1) * sin(radLat2) - sin(radLat1) * cos(radLat2) * cos(dLon);
  double bearing = RAD_TO_DEG(atan2(y, x));
  //  double bearing = atan2(y, x);
  
  printf("Bearing: %f\n", bearing);
  return bearing;
}


double DEG_TO_RAD (double degree) {

  return degree*PI/180;
} 


double RAD_TO_DEG (double radian) {

  return radian*180/PI;
} 


double round_down (double val) {  

  return floor(val * 100)/100;
}


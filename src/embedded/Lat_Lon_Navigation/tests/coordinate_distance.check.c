/*
 * Author: Felix Evbota, Haregowoin Amanuel Negusse.
 * Date  : 2012-04-10
 * Description: Cordinate distance API that creates the 
 *possibility to calculate the distance between two coordinates 
 *Hovercraft intends to journey to
 */
#include<stdio.h>
 
#include <math.h>
#include<stdlib.h>
#include "coordinate_distance.h"



#define d2r (M_PI / 180.0)


/*Below is haversine mathematical function to calculate 
the distance between two coordinates*/

double haversine_km(double lat1, double long1, double lat2, double long2)
{
    double dlong = (long2 - long1) * d2r;
    double dlat = (lat2 - lat1) * d2r;
    double a = pow(sin(dlat/2.0), 2) + cos(lat1*d2r) * cos(lat2*d2r) * pow(sin(dlong/2.0), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double d = 6367 * c;

    return d;
}

 // This function initializes default coordinates
double calculate(void)
{                  //Gbg default coordinate 
/*
 double lat1 = 57.71667;
 double long1 = 11.96667;


  //Another default coordinate
 double  lat2 = 57.6975;
 double long2 =11.90639;
*/

 double lat1 = 50.066389;
 double long1 = -5.714722;


  //Another default coordinate
 double  lat2 = 58.643889;
 double long2 = -3.07000;


 haversine_km(lat1, long1, lat2, long2);
  

}





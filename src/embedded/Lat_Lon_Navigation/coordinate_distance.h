
/*
 * Author: Felix Evbota, Haregewoin Amanuel Negusse
 * Date: 2012-04-10.
 * Description: Header file to calculate the distance between two coordinates API for an Hovercraft.
 *
 */

#ifndef COORDINATE_DISTANCE_H
#define COORDINATE_DISTANCE_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define d2r (M_PI / 180.0)

double haversine_km(double lat1, double long1, double lat2, double long2);

#endif

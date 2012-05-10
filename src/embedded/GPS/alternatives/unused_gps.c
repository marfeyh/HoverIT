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

/* $Id: unused_gps.c WP21 20120410 $ */
/*! 
 *  @brief     A module for GPS core functions.
 *  @details   This file contains code that was planned and designed, but after implementation. It was decided to be left out of the project. It contains functionality to calculate the distance between two given coordinates.
 *  @author    Johan Wikström Schützer
 *  @version   0.1
 *  @date      2012-05-07
 *  @pre       Compile with -lm flag for math.h use
 *  @bug       Do not have any known bugs.
 *  @copyright GNU Public License.
 */

#include <math.h>
#include "unused_gps.h"

/* Radius of earth in kilometer and miles */
/*!
  @def RADIUS_KM 6378.137
*/
/*!
  @def RADIUS_MI 3958.761
*/
#define RADIUS_KM 6378.137
#define RADIUS_MI 3958.761

/*!
 * @brief Calculates the distance between the two given points in kilometers
 * @param [in] p1 pointer to the first position of type struct position
 * @param [in] p2 pointer to the second position of type struct position
 * @see gps.h struct position for info on this struct
 * @warning The result might be inaccurate (faulty by up to ~50 metres)
 * @return double
 */
double get_distance_km(struct position *p1, struct position *p2) {
   double a = acos(sin(degrees_to_radians(p1->latitude))*sin(degrees_to_radians(p2->latitude)); 
   double b = cos(degrees_to_radians(p1->latitude))*cos(degrees_to_radians(p2->latitude));
   double c = cos(degrees_to_radians(p2->longitude-p1->longitude));
   return ((a+b)*c)*RADIUS_KM;
} 

/*!
 * @brief Calculates the distance between the two given points in miles
 * @param [in] p1 pointer to the first position of type struct position
 * @param [in] p2 pointer to the second position of type struct position
 * @see gps.h struct position for info on this struct
 * @warning The result might be inaccurate (faulty by up to ~50 metres)
 * @return double
 */
double get_distance_mi(struct position *p1, struct position *p2) {
   double a = acos(sin(degrees_to_radians(p1->latitude))*sin(degrees_to_radians(p2->latitude)); 
   double b = cos(degrees_to_radians(p1->latitude))*cos(degrees_to_radians(p2->latitude));
   double c = cos(degrees_to_radians(p2->longitude-p1->longitude));
   return ((a+b)*c)*RADIUS_MI; 
}

/*!
 * @brief Parses decimal degrees to radians
 * @param [in] d the degree to convert to radian
 * @return double
 */
double degrees_to_radians(double d) { 
  return (d/180)*M_PI; 
}

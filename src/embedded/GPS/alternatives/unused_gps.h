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

/* $Id: unused_gps.h WP21 20120410 $ */
/*! 
 *  @brief     A common header fie for unusded GPS module.
 *  @details   This module contains forward declarations of standard functions, identifiers, variables of GPS modules. These functions for planned and implemented but left out of the final product
 *  @author    Johan Wikström Schützer
 *  @version   0.1
 *  @date      2012-05-07
 *  @copyright GNU Public License.
 */

/*! @struct position
 *  @brief This structure represents a global position using latitude, latitude and orientation towards 'both the poles / equater'.
 *  @var position::longitude 
 *  Member 'longitude' contains longitude value of the position
 *  @var foreignstruct::latitude 
 *  Member 'latitude' contains latitude value of the position
 *  @var foreignstruct::ns 
 *  Member 'ns' contains orientiation value of the position
 *  @var foreignstruct::ew 
 *  Member 'ew' contains orientiation value of the position
 */
struct position {
  /*@{*/
  float longitude; /**< the  longitude value */
  float latitude; /**< the latitude value */
  /*@}*/ 
  
  /**
   * @name orientation
   */
  /*@{*/
  char ns;
  char ew;
  /*@}*/
};

/*!
 * @brief Calculates the distance between the two given points in kilometers
 * @param [in] p1 pointer to the first position of type struct position
 * @param [in] p2 pointer to the second position of type struct position
 * @see gps.h struct position for info on this struct
 * @warning The result might be inaccurate (faulty by up to ~50 metres)
 * @return double
 */
double get_distance_km(struct position *p1, struct position *p2);

/*!
 * @brief Calculates the distance between the two given points in miles
 * @param [in] p1 pointer to the first position of type struct position
 * @param [in] p2 pointer to the second position of type struct position
 * @see gps.h struct position for info on this struct
 * @warning The result might be inaccurate (faulty by up to ~50 metres)
 * @return double
 */
double get_distance_mi(struct position *p1, struct position *p2);

/*!
 * @brief Parses decimal degrees to radians
 * @param [in] d the degree to convert to radian
 * @return double
 */
double degrees_to_radians(double d);

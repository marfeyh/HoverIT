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

/* $Id: api_gps.c WP21 20120410 $ */
/*! 
 *  @brief     A module for GPS api functions.
 *  @details   This module has all the functions needed to retrive data from a gps device(Model: Ref Doc GPS DOCUMENTATION).
 *  @author    Johan Wikström Schützer
 *  @author    Gokul S. Evuri
 *  @version   0.3
 *  @date      2012-04-10
 *  @pre       It is adviced to connect the GPS device to the embedded system.
 *  @bug       Do not have any known bugs.
 *  @warning   Improper use of the the function might cause memory leaks in the system.
 *  @copyright GNU Public License.
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "gps.h"

/*!
@brief Checks if the given gps raw data starts with "$GPRMC"
@param [in] gpsData The raw gps data char array
@return 0 if true, 1 if false 
*/
int is_GPRMC(char gpsData[]) {
  return check_command(gpsData, "$GPRMC");
}

/*!
@brief Checks if the given gps raw data starts with "$GPGGA"
@param [in] gpsData The raw gps data char array
@return 0 if true, 1 if false 
*/
int is_GPGGA(char gpsData[]) {
  return check_command(gpsData, "$GPGGA");
}

/*!
@brief Checks if the given gps raw data starts with "$GPGSV"
@param [in] gpsData The raw gps data char array
@return 0 if true, 1 if false 
*/
int is_GPGSV(char gpsData[]) {
  return check_command(gpsData, "$GPGSV");
}

/*!
@brief Checks if the given gps raw data starts with "$GPGSA"
@param [in] gpsData The raw gps data char array
@return 0 if true, 1 if false 
*/
int is_GPGSA(char gpsData[]) {
  return check_command(gpsData, "$GPGSA");
}
  

/*!
 * @brief A function taking a argument of data and returning a character pointer to the time of UTC when the data is read.
 * @param[in] data   the char pointer to a return value from 'read_rmc_data'
 * @see retrive_data()
 * @see read_rmc_data()
 * @warning Function should be used carefully, in other case this might lead to a memory leakage
 * @return character pointer
 */
char *get_time(char *data){

  return retrive_data(data, 0);
}

/*!
 * @brief A function taking a argument of data and returning a struct position.
 * @see retrive_data()
 * @see read_rmc_data()
 * @warning Function should be used carefully, in other case this might lead to a memory leakage
 * @return struct position
 */
struct position *get_position(){
  char *data = read_rmc_data(); 
  return get_positionA(data);
}

/*!
 * @brief A function taking a argument of data and returning a struct position.
 * @param[in] data   the char pointer to a return value from 'read_rmc_data'
 * @see retrive_data()
 * @see read_rmc_data()
 * @warning Function should be used carefully, in other case this might lead to a memory leakage
 * @return struct position
 */
struct position *get_positionA(char *data){
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


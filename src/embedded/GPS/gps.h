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

/* $Id: gps.h WP21 20120410 $ */
/*! 
 *  @brief     A common header fie for GPS modules.
 *  @details   This module contains forward declarations of standard functions, identifiers, variables of GPS modules.
 *  @author    Johan Wikström Schützer
 *  @author    Gokul S. Evuri
 *  @version   0.3
 *  @date      2012-04-10
 *  @bug       Do not have any known bugs.
 *  @copyright GNU Public License.
 */

/**
 * Author:  Johan Wikström Schützer & Gokul Reddy
 * Date:    2012-04-10
 * Version: 1.0 - 2012-04-03 - Function prototypes
 * Version: 1.5 - 2012-04-10 - Added Gokuls parts (function prototypes and structs) 
 **/

/*!
  @def __posi_gps
*/
#if !defined __posi_gps
#define __posi_gps

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
@brief This function is used by the others to avoid duplicated code. Iterates through both arrays and checks if the first 6 characters are the same.
@param [in] gpsData The raw gps data character array
@param [in] gpr The gps command to be checked (GPRMC for example)
@return 0 if they are the same, 1 if not.
*/
int check_command(char[],char[]);

/*!
@brief Checks if the given gps raw data starts with "$GPRMC"
@param [in] gpsData The raw gps data char array
@return 0 if true, 1 if false 
*/
int is_GPRMC(char[]);

/*!
@brief Checks if the given gps raw data starts with "$GPGGA"
@param [in] gpsData The raw gps data char array
@return 0 if true, 1 if false 
*/
int is_GPGGA(char[]);

/*!
@brief Checks if the given gps raw data starts with "$GPGSV"
@param [in] gpsData The raw gps data char array
@return 0 if true, 1 if false 
*/
int is_GPGSV(char[]);

/*!
@brief Checks if the given gps raw data starts with "$GPGSA"
@param [in] gpsData The raw gps data char array
@return 0 if true, 1 if false 
*/
int is_GPGSA(char[]);

/*!
 * @brief A function to read data from a serial connection to return a pointer to that, if incomming data is a valid $GPRMC tagged NMEA data.
 * @details The functions tries to get data from serial connection for WAITING_LOOP_VALUE times, if no data received a null will be returnes
 * @warning Serial read baud rate should match the GPS device connected to the avr.
 * @warning Function should be used carefully, in other case this might lead to a memory leakage
 * @return character pointer
 */
char* read_rmc_data();



/*!
 * @brief A function taking a argument of data and returning a character pointer to the time of UTC when the data is read.
 * @param data   the char pointer to a return value from 'read_rmc_data'
 * @see retrive_data()
 * @see read_rmc_data()
 * @warning Function should be used carefully, in other case this might lead to a memory leakage
 * @return character pointer
 */
char* get_time(char* data);

/*!
 * @brief A function taking a argument of data and returning a struct position.
 * @param data   the char pointer to a return value from 'read_rmc_data'
 * @see retrive_data()
 * @see read_rmc_data()
 * @warning Function should be used carefully, in other case this might lead to a memory leakage
 * @return struct position
 */
struct position *get_positionA(char* data);

/*!
 * @brief A function taking a argument of data and returning a struct position.
 * @see retrive_data()
 * @see read_rmc_data()
 * @warning Function should be used carefully, in other case this might lead to a memory leakage
 * @return struct position
 */
struct position *get_position();


/*!
 * @brief A function taking two arguments of data and position and returning a character pointer to the data specified.
 * @details int value and data {0,UTC_Time},{2,Latitude},{3,Orientiation_N/S},{4,longitude},{5,Orientation_E/W}
 * @param data   the char pointer to a return value from 'read_rmc_data'
 * @param position   a integer value to specify s position in a array
 * @see read_rmc_data()
 * @warning Function should be used carefully, in other case this might lead to a memory leakage
 * @return struct position
 */
char* retrive_data(char* data,int position);

int *get_indices(char *gpsData);

#endif

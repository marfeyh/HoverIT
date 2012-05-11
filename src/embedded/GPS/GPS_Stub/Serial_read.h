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

/*! 
 *  @brief     A module for GPS Stub testing.
 *  @details   This module is used to get fake GPS data from GPS module.
 *  @details   It provides a data stub functions which returns byte data from a serial port.
 *  @author    Gokul S. Evuri
 *  @version   0.2
 *  @date      2012-04-10
 *  @pre       A defination of __testingGPS__ should be defined
 *  @bug       Do not have any known bugs.
 *  @copyright GNU Public License.
 */


#pragma once

int serial_read();

void reset();

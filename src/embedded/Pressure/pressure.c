/*! 
 *  \file	pressure.c
 *  \details	Gets voltage ranges from inner and outer pressure sensors,
 *		converts those to Pa and calculates the difference.
 *  \author	Rob Bruinsma
 *  \author	Anna Orazova
 *  \author	Markus Feyh - added optional API functions.
 *  \version	2.1
 *  \date	2012/05/02
 *  \copyright	Copyright (C) 2012  Kappa@HoverIT
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*!
 * Includes Arduino library
 */
#include <Arduino.h>
#include <stdio.h>
#include <serial_interface.h>


/*!
 * pins.h included to allow the pins to be substituted during 
 * integration
 */
#include "pins.h"

/*
 * ===========================================================
 * Internal  functions
 * ===========================================================
 */

/*!
 * \attention Pin numbers should be changed in the header file pins.h
 * \brief     Function for getting pressure from the physical sensors
 */
unsigned int get_pressure() {

  float inside_pressure_pa = 0;  /*!< Pressure in Pa inside of the skirt */
  float outside_pressure_pa = 0; /*!< Pressure in Pa outside of the skirt */
  float pressure_diff_pa = 0;    /*!< Pressure difference in Pa */
  unsigned int max_value = 65535;/*!< Maximum value of unsigned int on Arduino */

  /*!
   * Takes output of analog port 0 and converts it into Pa.
   * /attention The analog port number MUST be changed!
   */
  inside_pressure_pa =
	((float) analogRead(PRESSURE_PIN_0)/1023+0.04)/0.000004;
  debug_print3(analogRead(PRESSURE_PIN_0));
  debug_print_string("P\n");

  /*!
   * Takes output of analog port 1 and converts it into Pa.
   * /attention The analog port number MUST be changed!
   */
  outside_pressure_pa =
	((float) analogRead(PRESSURE_PIN_1)/1023+0.04)/0.000004;
  debug_print3(analogRead(PRESSURE_PIN_1));
  debug_print_string("Q\n");
  
  /*!
   * Calculation for getting pressure difference in Pa.
   */
  pressure_diff_pa = inside_pressure_pa - outside_pressure_pa;
  
  /*!
   * Preventing overflow. Any value higher then max_value isn't relevant.
   */
  if(pressure_diff_pa > max_value) {
    return max_value;
  }

  /*!
   * Checks if result value is negative. Returns 0 if it is.
   */
  else if (pressure_diff_pa < 0) {
    return 0;
  }
  
  /*!
   * Returns pressure difference value 
   */ 
  else {
    return (unsigned int) pressure_diff_pa; 
  }
}

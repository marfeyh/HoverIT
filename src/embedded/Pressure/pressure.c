/*! 
 *  \file    pressure.c
 *  \details Gets voltage ranges from inner and outer pressure sensors,
 *           converts those to Pa and calculates the difference.
 *  \author  Rob Bruinsma
 *  \author  Anna Orazova
 *  \version 2.0
 *  \date    2012/04/25
 */

/*!
 * Includes Arduino library
 */
#include <Arduino.h>
#include <stdio.h>

/*!
 * /attention Pin numbers should be changed! 
 * /brief     Function for getting pressure difference
 *  
 * /return    Difference between inside and outside pressure in Pa
 */
unsigned int get_pressure() {

  float inside_pressure_pa = 0;  /*!< Pressure in Pa inside of the skirt */
  float outside_pressure_pa = 0; /*!< Pressure in Pa outside of the skirt */
  float pressure_diff_pa = 0;    /*!< Pressure difference in Pa */
  unsigned int max_value = 65535;
  unsigned int result = 0;

  /*!
   * Takes output of analog port 0 and converts it into Pa.
   * /attention The analog port number MUST be changed!
   */
  inside_pressure_pa = ((float) analogRead(0)/1023+0.04)/0.000004; 

  /*!
   * Takes output of analog port 1 and converts it into Pa.
   * /attention The analog port number MUST be changed!
   */
  outside_pressure_pa = ((float) analogRead(1)/1023+0.04)/0.000004; 
  
  /*!
   * Calculation for getting pressure difference in Pa.
   */
  pressure_diff_pa = inside_pressure_pa - outside_pressure_pa;
  
  if(pressure_diff_pa > max_value) {
    return max_value;
  }

  /*!
   * Checks if result values are negative.
   */
  if (pressure_diff_pa < 0) {
    return 0; /*!< Returns zero if pressure difference is negative */
  }
  
  /*!
   * Returns pressure difference value 
   */ 
  return (unsigned int) pressure_diff_pa; 
}

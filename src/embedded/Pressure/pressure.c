/*! 
 *  \file    pressure.c
 *  \details Gets voltage ranges from inner and outer pressure sensors,
 *           converts those to Pa and calculates the difference.
 *  \author  Rob Bruinsma
 *  \author  Anna Orazova
 *  \author  Markus Feyh
 *  \version 2.1
 *  \date    2012/05/02
 */

/*!
 * Includes Arduino library
 */
#include <Arduino.h>
#include <stdio.h>


/*!
 * pins.h included to allow the pins.h to be substituted during 
 * integration
 */
#include "pins.h"

/*!
 * 
 */
static unsigned int pressure_difference;
static unsigned int pressure_inner;
static unsigned int pressure_outer;


/*
 * ======================================================================
 * API functions
 * ======================================================================
 */


/*!
 * /brief     Function for getting pressure difference
 *  
 * /return    Difference between inside and outside pressure in Pa
 */
unsigned int get_pressure_difference() {
  return pressure_difference;
}

/*!
 * /brief     Function for getting the inner pressure sensor's value
 *  
 * /return    Inside pressure in Pa
 */
unsigned int get_pressure_inner() {
  return pressure_inner;
}

/*!
 * /brief     Function for getting the outer pressure sensor's value
 *  
 * /return    Outer pressure in Pa
 */

unsigned int get_pressure_outer() {
  return pressure_outer;
}

/*
 * ===========================================================
 * Internal  functions
 * ===========================================================
 */

/*!
 * /attention Pin numbers should be changed in the header file pins.h
 * /brief     Function for getting pressure from the physical sensors
 */
void check_pressure() {

  float inside_pressure_pa = 0;  /*!< Pressure in Pa inside of the skirt */
  float outside_pressure_pa = 0; /*!< Pressure in Pa outside of the skirt */
  float pressure_diff_pa = 0;    /*!< Pressure difference in Pa */
  unsigned int max_value = 65535;
  unsigned int result = 0;

  /*!
   * Takes output of analog port 0 and converts it into Pa.
   * /attention The analog port number MUST be changed!
   */
  inside_pressure_pa = ((float) analogRead(PRESSURE_PIN_0)/1023+0.04)/0.000004; 
  pressure_inner = (unsigned int) inside_pressure_pa;

  /*!
   * Takes output of analog port 1 and converts it into Pa.
   * /attention The analog port number MUST be changed!
   */
  outside_pressure_pa = ((float) analogRead(PRESSURE_PIN_1)/1023+0.04)/0.000004; 
  pressure_outer = (unsigned int) outside_pressure_pa;
  
  /*!
   * Calculation for getting pressure difference in Pa.
   */
  pressure_diff_pa = inside_pressure_pa - outside_pressure_pa;
  
  if(pressure_diff_pa > max_value) {
    pressure_difference=max_value;
  }

  /*!
   * Checks if result values are negative.
   */
  else if (pressure_diff_pa < 0) {
    pressure_difference = 0; /*!< Saves zero if pressure difference is negative */
  }
  
  /*!
   * Saves pressure difference value 
   */ 
  else {
    pressure_difference = (unsigned int) pressure_diff_pa; 
  }
}

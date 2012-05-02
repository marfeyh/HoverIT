/*! 
 *  \file    pressure.h
 *  \details Header file for pressure.c
 *  \author  Rob Bruinsma
 *  \author  Anna Orazova
 *  \author  Markus Feyh
 *  \version 2.1
 *  \date    2012/05/02
 */

#ifndef PRESSURE_H
#define PRESSURE_H

/*!
 * /brief     Function for getting pressure difference
 *  
 * /return    Difference between inside and outside pressure in Pa
 */
int get_pressure_difference(void);

/*!
 * /brief     Function for getting the inner pressure sensor's value
 *  
 * /return    Inside pressure in Pa
 */
int get_pressure_inner(void);

/*!
 * /brief     Function for getting the outer pressure sensor's value
 *  
 * /return    Outer pressure in Pa
 */

int get_pressure_outer(void);

/*!
 * /brief     Function for getting pressure and pressure difference from physical sensors
 */
void check_pressure(void);

#endif

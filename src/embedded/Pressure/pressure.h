/*! 
 *  \file    pressure.h
 *  \details Header file for pressure.c
 *  \author  Rob Bruinsma
 *  \author  Anna Orazova
 *  \author  Markus Feyh
 *  \version 2.1
 *  \date    2012/05/02
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

#ifndef PRESSURE_H
#define PRESSURE_H

/*!
 * /brief     Function for getting the inner pressure sensor's value
 *  
 * /return    Inside pressure in kPa
 */
//float get_pressure_inner(void); Not currently in use

/*!
 * /brief     Function for getting the outer pressure sensor's value
 *  
 * /return    Outer pressure in kPa
 */

//float get_pressure_outer(void); Not currently in use

/*!
 * /brief     Function to get pressure values and calculates the difference
 *
 * /return    Pressure difference
 */
unsigned int get_pressure(void);

#endif

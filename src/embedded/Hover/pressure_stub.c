/***************************************************************************
 * Copyright (C) 2012  Eva-Lisa Kedborn
 *                     Jing Liu
 * 
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 ****************************************************************************/

/*!
@file hover_api.c
@headerfile pressure.h
@author Eva-Lisa Kedborn
@author Jing Liu
@date 2012-03-26
@brief Stub to generate fake air pressure inside the hovercraft skirt
*/

#include <stdio.h>
#include <stdlib.h>
#ifdef STUB_TEST
	#include <time.h>
#endif
#include <pressure_stub.h>
#include <pin.h>

#define HOVER_LEVEL_AUTO 10
#define HOVER_LEVEL_MANUAL 40

/*!
@brief Generates a fake random air pressure inside the hovercraft skirt
*/ 
int get_pressure() {
  int random;
  srand(time(NULL));
  random = rand() % 100;
  return random ;
}

/*!
@brief Generates fake air pressure higher than preferred 
*/
int get_positive() {
  return 70;
}

/*!
@brief Generates fake air pressure lower than preferred 
*/
int get_negative() {
  return 30;
}

/*!
@brief Generates fake air pressure equal to preferred
*/
int get_equal() {
  return 50;
}




  
  

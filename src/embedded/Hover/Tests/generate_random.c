
/***************************************************************************
 * Copyright (C) 2012  Seyed Ehsan Mohajerani
 *                     Navid Amiriarshad
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
 @file generate_random.c
 @headerfile generate_random.h
 @brief This module contain the functions for generating random numbers for 
 checking.
 @author Seyed Ehsan Mohajerani
 @author Navid Amiriarshad
 @version 0.2
 @date 14 May 2012
 @see Arduino.cc
 @see sandklef.com
 @see hoveritu.com
 @see dreamincode.net/forums/topic/34861-functions-stored-in-structure
 @see Turnigy_Plush_and_Sentry_ESC user manual
 @see reference for Coding standard ece.cmu.edu/~eno/coding/CCodingStandard
 .html
 @see reference for commenting stack.nl/~dimitri/doxygen/commands
 .html#cmdparam
 */

/*
  For using srandom
*/
#include <stdlib.h>

/*!
@brief The function for generating random number between 2 intgers.
@Param [in] lower This parameter is higher integer of the interval
@Param [in] higher This parameter is lower integer of the interval
@return the generated random number on succes
*/
int generate_random_number(int lower, int higher){
	/*
	This function changes the random number everytime the function runs
	*/	
	srandom((unsigned)time(NULL));
	int generated_random_number=random() %(higher-lower) +lower;
	return generated_random_number;
}


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
 @file brake.c
 @headerfile brake.h
 @brief This module contains the functions for breaking hovercraft.
 @author Seyed Ehsan Mohajerani
 @author Navid Amiriarshad
 @date 30 March 2012
 @version 1.0
 @refrence Arduino.cc
 @refrence sandklef.com
 @refrence hoveritu.com
 @refrence dreamincode.net/forums/topic/34861-functions-stored-in-structure
 @refrence Turnigy_Plush_and_Sentry_ESC user manual
 @refrence for Coding standard ece.cmu.edu/~eno/coding/CCodingStandard.html
 @refrence for commenting stack.nl/~dimitri/doxygen/commands.html#cmdparam
 */

#include <hover_api.h>
#include <stdlib.h>
#include <hover_api.h>
#include <hovering_motor.h>
#include <hovering_control.h>
#include <pressure_check.h>
#include <pin.h>

int hovrining_brake(void){
	hover_min();
	return 0;
}

int propulsion_brake(void){
	stop_propulsion_fan();
	delay(3000);
	change_polarity(5000);
	max_propulsion_fan(5000);
	delay(3000);

	return 0;
}

int change_pol_

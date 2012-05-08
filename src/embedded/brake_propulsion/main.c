/***************************************************************************
 * Copyright (C) 2012  Ezeh Prince Anthony Anayo
 *                     Xinran He
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
 * @file main.c
 * @headerfile propulsion.h
 * @headerfile propulsion_api.h
 * @headerfile Arduino.h
 * @headerfile searduino.h
 * @description: This is the main function for the compilation of the reverse
    propulsion fan implementation.more detailed description in offing
 * @author: Ezeh Prince Anthony Anayo
 * @author: Xinran He
 * @version: 0.3
 * @date: 2012-05-08
 * @reference: Arduino.cc
 * @reference: sandklef.com
 * @reference: hoveritu.com
 */



#include <propulsion.h>
#include <propulsion_api.h>
#include <brake_propulsion.h>
#include <Arduino.h>
#include <searduino.h>

int main(void){
  initialise_propulsion();
  increase_propulsion();
  increase_propulsion();
  increase_propulsion();
  brake_hovercraft();
}

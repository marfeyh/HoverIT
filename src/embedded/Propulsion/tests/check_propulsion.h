/***************************************************************************
 * Copyright (C) 2012  Yohanes Kuma
 *                     Khatereh Khosravianarab
 *                     Xinran He
 *                     Ezeh Prince Anthony Anayo
 *
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
 @file check_propulsion.c
 @author Yohanes Kuma
 @author Xinran He
 @author Khatereh Khosravianarab
 @author Ezeh Prince Anthony Anayo
 @brief This file is header file for unit testing propulsion, propulsion
  API and brake propulsion functions.
 @date 2012-05-10
 @reference http://check.sourceforge.net/doc/check_html/index.html#SEC_Top
*/

#ifndef CHECK_PROPULSION_H
#define CHECK_PROPULSION_H

void setup(void);
void teardown(void);
Suite* propulsion_suite(void);

#endif

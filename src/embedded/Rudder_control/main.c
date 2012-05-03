/*
 * main.c
 * This file is part of Rudder Control
 *
 * Copyright (C) 2012 - Epsilon
 *
 * Rudder Control is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Rudder Control is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Rudder Control. If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * @file main.c
 * @brief: Description: main function in C, required to initialize
 * RuddarControll object and begin execution.
 * @author: Rashid Darwish, David Giorgidze, Zarif Jawad, Paulius Vysniauskas.
 * @date: 2012-04-04.
 */

#include "steering.h"

int main(void)
{
  control_rudder(1);
  return 0;	
}


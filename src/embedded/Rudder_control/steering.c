/*
 * steering.c
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


/**
 * @file steering.c
 * @brief Description: Module, that deals with interaction
 * between C and C++ code.
 * @author: Paulius Vysniauskas
 * @date: 2012-04-11
 */

#include "steering.h"
#include "RuddarControll.h"

/**
 * The function that can be called from the scheduler and accepts user
 * input. Communicates with the RuddarControll.cpp module.
 */
void control_rudder(int command)
{
  void* rc = RuddarControll_construct();
  RuddarControll_steering(rc, command);
  RuddarControll_destruct(rc);
}

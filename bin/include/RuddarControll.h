/*
 * RuddarControll.h
 * This file is part of Rudder Control
 *
 * Copyright (C) 2012 - Epsilon
 *
 * Rudder Controll is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Rudder Controll is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Rudder Controll. If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @file RuddarControll.h
 * @brief Description: Header file for Ruddar Control API for hovercraft.
 * @author: Rashid Darwish, Paulius Vysniauskas.
 * @date: 2012-03-25.
 */

#ifndef RuddarControll_h
#define RuddarControll_h
#define CENTER 0
#define HARDLEFT 1
#define HARDRIGHT 2
#define SOFTRIGHT 3
#define SOFTLEFT 4
#define BRAKE 5


#ifdef __cplusplus

#include <Arduino.h>
#include <searduino.h>
#include <Servo.h>
#include "pin.h"

extern "C" {
#endif
void* RuddarControll_construct(void);
void RuddarControll_destruct(void*);
void RuddarControll_steering(void*, int);
#ifdef __cplusplus
}



class RuddarControll
{
public: 
       RuddarControll();
       int setupRuddar();
       int controllRuddar(int command);
 
//private:
        int setHardLeft();
        int setHardRight();
        int setCurrent();
        int setStraight();
        int setBrake();
        int setSoftRight();
        int setSoftLeft();

};

#endif
#endif

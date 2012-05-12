/*
 * RuddarControll.cpp
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
 * @file RuddarControll.cpp
 * @brief Description: Ruddar Control API for hovercraft. Which provides
 * ability to turn servos by certain amount of degrees.
 * NOTE: the degrees for both servo motors differ due to the way they are
 * mounted on the hovercraft.
 * @author: Rashid Darwish, David Giorgidze, Zarif Jawad, Paulius Vysniauskas.
 * @date: 2012-03-25.
 */

#include <Servo.h>
#include <Arduino.h>
#include <searduino.h>
#include "RuddarControll.h"

//#define OFFSET_ONE 0 /**< Defining offset value for servo motor 1 */
#define OFFSET_TWO 15 /**< Defining offset value for servo motor 2 */

Servo servo_1; /**< Initializing servo motor object 1 */
Servo servo_2; /**< Initializing servo motor object 2 */
   
/**
 * Default constructor
 */
RuddarControll::RuddarControll()
{	
}

/** 
 * Constructor for Rudder Control object, called
 * from external C module
 * @return rc returning the void pointer for rudder control object
 */
extern "C" void* RuddarControll_construct(void)
{
  RuddarControll *rc = new RuddarControll();
  return (void*) rc;
}

/** 
 * Destructor for Rudder Control object, called
 * from external C module
 * @param obj void pointer for ruddar controll object
 */
extern "C" void RuddarControll_destruct(void *obj)
{
  RuddarControll *rc = (RuddarControll*) obj;
  delete rc;
}

/**
 * Main function to control the rudders, called
 * from external C module
 * @param obj The void pointer for ruddar controll object
 * @param command The integer indicating the direction of ruddars  
 */
extern "C" void RuddarControll_steering(void *obj, int command)
{

  RuddarControll *rc = (RuddarControll*) obj;
  rc->setupRuddar();
  rc->controllRuddar(command);
}

/**
 * Attaching Servos to the pins and centering them
 */
int RuddarControll::setupRuddar()
{ 
  servo_1.attach(SERVO_PIN2);
  servo_2.attach(SERVO_PIN3);
  servo_1.write(95); 
  servo_2.write(110);

  return 0;
}
  
/**
 * Function which waits for user input and sets servo to desired position
 * @param command The integer indicating the direction of ruddars
 */

int RuddarControll::controllRuddar(int command)
{
  switch (command){
  case CENTER: 
    setStraight();
//    delay(500);
    break;
	
  case HARDLEFT:
    setHardLeft();
//    delay(500);
    break;
	
  case HARDRIGHT:
    setHardRight();
//    delay(500);
    break;

  case SOFTRIGHT:
    setSoftRight();
    break;

  case SOFTLEFT:
    setSoftLeft();
    break;

  case BRAKE:
    setBrake();
//    delay(500);
    break;

  default: 
    setCurrent();
  }
//  delay(500);
  return 11;
}
    
/**
 * setHardLeft sets servos to 30 degree
 */

int RuddarControll::setHardRight()
{
  servo_1.write(30);
  servo_2.write(30 + OFFSET_TWO);
  return 2;
}

/**
 * setHardRight sets servos to 150 degree
 */
int RuddarControll::setHardLeft()
{
  servo_1.write(150);
  servo_2.write(150 + OFFSET_TWO);
  return 3;
}

/**
 * setCurrent reads current position of servos
 */
int RuddarControll::setCurrent()
{
  servo_1.write(servo_1.read());
  servo_2.write(servo_2.read());
  return 4;
}

/**
 * setStraight sets servos to center 90 degree
 */
int RuddarControll::setStraight()
{
  servo_1.write(95); 
  servo_2.write(110);
  return 5;
}

/** 
 * setBrake sets servos to to oposite directions,
 * this can be used to stop hovercraft quicker
 */
int RuddarControll::setBrake()
{
  servo_1.write(180);
  servo_2.write(0 + OFFSET_TWO);
  return 6;
}
 
/**
 * setSoftRight gradually moves servos by 20 degree steps toward right side
 */
int RuddarControll::setSoftLeft()
{
  int currentPos = servo_1.read();
  if(currentPos < 150)
    {
      currentPos = currentPos + 15;
      servo_1.write(currentPos); 
      servo_2.write(currentPos + OFFSET_TWO);
      return 7;
    }
  else  
    {
      servo_1.write(currentPos); 
      servo_2.write(currentPos + OFFSET_TWO); 
      return 8;
    }
}

/**
 * setSoftLeft gradually moves servos by 20 degree steps toward left side
 */
int RuddarControll::setSoftRight()
{ 
  int currentPos = servo_1.read();
  if(currentPos > 30)
    {
      currentPos = currentPos - 15;
      servo_1.write(currentPos); 
      servo_2.write(currentPos + OFFSET_TWO); 
      return 9;
    }
  else  
    {
      servo_1.write(currentPos); 
      servo_2.write(currentPos); 
      return 10;
    }
}


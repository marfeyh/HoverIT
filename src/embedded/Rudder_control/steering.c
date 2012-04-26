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

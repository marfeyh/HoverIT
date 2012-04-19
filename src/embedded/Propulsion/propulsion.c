/*
@AUTHOR - Yohanes Kuma
@Description: This file is ment for controlling a fan motor. The code is responsible to controll the fan for the steering of the Hovercraft. it is developed by using the Libraries of Arduino and Searduino. Refere to their manual for more information. 
http://arduino.cc/en/Reference/Libraries
http://itupw185.itu.chalmers.se/searduino/?page_id=16
@Date : 2012-04-05
*/

#include <Arduino.h>
#include <searduino.h>
#include <propulsion.h>
#include <pin.h>

/* The level of the speed. it is dependent on the type of Microcontroller
   used and the PWM level available. The type is int since the levels is not
   guarented to be a maximum 1 byte. 
*/
static int speedLevel = 0;

/* There are three states: stopped, initialising, and rotating. 
   This is the control to switch between states. 0 is stopped state,
   1 is init state and 2 is the active or rotating state*/
unsigned char motor_status = 0;

/* initialise the searduino init() and sets the pin*/
int initialise_propulsion()
{
  // initialises the searduino init
#ifndef GLOBAL_MAIN
//  init();
#endif
  // sets PIN as output pin
  pinMode(PIN,OUTPUT);
  return 0;
}

/*manages the moter speed. The motor will rotate with PWM duty cycle
  from 132(MIN_DUTY_CYCLE) till 254(MAX_DUTY_CYCLE). with currunt implementation  with Arduino UNO and MEGA it has 122 speed levels.But this could be increased
  by introducing delay time-elapse*/
unsigned char manage_motor()
{
  switch (motor_status)
    {
      // initializing state
    case 0:
      analogWrite(PIN,100);
      break;
      // stopped state
    case 1:
      analogWrite(PIN,100);
      break;
      // rotating state
    case 2:
      if((speedLevel + MIN_DUTY_CYCLE) <  MAX_DUTY_CYCLE)
	{
	  analogWrite(PIN,speedLevel + MIN_DUTY_CYCLE);
	  //This commented code can be use in cases where more speed
	  // levels are required
	  //delay(TIME_ELAPSE);
	};
      break;
    }
  return motor_status;
}
/* returns the current propelsion speed level*/
int get_speed_level()
{
  return speedLevel;
}
/* changes propelsion fan speed to the level given. if the fan is in stopped
   state it will change it back to rotating state(provided the level given 
   is gerater than zero*/
void change_pro_speed(int level)
{
  if(level > MAX_SPEED_LEVEL)
    {
      speedLevel = MAX_SPEED_LEVEL;
      motor_status = 2;
    }
  else if(level <= 0)
    {
      speedLevel = 0;
      motor_status = 1;
    }
  else
    {
      speedLevel = level;
      motor_status = 2;
    }
  manage_motor();
}

/*stops the propelsion fan*/
void stop_pro_fan()
{
  motor_status = 1;
  manage_motor();
}
/*initialises the motor*/
void init_motor()
{
  motor_status = 0;
  manage_motor();
}
/* returns the current state of the motor
   0 is stopped state,
   1 is init state 
   2 is the active or rotating state
*/   
unsigned char get_motor_status()
{
  return motor_status;
}

/*
@author Yohanes Kuma
@details This file is ment for controlling the Propulsion fan motor. 
The code is responsible to controll the speed of the fan for
the movement of the Hovercraft. it is developed by using the 
Libraries of Arduino and Searduino. Refere to their manual for more 
information. 
@see http://arduino.cc/en/Reference/Libraries
@see http://itupw185.itu.chalmers.se/searduino/?page_id=16
@date 2012-04-05
*/

#include <Arduino.h>
#include <searduino.h>
#include <propulsion.h>
#include <pin.h>

/*
  @brief The level of the speed. it is dependent on the type 
  of Microcontroller used and the PWM level available. 
  The type is int since the levels is not guarented to 
  be a maximum 1 byte. 
*/
static int speed_level = 0;

/*
  @brief There are three states: stopped, initialising, 
  and rotating. This is the control to switch between states. 
  0 is stopped state, 1 is init state and 2 is the active 
  or rotating state
*/
unsigned char motor_status = 0;

/* 
   @brief initialises the searduino init() function, 
   sets the pin as output Pin and changes the propulsion fan
   to initialising state 
*/
int initialise_propulsion()
{
  /* initialises the searduino init */
#if !defined(GLOBAL_MAIN)
   init();
#endif
   /* sets PIN as output pin */
  pinMode(PIN, OUTPUT);
  /* sets motor to Initializing state */
  motor_status = 0;
  manage_motor();
  return 0;
}

/*
  @details manages the moter speed. The motor will rotate 
  with PWM duty cycle from 132(MIN_DUTY_CYCLE) till 
  254(MAX_DUTY_CYCLE). with currunt implementation with Arduino 
  UNO  and MEGA it has 122 speed levels.But this could be increased
  by introducing delay time-elapse. There are three states: stopped, 
  initialising, and rotating. This is the control to switch between 
  states. 0 is stopped state, 1 is init state and 2 is the active 
  or rotating state.
@return unsigned char representing the current state of the motor 
*/
unsigned char manage_motor(){
  switch (motor_status)
    {
      /* initializing state */
    case 0:
      analogWrite(PIN, 100);
      break;
      /* stopped state */
    case 1:
      analogWrite(PIN, 100);
      break;
      /* rotating state */
    case 2:
      if ((speed_level + MIN_DUTY_CYCLE) <  MAX_DUTY_CYCLE)
	{
	  analogWrite(PIN, speed_level + MIN_DUTY_CYCLE);
	  /* This commented code can be use in cases where 
	     more speed levels are required */
	  /**delay(TIME_ELAPSE);  ***********/
	};
      break;
    default:
      /* error will be logged here. code will be writen when
	 the package is done ***********/
      ;
    }
  return motor_status;
}
/* 
   @brief The level of the speed is dependent on the type of 
   Microcontroller used and the PWM level available. The type is 
   int since the levels is not guarented to be a maximum 1 byte. 
   @return the current propelsion speed level
*/
int get_speed_level() {
  return speed_level;
}

/* 
   @details changes propelsion fan speed to the level given. 
   if the fan is in stopped state it will change it back to rotating 
   state (provided the level given is gerater than zero)
   @param level  The level of the speed. it is dependent on the type
   of Microcontroller used and the PWM level available. The type is 
   int since the levels is not guarented to be a maximum 1 byte.
*/
void change_pro_speed(int level) {
  if (level > MAX_SPEED_LEVEL)
    {
      speed_level = MAX_SPEED_LEVEL;
      motor_status = 2;
    }
  else if (level <= 0)
    {
      speed_level = 0;
      motor_status = 1;
    }
  else
    {
      speed_level = level;
      motor_status = 2;
    }
  manage_motor();
}

/*
@brief changes the propelsion fan to stopped state
*/
void stop_pro_fan() {
  motor_status = 1;
  manage_motor();
}

/*
@brief returns the current state of the motor
@returns 0 is stopped state, 1 is init state, 
 2 is the active or rotating state
*/   
unsigned char get_motor_status() {
  return motor_status;
}

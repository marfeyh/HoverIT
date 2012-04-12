/*
@AUTHOR - Yohanes Kuma
@Description: This file is ment for controlling a fan motor. The code is responsible to controll the fan for the steering of the Hovercraft. it is developed by using the Libraries of Arduino and Searduino. Refere to their manual for more information. 
@Version: 1.4
@Date : 2012-04-05
*/

#include <Arduino.h>
#include <searduino.h>
#include <propulsion.h>

/* The level of the speed. it is dependent on the type of Microcontroller
   used and */
static int speedLevel = 0;
/* 0 is stopped state, 1 is init state and 2 is the active
   or rotating state*/
unsigned char motor_status = 0;

/* initialize the microcontroller */
int initialise_propulsion()
{
  init();
  return 0;
}

/*manages the moter speed. The motor will rotate with PWM duty cycle
  from 132(MIN_DUTY_CYCLE) till 254(MAX_DUTY_CYCLE)it has 122 speed levels.*/
int manage_motor()
{
  switch (motor_status)
    {
    case 0:
      analogWrite(PIN,100);
      break;
    case 1:
      analogWrite(PIN,100);
      //change_pro_speed(1);
      break;
    case 2:
      if((speedLevel + MIN_DUTY_CYCLE) <  MAX_DUTY_CYCLE)
	{
	  analogWrite(PIN,speedLevel + MIN_DUTY_CYCLE);
	  // analogWrite(PIN,speedLevel);
	  //delay(TIME_ELAPSE);
	  //speedLevel += Rate;
	  //change_pro_speed(speedLevel + 1);
	};
      break;
    }
  return motor_status;
}
/* returns the current propelsion speed level*/
int getSpeedLevel()
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
      //stopro_fan();
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
int get_motor_status()
{
  return motor_status;
}

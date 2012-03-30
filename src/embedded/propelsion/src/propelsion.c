#include <Arduino.h>
#include <searduino.h>
#include <propelsion.h>

static int speedLevel = 0;
unsigned char initMotor = 0;
unsigned char stopped = 0;

/* initialize the microcontroller */
int initialise_propelsion()
{
  init();
  return 0;
}

/*manages the moter speed. The motor will rotate with PWM duty cycle
  from 132(MIN_DUTY_CYCLE) till 254(MAX_DUTY_CYCLE)it has 122 speed levels.*/
void manage_motor()
{
  if(initMotor)
    {
      analogWrite(PIN,100);
    }
  else if(stopped)
    {
      speedLevel = 0;
      analogWrite(PIN,speedLevel);
      //change_pro_speed(1);
    }
  else if((speedLevel + MIN_DUTY_CYCLE) <  MAX_DUTY_CYCLE &&
	  !stopped && !initMotor)
    {
      analogWrite(PIN,speedLevel + MIN_DUTY_CYCLE);
      // analogWrite(PIN,speedLevel);
      delay(TIME_ELAPSE);
      //speedLevel += Rate;
      //change_pro_speed(speedLevel + 1);
    }
  else
    {
      printf("The Motor is in Initializing state or stopped state \n");
    }
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
      stopped = 0;
      initMotor = 0;
      //stopro_fan();
    }
  else if(level <= 0)
    {
      speedLevel = 0;
      stopped = 1;
      initMotor = 0;
    }
  else
    {
      speedLevel = level;
      stopped = 0;
      initMotor = 0;
    }
}

/*stops the propelsion fan*/
void stop_pro_fan()
{
  stopped = 1;
}
void init_motor()
{
  initMotor = 1;
}

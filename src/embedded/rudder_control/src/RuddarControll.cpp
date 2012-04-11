/*
 * Author: Rashid Darwish, David Giorgidze, Zarif Jawad, Paulius Vysniauskas.
 * Date: 2012-03-25.
 * Description: Ruddar Control API for hovercraft. Which provides ability
 * to turn servos by certain amount of degrees.
 *
 */

#include <Servo.h>
#include <Arduino.h>
#include <searduino.h>
#include "RuddarControll.h"

/* Initializing servo motor objects */
Servo servo_1;
Servo servo_2;
   
/* Default constructor */
RuddarControll::RuddarControll()
{	
}

/* 
 * The linking function, called from main.c, required to initialize
 * a RuddarControll object and begin execution
 *
 */
extern "C" void begin()
{	
  RuddarControll *r = new RuddarControll();
  init();
  r->setupRuddar();
  for(;;)
    {      
    } 
}

/* Attaching Servos to the pins and centering them */
int RuddarControll::setupRuddar()
{ 
  servo_1.attach(2);
  servo_2.attach(3);
  servo_1.write(90); 
  servo_2.write(90);

  return 0;
}
  
/* Function which waits for user input and sets servo to desired position */
void RuddarControll::controllRuddar(int command)
{
  switch (command){
  case CENTER: 
    setStraight();
    delay(500);
    break;
	
  case HARDLEFT:
    setHardLeft();
    delay(500);
    break;
	
  case HARDRIGHT:
    setHardRight();
    delay(500);
    break;

  case SOFTRIGHT:
    setSoftRight();
    break;

  case SOFTLEFT:
    setSoftLeft();
    break;

  case BRAKE:
    setBrake();
    delay(500);
    break;

  default: 
    setCurrent();
  }
  delay(500);
}
    
/* setHardLeft sets servos to 30 degree */
void RuddarControll::setHardLeft()
{
  servo_1.write(30);
  servo_2.write(30);
}

/* setHardRight sets servos to 150 degree */
void RuddarControll::setHardRight()
{
  servo_1.write(150);
  servo_2.write(150);
}

/* setCurrent reads current position of servos */
void RuddarControll::setCurrent()
{
  servo_1.write(servo_1.read());
  servo_2.write(servo_2.read());
}

/* setStraight sets servos to center 90 degree */
void RuddarControll::setStraight()
{
  servo_1.write(90); 
  servo_2.write(90);
}

/* 
 * setBrake sets servos to to oposite directions,
 * this can be used to stop hovercraft quicker
 *
 */
void RuddarControll::setBrake()
{
  servo_1.write(180);
  servo_2.write(0);
}
 
/* setSoftRight gradually moves servos by 20 degree steps toward right side */
void RuddarControll::setSoftRight()
{
  int currentPos = servo_1.read();
  if(currentPos < 150)
    {
      currentPos = currentPos + 20;
      servo_1.write(currentPos); 
      servo_2.write(currentPos);
    }
  else  
    {
      servo_1.write(currentPos); 
      servo_2.write(currentPos); 
    }
}

/* setSoftLeft gradually moves servos by 20 degree steps toward left side */
void RuddarControll::setSoftLeft()
{ 
  int currentPos = servo_1.read();
  if(currentPos > 30)
    {
      currentPos = currentPos - 20;
      servo_1.write(currentPos); 
      servo_2.write(currentPos); 
    }
  else  
    {
      servo_1.write(currentPos); 
      servo_2.write(currentPos); 
    }
}


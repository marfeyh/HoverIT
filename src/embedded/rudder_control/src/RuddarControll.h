/*
 * Author: Rashid Darwish,
 * Date: 2012-03-25.
 * Description: Header file for Ruddar Control API for hovercraft.
 *
 */

#include <Arduino.h>
#include <searduino.h>
#include <Servo.h> 

#ifndef RuddarControll_h
#define RuddarControll_h
#define CENTER 0
#define HARDLEFT 1
#define HARDRIGHT 2
#define SOFTRIGHT 3
#define SOFTLEFT 4
#define BRAKE 5

class RuddarControll
{
public: 
       RuddarControll();
       void begin();
       int setupRuddar();
       void controllRuddar(int command);
 
private:
        void setHardLeft();
        void setHardRight();
        void setCurrent();
        void setStraight();
        void setBrake();
        void setSoftRight();
        void setSoftLeft();

};
#endif

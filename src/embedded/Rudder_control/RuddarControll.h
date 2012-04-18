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
#endif

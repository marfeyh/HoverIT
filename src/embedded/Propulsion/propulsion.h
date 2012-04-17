/*
@AUTHOR - Yohanes Kuma
@Description: This file is ment for controlling a fan motor. The code is responsible to controll the fan for the steering of the Hovercraft. it is developed by using the Libraries of Arduino and Searduino. Refere to their manual for more information. 
http://arduino.cc/en/Reference/Libraries
http://itupw185.itu.chalmers.se/searduino/?page_id=16
@Date : 2012-04-05
*/
#define MAX_DUTY_CYCLE 254
#define MIN_DUTY_CYCLE 132
#define MAX_SPEED_LEVEL 122
#define TIME_ELAPSE 100
#define RATE 1

unsigned char manage_motor();
int initialise_propulsion();
int get_speed_level();
void change_pro_speed(int level);
void stop_pro_fan();
void init_motor();
unsigned char get_motor_status();

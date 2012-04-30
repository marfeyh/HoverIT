/*
 *  calculateSpeed.h
 *  
 *
 *  Created by Nena Stojova on 3/20/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef SPPED_H
#define SPEED_H
struct Speed
{
	int speed;
	int time;
	
};
typedef struct Speed Speed;
void create_speed(int speed, int time);
void calculate_speed(int currentTime);
int get_speed();
int get_time();

Speed *struct_adress;
#endif


/******************************************
 * Embedded project - Determining Speed
 * calculateSpeed.h
 *
 * Copyright (c) Whatever, no warranty.
 *
 * Author: Nena Stojova
 * Date: 3/20/12
 ******************************************/

#ifndef SPPED_H
#define SPEED_H
struct Speed
{
	int speed;
	int time;
    float bias;
	
};
typedef struct Speed Speed;
void create_speed(int speed, int time);
void calculate_speed(int currentTime);
int get_speed();
int get_time();

Speed *struct_adress;
#endif


/*
 *  calculateSpeed.c
 *  
 *
 *  Created by Nena Stojova on 3/20/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 *  Module for calculatin the speed of the object
 *
 */

#include <stdlib.h>
#include "calculateSpeed.h"

void create_speed(int speed, int time){

struct_adress = (Speed*) malloc (sizeof (Speed));
struct_adress->speed = speed;
struct_adress->time = time;

}

void calculate_speed(int currentTime){
	
	int deltaTime = currentTime - struct_adress->time;

	int speed = struct_adress->speed + 56 /* getAcceleration()*/ * deltaTime;
	
	struct_adress->speed = speed;
	struct_adress->time = currentTime;

} 

int get_speed(){

return struct_adress->speed;

}

int get_time(){

return struct_adress->time;

}

void speed_free ()
{
  free (struct_adress);
}








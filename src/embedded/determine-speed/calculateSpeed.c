/******************************************
 * Embedded project - Determining Speed
 * Calculating the speed of the object
 *
 * Copyright (c) Whatever, no warranty.
 *
 * Author: Nena Stojova
 * Edited by: Sorush Arefipour on 4/11/12
 * Integrator: Sorush Arefipour
 * Date: 3/20/12
 ******************************************/

#include <stdlib.h>
#include "calculateSpeed.h"
#include "bma180.h"

void create_speed(int speed, int time){

    struct_adress = (Speed*) malloc (sizeof (Speed));
    struct_adress->speed = speed;
    struct_adress->time = time;
    struct_adress-> bias = calcBias();

}

void calculate_speed(int currentTime){
	
	int deltaTime = currentTime - struct_adress->time;

	int speed = struct_adress->speed + 56 * getXAccel(struct_adress->bias) * deltaTime;
	
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








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
  unsigned long time;
  float bias;
};

typedef struct Speed Speed;


Speed* create_speed(void);
void calculate_speed(Speed* st_speed);
int get_speed(Speed* st_speed);
int get_time(Speed* st_speed);
void speed_free(Speed* st_speed);

/*Speed *struct_adress;   /* Global variabe, not allowed */
#endif


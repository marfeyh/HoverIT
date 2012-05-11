#include <hover_speed_stub.h>
#include <stdio.h>
#include <Arduino.h>

int speed = 100;
int get_hover_speed(){ 
  speed  -= 25;
  return speed;
}


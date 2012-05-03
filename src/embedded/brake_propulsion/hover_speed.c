#include <hover_speed.h>
#include <stdio.h>


static int speed = 100; 

int get_hover_speed(){
  speed  -= 25;
  printf("speed === %d\n", speed);
  return speed;
}

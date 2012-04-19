/*
  Author: Xinran He, Khatereh Khosravianarab
  Date: 2012-03-27
  Description: the main to execute change speed and manual test
*/

#include <propulsion.h>
#include <propulsion_api.h>
#include <stdio.h>

int main(void){
  increase_speed();
  printf("get_fan_level() ======= %d\n", get_fan_level());
  sleep(1);
  increase_speed();
  printf("get_fan_level() ======= %d\n", get_fan_level());
  sleep(1);
  increase_speed();
  printf("get_fan_level() ======= %d\n", get_fan_level());
  sleep(1);
  increase_speed();
  printf("get_fan_level() ======= %d\n", get_fan_level());
  sleep(1);
  decrease_speed();
  printf("get_fan_level() ======= %d\n", get_fan_level());
  sleep(1);
  decrease_speed();
  printf("get_fan_level() ======= %d\n", get_fan_level());
  sleep(1);
  decrease_speed();
  printf("get_fan_level() ======= %d\n", get_fan_level());
  sleep(1);
  decrease_speed();
  printf("get_fan_level() ======= %d\n", get_fan_level());
  sleep(1);
  stop_pro_fan();
  printf("get_fan_level() ======= %d\n", get_fan_level());
  sleep(1);
  increase_speed();
  printf("get_fan_level() ======= %d\n", get_fan_level());
  sleep(1);
  stop_pro_fan();
  printf("get_fan_level() ======= %d\n", get_fan_level());
  printf("Finish\n");
}

/*
  Author: Xinran He, Khatereh Khosravianarab
  Date: 2012-03-27
  Description: the main to execute change speed and manual test
*/

#include <propulsion.h>
#include <propulsion_api.h>
#include <Arduino.h>
#include <searduino.h>

int main(void){
  start_propulsion_fan();
  delay(5000);
  increase_propulsion();
  //printf("get_fan_level() ======= %d\n", get_fan_level());
  delay(5000);
  increase_propulsion();
  //printf("get_fan_level() ======= %d\n", get_fan_level());
  delay(5000);
  increase_propulsion();
  //printf("get_fan_level() ======= %d\n", get_fan_level());
  delay(5000);
  increase_propulsion();
  //printf("get_fan_level() ======= %d\n", get_fan_level());
  delay(5000);
  decrease_propulsion();
  //printf("get_fan_level() ======= %d\n", get_fan_level());
  delay(5000);
  decrease_propulsion();
  //printf("get_fan_level() ======= %d\n", get_fan_level());
  delay(5000);
  decrease_propulsion();
  //printf("get_fan_level() ======= %d\n", get_fan_level());
  delay(5000);
  decrease_propulsion();
  //printf("get_fan_level() ======= %d\n", get_fan_level());
  delay(5000);
  stop_propulsion_fan();
  //printf("get_fan_level() ======= %d\n", get_fan_level());
  delay(5000);
  increase_propulsion();
  //printf("get_fan_level() ======= %d\n", get_fan_level());
  delay(5000);
  stop_propulsion_fan();
  //printf("get_fan_level() ======= %d\n", get_fan_level());
  //printf("Finish\n");
  return 0;
}

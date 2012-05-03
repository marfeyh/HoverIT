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
  initialise_propulsion();
  increase_propulsion();
  decrease_propulsion();
  increase_propulsion();
  increase_propulsion();
  decrease_propulsion();
  decrease_propulsion();
  decrease_propulsion();
  decrease_propulsion();
  return 0;
}

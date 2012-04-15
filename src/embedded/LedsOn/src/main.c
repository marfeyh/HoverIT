/*
 * @ Module name:  main.c
 * @ Description:  main file to run functions in fourLedson.c
 * @ Author names :Nahid Vafaie
 * @ Release      :13 April 2012
 * @ Version      : 1
 * @ Refrences    : Arduino.cc, sandklef.com
 */

#include <Arduino.h>
#include<searduino.h>

int main(void)
{
  init();
  init_leds();

  for(;;){
    run_leds();
  }
}

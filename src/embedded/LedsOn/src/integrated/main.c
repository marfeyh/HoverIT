/*
 * @ Module name:  main.c
 * @ Description:  main file to run functions in fourLedson.c
 * @ Author names :Nahid Vafaie, Kuhan Loh, Aran Gerami, Denir Leric
 * @ Release      :13 April 2012
 * @ Version      : 3
 * @ Refrences    : Arduino.cc, sandklef.com
 */

#include <Arduino.h>
#include <searduino.h>
#include "batteryLevel.h"

int main(void)
{
  init();
  init_leds();

  for(;;){
    check();
  }
}

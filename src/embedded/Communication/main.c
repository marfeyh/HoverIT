/*
 * main.c
 *
 *  Created on: Mar 28, 2012
 */

#include <stdio.h>
#include <initTimerInterrupt.h>
#include <messageHandler.h>
#include <API_bluetooth_controler.h>
int main (int argc, char** argv){
  init();
  run();
}

void init(void) {
  initTimerInterrupt();
}

void run(void) {
  printf("the main is working...\n");
  parseBinary(16);
//  return 0;
}

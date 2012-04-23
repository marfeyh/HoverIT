/*
2	
 * @ Module name:  main.c
3	
 * @ Description:  main file to run functions in alarm.c
4	
 * @ Author names :Neda MOhammadian
5	
 * @ Release      :17 April 2012
6	
 * @ Version      : 1
7	
 */
#include <Arduino.h>
#include <searduino.h>
#include <alarm.h>

int main(void) {
	init();
	setup();
	exec();
	return 0;
}
/*
* @ Module name:  main.c
* @ Description:  main file to run functions in alarm.c
* @ Author names :Neda MOhammadian
* @ Release      :17 April 2012
* @ Version      : 1
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
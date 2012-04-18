/*
 * main.c
 *
 *  Created on: Mar 19, 2012
 *      Author: Anita
 */
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include "main_extension.h"


int main(void) {

	fflush(stdin);

	setTerminal();
}

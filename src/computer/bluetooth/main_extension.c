//#include <ncurses.h>
#include "hcraft_remote_api.h"
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include "main_extension.h"
#define LEFT_ARROW 67
#define RIGHT_ARROW 68

#define ADDRESS "00:0C:84:00:0F:63"

#define BYTETOBINARYPATTERN "%d%d%d%d%d%d%d%d\n"
#define BYTETOBINARY(byte)  \
  (byte & 0x80 ? 1 : 0), \
  (byte & 0x40 ? 1 : 0), \
  (byte & 0x20 ? 1 : 0), \
  (byte & 0x10 ? 1 : 0), \
  (byte & 0x08 ? 1 : 0), \
  (byte & 0x04 ? 1 : 0), \
  (byte & 0x02 ? 1 : 0), \
  (byte & 0x01 ? 1 : 0) 

//print information
void printInfo(char c[]) {
	printf(c, "\n");
}

//different cases that can happen
int processInformation(int c) {
	switch (c) {
	case 'w':
		//send a start message
		printInfo("fan forward speed increase");
		set_move_speed(0b00001000);
		break;
	case 's':
		//send a stop message
		printInfo("fan forward speed decrease");
		set_move_speed(0b00001001);
		break;
	case LEFT_ARROW:
		//go left message
		//printf("left");
		printInfo("left");
		set_rudder(0b00000001);
		break;
	case RIGHT_ARROW:
		//go right message
		printInfo("right");
		set_rudder(0b00000101);
		break;
	default:
		//printf("keystroke: %d\n", c);
		break;
	}

	return c;
}

//getting input from keyboard
void readCharacter(void) {
	int c;
	int quit = 0;
	hc_connect(NULL);
	while (!quit) {
		unsigned char val;			
		c = getchar();
		processInformation(c);
		get_speed(&val);
		printf("Speed:"BYTETOBINARYPATTERN, BYTETOBINARY(val));
		get_pressure(&val);
		printf("Pressure:"BYTETOBINARYPATTERN, BYTETOBINARY(val));
		if (c == 'q') {
			hc_disconnect();
			quit = 1;
		}
	}
}

//settings for the terminal
void setTerminal(void) {
	struct termios oldt, newt;

	tcgetattr(STDIN_FILENO, &oldt); // write terminal attributes to oldt
	newt.c_lflag &= ~(ICANON | ECHO); // make terminal incanonical
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);

	readCharacter();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}
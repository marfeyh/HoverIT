/**
 * Author:  Johan Wikström Schützer & Gokul Reddy
 * Date:    2012-04-10
 * Version: 1.0 - 2012-04-03 - Function prototypes
 * Version: 1.5 - 2012-04-10 - Added Gokuls parts (function prototypes and structs) 
 **/

#pragma once

struct Position {
  float longitude;
  float latitude;
  char nsew;
};

int check_command(char[],char[]);

/* returns 0 if the given data starts with "$GPRMC", 1 if not */
int is_GPRMC(char[]);

/* returns 0 if the given data starts with "$GPGGA", 1 if not */
int is_GPGGA(char[]);

/* returns 0 if the given data starts with "$GPGSV", 1 if not */
int is_GPGSV(char[]);

/* returns 0 if the given data starts with "$GPGSA", 1 if not */
int is_GPGSA(char[]);

char* read_data();

char* get_time(char[]);

struct Position *get_position(char[]);

char* retrive_data(char[],int);

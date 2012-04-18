/**
 * Author:  Johan Wikström Schützer & Gokul Reddy
 * Date:    2012-04-10
 * Version: 1.0 - 2012-04-03 - Function prototypes
 * Version: 1.5 - 2012-04-10 - Added Gokuls parts (function prototypes and structs) 
 **/

#pragma once

struct position {
  float longitude;
  float latitude;
  char nsew;
};

/* Radius of earth in kilometer and miles */
#define RADIUS_KM 6378.137
#define RADIUS_MI 3958.761
 
/*
 * function used by the others to avoid duplicated code.
 * Iterates through both arrays and checks if the first 6 characters
 * are the same. Returns 0 if they are the same, 1 if not.
 */
int check_command(char[],char[]);

/*  
 * returns a pointer to an array of 13 integers, containing the indices
 * of commas in the gps char array. 
 * DONT FORGET TO FREE THE VARIABLE IN WHICH THE RESULT IS STORED!
 */
int* get_indices(char);

/* returns 0 if the given data starts with "$GPRMC", 1 if not */
int is_GPRMC(char[]);

/* returns 0 if the given data starts with "$GPGGA", 1 if not */
int is_GPGGA(char[]);

/* returns 0 if the given data starts with "$GPGSV", 1 if not */
int is_GPGSV(char[]);

/* returns 0 if the given data starts with "$GPGSA", 1 if not */
int is_GPGSA(char[]);

/* Calculates the distance between the two given points in kilometers */
double get_distance_km(struct position, struct position);

/* Calculates the distance between the two given points in miles */
double get_distance_mi(struct position, struct position);

char* read_data();

char* get_time(char[]);

struct position *get_position(char[]);

char* retrive_data(char[],int);

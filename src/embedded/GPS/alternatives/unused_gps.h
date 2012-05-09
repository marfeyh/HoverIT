/*
 * Author: Johan Wikström Schützer
 * Date: 2012-05-07
 * Version: 1.0
 * This file contains code that was planned and designed, but after implementation
 * was decided to be left out of the project.
 * It contains declarations of functions to calculate the distance between two given coordinates.
 */ 

/* 
 * Author: Johan
 * Calculates the distance between the two given points in kilometers 
 */
double get_distance_km(struct position p1, struct position p2);

/*  
 * Author: Johan
 * Calculates the distance between the two given points in miles
 */
double get_distance_mi(struct position p1, struct position p2);

/* Parses decimal degrees to radians */
double d2r(double);

/*!
@file hover_api.c
@headerfile pressure.h
@author Eva-Lisa Kedborn
@author Jing Liu
@date 2012-03-26
@brief Stub to generate fake air pressure inside the hovercraft skirt
*/

#include <stdio.h>
#include <stdlib.h>
#ifdef STUB
	#include <time.h>
#endif
#include <pressure.h>

/*!
@brief Generates a fake random air pressure inside the hovercraft skirt
*/ 
int get_pressure() {
  int random;
  srand(time(NULL));
  random = rand() % 100;
  return random ;
}

/*!
@brief Generates fake air pressure higher than preferred 
*/
int get_positive() {
  return 70;
}

/*!
@brief Generates fake air pressure lower than preferred 
*/
int get_negative() {
  return 30;
}

/*!
@brief Generates fake air pressure equal to preferred
*/
int get_equal() {
  return 50;
}
  
  

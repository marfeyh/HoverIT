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

int get_positive() {   /* generate air pressure higher than preferred */
  return 70;
}

int get_negative() {  /* generate air pressure lower than preferred */
  return 30;
}

int get_equal() {  /* generate air pressure equal to preferred */
  return 50;
}
  
  

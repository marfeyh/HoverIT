/* 
Author: Eva-Lisa Kedborn, Jing Liu
Date: 2012-03-26
Description: A stub to generate fake air pressure inside the hovercraft skirt
*/

#include <stdio.h>
#include <stdlib.h>
#ifdef STUB
	#include <time.h>
#endif
#include <pressure_sensor.h>

float get_pressure(){   /* generate a random air pressure */
  float random;
  srand(time(NULL));
  random = rand() % 100;
  return random ;

}

float get_positive(){   /* generate air pressure higher than preferred */
  return 70;
}

float get_negative(){  /* generate air pressure lower than preferred */
  return 30;
}

float get_equal(){  /* generate air pressure equal to preferred */
  return 50;
}
  
  

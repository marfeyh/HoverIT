/* 
Author: Eva-Lisa Kedborn, Jing Liu
Date: 2012-03-28
Description: API for controling hovering fan
*/

#include <hovering_motor.h>
#include <pressure_check.h>
#include <stdlib.h>
#define USING_PIN 11

int start_hover() {         /* start the hovering fan */ 
  initialize(USING_PIN);
  return 0;
}

int decrease_hover_min(){   /* minimize the speed */
  normal();
  return 0;
}

int increase_hover_max(){   /* maximize the speed */
  turbo();
  return 0;
}

int decrease_hover(){       /* decrease the speed */
  decrease(10);
  return 0;
}

int increase_hover(){       /* increase the speed */
  increase(10);
  return 0;
}

int stop_hover(){           /* stop the fan */
  stop();
  return 0;
}

int autocontrol(){          /* let the fan speed be cotrolled by pressure sensor
			       automatically */
  loop();
  return 0;
}


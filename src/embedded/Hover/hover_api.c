/* 
Author: Eva-Lisa Kedborn, Jing Liu
Date: 2012-03-28
Description: API for controling hovering fan
*/

#include <stdlib.h>
#include <hover_api.h>
#include <hovering_motor.h>
#include <hovering_control.h>
#include <pressure_check.h>
#include <pin.h>

#define LEVEL 10

int start_hover() {         /* start the hovering fan */ 
  initialize(USING_PIN);
  return 0;
}

int stop_hover(){           /* stop the fan */
  hover_func(stop,USING_PIN);
  return 0;
}

int hover_min(){   /* minimize the speed */
  hover_func(normal,USING_PIN);
  return 0;
}

int hover_max(){   /* maximize the speed */
  hover_func(turbo,USING_PIN);
  return 0;
}

int decrease_hover(){       /* decrease the speed */
  hover_change(decrease,USING_PIN,LEVEL);
  return 0;
}

int increase_hover(){       /* increase the speed */
  hover_change(increase,USING_PIN,LEVEL);
  return 0;
}

//int autocontrol(){          /* let the fan speed be cotrolled by pressure sensor
//			       automatically */
//  start_sensor_reading();
//  return 0;
//}

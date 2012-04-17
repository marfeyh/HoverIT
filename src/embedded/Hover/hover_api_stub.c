#include <stdlib.h>
#include <hover_api_stub.h>
#include <propulsion.h>

#define USING_PIN 11
#define LEVEL 10

int start_hover() {         /* start the hovering fan */ 
  initialise_propulsion();
  init_motor();
  return 0;
}

int stop_hover(){           /* stop the fan */
  stop_pro_fan();
  return 0;
}

int hover_min(){   /* minimize the speed */
  change_pro_speed(PERSPEED);
  return 0;
}

int hover_max(){   /* maximize the speed */
  change_pro_speed(PERSPEED*3);
  return 0;
}

int decrease_hover(){       /* decrease the speed */
  int speed = getSpeedLevel();
  if(speed <= 0){
    stop_pro_fan();
    return 0;
  }
  else if(speed > 0){
    change_pro_speed(speed - PERSPEED);
    return speed - PERSPEED;
  }
  return -1;
}

int increase_hover(){       /* increase the speed */
  int speed = getSpeedLevel();
  if(speed >= MAXSPEED - 3){
    change_pro_speed(PERSPEED*3);
    return PERSPEED*3;
  }
  else if( speed < MAXSPEED){
    change_pro_speed(speed + PERSPEED);
    return speed+PERSPEED;
  }
  return -1;
}


//int autocontrol(){          /* let the fan speed be cotrolled by pressure sensor
//			       automatically */
//  start_sensor_reading();
//  return 0;
//}

#include <brake_propulsion.h>
#include <hover_speed.h>
#include <propulsion.h>
#include <Arduino.h>
#include <pin.h>
#include <searduino.h>

static int hover_speed = 0;

void init_brake_propulsion(void){

}

int reverse_motor(int current_hover_speed){
  

  change_pro_speed(current_hover_speed - 20);
  break_pro();
  return 0;
}

int brake_pro(void){
  for(;;){
    hover_speed = get_hover_speed();
    if(hover_speed < 10){
      stop_pro_fan();
      break;
    }
  }
  return 0;
}


#include <brake_propulsion.h>
#include <hover_speed_stub.h>
#include <propulsion_api.h>
#include <Arduino.h>
#include <pin.h>
#include <searduino.h>

/*!
 * @brief: reverse rotation 
 */
int reverse_prop_motor(){
   int hover_speed = 0;
   digitalWrite(RELAYPIN,HIGH);
   set_propulsion_fan(MAXSPEED);
  for(;;){
    hover_speed = get_hover_speed();
    if(hover_speed < 10){ //need test
      stop_propulsion_fan();
      break;
    }
  // delay(1000);
   }
   return 0;
}

int initialize_relay(){
#if !defined(GLOBAL_MAIN)
   init();
#endif
   /* sets PIN as output pin */
   pinMode(RELAYPIN, OUTPUT);
  // digitalWrite(RELAYPIN, HIGH);
   return 0;
}

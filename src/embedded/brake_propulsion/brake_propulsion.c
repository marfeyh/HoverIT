
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
<<<<<<< HEAD
   digitalWrite(RelayPin, HIGH);
   delay(2000);
   analogWrite(PIN, 100);
   delay(2000);
   digitalWrite(RelayPin, LOW);
   delay(2000);
   analogWrite(PIN, 100);
   delay(2000);
   change_pro_speed(MAXSPEED);
   brake_pro();
   return 0;
}


/*!
 * @brief: get hovercraft speed. If the speed is less than
 * 10, then the propulsion fan is stopped.
 */
int brake_pro(void){
=======
   int hover_speed = 0;
   digitalWrite(RELAYPIN,LOW);
   set_propulsion_fan(MAXSPEED);
>>>>>>> fc3408bf60875ec5fe7784822b865277a78e2728
  for(;;){
    hover_speed = get_hover_speed();
    if(hover_speed < 10){ //need test
      stop_propulsion_fan();
      break;
    }
   delay(1000);
   }
   return 0;
}

int initialize_relay(){
#if !defined(GLOBAL_MAIN)
   init();
#endif
   /* sets PIN as output pin */
   pinMode(RELAYPIN, OUTPUT);
   digitalWrite(RELAYPIN, HIGH);
   return 0;
}

#include <Arduino.h>
#include <searduino.h>
#include <Theta-API.h>
#include <API_bluetooth_controler.h>

int main(void) {
  init();
  bluetooth_serial_setup();
  //start_propulsion_fan();
  //start_hover();
  //control_rudder(0);

  for(;;) {
    control();
  }
  return 0;
}


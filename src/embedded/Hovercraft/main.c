#include <Arduino.h>
#include <searduino.h>
#include <Theta-API.h>
#include <API_communication_controler.h>
#include <propulsion_api.h>
#include <hover_api.h>
#include <hovercraft_pin.h>
#include <steering.h>

int main(void) {
  init();
  communication_serial_setup();
  start_propulsion_fan();
  start_hover();
  control_rudder(0);

  for(;;) {
    control();
  }
  return 0;
}


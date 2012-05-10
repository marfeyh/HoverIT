#include <propulsion.h>
#include <propulsion_api.h>
#include <brake_propulsion.h>
#include <Arduino.h>
#include <searduino.h>

int main(void){
  initialize_relay();
  start_propulsion_fan();
  increase_propulsion();
  delay(2000);
  increase_propulsion();
  delay(2000);
  brake_hovercraft();
}

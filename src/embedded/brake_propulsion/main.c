#include <propulsion.h>
#include <propulsion_api.h>
#include <brake_propulsion.h>
#include <Arduino.h>
#include <searduino.h>

int main(void){
  initialise_propulsion();
  increase_propulsion();
  increase_propulsion();
  increase_propulsion();
  brake_hovercraft();
}

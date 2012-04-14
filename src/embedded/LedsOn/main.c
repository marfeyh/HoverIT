#include <Arduino.h>
#include<searduino.h>

int main(void)
{
  init();
  init_leds();

  for(;;){
    run_leds();
  }
}

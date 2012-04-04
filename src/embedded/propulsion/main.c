#include <stdlib.h>
#include <Arduino.h>
#include <searduino.h>
#include <propulsion.h>

int main(void)
{
  initialise_propulsion();
  while(1)
    {
      manage_motor();
    }
}


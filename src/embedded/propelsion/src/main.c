#include <stdlib.h>
#include <Arduino.h>
#include <searduino.h>
#include <propelsion.h>

int main(void)
{
  initialise_propelsion();
  while(1)
    {
      manage_motor();
    }
}


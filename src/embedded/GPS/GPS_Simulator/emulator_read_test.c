#include <stdio.h>

#include "emulator_GPS.h"

int main(){
  int i;
  for(i=0;i<300;i++){
    printf("%c",(char)serial_read());
  }  
  printf("\n");
  return 0;
}

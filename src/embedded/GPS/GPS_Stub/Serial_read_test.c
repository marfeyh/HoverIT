#include <stdio.h>

#include "Serial_read.h"

int main(){
  int i;
  for(i=0;i<300;i++){
    printf("%c",(char)serial_read());
  }  
  printf("\n");
  return 0;
}

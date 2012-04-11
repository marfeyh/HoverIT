#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<pressure_sensor.h>

float get_pressure(){
  float random;
  srand(time(NULL));
  random = rand()%100;
  printf("THE NUMBER IS %f\n",random);
  return random ;

}

/* int main(void){ */
/*   int i; */
/*   for(i = 0;i<10;i++){ */
/*     sleep(1); */
/*     get_pressure(); */
/*   } */
/*   return 0; */
/* } */
  
  

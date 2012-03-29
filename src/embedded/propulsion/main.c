#include <propelsion.h>
#include <pro_api.h>
#include <stdio.h>

int main(void){
  increase_speed();
  sleep(1);
  increase_speed();
  sleep(1);
  increase_speed();
  sleep(1);
  increase_speed();
  sleep(1);
  decrease_speed();
  sleep(1);
  decrease_speed();
  sleep(1);
  decrease_speed();
  sleep(1);
  decrease_speed();
  sleep(1);
  stop_pro_fan();
  sleep(1);
  increase_speed();
  sleep(1);
  stop_pro_fan();
  printf("Finish\n");
  
}
#include <propelsion.h>
#include <stdio.h>

int getSpeedLevel(){
  int spLevel=0;
  spLevel = level;
  printf("getSPeedLEvel = %d\n", spLevel);
  return spLevel;
  
}

int stop_pro_fan(){
  level = 0;
  printf("Stop = 0\n",level);
  return level;
}

void change_pro_speed(int change_level){
//  printf("changelebeeeeeeeeeeeee %d\n", change_level);
  level = change_level;
  printf("change_pro_speed= %d\n", level);
}

#include <stdio.h>
#include <pressure_sensor.h> //file from pressure sensor group
//#include<hover_fan.h> //file from our own group
#include <pressure_loop.h>
#define PROPER_PRESSURE 50.1

int loop(){
  while(1){
    handle_pressure(get_gap());
    printf("pressure has been handled\n");
    sleep(1);
  }
  return 0;
}

float get_gap(){
  float pressure;//the real air pressure in cushion
  float gap;
  pressure = get_pressure();
  
  float proper_p = PROPER_PRESSURE;
  gap = proper_p-pressure;
  // printf("GAP IS %d",gap);
  
  return gap;
}

int handle_pressure(float gap){
  
  if(gap>10){
    //change_pressure(gap);//function in hover_fan will change later
    printf("gap = %f\tpressure increased\n",gap);
    return 1;
  }
 
  if(gap<-10){
    //change_pressure(gap);//function in hover_fan will change later
    printf("gap = %f\tpressure decreased\n",gap);
    return -1;
  }

  return 0;
}


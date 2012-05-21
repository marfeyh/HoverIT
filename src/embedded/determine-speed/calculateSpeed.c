/*!
 @file calculateSpeed.c
 @headerfile calculateSpeed.h
 @headerfile stdlib.h
 @headerfile bma180.h
 @brief Calculating the speed of the Hovercraft
 @author Nena Stojova
 @date Mach 20 2012
 @Edited by: Sorush Arefipour on 4/11/12
 @Integrator: Sorush Arefipour
 @Edited by: Viktor Green on 4/19/12
 */

/*#include <stdlib.h>*/
#include <Arduino.h>
#include "calculateSpeed.h"
#include "bma180.h"


/*!
 @brief Initialize the accelerometer and allocate memory 
 for the value keeping struct
 */
Speed* create_speed(void) {
  
  Speed* struct_adress;
  struct_adress = (Speed*) malloc (sizeof (Speed));
  if(NULL == struct_adress) {
    /* Error */
    return NULL;
  }
    
  // Calls the function to initialize the accelerometer from bma180 module
  bma180_initialize();

  struct_adress -> bias = calcXBias();
  struct_adress -> speed = 0.0;
  struct_adress -> time = millis();

  return struct_adress;
}

/*!
 @brief Calculates the speed of hovercraft
 @param st_speed is the pointer returned from create_speed(void)
 */
void calculate_speed(Speed* st_speed){
	
  unsigned long deltaTime; /**< subtraction of start and end time */
  unsigned long time;  

  // Get current time of board
  time = millis(); 
  deltaTime = time - st_speed->time;
  
  st_speed->speed += (getXAccel(st_speed->bias) * deltaTime)/1000;
  st_speed->time = time;

} 

/*!
 @brief Retrieve the current speed by calling
 @param st_speed: The pointer returned from create_speed(void)
 @return speed: The speed of hovercraft from struct
 */
int get_speed(Speed* st_speed){

  return (int) st_speed->speed;

}

/*!
 @brief Retrieve time from st_speed pointer
 @param st_speed: The pointer returned from create_speed(void)
 @return time from st_speed pointer
 */
int get_time(Speed* st_speed){

return st_speed->time;

}

/*!
 @brief Freeing memory when the speed should no longer be calculated,
 This should be called when the hovercraft is shutting down.
 @param st_speed: The pointer returned from create_speed(void)
 */
void speed_free (Speed* st_speed)
{
  free (st_speed);
}








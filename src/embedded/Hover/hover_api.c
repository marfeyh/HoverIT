/*!
@file hover_api.c
@headerfile hover_api.h
@author Eva-Lisa Kedborn
@author Jing Liu
@date 2012-03-28
@version 0.2
@brief API for controling hovering fan
 */

#include <stdlib.h>
#include <hover_api.h>
#include <hovering_motor.h>
#include <hovering_control.h>
#include <pressure_check.h>
#include <pin.h>

#define HOVER_LEVEL 10

/*!
@brief start the hovring fan
 */
int start_hover() {
  initialize(USING_PIN);
  return 0;
}

/*!
@brief stop the hovering fan
 */
int stop_hover() {          
  hover_func(stop, USING_PIN);
  return 0;
}

/*!
@brief minimize the fan speed
 */
int hover_min() {
  hover_func(normal, USING_PIN);
  return 0;
}

/*!
@brief maximize the fan speed
 */
int hover_max() {
  hover_func(turbo, USING_PIN);
  return 0;
}

/*!
@brief decrease the fan speed
 */
int decrease_hover() {       
  hover_change(decrease, USING_PIN,HOVER_LEVEL);
  return 0;
}

/*!
@brief increase the speed
 */
int increase_hover() {
  hover_change(increase, USING_PIN, HOVER_LEVEL);
  return 0;
}

/*!
@brief fan speed cotrolled by pressure sensor automatically
 */
int autocontrol() {       
  start_sensor_reading();
  return 0;
}

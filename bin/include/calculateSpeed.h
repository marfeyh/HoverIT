/*!
 @file calculateSpeed.h
 @brief Calculating the speed of the Hovercraft
 @author Nena Stojova
 @date Mach 20 2012
 */

#ifndef SPPED_H
#define SPEED_H

/*!
 @brief struct for speed 
 @struct Speed 
 */
struct Speed
{
  float speed; /**< the speed value */
  unsigned long time; /**< time */
  float bias; /**< bias */
};

typedef struct Speed Speed;

/*!
 @brief Initialize the accelerometer and allocate memory 
 for the value keeping struct
 */
Speed* create_speed(void);

/*!
 @brief Calculates the speed of hovercraft
 @param st_speed is the pointer returned from create_speed(void)
 */
void calculate_speed(Speed* st_speed);

/*!
 @brief Retrieve the current speed by calling
 @param st_speed: The pointer returned from create_speed(void)
 @return speed: The speed of hovercraft from struct
 */
int get_speed(Speed* st_speed);

/*!
 @brief Retrieve time from st_speed pointer
 @param st_speed: The pointer returned from create_speed(void)
 @return time from st_speed pointer
 */
int get_time(Speed* st_speed);

/*!
 @brief Freeing memory when the speed should no longer be calculated,
 This should be called when the hovercraft is shutting down.
 @param st_speed: The pointer returned from create_speed(void)
 */
void speed_free(Speed* st_speed);

#endif


/* 
 * @ Module name:  hovering_motor.h
 * @ Description:  Header file for controlling hovering motor by 
 *                 hovering_motor.c hover_api.c pressure_loop.c
 *
 * @ Author names :Seyed Ehsan Mohajerani - Navid Amiriarshad
 * @ Version      :
 * @ Refrences    :
 *
 */


#include <Arduino.h>
#include <searduino.h>


// Definition

#define throttle_stick_bottom_level 100
#define using_pin 11

//////////////    typedef void (*functiontype)();


// Function prototypes
int hovering_motor_func(int (*f)(void));
int pin_program(int level);
int start(void);
int throttle_stick_bottom(void);
int normal(void);
int turbo(void);
int stop(void);
int increase(int level);
int decrease(int level);
int climb(int level);
int descend(int level);
int check_and_fix_level(void);


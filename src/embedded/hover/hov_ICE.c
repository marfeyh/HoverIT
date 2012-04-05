/*
 * @ Module name:  hov_ICE.c
 * @ Description:  Contains the functions to stop the motor in case of 
 * @ 		   emergency.
 *
 * @ Author names :Seyed Ehsan Mohajerani, Nelson Sekitoleko
 * @ Release      :20 March 2012
 * @ Version      :1.0
 * @ Refrences    :Arduino.cc, http://www.sandklef.com
 * http://www.dreamincode.net/forums/topic/34861-functions-stored-in-structure/
 */

#include <hov_ICE.h>
/* Call stop function in the hovering motor */
int hov_emerg_stop(void){
	hover_func(stop);
}

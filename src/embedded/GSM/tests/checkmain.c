/*
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

This program is distodributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public
License along with this program. If not, see
<http://www.gnu.org/licenses/gpl-3.0.html>.
*/


/*!
 @file checkmain.c
 @uthors Bishare and Stepan
 @date 20120504
*/

#include <Arduino.h>
#include <searduino.h>
#include <check.h>


/*!
 @brief setup function 
 @this function is supported by searduino library
 @it should be included and the pinMode is 13
*/

void setup() {
  init(); 
  pinMode(13, OUTPUT);      
}
 
/*!
 @brief main function 
 @here are executed the file check_blink.c and the function setup
*/ 
    
uint8_t main(void){
    
    int number_failed;
    Suite *s = new_suite();
    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;

}
  
  
   


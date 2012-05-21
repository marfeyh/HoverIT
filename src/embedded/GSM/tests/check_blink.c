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
 @file check_blink.c
 @autors Bishare Sufi, Stepan Stepasyuk
 @date 20120504
 */

/*!
 @All unit tests in this file have been tested several times by giving 
 @different inputs each time. 
*/
#include <Arduino.h>
#include <check.h>


/*!
 @brief Check unit test for blinker function 
 *this test function checks if the GSM is connecting or calling
 *it takes pin 13 as parameter
 @return 0 on success
 @par Test id: blk 01 \n 
 @par Testname: testing blinker function \n
 @par Preconditions: none \n 
 @par Postconditions: the LED is blinking \n 
 @par Procedure: assign value 0 for passing otherwise fail the test \n
 @par Outcome: test is passed \n
*/

START_TEST(test_blinker){
    
    setup();
    
    fail_unless(blinker(13) == 0, NULL);
    fail_if(blinker(13) != 0, NULL);
    
}
END_TEST

/*!
 @brief Check unit test for isOn function 
 *this test function checks if the GSM is already connected
 *it takes pin 13 as parameter
 @return 0 on success
 @par Test id: blk 02 \n 
 @par Testname: testing isOn function \n
 @par Preconditions: the Hover-craft is turned on \n 
 @par Postconditions: the LED is On \n 
 @par Procedure: assign value 0 for passing otherwise fail the test \n
 @par Outcome: test is passed \n
*/


START_TEST(test_set_led_On){

    setup();
	
    fail_unless(set_led_On(13) == 0, NULL);
    fail_if(set_led_On(13) != 0, NULL);
    
}
END_TEST  

/*!
 @brief Check unit test for isOff function 
 *this test function checks if the GSM is not connected
 *it takes pin 13 as argument
 @return 0 on success
 @par Test id: blk 03 \n 
 @par Testname: testing isOff function \n
 @par Preconditions: the Hover-craft is turned off \n 
 @par Postconditions: the LED is Off \n 
 @par Procedure: assign value 0 for passing otherwise fail the test \n
 @par Outcome: test is passed \n
*/

START_TEST(test_set_led_Off){

    setup();
    
    fail_unless(set_led_Off(13) == 0, NULL);
    fail_if(set_led_Off(13) != 0, NULL);
    
}
END_TEST

/* Suite for client test functions */
               
Suite * new_suite(void){

    Suite *s = suite_create("New Suite");
    
/* Core test case */
    
    TCase *tc_core = tcase_create("New Test Cases");
    
    tcase_add_test(tc_core, test_blinker);
    tcase_add_test(tc_core, test_set_led_On);
    tcase_add_test(tc_core, test_set_led_Off);
    
    tcase_set_timeout(tc_core, 0);
    
    suite_add_tcase(s, tc_core);
    return s;
    
}



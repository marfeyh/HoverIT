/***************************************************************************
 * Copyright (C) 2012  Yohanes Kuma
 *                     Khatereh Khosravianarab
 *                     Xinran He
 *                     Ezeh Prince Anthony Anayo
 *
 *
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 ****************************************************************************/

/*!
 @file check_propulsion.c
 @brief Contains the functions that check the hovering control files.
 @author Khatereh Khosravianarab
 @author Xinran He
 @author Yohanes Kuma
 @author Ezeh Prince Anthony Anayo
 @version 1.0
 @date 2012-05-10
 @reference http://check.sourceforge.net/doc/check_html/index.html#SEC_Top

 */

#include <check.h>
#include <propulsion.h>
#include <propulsion_api.h>
#include <brake_propulsion.h>
#include <pin.h>
#include <Arduino.h>
#include <searduino.h>

void setup(void){
  //nothing for the moment
}

void teardown(void){
  //nothing for the moment
}

/*!
   PROPULSION_API UNIT TESTS  
   Authors:Xinran He 
           Khatereh Khosravianarab
*/

/* 
 @brief  test if user increase propulsion fan over the maximum value of fan 
 @par Test id: \n
 * XK1 \n
 @par Testname: \n
 * test increases propulsion speed \n
 @par Precondition: \n
 * initialize propulsion fan \n
 @par Outcome: \n
 *  propulsion fan speed should keep the highest level without any errors \n
*/
START_TEST(test_Pro){
  fail_if(increase_propulsion() != PERSPEED, "Expected 6");
  increase_propulsion(); increase_propulsion(); increase_propulsion();
  increase_propulsion(); increase_propulsion(); increase_propulsion();
  fail_if(increase_propulsion() != PERSPEED * 8, "Expected 48");
  increase_propulsion(); increase_propulsion(); increase_propulsion();
  increase_propulsion(); increase_propulsion(); increase_propulsion();
  increase_propulsion(); increase_propulsion(); increase_propulsion();
  increase_propulsion(); increase_propulsion(); increase_propulsion();
  increase_propulsion(); increase_propulsion(); increase_propulsion();
  fail_if(increase_propulsion() != PERSPEED * 20, "Expected 120 ");
}END_TEST

/*! 
 @brief test if user keep decreasing propulsion fan
 @par Test id: \n
 * XK2\n
 @par Testname: \n
 *  test increase propulsion speed \n
 @par Precondition: \n
 *  initialize propulsion fan \n
 @par Outcome: \n
 *  propulsion fan speed should stop without errors \n
*/
START_TEST(test_dec){
  increase_propulsion();
  fail_if(decrease_propulsion() != 0, "Expected 0");
  increase_propulsion();
  increase_propulsion();
  fail_if(decrease_propulsion() != PERSPEED, "Expected 6");
  decrease_propulsion();
  decrease_propulsion();
  fail_if(decrease_propulsion() != 0, "Expected 0");
}END_TEST

/*! 
 @brief test if user can get right propulsion fan speed level
 @par Test id: \n
 * XK3 \n
 @par Testname: \n
 *  test get current propulsion fan speed level \n
 @par Precondition: \n
 *  initialize propulsion fan \n
 @par Outcome: \n
 *  return right current fan speed level \n
*/
START_TEST(test_fanlevel){
  increase_propulsion();
  fail_if(get_propulsion_level() != 1 ,"Expected 1");
  increase_propulsion();
  increase_propulsion();
  fail_if(get_propulsion_level() != 3 ,"Expected 3");
  decrease_propulsion();
  decrease_propulsion();
  decrease_propulsion();
  decrease_propulsion();
  fail_if(get_propulsion_level() != 0 ,"Expected 0");
}END_TEST

/*! 
 @brief test if the propulsion fan is stoped normally
 @par Test id: \n
 * XK4 \n
 @par Testname: \n
 *  test stop propulsion fan speed \n
 @par Precondition: \n
 *  initialize propulsion fan \n
 @par Outcome: \n
 *  propulsion fan stop \n
*/
START_TEST(test_stop){
  increase_propulsion();
  fail_if(stop_propulsion_fan() != 0, "Expected 0");
  increase_propulsion();
  increase_propulsion();
  fail_if(stop_propulsion_fan() != 0, "Expected 0");
}END_TEST

/*! 
 @brief user wants to set propulsion fan by himself
 @par Test id: \n
 * XK5 \n
 @par Testname: \n
 *  test set propulsion fan speed by manual \n
 @par Precondition: \n
 *  initialize propulsion fan \n
 @par Outcome: \n
 *  propulsion fan speed should change to the speed that the user wants \n
*/
START_TEST(test_set_speed){
  fail_if(set_propulsion_fan(30) != 30,"Expected 30");
  fail_if(set_propulsion_fan(50) != 50,"Expected 50");
  fail_if(set_propulsion_fan(-40) != -1,"Expected -40");
  fail_if(set_propulsion_fan(500) != -1,"Expected 500");
}END_TEST


/*! 
 @brief propulsion fan should be init before starting propulsion fan
 @par Test id: \n
 * XK6 \n
 @par Testname: \n
 *  test initialize propulsion fan \n
 @par Precondition: \n
 *  NULL \n
 @par Outcome: \n
 *  propulsion fan should be initialized and return 0 \n
*/
START_TEST(test_init_propulsion){
  fail_if(start_propulsion_fan() != 0, "Expected 0 to init propulsion");
}END_TEST

 /* END OF PROPULSION API UNIT TESTS */



/*!
   PROPULSION UNIT TESTS
   Author: Yohanes Kuma
 */

 /*!
 @brief tests setting PIN as output and the initialising/preparation 
  state of the propulsion
 @par Test id: \n
 * Y1 \n
 @par Testname: \n
 *  initialising test \n
 @par Precondition: \n
 *  arduino init() is called \n
 @par Outcome: \n
 *  1. 0 will be returned from initalise_propulsion showing the motor 
	has set the pin \n          
 *  2. 1 will be returned from manage_motor showing the motor
 	is now initiated. \n           
 */
START_TEST(test_init) {
  fail_unless((initialise_propulsion() == 0),NULL);
  fail_unless((manage_motor() == 1),NULL);
}END_TEST

 /*!
 @brief tests the stopped state of the propulsion
 @par Test id: \n
 * Y2 \n
 @par Testname: \n
 *  stopping test \n
 @par Precondition: \n
 *  1. the arduino init() function is called \n
 *  2. the propulsion is in another state \n
 @par Outcome: \n
 *  0 will be returned showing the motor is stopped \n  
 */
START_TEST(test_stop_motor) {
  initialise_propulsion(); 
  stop_pro_fan();
  fail_unless((manage_motor() == 0),NULL);
}END_TEST

 /*!
 @brief tests the minimum boundary speed level of the propulsion
 @par Test id: \n
 * Y3 \n
 @par Testname: \n
 *  Rotating boundary test \n
 @par Precondition: \n
 *  1. the arduino init() function is called \n
 *  2. the propulsion is aleardy initialized \n
 *  3. a speed level of 1 is declared. \n
 @par Outcome: \n
 *  1. 2 will be returned from the manage_motor() function
        showing the propulsion is now in rotating state \n
 *  2. 1 is returned from get_speed_level() showing the speed
    is now at level 1(Minimum boundary) \n            
 */

START_TEST(test_minimum_speed) {
  int level = 1;
  initialise_propulsion();
  change_pro_speed(level);
  fail_unless((manage_motor() == 2),NULL);
  fail_unless((get_speed_level() == 1),NULL);  
}END_TEST

 /*!
 @brief tests the maximum boundary speed level of the propulsion
 @par Test id: \n
 * Y4 \n
 @par Testname: \n
 *  Rotating boundary test \n
 @par Precondition: \n
 *  1. the arduino init() function is called \n
 *  2. the propulsion is aleardy initialized \n
 *  3. a maximum speed level is declared. \n
 @par Outcome: \n
 *  1. 2 will be returned from the manage_motor() function
        showing the propulsion is now in rotating state \n
 *  2. MAX_SPEED_LEVEL is returned from get_speed_level() showing the speed
    is now at level 1(Maximum boundary) \n     
 */

START_TEST(test_maximum_speed) {
  int level = (MAX_DUTY_CYCLE - MIN_DUTY_CYCLE);
  initialise_propulsion();
  change_pro_speed(level);
  fail_unless((manage_motor() == 2),NULL);
  fail_unless((get_speed_level() == (MAX_DUTY_CYCLE - MIN_DUTY_CYCLE)),NULL);  
}END_TEST

/* END OF PROPULSION UNIT TESTS*/

/*!
   BRAKE PROPULSION UNIT TESTS 
   Authors: Xinran He
            Ezeh Prince Anthony Anayo
*/

/*! 
 @brief test if the hovercraft would be stopped immediately once
   stop command is received
 @par Test id: \n
 * XA1 \n
 @par Testname: \n
 *  test brake hovercraft \n
 @par Precondition: \n
 *  initialize relay \n
 @par Outcome: \n
 *  propulsion motor reverse rotation, return 0 \n     
*/
START_TEST(test_brake_hovercraft){
  initialise_propulsion();
  initialize_relay();
  fail_unless(reverse_prop_motor() == 0);
}END_TEST


/*! 
 @brief test if the realy is initialized before starting hovercraft
 @par Test id: \n
 * XA2 \n
 @par Testname: \n
 *  test initialize relay \n
 @par Precondition: \n
 *  none \n
 @par Outcome: \n
 *  propulsion motor reverse rotation, return 0 \n   
*/
START_TEST(test_initialize_relay){
  fail_unless((initialize_relay() == 0), NULL); 
}END_TEST

 /* END OF BRAKE PROPULSION UNIT TESTS*/


/* Creates test suit for check. see check manual for details
    http://check.sourceforge.net/doc/check_html/index.html#SEC_Top
*/

Suite * propulsion_suite(void) {
  Suite *s = suite_create("Propulsion_fan");
  TCase *tc = tcase_create("Core");
  tcase_add_checked_fixture(tc, setup, teardown);
  tcase_add_test(tc, test_init);
  tcase_add_test(tc, test_stop_motor);
  tcase_add_test(tc, test_minimum_speed);
  tcase_add_test(tc, test_maximum_speed);
  tcase_add_test(tc, test_Pro);
  tcase_add_test(tc, test_dec);
  tcase_add_test(tc, test_fanlevel);
  tcase_add_test(tc, test_stop);
  tcase_add_test(tc, test_set_speed);
  tcase_add_test(tc, test_brake_hovercraft);
  tcase_add_test(tc, test_initialize_relay);
  suite_add_tcase(s, tc);
  return s;
}

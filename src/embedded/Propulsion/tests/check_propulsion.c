/*!
 @file check_propulsion.c
 @author Yohanes Kuma
 @author Xinran He
 @author Khatereh Khosravianarab
 @author Ezeh Prince Anthony Anayo
 @brief This file is the unit tests for the propulsion and propulsion
  API functions.Check libraries are used as a tool for the unit tests. 
  check their manual for details.
 @date 2012-04-05
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

/* PROPULSION_API UNIT TESTS */

/* 
   Id/Title: XK1/test increases propulsion speed
   Purpose: test if user increase propulsion fan over the
            maximum value of fan
   Prerequisites: initialize propulsion fan
   Expected results: propulsion fan speed should keep the 
                     highest level without any errors
   Pass/Fail criteria: when check is run response is 100%: Checks: 1,
                       Failures: 0, Errors: 0
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

/* 
   Id/Title: XK2/test increase propulsion speed
   Purpose: test if user keep decreasing propulsion fan
   Prerequisites: initialize propulsion fan
   Expected results: propulsion fan speed should stop without errors
   Pass/Fail criteria: when check is run response is 100%: Checks: 2,
                       Failures: 0, Errors: 0
*/
START_TEST(test_dec){
  increase_propulsion();
  fail_if(decrease_propulsion() != PERSPEED, "Expected 6");
  increase_propulsion();
  increase_propulsion();
  fail_if(decrease_propulsion() != PERSPEED * 2 , "Expected 12");
  decrease_propulsion();
  decrease_propulsion();
  fail_if(decrease_propulsion() != PERSPEED, "Expected 6.");
}END_TEST

/* 
   Id/Title: XK3/test get current propulsion fan speed level
   Purpose: test if user can get right propulsion fan speed level
   Prerequisites: initialize propulsion fan
   Expected results: return right current fan speed level
   Pass/Fail criteria: when check is run response is 100%: Checks: 3,
                       Failures: 0, Errors: 0
*/
START_TEST(test_fanlevel){
  increase_propulsion();
  fail_if(get_propulsion_level() != 1 ,"Expected 1");
  increase_propulsion();
  increase_propulsion();
  fail_if(get_propulsion_level() != 3 ,"Expected 1");
  decrease_propulsion();
  fail_if(get_propulsion_level() != 2 ,"Expected 2");
}END_TEST

/* 
   Id/Title: XK4/test stop propulsion fan speed
   Purpose: test if the propulsion fan is stoped normally
   Prerequisites: initialize propulsion fan
   Expected results: propulsion fan stop
   Pass/Fail criteria: when check is run response is 100%: Checks: 4,
                       Failures: 0, Errors: 0
*/
START_TEST(test_stop){
  increase_propulsion();
  fail_if(stop_propulsion_fan() != 0, "Expected 0");
  increase_propulsion();
  increase_propulsion();
  fail_if(stop_propulsion_fan() != 0, "Expected 0");
}END_TEST

/* 
   Id/Title: XK5/test set propulsion fan speed by manual
   Purpose: user wants to set propulsion fan by himself
   Prerequisites: initialize propulsion fan
   Expected results: propulsion fan speed should change to
                     the speed that the user wants
   Pass/Fail criteria: when check is run response is 100%: Checks: 5,
                       Failures: 0, Errors: 0
*/
START_TEST(test_set_speed){
  fail_if(set_propulsion_fan(30) != 30,"Expected 30");
  fail_if(set_propulsion_fan(50) != 50,"Expected 50");
  fail_if(set_propulsion_fan(-40) != -1,"Expected -40");
  fail_if(set_propulsion_fan(500) != -1,"Expected 500");
}END_TEST


/* 
   Id/Title: XK6/test initialize propulsion fan
   Purpose: propulsion fan should be init before starting propulsion fan
   Prerequisites: NULL
   Expected results: propulsion fan should be initialized and return 0
   Pass/Fail criteria: when check is run response is 100%: Checks: 6,
                       Failures: 0, Errors: 0
*/
START_TEST(test_init_propulsion){
  fail_if(start_propulsion_fan() != 0, "Expected 0 to init propulsion");
}END_TEST

 /* END OF PROPULSION API UNIT TESTS */



/* PROPULSION UNIT TESTS */

 /* id: Y1
    purpose: tests init() function of searduino and setting PIN as output and
    the initialising/preparation state of the propulsion
    prerequisites: none
    expected results: 0 will be returned
 */
START_TEST(test_init) {
  fail_unless((initialise_propulsion() == 0),NULL);
  fail_unless((manage_motor() == 1),NULL);
}END_TEST

 /* id: Y2
    purpose: tests the stopped state of the propulsion
    prerequisites: 1. the searduino init() function is called
                   2. the propulsion is in another state
    expected results: 0 will be returned
 */
START_TEST(test_stop_motor) {
  initialise_propulsion(); 
  stop_pro_fan();
  fail_unless((manage_motor() == 1),NULL);
}END_TEST

 /* id: Y3
    purpose: tests the boundary speed level of the propulsion
    prerequisites: 1. the searduino init() function is called
                   2. the propulsion is aleardy initialized
 		   3. a speed level of 1 is declared
    expected results:1. 2 will be returned from the manage_motor() function
                        showing the propulsion is now in rotating state
 	 	     2. 1 is returned from get_speed_level() showing the speed
		        is now at level 1(Minimum boundary)
 */

START_TEST(test_minimum_speed) {
  int level = 1;
  initialise_propulsion();
  change_pro_speed(level);
  fail_unless((manage_motor() == 2),NULL);
  fail_unless((get_speed_level() == 1),NULL);  
}END_TEST

 /* id: Y4
    purpose: tests the boundary speed level of the propulsion
    prerequisites: 1. the searduino init() function is called
                   2. the propulsion is aleardy initialized
	 	   3. a speed level of MAX_SPEED_LEVEL is declared
    expected results:1. 2 will be returned from the manage_motor() function
                        showing the propulsion is now in rotating state
		     2. MAX_SPEED_LEVEL is returned from get_speed_level()
		        showing the speed is now at level MAX_SPEED_LEVEL
		        (Maximum boundary)
 */

START_TEST(test_maximum_speed) {
  int level = MAX_SPEED_LEVEL;
  initialise_propulsion();
  change_pro_speed(level);
  fail_unless((manage_motor() == 2),NULL);
  fail_unless((get_speed_level() == MAX_SPEED_LEVEL),NULL);  
}END_TEST

/* END OF PROPULSION UNIT TESTS*/

/* BRAKE PROPULSION UNIT TESTS */

/* 
   Id/Title: XA1/test brake hovercraft
   Purpose: test if the hovercraft would be stopped immediately once 
            stop command is received
   Prerequisites: initialize realy
   Expected results: propulsion motor reverse retation, return 0
   Pass/Fail criteria: when check is run response is 100%: Checks: 1,
                       Failures: 0, Errors: 0
*/
START_TEST(test_brake_hovercraft){
  initialise_propulsion();
  initialize_relay();
  fail_unless(reverse_prop_motor() == 0);
}END_TEST


/* 
   Id/Title: XA2/test initialize relay
   Purpose: test if the realy is initialized before starting hovercraft
   Prerequisites: NULL
   Expected results: propulsion motor reverse retation, return 0
   Pass/Fail criteria: when check is run response is 100%: Checks: 1,
                       Failures: 0, Errors: 0
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

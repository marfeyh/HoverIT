/*! 
 *  \file    pressure_test.c
 *  \brief   Test cases for pressure.c
 *  \author  Rob Bruinsma
 *  \author  Anna Orazova
 *  \version 1.0
 *  \date    2012/04/26
 */

/*!
 * Includes Check library
 */
#include <check.h>
/*!
 * Includes standard library
 */
#include <stdlib.h>
/*!
 * Includes Searduino library
 */
#include <searduino.h>
/*!
 * Includes Arduino library
 */
#include <Arduino.h>
/*!
 * Includes Searduino simulation
 */
#include <seasim.h>
/*!
 * Includes header file for pressure.c
 */
#include "pressure.h"

/*!
 * /attention Pin numbers should be changed! 
 * /brief     Test case for checking positive values
 */
START_TEST (test_positive_values) {
  unsigned int in = 1023; /*!< Value for inside pin */
  unsigned int out = 0;   /*!< Value for outside pin */

  seasim_set_input(0, in, INPUT);    /*!< Sets value to the pin */

  for(out = 0; out < 1023; out++) {

    seasim_set_input(1, out, INPUT); /*!< Sets value to the pin */

    /*!
     * Test case will pass if return from get_pressure() is bigger then 0.
     */
    
    fail_unless(get_pressure() > 0);
  }
}END_TEST

/*!
 * /attention Pin numbers should be changed! 
 * /brief     Test case for checking negative values
 */
START_TEST (test_negative_values) {
  int in = 0;   /*!< Value for inside pin */
  int out = 0;  /*!< Value for outside pin */

  seasim_set_generic_input(0, in, INPUT);   /*!< Sets value to the pin */

  for(out = 0; out <= 1023; out++) {

    seasim_set_generic_input(1, out, INPUT); /*!< Sets value to the pin */

    /*!
     * Test case will pass if return from get_pressure() is equal to 0.
     */
    fail_unless(get_pressure() == 0);
  }
}END_TEST

/*!
 * /attention Pin numbers should be changed! 
 * /brief     Test case for checking all possible pairs of values
 */
START_TEST (test_all_values) {
  int in = 0;   /*!< Value for inside pin */
  int out = 0;  /*!< Value for outside pin */

  for (in = 0; in <= 1023;in++) {

    seasim_set_generic_input(0, in, INPUT);    /*!< Sets value to the pin */

    for(out = 0; out <= 1023;out++) {

      seasim_set_generic_input(1, out, INPUT); /*!< Sets value to the pin */
      
      /*!
       * Test case will pass if return from get_pressure() is more or equal 0.
       */
      fail_unless(get_pressure >= 0);
    }
  }
}END_TEST
      
/*!
 * Standard C Check functions.
 */
Suite* pressure_test(void) {
  Suite* s = suite_create("Pressure Test");
  TCase* tc1 = tcase_create("Positive values");
  TCase* tc2 = tcase_create("Negative values");
  TCase* tc3 = tcase_create("All values");
  tcase_add_test(tc1,test_positive_values);
  tcase_add_test(tc2,test_negative_values);
  tcase_add_test(tc3,test_all_values);
  suite_add_tcase(s, tc1);
  //suite_add_tcase(s, tc2);
  //suite_add_tcase(s, tc3);
  return s;
}



int main(void) {
  /*int number_failed;
  Suite* suite = pressure_test();
  SRunner* suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner,CK_NORMAL);
  number_failed = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
  */
unsigned int in = 1023; /*!< Value for inside pin */
  unsigned int out = 0;   /*!< Value for outside pin */

  seasim_set_input(0, in, INPUT);    /*!< Sets value to the pin */

  for(out = 0; out < 1023; out++) {

    seasim_set_input(1, out, INPUT); /*!< Sets value to the pin */

    /*!
     * Test case will pass if return from get_pressure() is bigger then 0.
     */
    
    fail_unless(get_pressure() > 0);
  }
}

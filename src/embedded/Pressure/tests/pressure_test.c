/*! 
 *  \file    pressure_test.c
 *  \brief   Test cases for pressure.c
 *  \author  Rob Bruinsma
 *  \author  Anna Orazova
 *  \version 1.1
 *  \date    2012/05/02
 *  \copyright	Copyright (C) 2012  Kappa@HoverIT
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
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
 * Includes header file for pin definitions
 */
#include "pins.h"

/*!
 * /attention Pin numbers should be changed in the header file pins.h 
 * /brief     Test case for checking positive values
 */
START_TEST (test_positive_values) {
  unsigned int in = 1023; /*!< Value for inside pin */
  unsigned int out = 0;   /*!< Value for outside pin */

  seasim_set_input(PRESSURE_PIN_0, in, INPUT);    /*!< Sets value to the pin */

  for(out = 0; out < 1023; out++) {

    seasim_set_input(PRESSURE_PIN_1, out, INPUT); /*!< Sets value to the pin */
    check_pressure();

    /*!
     * Test case will pass if return from get_pressure() is bigger then 0.
     */
    
    fail_unless(get_pressure_difference() > 0);
  }
}END_TEST

/*!
 * /attention Pin numbers should be changed! 
 * /brief     Test case for checking negative values
 */
START_TEST (test_negative_values) {
  int in = 0;   /*!< Value for inside pin */
  int out = 0;  /*!< Value for outside pin */

  seasim_set_generic_input(PRESSURE_PIN_0, in, INPUT);   /*!< Sets value to the pin */

  for(out = 0; out <= 1023; out++) {

    seasim_set_generic_input(PRESSURE_PIN_1, out, INPUT); /*!< Sets value to the pin */
    check_pressure();
    /*!
     * Test case will pass if return from get_pressure() is equal to 0.
     */
    fail_unless(get_pressure_difference() == 0);
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

    seasim_set_generic_input(PRESSURE_PIN_0, in, INPUT);    /*!< Sets value to the pin */

    for(out = 0; out <= 1023;out++) {

      seasim_set_generic_input(PRESSURE_PIN_1, out, INPUT); /*!< Sets value to the pin */
      check_pressure();
      /*!
       * Test case will pass if return from get_pressure() is more or equal 0.
       */
      fail_unless(get_pressure_difference() >= 0);
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
  suite_add_tcase(s, tc2);
  suite_add_tcase(s, tc3);
  return s;
}



int main(void) {
  int number_failed;
  Suite* suite = pressure_test();
  SRunner* suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner,CK_NORMAL);
  number_failed = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

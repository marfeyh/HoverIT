/*
 * Author: Paulius Vysniauskas, David Giorgidze.
 * Date: 2012-04-04.
 * Test case implementation.
 *
 */

#include <check.h>
#include "../RuddarControll.h"
#include "ruddar_check.h"

START_TEST (test_one)
{
  RuddarControll *r = new RuddarControll();
  init();
  fail_unless(r->setupRuddar()== 0, "FAILED: Could not setup rudder");
}
END_TEST

Suite * calc_suite(void) {
  Suite *s = suite_create("Ruddar");
  TCase *tc = tcase_create("First_case");
  tcase_add_test(tc,test_one);
  suite_add_tcase(s,tc);
  return s;
}

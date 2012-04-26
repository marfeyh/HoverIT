#include <check.h>
#include "coordinate_distance.h"
#include "destination.h"

START_TEST(test_get_destination) {

  double val = haversine_km( 50.066389, -5.714722, 58.643889, -3.07000);
  fail_unless( round_down(val) == 968.24, "FAILED: expected val: 968.24");

}END_TEST


START_TEST(test_deg2rad) {  

  fail_unless(round_down(DEG_TO_RAD(180)) == 3.14, "expected: 3.14");

}END_TEST


START_TEST(test_rad2deg) {  

  fail_unless((RAD_TO_DEG(0)) == 0, "expected: 0");

}END_TEST


START_TEST(test_bearing) {  

  double val = find_bearing(50.06639, -5.71472, 58.64389, -3.07);  
  fail_unless( round_down(val) == 9.11, "expected val: 9.11");

}END_TEST


Suite * new_suite(void) {

  Suite *s = suite_create("Navigation_suite");
  TCase *tc = tcase_create("Navigation_test_case");
  
  tcase_add_test(tc, test_get_destination);
  tcase_add_test(tc, test_bearing);
  tcase_add_test(tc, test_deg2rad);
  tcase_add_test(tc, test_rad2deg);

  suite_add_tcase(s,tc);
  return s;
}

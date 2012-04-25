#include <check.h>
#include "coordinate_distance.h"

START_TEST(first_test) {
double val = haversine_km( 50.066389, -5.714722, 58.643889, -3.07000);
printf("%f VALUE\n", val); 
//fail_unless(haversine_km(!50.066389, -5.714722, 58.643889, -3.07000) == 968.245254, "FAILED: Could not calculate distance"); 
fail_unless(val >= 968.245 && val <= 968.246, "FAILED: Could not calculate distance"); 
//fail_if(val >= 968.245 && val <= 968.246, "FAILED: Could not calculate distance");
}END_TEST

Suite * new_suite(void) {
  Suite *s = suite_create("Coordinate distance");
  TCase *tc = tcase_create("First Test Case");
  tcase_add_test(tc, first_test);
  suite_add_tcase(s,tc);
  return s;
}

#include <check.h>
#include <info.h>

START_TEST (test_function) {
	fail_unless(member_number()== 9);
} END_TEST

Suite* info_test (void) {
	Suite* s = suite_create("Info test");
	TCase* tc = tcase_create("Function returns test");
	tcase_add_test(tc, test_function);
	suite_add_tcase(s,tc);
	return s;
}

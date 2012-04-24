#include <check.h>
#include "../src/pc_log.h"

//FILE *p = NULL;
//char *file = "log.txt";

void setup(void){
	init_log_file();
}

void teardown (void) {
 	close_log_file();
}

START_TEST(test_log_file_writer) {

  
	fail_unless(log_file_writer("just test!") == 1,
	      	  "failed in writing ");

}END_TEST

/*START_TEST(test_division) {
  fail_unless(!strcmp(getBuffer(calc),""),
	      "Expected buffer content: ");

  pressDigit(calc,'9');
  fail_unless(!strcmp(getBuffer(calc),"9"),
	      "Expected buffer content: 9");

}END_TEST
*/


Suite * pclog_suite(void) {
  Suite *s = suite_create("pc_log");
  
  TCase *tc = tcase_create("Core");
  tcase_add_checked_fixture(tc,setup,teardown);
  tcase_add_test(tc,test_log_file_writer);
  //tcase_add_test(tc,test_division);
  suite_add_tcase(s,tc);
  return s;
}

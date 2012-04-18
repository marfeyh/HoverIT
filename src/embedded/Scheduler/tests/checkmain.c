/**
   Author: Gokul Sai Evuri
   Test Suite and Main for check.
   Tests the 'test cases' provided.
**/


#include <stdlib.h>
#include <check.h>
#include "fangzhou_test.c"
#include "mozhan_tests.c"
#include "pop_test.c"
#include "testPop.c"
#include "YuZhao_test.c"
#include "priority_test_johan.c"

/* #include "../../job.h" */
/* #include "../../jobpriority.h" */
/* #include "../../jobtype.h" */
/* #include "../../list.h" */

void addJob(struct Job job, struct List * list);
struct Job pop(struct List * list);
void printList(struct List * list);


Suite * test_suite(void){
	Suite *s=suite_create("Suite");
	TCase *tc=tcase_create("Case1");
	tcase_add_test(tc, fangzhou_test);
	tcase_add_test(tc, emptyList_test);
	tcase_add_test(tc, pop_test);
	tcase_add_test(tc, jobs_test);	
	//	tcase_add_test(tc, jobs_test1);
	tcase_add_test(tc, new_test);
	suite_add_tcase(s,tc);
	return s;
}


main(void) {
  int number_failed;
  Suite *s = test_suite();
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

/**
   Author: Gokul Sai Evuri
   Test Suite and Main for check.
   Tests the 'test cases' provided.
**/


#include <stdlib.h>
#include <check.h>
#include "../Theta-API.h"

#include "testTaskOrderForTwoTasks.c"
#include "testEmptyList.c"
#include "testPriorityBasedSorting.c"
#include "testPushAndPop.c"
#include "testSorting.c"
#include "testTakingOutLastJob.c"
#include "testOrderedList.c"

void addJob(struct Job job, struct List * list);
struct Job pop(struct List * list);
void printList(struct List * list);


Suite * test_suite(void){
	Suite *s=suite_create("Suite");
	TCase *tc=tcase_create("Scheduler test case");
	tcase_add_test(tc, testTaskOrderForTwoTasks);
	tcase_add_test(tc, testPriorityBasedSorting);
	tcase_add_test(tc, testSorting);
	tcase_add_test(tc, testPushAndPop);	
	tcase_add_test(tc, testEmptyList);
	tcase_add_test(tc, testTakingOutLastJob);
	tcase_add_test(tc, testOrderedList);
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

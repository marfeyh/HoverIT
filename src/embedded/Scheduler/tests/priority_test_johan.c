/**
   Author: Johan Wikström Schützer
   Test case for priority bases algorithm.
   Tests if the jobs are sorted by priority.
**/

#include <check.h>
#include <stdlib.h>
#include "../../job.h"
#include "../../jobpriority.h"
#include "../../jobtype.h"
#include "../../list.h"
//#include "../../src/loc_struct.h"
//#include "../../src/job_queue.h"

/*
 * Change these values for different test cases.
 */
#define nTests 20
#define givenPrios {LOW, HIGH, LOW, HIGH, RIGHT_NOW, MEDIUM, RIGHT_NOW, HIGH, LOW, RIGHT_NOW, RIGHT_NOW, MEDIUM, MEDIUM, HIGH, MEDIUM, LOW, RIGHT_NOW, HIGH, HIGH, LOW}

/*
 * Prototype of the funtion to the tested.
 */
void addJob(struct Job, struct List *);

/*
 * Creates a new Job by prio and type and returns the
 * pointer value.
 */
struct Job newJob(enum PRIORITY prio, enum JOB_TYPE type) {
  struct Job *job = (struct Job *) malloc(sizeof(struct Job));
  job->prio = prio;
  job->type = type;
  return *job;
}

/* 
 * A copy of the putJobInQueue function in main.c (for prio algorithm).
 * Modified so it puts the job in the list created by this test, but
 * it works exactly the same as the original function
 */
void putJobInQueueTest(struct Job job, struct List *list) {
  addJob(job, list);
}

/* Test case */
START_TEST(new_test) {
  
  /* Setup list and prios list for the test */
  int i;
  struct List *taskList =  (struct List *) malloc(sizeof(struct List));
  enum PRIORITY prios[nTests] = givenPrios;

  /* Create new jobs by prios and put the in the list */
  for (i = 0; i < nTests; i++) { 
    putJobInQueueTest(newJob(prios[i], DEMO), taskList);
  }

  /* Setup variables for the checking loop */  
  int bool = 1;
  struct Node *currentNode = taskList->head;
  struct Node *previousNode = taskList->head;
  enum PRIORITY currentPrio;
  enum PRIORITY previousPrio;

  /* 
   * Bool is set to 1, and then the loop checks the current
   * job and the previous job, compares their prios and checks
   * if they are in the correct order. If any case evaluates to
   * "false", bool will be set to 0 and won't be changed back.
   */
  for (i = 0; i < nTests; i++) {
    currentPrio = currentNode->value.prio;
    previousPrio = previousNode->value.prio;
    if (!(currentPrio <= previousPrio)) {
      bool = 0;
    }
    previousNode = currentNode;
    currentNode = currentNode->next;
  }
  
  /* Passing criteria and cleanup */
  fail_unless(bool == 1);
  free(taskList);

}END_TEST


/* /\* Test suite *\/ */
/* Suite * new_suite(void) { */
/*   Suite *s = suite_create("New Suite"); */
/*   TCase *tc = tcase_create("New Test Case"); */
/*   tcase_add_test(tc, new_test); */
/*   suite_add_tcase(s,tc); */
/*   return s; */
/*  } */

/* /\* Main function for this test *\/ */
/* int main(void) { */
/*   int number_failed; */
/*   Suite *s = new_suite(); */
/*   SRunner *sr = srunner_create(s); */
/*   srunner_run_all(sr,CK_NORMAL); */
/*   number_failed = srunner_ntests_failed(sr); */
/*   srunner_free(sr); */
/*   return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE; */
/* }  */


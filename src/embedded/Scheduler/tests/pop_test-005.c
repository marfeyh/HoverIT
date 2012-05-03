/**
 * \file 	      pop_test-005.c
 * \date 		25-03-2012
 * \version 	0.1 
 * \author 		Sebastian Hansson          
 * \attention 	Sections added/modified are as follow:
 * 				- The test cases, test suites and the main funtion were added. 
 * 
 * \date 		02-04-2012	   
 * \version		0.2 
 * \attention 	Sections added/modified are as follow:
 *              - Unneeded includes were removed and Gokul's comments were tagged with his name.  
 *
 * \date 		20-04-2012	   
 * \version		0.3 
 * \attention 	Sections added/modified are as follow:
 *              - Comments were revised and modified considering the provided coding standards.
 */



#include <check.h>
#include <stdlib.h>
#include "../../job.h"
#include "../../jobpriority.h"
#include "../../jobtype.h"
#include "../../list.h"
//#include "../../src/loc_struct.h"
//#include "../../src/job_queue.h"

/**
 * Purpose: The jobs should be added according to their priorities not by the order they where added.
 * Preparation: 
 *   some sample jobs are prepared and added to the tasklist.
 * Expected outcome: The list should contain the ordered jobs.
 */

void addJob(struct Job, struct List*);
struct Job  pop(struct List*);


START_TEST(pop_test) {

  /*Jobs are prepared.*/
  struct Job job1;
  struct Job job2;
  struct Job job3;
  struct Job job4;

    job1.prio = LOW;
    job2.prio = HIGH;
    job3.prio = MEDIUM;
    job4.prio = RIGHT_NOW;
    struct List * taskList = (struct List *) calloc(1, sizeof(struct List) );
    if (taskList == NULL) {
      exit(-1);
    }
    
    /*Jobs are added together with tasklist.*/
    addJob(job1, taskList);
    addJob(job2, taskList);
    addJob(job3, taskList);
    addJob(job4, taskList);

    struct Job tempJob = pop(taskList);

    /*Memory is freed and fail criteria*/
    free(taskList);
    fail_if(tempJob.prio != 40);
  
}END_TEST

 /*Commented by Gokul*/
/* Suite * new_suite(void) { */
/*   Suite *p = suite_create("New Suite"); */
/*   TCase *tc_p = tcase_create("New Test pop Case"); */
/*   tcase_add_test(tc_p, pop_test); */
/*   suite_add_tcase(p,tc_p); */
/*   return p; */
/* } */

/* int main(void) { */
/*   int number_failed; */
/*   Suite *p = new_suite(); */
/*   SRunner *sr_p = srunner_create(p); */
/*   srunner_run_all(sr_p,CK_NORMAL); */
/*   number_failed = srunner_ntests_failed(sr_p); */
/*   srunner_free(sr_p); */
/*   return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE; */
/* }  */


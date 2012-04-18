/**
 * \file 		testcases-003.1-003.2.c
 * \date 		25-03-2012
 * \version 	0.1 
 * \author 		Fangzhou Cao          
 * \attention 	Sections added/modified are as follow:
 * 				- The test cases, test suites and the main funtion were added. 
 * 
 * \date 		02-04-2012	   
 * \version		0.2 
 * \attention 	Sections added/modified are as follow:
 *              - Unneeded includes were removed and Gokul's comments were tagged with his name.  
 *
 * \date 		13-04-2012	   
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


/**
 *Purpose: to test the addJob function and printList functio.
 *Preparation: create two jobs and assign one job with High priority 
               and the other one with low priority, both types are set to DEMO.
 *Action: call addJob function to add two jobs into the list.
          call printList function.
 *Expected outcome: Job with High priority should be put in the first place 
                   which comes with the low one.
                   the sorted list should be printed out.
 */


static struct List *taskList;
START_TEST (fangzhou_test){


		taskList = (struct List *)  calloc( 1, sizeof(struct List) );
		taskList->size = 0;
            
                /* set the jobs and add jobs in the tasklist */
		struct Job job1;
		struct Job job2;
            
		job1.prio= HIGH;
		job1.type= DEMO;
		addJob(job1,taskList);

		job2.prio=LOW;
		job2.type=DEMO;
		addJob(job2,taskList);
                /* print the tasklist*/
		 printList(taskList);

		fail_if(taskList->head->value.prio < taskList->head->next->value.prio,"Wrong priorities");


	free(taskList);


}
END_TEST  /* test case emptyList */




/* Suite * test_suite(void){ */
/* 	Suite *s=suite_create("Suite"); */
/* 	TCase *tc=tcase_create("Case1"); */
/* 	tcase_add_test(tc, fangzhou_test); */
/* 	suite_add_tcase(s, tc); */

/* 	return s; */
/* } */

/* int main(void){ */

/* 	int number_failed; */
/* 	Suite *s=test_suite(); */
/* 	SRunner *sr= srunner_create(s); */
/* 	srunner_run_all(sr,CK_NORMAL); */
/* 	number_failed=srunner_ntests_failed(sr); */
/* 	srunner_free(sr); */
/* 	return(number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE; */


/* } */



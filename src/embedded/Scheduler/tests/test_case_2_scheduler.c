/**
 * \file 		test_case_2_scheduler.c
 * \date 		24-04-2012
 * \version 	0.1 
 * \author 		Mozhan Soltani          
 * \attention 	Sections added/modified are as follow:
 * 				- The "emptyList" test case, the test suite "emptyList_suite"  and the main funtion were provided.  
 */
 
#include <check.h>
#include <stdlib.h>
#include <stdio.h>
/**
 * Purpose: To check if the Node list is emptied when the last job is poped out. 
 * Preparation: 
 *   A sample job is set and added to a task list.
 *	 The added job is poped out from the list.
 * Expected outcome: The list should be empty and its size should be zero.
 */
START_TEST(emptyList_test) {

/* job is set */
  struct Job job;
  job.prio = PRIO_LOW;
  job.type = DEMO;
  
  // A list to which the created job will be added and then popped out.
  struct List * list = (struct List *) calloc(1,sizeof(struct Node) );
  // check against the NULL value that might be returned by calloc
  if (list == NULL){
    printf("Dynamic memory allocation failed\n");
    exit(-1);
  }
/* job is added and popped out */  
  addJob(job,list);
  pop(list);
  
  int node_num = list->size;
  fail_if( node_num != 0 || list->head != NULL );
  free(list);
}END_TEST /* test case emptyList */


 /*Commneted to include these test cases in test suite- by Gokul*/
/**
 * Returns a suite pointer containing the emptyList test case.
 */
/* Suite * emptyList_suite(void) { 
   Suite *suite = suite_create("empty_list suite"); 
   TCase *test_case = tcase_create("Test case of an emptied list"); 
   tcase_add_test(test_case, emptyList_test); 
   // The emptyList test case is added to the created suite.
   suite_add_tcase(suite,test_case); 
   return suite; 
} */ 

/*Commneted to include these test cases in test suite- by Gokul*/
/**
 * The main function to run the test case through creating a SRunner.
 */
/* int main(void) { 
   // will be used to get the number of the failed test cases.
   int failed_num; 
   Suite *suite = emptyList_suite();
   //A suite runner object of SRunner is created using the suite returned from emptyList_suite.   
   SRunner *suite_runner = srunner_create(suite); 
   //The suite is run and a summary and list of the occurred failures is printed out.
   srunner_run_all(suite_runner,CK_NORMAL); 
   failed_num = srunner_ntests_failed(suite_runner); 
   srunner_free(suite_runner);  
   return (failed_num == 0 ) ? EXIT_SUCCESS : EXIT_FAILURE; 
} */ /* end of main */ 



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
START_TEST(testEmptyList) {

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





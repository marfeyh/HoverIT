/**
 * \file 		test_case_9_scheduler.c
 * \date 		24-04-2012
 * \version 	0.1 
 * \author 		Mozhan Soltani          
 * \attention 	Sections added/modified are as follow:
 * 				- The "orderedList" test case, the test suite "orderedList_suite"  and the main funtion were provided.  
 */
#include <check.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * Purpose: To check if the Node list is in order when 4 jobs with different priorities are added. 
 * Preparation: 
 *   Four sample jobs are set and added to a task list.
 * Expected outcome: The list should contain the jobs with the order from Right_NOW to LOW.
 */
START_TEST(testOrderedList) {

/* Jobs are set */
  struct Job job1;
  job1.prio = PRIO_LOW;
  job1.type = DEMO;
  
  struct Job job2;
  job2.prio = PRIO_HIGH;
  job2.type = DEMO;
  
  struct Job job3;
  job3.prio = PRIO_MEDIUM;
  job3.type = DEMO;
  
  struct Job job4;
  job4.prio = PRIO_RIGHT_NOW;
  job4.type = DEMO;
  
  // A list to hold the created jobs
  struct List * list = (struct List *) calloc(1,sizeof(struct Node) );
  // check against the NULL value that might be returned by calloc
  if (list == NULL){
    printf("Dynamic memory allocation failed\n");
    exit(-1);
  }
  
 /* Jobs are added to the list */ 
  addJob(job1,list);
  addJob(job2,list);
  addJob(job3,list);
  addJob(job4,list);
  int node_num = list->size;
  struct Node * temp_node = list->head;
  int flag = 1; 
  if(node_num != 4){
    flag = 0;
  }
  if(temp_node->value.prio != 40){
    flag = 0;
  }
  if(temp_node->next->value.prio != 30){
    flag = 0;
  }
  if(temp_node->next->next->value.prio != 20){
    flag = 0;
  }
  if(temp_node->next->next->next->value.prio != 10){
    flag = 0;
  }
  fail_if( flag == 0);
  free(list);
}END_TEST /* test case orderedList */
 


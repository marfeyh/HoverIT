/**
  Author: Mozhan Soltani 
  Date: 25-03-2012     Version:0.1
**/
#include <check.h>
#include <stdlib.h>
#include "job.h"
#include "jobpriority.h"
#include "jobtype.h"
#include "list.h"

void addJob(struct Job, struct List * list);
struct Job pop(struct List * list);
/*
 * Purpose: To check if the Node list is emptied when the last job is poped out. 
 * Preparation: 
 *   A sample job is set and added to a task list.
 *	 The added job is poped out from the list.
 * Expected outcome: The list should be empty and its size should be zero.
 */
START_TEST(emptyList_test) {

/* Job is set*/
  struct Job job;
  job.prio = LOW;
  job.type = DEMO;
  
  struct List * list = (struct List *) calloc(1,sizeof(struct Node) );
  
  if (list == NULL){
    exit(-1);
  }
/* Job is added and poped out */  
  addJob(job,list);
  pop(list);
  
  int node_num = list->size;
  fail_if( node_num != 0 || list->head != NULL );
  free(list);
}END_TEST


 /*Commneted to include thses test cases in test suite -Gokul*/

/* SUITE * SUITE1(VOID) { */
/*   SUITE *S = SUITE_CREATE("SUITE1"); */
/*   TCASE *TC = TCASE_CREATE("TEST CASE OF AN EMPTIED LIST"); */
/*   TCASE_ADD_TEST(TC, EMPTYLIST_TEST); */
/*   SUITE_ADD_TCASE(S,TC); */
/*   RETURN S; */
/* } */

/*
 * Purpose: To check if the Node list is in order when 4 jobs with different priorities are added. 
 * Preparation: 
 *   Four sample jobs are set and added to a task list.
 * Expected outcome: The list should contain the jobs with the order from Right_NOW to LOW.
 */

START_TEST(orderedList_test) {

/* Jobs are set */
  struct Job job1;
  job1.prio = LOW;
  job1.type = DEMO;
  
  struct Job job2;
  job2.prio = HIGH;
  job2.type = DEMO;
  
  struct Job job3;
  job3.prio = MEDIUM;
  job3.type = DEMO;
  
  struct Job job4;
  job4.prio = RIGHT_NOW;
  job4.type = DEMO;
  
  
  struct List * list = (struct List *) calloc(1,sizeof(struct Node) );
  if (list == NULL){
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
}END_TEST

/*Commneted to include thses test cases in test suite -Gokul*/
/* Suite * suite2(void) { */
/*   Suite *sp2 = suite_create("Suite2"); */
/*   TCase *tcp2 = tcase_create("Test Case of an ordered list"); */
/*   tcase_add_test(tcp2, emptyList_test); */
/*   suite_add_tcase(sp2,tcp2); */
/*   return sp2; */
/* } */

/*Commneted to include thses test cases in test suite -Gokul*/

/* int main(void) { */
/*   int failed_num , failed_num2; */
/*   Suite *sp = suite1(); */
/*   SRunner *srp = srunner_create(sp); */
/*   srunner_run_all(srp,CK_NORMAL); */
  
/*   Suite *sp2 = suite2(); */
/*   SRunner *srp2 = srunner_create(sp2); */
/*   srunner_run_all(srp2,CK_NORMAL); */
  
/*   failed_num = srunner_ntests_failed(srp); */
/*   failed_num2 = srunner_ntests_failed(srp2); */
  
/*   srunner_free(srp); */
/*   srunner_free(srp2); */
/*   return (failed_num == 0 && failed_num2 == 0 ) ? EXIT_SUCCESS : EXIT_FAILURE; */
/* }  */
  

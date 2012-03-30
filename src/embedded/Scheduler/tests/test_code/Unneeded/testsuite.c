#include <check.h>
#include<stdlib.h>
#include "../../src/job.h"
#include "../../src/list.h"
#include "../../src/jobpriority.h"
#include "../../src/jobtype.h"

static struct List *taskList;


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
}
END_TEST


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

 /*Start Jermy test case*/

START_TEST(jobs_test) {
  
	struct Job job_1;
	struct Job job_2;
	struct Job job_3;
	struct Job job_4;
	struct Job job_5;
	
	job_1.prio = LOW;
	job_2.prio = MEDIUM;
	job_3.prio = HIGH;
	job_4.prio = RIGHT_NOW;
	job_5.prio = RIGHT_NOW;
	
	struct List * list1 = (struct List *)  calloc( 1, sizeof(struct List) );
	
	addJob(job_1,list1);
	addJob(job_2,list1);
	addJob(job_3,list1);
	addJob(job_4,list1);
	addJob(job_5,list1);
	
	struct Job job_temp1 = pop(list1);
	struct Job job_temp2 = pop(list1);
	struct Job job_temp3 = pop(list1);
	struct Job job_temp4 = pop(list1);
	struct Job job_temp5 = pop(list1);
	
	int number = 1;
	if(job_temp1.prio != 40){
		number = 0;
	}
	if(job_temp2.prio != 40){
		number = 0;
	}
	if(job_temp3.prio != 30){
		number = 0;
	}
	if(job_temp4.prio != 20){
		number = 0;	}
	if(job_temp5.prio != 10){
		number= 0;}
  fail_unless( number == 1);
 
}END_TEST
 /*end Jermy test case*/


START_TEST (fangzhou_test){


		taskList = (struct List *)  calloc( 1, sizeof(struct List) );
		taskList->size = 0;

		struct Job job1;
		struct Job job2;

		job1.prio= HIGH;
		job1.type= DEMO;
		addJob(job1,taskList);

		job2.prio=LOW;
		job2.type=DEMO;
		addJob(job2,taskList);

		 printList(taskList);

		fail_if(taskList->head->value.prio < taskList->head->next->value.prio,"Wrong priorities");


	free(taskList);


}
END_TEST











 Suite * test_suite(void){ 
 	Suite *s=suite_create("Suite");
 	TCase *tc1=tcase_create("Case1");
 	tcase_add_test(tc1, fangzhou_test);
	//tcase_add_test(tc1, jobs_test); 
	suite_add_tcase(s, tc1);
	TCase *tc2=tcase_create("Case2");
	tcase_add_test(tc2,jobs_test);
	suite_add_tcase(s, tc2);
	TCase *tc3=tcase_create("Case3");
	tcase_add_test(tc3,orderedList_test);
	suite_add_tcase(s, tc3);
	TCase *tc4=tcase_create("Case4");
	tcase_add_test(tc4,emptyList_test);
	suite_add_tcase(s, tc4);
	/* TCase *tc5=tcase_create("Case5"); */
	/* tcase_add_test(tc5, );                                            /// testcase fill up */
 	/* suite_add_tcase(s, tc5); */ 
 	return s; 
 } 

 int main(void){ 

 	int number_failed; 
 	Suite *s=test_suite(); 
 	SRunner *sr= srunner_create(s);
 	srunner_set_log (sr, "test.log");
 	srunner_run_all(sr,CK_NORMAL);
	number_failed=srunner_ntests_failed(sr);
 	srunner_free(sr); 
 	return(number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE; 
 } 

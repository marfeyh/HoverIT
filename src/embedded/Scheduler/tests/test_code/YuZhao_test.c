#include <check.h>
#include <stdlib.h>
#include "../../src/job_queue.h"
#include "../../src/loc_struct.h"

/* void addJob(struct Job job, struct List * list); */
/* struct Job pop(struct List * list); */

START_TEST(jobs_test1) {
  
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

/* Suite * new_suite(void) { */
/*   Suite *suite = suite_create("jobs_test Suite"); */
/*   TCase *tcase = tcase_create("jobs_test Test Case"); */
/*   tcase_add_test(tcase, jobs_test); */
/*   suite_add_tcase(suite,tcase); */
/*   return suite; */
/* } */

/* int main(void) { */
/*   int number_failed; */
/*   Suite *suite = new_suite(); */
/*   SRunner *suiter = srunner_create(suite); */
/*   srunner_run_all(suiter,CK_NORMAL); */
/*   number_failed = srunner_ntests_failed(suiter); */
/*   srunner_free(suiter); */
/*   return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE; */
/* }  */
  

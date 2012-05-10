#include <check.h>
#include <stdlib.h>
#include "../job.h"
#include "../jobpriority.h"
#include "../list.h"

/* void addJob(struct Job job, struct List * list); */
/* struct Job pop(struct List * list); */

START_TEST(testSorting) {
  
	struct Job job_1;
	struct Job job_2;
	struct Job job_3;
	struct Job job_4;
	struct Job job_5;
	
	job_1.prio = PRIO_LOW;
	job_2.prio = PRIO_MEDIUM;
	job_3.prio = PRIO_HIGH;
	job_4.prio = PRIO_RIGHT_NOW;
	job_5.prio = PRIO_RIGHT_NOW;
	
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



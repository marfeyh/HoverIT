/*
  @file testPushAndPop.c
  @author: Dmitry Igoshin	
  @brief: simple push-and-pop test case; put a value in the list and try taking it out
  @attention License: GPLv3
*/	

#include <check.h>
#include <stdlib.h>
#include "../job.h"
#include "../jobpriority.h"
#include "../jobtype.h"
#include "../list.h"

void addJob(struct Job job, struct List * list);
/*
* @var testing job
*/
struct Job pop(struct List * list);

/*
* @brief putting the value and taking it out
*/
START_TEST(testPushAndPop) {
        struct Job testJob;
        testJob.prio = PRIO_HIGH; 								//the task has high priority		
        struct List * list1 = (struct List *)  calloc( 1, sizeof(struct List) ); 		//allocating memory
        addJob(testJob,list1);  								//adding to the list
        struct Job result = pop(list1); 							//taking out       /*
/*
* expected test outcome: the job has high priority
*/ 
  fail_unless( result.prio == PRIO_HIGH);

}END_TEST




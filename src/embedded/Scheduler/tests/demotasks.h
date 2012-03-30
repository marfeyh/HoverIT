/**
Author: Dmitry Igoshin
Demo jobs
**/

#include "../src/loc_struct.h"
#include "../src/job_queue.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef __demotasks_h_
#define __demotasks_h_

void demotask1();
void demotask2();
void demotask3();
void demotask4();

void demotask1() {
	printf("Task 1 there.\n");
}

void demotask2() {
	printf("Task 2 there.\n");
}

void demotask3() {
	printf("Task 3 there.\n");
}

void demotask4() {
	char c;
	printf("Task 4: Shutting down.\n");

	printf("Press any key to exit\n");
	scanf("%c", &c);
	exit(0);
}

void initDemoData(struct List * list) {
	struct Job job1;
	struct Job job2;
	struct Job job3;
	struct Job job4;

	job4.prio = LOW;
	job4.type = DEMO;
	job4.task = &demotask4;
	addJob(job4, list);

	printList(list);
	job2.prio = RIGHT_NOW;
	job2.type = DEMO;
	job2.task = &demotask2;
	addJob(job2, list);
	printList(list);

	job1.prio = MEDIUM;
	job1.type = DEMO;
	job1.task = &demotask1;
	addJob(job1, list);
	printList(list);


	job3.prio = HIGH;
	job3.type = DEMO;
	job3.task = &demotask3;
	addJob(job3, list);
	printList(list);

}

#endif

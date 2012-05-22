/*!
  This file is part of Hoveritu.
  
  Hoveritu is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Hoveritu is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with Hoveritu.  If not, see <http://www.gnu.org/licenses/>.
*/
/**
@author: Dmitry Igoshin
@brief Demo jobs: used for demo purposes
**/
#pragma once
#include "list.h";
#include "job.h"
#include "jobtype.h";
#include "jobpriority.h"
void demotask1();
void demotask2();
void demotask3();
void demotask4();

/**
Dummy function
**/
void demotask1() {
	printf("Task 1 there.\n");
}

/**
Dummy function
**/
void demotask2() {
	printf("Task 2 there.\n");
}

/**
Dummy function
**/
void demotask3() {
	printf("Task 3 there.\n");
}

/**
Dummy function exiting the program
**/
void demotask4() {
	char c;
	printf("Task 4: Shutting down.\n");

	printf("Press any key to exit\n");
	scanf("%d", &c);
	exit(0);
}

/**
Adding all the demo jobs to the list
**/
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

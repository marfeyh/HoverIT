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
@brief Main control loop & entry point
@attention desktop program to demonstrate the scheduler. Not supposed to work on Arduino.
**/
#pragma once
#define DBG 1
#include "stdio.h";
#include "stdlib.h";
#include "demotasks.h";
#include "jobpriority.h";
#include "job.h";
#include "jobtype.h";
#include "list.h";

static struct List * taskList; // Job queue

//Add a job in the queue
void putJobInQueue(struct Job job) {
	addJob(job, taskList);
}

//ititializing
void setUp() {
	taskList = (struct List *)  calloc( 1, sizeof(struct List) );
	taskList->size = 0;
	if (DBG) {
		//demo tasks & debug output
		initDemoData(taskList);
		printf("Starting to execute...\n");	
	}
}

//main control loop
int main(void) {		
	struct Job currentJob;
	void (*t)();
	setUp();
	while(1) {
		if (taskList->size > 0) {
			currentJob = pop(taskList);
			t = currentJob.task;
			(*t)();	//execute the job 	
		}
	}	
	return 0;
}


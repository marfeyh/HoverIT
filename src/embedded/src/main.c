/**
Author: Dmitry Igoshin
Main control loop & entry point
**/
#pragma once
#define DBG 1
#include "stdio.h"
#include "stdlib.h"
#include "demotasks.h"
#include "jobpriority.h"
#include "job.h" //removed ; to make it work on linux - Kirill
#include "jobtype.h"
#include "list.h"

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
                        (*t)(); //execute the job
                }
        }
        return 0;
}


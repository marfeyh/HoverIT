/**
Author: Dmitry Igoshin
Main control loop & entry point
**/

#define DBG 1
#include <stdio.h>
#include <stdlib.h>

#include "demotasks.h"

#include "../src/loc_struct.h"
#include "../src/job_queue.h"

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


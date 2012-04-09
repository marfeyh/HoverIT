/**   
 Date: 03-04-2012     Version:0.1   Author: Mozhan Soltani
 Sections added/modified: The functions "init_list", "execute_jobs" and "control" were added.

 **/
//==================================================
#include <serial_interface.h>
//==================================================

#include <list.h>
#include <API_bluetooth_controler.h>
#include <jobpriority.h>
#include <jobtype.h>
#include <job.h>
#include <Theta-API.h>
static struct List *g_taskList;

/*
 Initializes the task list.
 - Borrowed from the first version of scheduler.
 */
void init_list() {
	g_taskList = (struct List *) calloc(1, sizeof(struct List));
	g_taskList->size = 0;
}

/*
 executes the jobs added to the task list.
 - Partly borrowed from the first version of scheduler.
 */
void execute_jobs() {

	while (g_taskList->size > 0) {
		struct Job currentJob = pop(g_taskList);

//    if(currentJob.job_num == 0){
//     void (*task)();
//     task = currentJob.task_p1;
//     (*task)(); //execute the job
//    }

//    else
		if (currentJob.job_num == 1) {
			int (*task)();
			task = currentJob.task_p2;
			(*task)(); //execute the job
		}

//	else if(currentJob.job_num == 2){
//     void (*task)();
//     task = currentJob.task_p3;
//     (*task)(); //execute the job
//    }
//
//	else if(currentJob.job_num == 3){
//     int (*task)();
//     task = currentJob.task_p4;
//     (*task)(); //execute the job
//    }

	}

}

/* 


 */
void control() {
	init_list(); // A task list is initialized.
	while (1) {
		check_serial_input();
		// Get gps data
		// Get hovercraft speed
		// Get Battery level
		// Get Sonar data
		// Get Pressure

		// Handle the received data by preparing relevant jobs and putting them in the queue.
		 execute_jobs();

	}

}

//Add a job in the queue
void putJobInQueue(struct Job job) {
	debug_print_string("We are already in queue!!\n");
	addJob(job, g_taskList);
}

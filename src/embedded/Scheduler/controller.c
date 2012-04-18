/** 
 *  \file			controller.c	
 *	\details		This module was added to the scheduler modules in order to
 *                  integrate this work package with the other ones.
 *					It provides a control function which coordinates other tasks included in the application
 *					through an infinite while loop.
 *	\date			03-04-2012 
 *	\version		0.1
 *	\author 		Mozhan Soltani
 *	\attention 		Sections added/modified are as follow: 
 *                  - The functions "init_list", "execute_jobs" and "control" were added.
 *  \n
 *	\date			09-04-2012  
 *	\version		0.2
 *	\author 		Amir Almasi
 *	\attention 		Sections added/modified are as follow: 
 *                  - The header files: "list.h", "API_bluetooth_controler.h", "jobpriority.h", "jobtype.h", "job.h" and"Theta-API.h" were added.
 *                  - The function putJobInQueue was placed in this file from its original file, "main.c". 
 * \n
 * \date			11-04-2012 
 * \version		    0.3
 * \author 		    Mozhan Soltani
 * \attention 		Sections added/modified are as follow: 
 *                  - The function "execute_jobs" was updates.
 */

#include <list.h>
//#include <API_bluetooth_controler.h>
#include <jobpriority.h>
#include <jobtype.h>
#include <job.h>
#include <Theta-API.h>
#include <stdlib.h>

static struct List *g_taskList;

/**
 * \brief	    Initializes the task list.
 * \attention	Borrowed from the first version of scheduler.
 */
void init_list() {
	g_taskList = (struct List *) calloc(1, sizeof(struct List));
	g_taskList->size = 0;
} /* init_list function */

/**
 * \brief 		executes the jobs added to the task list.
 * \attention	Partly borrowed from the first version of scheduler and
 *				would be modified for each integration session accordingly.
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
//			free(currentJob);
		} /* If job_num == 1 */

      else if (currentJob.job_num == 2){
         void (*task)(unsigned char);
         task = currentJob.task_p3;
         (*task)(currentJob.arg1); //execute the job
//		 free(currentJob);
      } /* If job_num == 2 */
	  
//	else if(currentJob.job_num == 3){
//     int (*task)();
//     task = currentJob.task_p4;
//     (*task)(); //execute the job
//    }

	}

} /* execute_jobs function */

/** 
 * \brief       Contains an infinite while loop in which tasks are coordinated and jobs are set
 *              and added to a task list and executed accordingly. 
 * \attention   The function control is to be modified and updated for each integration session.
 */
void control() {
	init_list(); // A task list is initialized.
	while (1) {
//		check_serial_input();
		// Get gps data
		// Get hovercraft speed
		// Get Battery level
		// Get Sonar data
		// Get Pressure

		// Handle the received data by preparing relevant jobs and putting them in the queue.
		 execute_jobs();

	}

} /* Control function */

/** 
 * \brief      Gets an instance of Job struct and adds it to the g_taskList.
 * \param      job  The job that is to be added to the g_taskList.
 * \attention  This function is replaced here from its original module,"main.c". 
 */
void putJobInQueue(struct Job job) {
	addJob(job, g_taskList);
} /* putJobInQueue function */

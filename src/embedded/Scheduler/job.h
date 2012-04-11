/**
 * \file 		  job.h
 *
 * \date		  23-03-2012
 * \version		  0.1
 * \author  	  Dmitry Igoshin
 *  
 * \date		  09-04-2012
 * \version       0.2
 * \author        Mozhan Soltani
 * \attention     Sections added/modified are as follow:
 *				  - Fields "job_num", "*task_p1", "*task_p2", "*task_p3", and "*task_p4" 
 *				    were added to the definition of struct Job in the first integration session.
 *
 * \date		  11-04-2012
 * \version       0.3
 * \author        Mozhan Soltani
 * \attention	  Sections added/modified are as follow:
 *				  - The field "*arg1" was added to the struct Job.
 *				  - Comments were modified considering the provided coding standards.
 */
#pragma once
#include <jobpriority.h>
#include <jobtype.h>
#ifndef __job_h_
#define __job_h_

struct Job {
    unsigned char job_num; /* indicates which task pointer is used */
	int *arg1;			   /* is passed to the task pointers that take integer arguments */
//	void (*task_p1)();
	int (*task_p2)();
	void (*task_p3)(int);
//	int (*task_p4)(int);
	enum PRIORITY prio;
	enum JOB_TYPE type;
};


#endif

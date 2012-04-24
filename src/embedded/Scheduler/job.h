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
 *				  - The field "arg1" was added to the struct Job.
 *				  - Comments were modified considering the provided coding standards.
 * @date  24-04-2012
 * @version 0.3 
 * @author Dmitry Igoshin
 * @attention added more comments
 */
#pragma once
#include <jobpriority.h>
#include <jobtype.h>
#if !defined job_h
#define job_h

/**
@struct Job
@brief Job to be executed
**/
struct Job {
        unsigned char job_num;           /* @var indicates which task pointer is used */
	unsigned char arg1;              /* @var is passed to the task pointers that take integer arguments */
	int (*task_p2)();                /* @var pointer to a void function */
	void (*task_p3)(unsigned char);  /* @var pointer to the fucntion taking char argument*/
	enum PRIORITY prio;              /* @var job priority */
	enum JOB_TYPE type;              /* @var type of job */     
};


#endif

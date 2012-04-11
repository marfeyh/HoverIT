/**
Author: Dmitry Igoshin
Job structure
**/
#pragma once
#include <jobpriority.h>
#include <jobtype.h>
#ifndef __job_h_
#define __job_h_

struct Job {
    unsigned char job_num; // indicates which job pointer is used. (Added by Mozhan)
//	void (*task_p1)();
	int (*task_p2)();
//	void (*task_p3)(int);
//	int (*task_p4)(int);
	enum PRIORITY prio;
	enum JOB_TYPE type;
};


#endif

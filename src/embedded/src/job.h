/**
Author: Dmitry Igoshin
Job structure
**/
#pragma once
#include "jobpriority.h"
#include "jobtype.h"
#ifndef __job_h_
#define __job_h_

struct Job {
	void (*task)();
	enum PRIORITY prio;
	enum JOB_TYPE type;
};


#endif

/**
Author: Dmitry Igoshin
Job structure
**/
#pragma once
#ifndef __job_h_
#define __job_h_

enum JOB_TYPE {
	MOVEMENT,
	SENSORS,
	DEMO
};

/*enum PRIORITY
{
	RIGHT_NOW,
	LOW,
	MEDIUM,
	HIGH
	};*/

enum PRIORITY {
  RIGHT_NOW,
};

struct Job {
  unsigned char job_num; // indicates which job pointer is used. (Added by Mozhan)
  void (*task_p1)();
  int (*task_p2)();
  void (*task_p3)(int);
  int (*task_p4)(int);
  enum PRIORITY prio;
  enum JOB_TYPE type;
};


#endif

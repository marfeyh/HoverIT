
#pragma once

#ifndef __jobpriority_h_
#define __jobpriority_h_

enum PRIORITY
{
	RIGHT_NOW = 40,
	LOW = 10,
	MEDIUM = 20,
	HIGH= 30
};

#endif

#ifndef __jobtype_h_
#define __jobtype_h_
enum JOB_TYPE {
	MOVEMENT,
	SENSORS,
	DEMO
};

#endif


#ifndef __job_h_
#define __job_h_

struct Job {
	void (*task)();
	enum PRIORITY prio;
	enum JOB_TYPE type;
};


#endif


struct Node {
	struct Job value;
	struct Node *next;
	struct Node *prev;
};

struct List {
	struct Node * head;
	struct Node * tail;
	int size;
};

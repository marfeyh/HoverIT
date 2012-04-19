#ifndef EXTERNAL_H
#define EXTERNAL_H
extern void check_serial_input(void);
extern enum PRIORITY {PRIO_LOW=10,PRIO_MEDIUM=20,PRIO_HIGH=30,PRIO_RIGHT_NOW=40};

extern enum JOB_TYPE {
	MOVEMENT,
	SENSORS,
	DEMO
};
extern struct Job {
    unsigned char job_num; /* indicates which task pointer is used */
	unsigned char arg1;			   /* is passed to the task pointers that take integer arguments */
//	void (*task_p1)();
	int (*task_p2)();
	void (*task_p3)(unsigned char);
//	int (*task_p4)(int);
	enum PRIORITY prio;
	enum JOB_TYPE type;
};

#endif

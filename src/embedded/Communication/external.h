#ifndef EXTERNAL_H
#define EXTERNAL_H
extern void check_serial_input(void);
extern enum PRIORITY {
	PRIO_LOW = 10, PRIO_MEDIUM = 20, PRIO_HIGH = 30, PRIO_RIGHT_NOW = 40
};

extern enum JOB_TYPE {
	MOVEMENT, SENSORS, DEMO
};
extern struct Job {
	unsigned char job_num; /* indicates which task pointer is used */
	unsigned char arg1; /* is passed to the task pointers that take integer arguments */
//	void (*task_p1)();
	int (*task_p2)();
	void (*task_p3)(unsigned char);
//	int (*task_p4)(int);
	enum PRIORITY prio;
	enum JOB_TYPE type;
};

// Propulsion package propulsion_api.h
extern int start_propulsion_fan();
extern int increase_propulsion();
extern int speedLevel;
extern int decrease_propulsion();
extern int get_propulsion_level();
//extern int newprospeed;
extern int stop_propulsion_fan();

// Hover package hover_api.h
extern int initialize(); /* initialize hover fan */
extern int start_hover(); /* start the hovering fan */
extern int stop_hover(); /* stop the fan */
extern int hover_min(); /* minimize the speed */
extern int hover_max(); /* maximize the speed */
extern int decrease_hover_auto(); /* decrease the speed */
extern int increase_hover_auto(); /* increase the speed */
extern int autocontrol(); /* let the fan speed be cotrolled by pressure  sensor automatically */

// Rudder Direction
extern void control_rudder(int);

extern int set_propulsion_fan(int);

#endif

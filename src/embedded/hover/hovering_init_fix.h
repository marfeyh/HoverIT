

/* Variables */
boolean loop_need;
boolean start_check;


/* Struct to be used in hover_loop */
typedef struct {
	int (*func1)(int);
	void (*func2)(long unsigned int);
	int level;
	int delay_time;
} FUNCS;
/* Function prototype */
int initialize(int using_pin);
int check_and_fix_level(int using_pin, int throttle_stick_level);
boolean check_loop_need(void);


#define MAXSPEED 122
#define PERSPEED 40
int initialize();	   /* initialize hover fan */		
int start_hover();          /* start the hovering fan */ 
int stop_hover();           /* stop the fan */
int hover_min();   /* minimize the speed */
int hover_max();   /* maximize the speed */
int decrease_hover();       /* decrease the speed */
int increase_hover();       /* increase the speed */
int autocontrol();          /* let the fan speed be cotrolled by pressure  sensor automatically */

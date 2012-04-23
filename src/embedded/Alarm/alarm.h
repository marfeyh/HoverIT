/*
2	
 * @ Module name:  alarm.h
3	
 * @ Description:  Header file alarm.c
4	
 * @ Author names :Neda Mohammadian
5	
 * @ Release      :17 April 2012
6	
 * @ Version      : 1
7	
 */
 
 #ifndef ALARM_H
#define ALARM_H
	#define EMPTY_BATTERY 5
	#define LOW_BATTERY 20
	#define LOW_BATTERY_DURATION 20
	
	void setup(void);
	void exec(void);
	int beep(int);
	int getBattery(void);
	void setup_battery_level(void);
	int loop_battery_level(void);
	
#endif
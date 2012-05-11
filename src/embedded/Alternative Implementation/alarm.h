/*
 * @ Module name:  alarm.h
 * @ Description:  Header file alarm.c
 * @ Author names :Neda Mohammadian
 * @ Release      :17 April 2012
 * @ Version      : 2
*/
 
 #ifndef ALARM_H
#define ALARM_H
	#define EMPTY_BATTERY 5
	#define LOW_BATTERY 20
	#define LOW_BATTERY_DURATION 20
	
	void init_alarm(void);
	void setup_alarm(uint8_t);
	int beep(int);
//	int getBattery(void);
	void setup_battery_level(void);
	int loop_battery_level(uint8_t);
	
#endif
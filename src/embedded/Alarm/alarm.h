#ifndef ALARM_H
#define ALARM_H
	#define EMPTY_BATTERY 5
	#define LOW_BATTERY 20
	#define LOW_BATTERY_DURATION 20
	
	void setup(void);
	void exec(void);
	void beep(int);
	int getBattery(void);
	void setup_battery_level(void);
	void loop_battery_level(void);
	
#endif
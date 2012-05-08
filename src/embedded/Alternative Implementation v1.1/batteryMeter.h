//
//  batteryMeter.h
//  
//
//  Created by Working Bruce on 4/26/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef _batteryMeter_h
#define _batteryMeter_h

//#define FIRST_BATTERY 1
//#define SECOND_BATTERY 2 //old code by denir
//#define THIRD_BATTERY 3
#define FIRST_BATTERY_ID 0x50
#define SECOND_BATTERY_ID 0x50 //TODO not 0x50
#define THIRD_BATTERY_ID 0x50 //TODO not 0x50

int init_battery_meter(void);
uint8_t get_battery_level(int);

#endif

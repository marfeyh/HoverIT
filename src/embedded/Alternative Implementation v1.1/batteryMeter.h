//
//  batteryMeter.h
//  
//
//  Created by Working Bruce on 4/26/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef _batteryMeter_h
#define _batteryMeter_h

#define FIRST_BATTERY 1
#define SECOND_BATTERY 2
#define THIRD_BATTERY 3

int init_battery_meter(void);
uint16_t get_battery_meter(void);

#endif

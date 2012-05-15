/*!
 * @file battery_meter.c
 * @details the API of the battery meter
 * @author Bruce Yinhe
 * @version 2, 26 Arpil 2012
 * @note 
 * @todo 
 * 
 * @section LICENSE
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 * 
 * This program is distodributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public
 * License along with this program. If not, see
 * <http://www.gnu.org/licenses/gpl-3.0.html>.
 */

#include <Arduino.h>
#include <searduino.h>
#include "battery_meter.h"
#include "percentage.h"
#include "alarm.h"
#include "four_leds.h"
#include "pin.h"

/*!
 * @brief initialize all
 * @return 0
 */
int init_battery_meter() {    
    /* init the leds */
    init_leds();
    /* init the alarm*/
    init_alarm();
    return 0;
}

/*!
 * @brief The battery level goes from level 1 (0x0) to 16 (0xE). This function takes input of 0 -100 and gives output of a binay message
 * @param percentage the percentage of the battery level
 * @return a binary message that contains the level, from 0x0 to 0xE
 */
unsigned char translate_level(int percentage) {
    if (percentage >= 0 && percentage < 7) 
        return 0x0;
    else if (percentage < 14)
        return 0x1;
    else if (percentage < 20)
        return 0x2;
    else if (percentage < 27)
        return 0x3;
    else if (percentage < 34)
        return 0x4;
    else if (percentage < 40)
        return 0x5;
    else if (percentage < 47)
        return 0x6;
    else if (percentage < 53)
        return 0x7;
    else if (percentage < 60)
        return 0x8;
    else if (percentage < 67)
        return 0x9;
    else if (percentage < 73)
        return 0xA;
    else if (percentage < 80)
        return 0xB;
    else if (percentage < 86)
        return 0xC;
    else if (percentage < 93)
        return 0xD;
    else if (percentage <= 100)
        return 0xE;
    else 
        return 0x0;
}

/*!
 * @brief This function takes the battery number and percentage as input, and returns a binary message according to the protocol as output
 * @param battery_number the numbder of the battery
 * @param percentage the percentage of the battery level
 * @return a binary message that contains the battery number ID and the level
*/
unsigned char make_msg(int battery_number, int percentage) {
	unsigned char msg = 0;
    switch (battery_number) {
        case FIRST_BATTERY:
            msg = FIRST_BATTERY_ID + translate_level(percentage);
            break;
        case SECOND_BATTERY:
            msg = SECOND_BATTERY_ID + translate_level(percentage);
            break;
        case THIRD_BATTERY:
            msg = THIRD_BATTERY_ID + translate_level(percentage);
            break;
        default:
            break;
    }
    return msg;
}

/*!
 * @brief This function will be called by the Scheduler. It takes the battery number as input, and returns a binary message as output.
 * @param battery_number the battery number
 * @return a binary message that contains the battery level, from 0x0 to 0xE
 */
unsigned char get_battery_level(int battery_number) {
    /* get the percentage from the battery*/
    uint16_t percentage = get_percentage(battery_number);
    
    if (battery_number == FIRST_BATTERY) {
        /* send the percentage to the alarm */
        setup_alarm(percentage);
        /* send the percentage to the leds*/
        display_percentage(percentage);
    }
    /* the new bin msg protocol needs to be negotiated with Scheduler*/
//    uint8_t binMsg = make_msg(batteryNumber, percentage);
    unsigned char bin_msg = translate_level(percentage);
    
    return bin_msg;
}







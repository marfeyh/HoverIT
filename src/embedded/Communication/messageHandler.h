/*
 * messageHandler.h
 *
 *  Created on: Mar 28, 2012
 */

#ifndef MESSAGEHANDLER_H_
#define MESSAGEHANDLER_H_
unsigned char parseBinary(unsigned char*);
unsigned char findMessage(unsigned char*);
unsigned char create_fan_forward_speed(unsigned char*);
unsigned char create_fan_hovering_speed(unsigned char*);
unsigned char create_ruder_direction(unsigned char*);
unsigned char create_hovercraft_speed(unsigned char*);
unsigned char create_hovercraft_pressure(unsigned char*);
unsigned char create_battery_level(unsigned char*);
unsigned char check_number_limit(unsigned char*);
unsigned char is_increase(unsigned char*);
unsigned char getValue_fans(unsigned char*);
unsigned char get_direction(unsigned char*);
#endif /* MESSAGEHANDLER_H_ */

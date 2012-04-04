/*
 * messageHandler.h
 *
 *  Created on: Mar 28, 2012
 */

#ifndef MESSAGEHANDLER_H_
#define MESSAGEHANDLER_H_
unsigned char parseBinary(unsigned char* message);
unsigned char findMessage(unsigned char* message);
unsigned char create_fan_forward_speed(unsigned char* message);
unsigned char create_fan_hovering_speed(unsigned char* message);
unsigned char create_ruder_direction(unsigned char* message);
unsigned char create_hovercraft_speed(unsigned char* message);
unsigned char create_hovercraft_pressure(unsigned char* message);
unsigned char create_battery_level(unsigned char* message);
unsigned char check_number_limit(unsigned char* message);
#endif /* MESSAGEHANDLER_H_ */

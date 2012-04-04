/*
 * API_messageHandler.h
 *
 *  Created on: Apr 01, 2012
 */

#ifndef API_BLUETOOTH_CONTROLER_H_
#define API_BLUETOOTH_CONTROLER_H_


/**
 * API function which is called by timer
 * Basically when this function is called the bluetooth gets the resources of the board and
 * it should check if there is anything available on serial input
 *
 */
unsigned char check_serial_input();

/**
 * API function to create fan forward speed message
 * message argument is followed by hovercraft protocol available on wiki
 */
unsigned char fan_forward_speed(unsigned char message);

/**
 * API function to create fan hovering speed message
 * message argument is followed by hovercraft protocol available on wiki
 */
unsigned char fan_hovering_speed(unsigned char message);

/**
 * API function to create ruder direction message
 * message argument is followed by hovercraft protocol available on wiki
 */
unsigned char ruder_direction(unsigned char message);

/**
 * API function to create hovercraft speed (measured by sensor) message
 * message argument is followed by hovercraft protocol available on wiki
 */
unsigned char hovercraft_speed(unsigned char message) ;

/**
 * API function to create hovercraft pressure (measured by sensor) message
 * message argument is followed by hovercraft protocol available on wiki
 */
unsigned char hovercraft_pressure(unsigned char message) ;

/**
 * API function to create hovercraft battery level (measured by sensor) message
 * message argument is followed by hovercraft protocol available on wiki
 */
unsigned char battery_level(unsigned char message);
#endif /* API_BLUETOOTH_CONTROLER_H_ */

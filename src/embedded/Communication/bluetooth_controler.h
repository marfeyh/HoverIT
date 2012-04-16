/*
 * This header file is for internal functions
 * bluetooth_controler.h
 *
 *  Created on: Apr 9, 2012
 *      Author: amir
 */

#ifndef BLUETOOTH_CONTROLER_H_
#define BLUETOOTH_CONTROLER_H_

void send_serial_string(char* string);
void send_serial_binary(unsigned char* binary);

int blink();

#endif /* BLUETOOTH_CONTROLER_H_ */

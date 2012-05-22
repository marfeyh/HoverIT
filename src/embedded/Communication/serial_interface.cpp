/*
 This file is part of Hoverit.

 Hoverit is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 Hoverit is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with Hoverit.  If not, see <http://www.gnu.org/licenses/>.
 */

/*!
 @file serial_interface.cpp
 @headerfile Arduino.h
 @headerfile searduino.h
 @headerfile HardwareSerial.h
 @headerfile serial_interface.h
 @headerfile pin.h
 @author Viktor Green
 @author Peter Mylikoski
 @details Following code is saved as c++ extension because it has to be compiled by c++ compiler
 since it is using serial libraries of searduino
 @author Amir Almasi
 @author Retta Shiferaw
 @author Bligh Pratanporn Borjesson
 @version 0.3
 */
#include <serial_interface.h>
#include <Arduino.h>
#include <searduino.h>
#include <HardwareSerial.h>
#include <pin.h>
#include <string.h>

/*!
 @brief When this function is called the bluetooth gets the resources of CPU, Arduino,
 and it should check if there is anything available or not
 @return unsigned char containing the binary message
 return 255 if there was nothing availble
 */
unsigned char serial_read() {
//	unsigned char temp = check_connection();
//	debug_print(&temp);
//	if (1 == check_connection()) {
	// Check serial input if there is anything available
	if (COMMUNICATION_PIN.available() > 0) {
		unsigned char input = COMMUNICATION_PIN.read();
//			debug_print(&input);
		return input;
	} // if there is anything available on serial input
	return 255;
//	}
//	return 254;
}

/*!
 @brief A function to send the data to serial pins
 @param pointer to unsigned char of the binary to be sent
 */
void serial_binary_write(unsigned char* binary) {
	//	printf("Module serial_interface.cpp: function serial_binary_write is working...\n");
	COMMUNICATION_PIN.write(*binary);
}

/*!
 @brief A function to send string to bluetooth character by character to be sent
 @param pointer to first char of the string to be sent
 */
void serial_string_write(char* string) {
	unsigned char length = strlen(string);
	unsigned char counter = 0;
	for (; counter < length; counter++) {
		Serial.println(*(counter + string));
		COMMUNICATION_PIN.print(*(counter + string));
	}
}

/*!
 @brief A function to initialize pins
 */
void serial_setup(void) {
	MONITORING_PIN.begin(9600);
	COMMUNICATION_PIN.begin(9600);
	pinMode(COMMUNICATION_STATUS_PIN, INPUT);
}

/*!
 @brief A function to send data to serial for the use monitoring
 @param pointer to unsigned char of first char of the string to be sent
 */
void debug_print(unsigned char* data) {
	MONITORING_PIN.print(*data);
}

/*!
 @brief A function to send data to serial for the use monitoring
 @param pointer to unsigned int of first char of the string to be sent
 */
void debug_print2(unsigned int* data) {
	MONITORING_PIN.print(*data);
}

/*!
 @brief A function to send data to serial for the use monitoring
 @param int value to be sent to monitoring
 */
void debug_print3(int data) {
	MONITORING_PIN.print(data);
}

/*!
 @brief A function to send speed data
 @param pointer to int value to be sent via Bluetooth
 */
void serial_binary_write_speed(int* speed) {
	COMMUNICATION_PIN.print(*speed);
}

/*!
 @brief A function to send data to serial for the use monitoring IN BINARY
 @param pointer to unsigned char of first char of the string to be sent
 */
void debug_write(unsigned char* data) {
	MONITORING_PIN.write(*data);
}

/*!
 @brief A function to send string to serial pin character by character
 @param pointer to first charCOMMUNICATION_STATUS_PIN of the string to be sent
 */
void debug_print_string(char* character) {
	for (; *character != '\0'; character++) {
		MONITORING_PIN.print(*character);
	}
	MONITORING_PIN.print("\n");
}

/*!
 @brief A function to change the communication connection.
 This function was implemented when changing request should have been made before
 compiling which was in earlier architecture. In the latest architecture and implementation
 this is not effecting and in used anymore.
 */
void serial_switch() {
#ifdef BLUETOOTH
	debug_print_string("Bluetooth is activated");
#endif
#ifdef WIFI
	debug_print_string("Wifi is activated");
#endif
#ifdef GSM
	debug_print_string("Gsm is activated");
#endif
}

/*!
 @brief A function to check if the connection is established or not
 */
unsigned char check_connection() {
	return digitalRead(COMMUNICATION_STATUS_PIN);
}

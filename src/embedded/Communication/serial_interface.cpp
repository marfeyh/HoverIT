/*!
 @file serial_interface.cpp
 @headerfile Arduino.h
 @headerfile searduino.h
 @headerfile HardwareSerial.h
 @headerfile serial_interface.h
 @headerfile pin.h
 @details Following code is saved as c++ extension because it has to be compiled by c++ compiler
 since it is using serial libraries of searduino
 @author Amir Almasi
 @author Retta Shiferaw
 @version 0.2
 */
#include <Arduino.h>
#include <searduino.h>
#include <HardwareSerial.h>
#include <serial_interface.h>
#include <pin.h>
#include <string.h>

/*!
 @brief When this function is called the bluetooth gets the resources of CPU, Arduino,
 and it should check if there is anything available or not
 @return unsigned char containing the binary message
 return 255 if there was nothing availble
 */
unsigned char serial_read() {
	// Check serial input if there is anything available
	if (COMMUNICATION_PIN.available() > 0) {
		unsigned char input = COMMUNICATION_PIN.read();
		debug_print(&input);
		return input;
	} // if there is anything available on serial input
	return 255;
}

/*!
 @brief A function to send the data to serial pins
 @param pointer to unsigned char of the binary to be sent
 */
void serial_binary_write(unsigned char* binary) {
	//	printf("Module serial_interface.cpp: function serial_binary_write is working...\n");
	COMMUNICATION_PIN.write(*binary);
	Serial.write(*binary);
}

/*!
 @brief A function to send string to bluetooth character by character to be sent
 @param pointer to first char of the string to be sent
 */
void serial_string_write(char* string) {
	uint8_t length = strlen(string);
	uint8_t counter = 0;
	for (; counter < length; counter++) {
		Serial.println(*( counter + string ));
		COMMUNICATION_PIN.print(*( counter + string ));
	}
}

/*!
 @brief A function to initialize pins
 */
void serial_setup(void) {
	MONITORING_PIN.begin(9600);
	COMMUNICATION_PIN.begin(9600);
}

/*!
 @brief A function to send data to serial for the use monitoring IN HEX
 @param pointer to unsigned char of first char of the string to be sent
 */
void debug_print(unsigned char* data) {
	MONITORING_PIN.print(*data);
}
void debug_print2(unsigned int* data) {
	MONITORING_PIN.print(*data);
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
 @param pointer to first char of the string to be sent
 */
void debug_print_string(char* character) {
	for (; *character != '\0'; character++) {
		MONITORING_PIN.print(*character);
	}
	MONITORING_PIN.print("\n");
}



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

unsigned char check_connection(){
	return digitalRead(COMMUNICATION_STATUS_PIN);
}

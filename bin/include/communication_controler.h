/*!
 @file communication_controler.h
 @details This header file contains internal functions
 @author Amir Almasi
 @author Retta Shiferaw
 @version 0.2
 */

#ifndef BLUETOOTH_CONTROLER_H_
#define BLUETOOTH_CONTROLER_H_

/*!
 @brief The function sends an string to the monitoring of Arduino for the purpose of debugging
 @param pointer to character which keeps the first character address.
 */
void send_serial_string(char* string);

/*!
 @brief The function sends one binary to the monitoring of Arduino for the purpose of debugging
 @param pointer to unsigned character which keeps the address of unsigned character.
 */
void send_serial_binary(unsigned char*);
void send_serial_binary_speed(int*);
unsigned char check_bluetooth(unsigned char*);
unsigned char check_wifi(unsigned char*);
unsigned char parse_input(unsigned char* result);
unsigned char ruder_direction_handler(unsigned char*);
unsigned char fan_hovering_speed_handler(unsigned char*);
unsigned char fan_forward_speed_handler(unsigned char*);

#endif /* BLUETOOTH_CONTROLER_H_ */

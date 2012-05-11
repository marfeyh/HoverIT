/*!
 @file serial_interface.h
 @details This header file contains function prototypes of serial_interface.c
 @author Amir Almasi
 @author Retta Shiferaw
 @author Viktor Green
 @author Peter Myllykoski
 @version 0.3
 @note This header file is written by the help of Viktor and Peter
 @see http://hoveritu.com/projects/semb2012/wiki for more information
 */
#ifndef SERIAL_INTERFACE_H
#define SERIAL_INTERFACE_H

#define BLUETOOTH
//#define WIFI
//#define GSM

#ifdef __cplusplus
extern "C" {
#endif

/*!
 @brief When this function is called the bluetooth gets the resources of CPU, Arduino,
 and it should check if there is anything available or not
 @return unsigned char containing the binary message
 return 255 if there was nothing availble
 */
unsigned char serial_read(void);

/*!
 @brief A function to send the data to serial pins
 @param pointer to unsigned char of the binary to be sent
 */
void serial_binary_write(unsigned char*);

/*!
 @brief A function to send string to bluetooth character by character to be sent
 @param pointer to first char of the string to be sent
 */
void serial_string_write(char*);

/*!
 @brief A function to initialize pins
 */
void serial_setup (void);

/*!
 @brief A function to send data to serial for the use monitoring IN HEX
 @param pointer to unsigned char of first char of the string to be sent
 */
void debug_print (unsigned char*);

/*!
 @brief A function to send data to serial for the use monitoring IN BINARY
 @param pointer to unsigned char of first char of the string to be sent
 */
void debug_write (unsigned char*);

/*!
 @brief A function to send string to serial pin character by character
 @param pointer to first char of the string to be sent
 */
void debug_print_string (char*);


void serial_switch(void);

unsigned char check_connection(void);

#ifdef __cplusplus
}
#endif
#endif

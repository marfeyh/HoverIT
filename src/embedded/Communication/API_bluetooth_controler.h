/*!
 @file API_bluetooth_controler.h
 @details This header file contains all API functions
 @author Amir Almasi
 @author Retta Shiferaw
 @version 0.3
 @note All the aruguments and returns of the functions are unsigned char
 */

#ifndef API_BLUETOOTH_CONTROLER_H_
#define API_BLUETOOTH_CONTROLER_H_

/*!
 @brief Initializing bluetooth serial pins on Arduino
 */
void bluetooth_serial_setup();

/*!
 @brief When this function is called, by Scheduler, the bluetooth gets the resources of
 the board and it should check if there is anything available on serial input or not
 */
void check_serial_input();

/*!
 @brief The function creates fan forward speed message.
  message argument is followed by hovercraft protocol available on wiki
 @see http://hoveritu.com/projects/semb2012/wiki
 @param unsigned char of the value to be sent to pc
 @return unsigned char containing value and message type
 */
unsigned char fan_forward_speed(unsigned char message);

/*!
 @brief The function creates fan hovering speed message.
  message argument is followed by hovercraft protocol available on wiki
 @see http://hoveritu.com/projects/semb2012/wiki
 @param unsigned char of the value to be sent to pc
 @return unsigned char containing value and message type
 */
unsigned char fan_hovering_speed(unsigned char message);

/*!
 @brief The function creates ruder direction message.
  message argument is followed by hovercraft protocol available on wiki
 @see http://hoveritu.com/projects/semb2012/wiki
 @param unsigned char of the value to be sent to pc
 @return unsigned char containing value and message type
 */
unsigned char ruder_direction(unsigned char message);

/*!
 @brief The function creates hovercraft speed (measured by sensor) message.
  message argument is followed by hovercraft protocol available on wiki
 @see http://hoveritu.com/projects/semb2012/wiki
 @param unsigned char of the value to be sent to pc
 @return unsigned char containing value and message type
 */
unsigned char hovercraft_speed(unsigned char message);

/*!
 @brief The function creates hovercraft pressure (measured by sensor) message.
  message argument is followed by hovercraft protocol available on wiki
 @see http://hoveritu.com/projects/semb2012/wiki
 @param unsigned char of the value to be sent to pc
 @return unsigned char containing value and message type
 */
unsigned char hovercraft_pressure(unsigned char message);

/*!
 @brief The function creates hovercraft battery level message.
  message argument is followed by hovercraft protocol available on wiki
 @see http://hoveritu.com/projects/semb2012/wiki
 @param unsigned char of the value to be sent to pc
 @return unsigned char containing value and message type
 */
unsigned char battery_level(unsigned char message);
#endif /* API_BLUETOOTH_CONTROLER_H_ */

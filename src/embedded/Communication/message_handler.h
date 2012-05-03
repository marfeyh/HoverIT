/*!
 @file message_handler.h
 @details This header file contains all conventions number based on project Wiki
 @author Amir Almasi
 @author Retta Shiferaw
 @version 0.6
 @see http://hoveritu.com/projects/semb2012/wiki for more information
 */

#ifndef MESSAGEHANDLER_H_
#define MESSAGEHANDLER_H_

/*!
 @brief A function which is called when there is binary received on serial.
 When binary argument is based on protocol the return of the function is: 0 - 5
 When binary argument is not based on anything on protocol the
 return of the function is 255
 @param pointer to unsigned char of the message which is received
 @return unsigned char containing a number
 */
unsigned char parse_binary(unsigned char*);

/*!
 @brief A function to find out message contains increasing and decreasing or not.
 @param pointer to unsigned char of the message which is received
 @return unsigned char containing a number
 1 if increase or decrease message
 2 if normal setting speed message
 255 if something is wrong
 */
unsigned char increase_decrease(unsigned char*);

/*!
 @brief A function to find out about the direction.
 @param pointer to unsigned char of the message which is received
 @see http://hoveritu.com/projects/semb2012/wiki
 @return unsigned char containing a number
 return number is in the range of 0 to 5
 */
unsigned char get_direction(unsigned char*);

/*!
 @brief A function to find out about exact data of value in binary received.
 @param pointer to unsigned char of the message
 @return unsigned char containing a number
 return number is in the range of 0 to 7
 */
unsigned char get_value_fans(unsigned char*);

/*!
 @brief A function to find the type of the message of the received binary
 The function returns 0 - 5 if the binary message is based on the protocol
 The function returns 255 when the binary message is not based on the protocol.
 @see http://hoveritu.com/projects/semb2012/wiki
 @param pointer to unsigned char of the message
 @return number is in the range of 0 to 5
 return number 255 for expressing error
 */
unsigned char find_message(unsigned char*);

/*!
 @brief A function to create fan forward speed message based on protocol
 @see http://hoveritu.com/projects/semb2012/wiki
 @param pointer to unsigned char of the message
 @return number based on the message type
 return 255 if the value is bigger the limit
 */
unsigned char create_fan_forward_speed(unsigned char*);

/*!
 @brief A function to create fan hovering speed based on protocol
 @see http://hoveritu.com/projects/semb2012/wiki
 @param pointer to unsigned char of the message
 @return number based on the message type
 return 255 if the value is bigger the limit
 */
unsigned char create_fan_hovering_speed(unsigned char*);

/*!
 @brief A function to create ruder direction message based on protocol
 @see http://hoveritu.com/projects/semb2012/wiki
 @param pointer to unsigned char of the message
 @return number based on the message type
 return 255 if the value is bigger the limit
 */
unsigned char create_ruder_direction(unsigned char*);
/*!
 @brief A function to create hover craft speed message based on protocol
 @see http://hoveritu.com/projects/semb2012/wiki
 @param pointer to unsigned char of the message
 @return number based on the message type
 return 255 if the value is bigger the limit
 */
unsigned char create_hovercraft_speed(unsigned char*);

/*!
 @brief A function to create hover craft pressure message based on protocol
 @see http://hoveritu.com/projects/semb2012/wiki
 @param pointer to unsigned char of the message
 @return number based on the message type
 return 255 if the value is bigger the limit
 */
unsigned char create_hovercraft_pressure(unsigned char*);
/*!
 @brief A function to create battery level message based on protocol
 @see http://hoveritu.com/projects/semb2012/wiki
 @param pointer to unsigned char of the message
 @return number based on the message type
 return 255 if the value is bigger the limit
 */
unsigned char create_battery_level(unsigned char*);
/*!
 @brief A function to check the limit of the value of the message
 @note The limit of the message is from 0 to 15 ( 4 bits )
 @see http://hoveritu.com/projects/semb2012/wiki
 @param pointer to unsigned char of the message
 @return 1 if the message is in the range
 return 255 if the value is bigger the limit
 */
unsigned char check_number_limit(unsigned char*);
#endif /* MESSAGEHANDLER_H_ */

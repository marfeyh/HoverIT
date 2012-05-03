/*!
 @file pc_log.h
 @details This header file contains all structure and functions in logfile system on PC side
 @author Jianfeng Xie
 @author Siyang Suo
 @version 0.2
 */

typedef struct obj{
	char* tag;  /* log level e.g. Info, Error and Warning )*/
	char* info; /* log description*/
	char* function; /* which moduels/funcions the log info comse from*/
}log_obj;

/*!
 @brief A function is called to initilize .txt file, which stores log information.
 Before starting to record log information.
 It creats a .txt file named "log.txt", if it didn't exist; or reopen "log.txt" file, if it existed.
 @param void
 @return void
 */
void init_log_file();

/*!
 @brief A function is called to get the currently local time.
 @param void
 @return a pointer to char, which contains 
 */
char* get_time();

/*!
 @brief A function is called to write one line of string in .txt file.
 @param a pointer to char, which contains one line of log information.
 @return void
 */
void log_file_writer();

/*!
 @brief A function is externally called to send a log message to .txt file.
 @param a pointer to char, which contains tag
 @param a pointer to char, which contains message
 @param a pointer to char, which contains function name
 @return void
 */
void log_to_file(char *tag ,char *message, char *function);

/*!
 @brief A function is called to close and save .txt file, which stores log information.
 When log recording finished
 @param void
 @return void
 */
void close_log_file();
/*!
 @brief A function is called to delet .txt file, which stores log information.
 @param void
 @return void
 */
void delet_log_file();

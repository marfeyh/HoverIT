/*!
 @file pc_log.c 
 @headerfile pc_log.h
 @details This module is to provide logfile APIs for recoding the log info in .text file on PC side during execution.
 @author Jianfeng Xie
 @author Siyang Suo
 @version 0.4
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <time.h>
#include "pc_log.h"



FILE *g_ptr= NULL;
char *g_file = "log.txt";

/*!
 @brief A function is called to initilize .txt file, which stores log information.
 Before starting to record log information.
 It creats a .txt file named "log.txt", if it didn't exist; or reopen "log.txt" file, if it existed.
 @param void
 @return void
 */
void init_log_file(){	
	
	g_ptr = fopen(g_file, "a");
	if (g_ptr == NULL) printf("Error in opening a file..",g_file); /* if opening file failed, print error info */

}

/*!
 @brief A function is called to close and save .txt file, which stores log information.
 When log recording finished
 @param void
 @return void
 */
void close_log_file(){
		
    fclose(g_ptr);
}

/*!
 @brief A function is called to delet .txt file, which stores log information.
 @param void
 @return void
 */
void delet_log_file(){
	remove(g_file);
}

/*!
 @brief A function is called to get the currently local time.
 @param void
 @return a pointer to char, which contains 
 */
char* get_time(){
	char str[100];	/*string to contain time */
	time_t the_time;
    struct tm *tp;
    the_time = time(NULL);
 	tp = localtime(&the_time);  /*get the pointer of curret time*/
	sprintf(str, "%2.2d-%2.2d-%2.2d %2.2d:%2.2d:%2.2d", tp->tm_year+1900, 
	tp->tm_mon+1, tp->tm_mday, tp->tm_hour, tp->tm_min, tp->tm_sec);  /* convert tiime into string formate */
	//printf("Time: %s \n", str);
	return str;	
}

/*!
 @brief A function is called to write one line of string in .txt file.
 @param a pointer to char, which contains one line of log information.
 @return void
 */
void file_writer(char *buf){
	size_t len = 0;
  	len = strlen(buf);
	fwrite(buf, len, 1, g_ptr);      /*wirte one line in file*/
	//printf("\n Written Successfuly in the file.\n");

}

/*!
 @brief A function is externally called to send a log message to .txt file.
 @param a pointer to char, which contains tag
 @param a pointer to char, which contains message
 @param a pointer to char, which contains function name
 @return void
 */

void log_to_file(char *tag, char *module, char *function, char *message){	
	
	char temp[100]; /*one line of log information*/			
	log_obj log = {tag, module,function,message};  /*add log information in log object*/
	//printf("log_level: %s, info: %s, function: %s \n",log.tag, log.info, log.function);
	sprintf(temp,"%s, %s, %s, %s, %s  \n",get_time(),log.tag, log.module, log.function, log.info);	/*constaract the strings*/	
	file_writer(temp); /* wirte one line in file*/
}



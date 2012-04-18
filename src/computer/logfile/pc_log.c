#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <time.h>
#include "pc_log.h"

FILE *p = NULL;
char *file = "default.log";


void init_log_file(){
	p = fopen(file, "w");
	
  	if (p== NULL) {
  	printf("Error in opening a file..", file);
  	}
}

void close_log_file(){
	fclose(p);
}

void delet_log_file(){
	remove(file);
}

char* get_time(){
	char str[100];	
	time_t the_time;
    struct tm *tp;
    the_time = time(NULL);
 	tp = localtime(&the_time);
	sprintf(str, "%2.2d-%2.2d-%2.2d %2.2d:%2.2d:%2.2d", tp->tm_year+1900, tp->tm_mon+1, tp->tm_mday, tp->tm_hour, tp->tm_min, tp->tm_sec);
	return str;	
}

void log_file_writer(char* buf){
	  	
	size_t len = 0;
  	len = strlen(buf);
	fwrite(buf, len, 1, p);
	//printf("\n Written Successfuly in the file.\n");

}



void log_to_file(char* tag, char* message, char *function ){	
	char temp[100];			
	log_obj log = {tag, message,function};
	printf("log_level: %s, info: %s, function: %s \n",log.tag, log.info, log.function);
	sprintf(temp,"%s, %s, %s, %s  \n",get_time(),log.tag, log.info, log.function);		
	log_file_writer(temp);
	
	
}

void main(){
	init_log_file();
	sleep(1);		
	log_to_file("Info","turn off","moter");
	sleep(1);
	log_to_file("Error","Connection fail","scheduel");
	sleep(1);
	log_to_file("Warning","wtf","fan");
	close_log_file();
	//delet_log_file();
}

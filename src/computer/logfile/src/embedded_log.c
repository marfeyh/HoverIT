#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "embedded_log.h"
#include "pc_log.h"

char* send_info(char* moduleName, char* functionName, char* message){
	char temp[100];		

	sprintf(temp,"%s,%s,%s",moduleName,functionName,message);
	log_to_file("Info", moduleName,functionName,message);

	return temp;
}

char* send_warning(char* moduleName, char* functionName, char* message){
	char temp[100];	

	sprintf(temp,"%s,%s,%s",moduleName,functionName,message);	
	log_to_file("Warning", moduleName,functionName,message);

	return temp;

}
char* send_error(char* moduleName, char* functionName, char* message){
	char temp [100]; /* using malloc, so that this variable will not be distroied*/	
	
	sprintf(temp,"%s,%s,%s",moduleName,functionName,message);	
	log_to_file("Error", moduleName,functionName,message);
	return temp;

}

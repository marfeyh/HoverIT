#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "debug1.h"
#include "pc_log.h"

char* send_info(char* moduleName, char* functionName, char* message){
	char temp[100];	
	log_obj log = {moduleName, functionName, message};	

// log.moduleName = moduleName;
// log.functionName = functionName;
// log.message= info;

	sprintf(temp,"%s,%s,%s",log.moduleName,log.functionName,log.message);
	log_to_file("Info", moduleName, functionName, message);

	return temp;
}

char* send_warning(char* moduleName, char* functionName, char* message){
	char temp[100];
	log_obj log = {moduleName, functionName, message};	

	sprintf(temp,"%s,%s,%s",log.moduleName,log.functionName,log.message);	
	log_to_file("Warning", moduleName, functionName, message);

	return temp;

}
char* send_error(char* moduleName, char* functionName, char* message){
	char temp [100]; /* using malloc, so that this variable will not be distroied*/
	log_obj log = {moduleName, functionName, message};	
	sprintf(temp,"%s,%s,%s",log.moduleName,log.functionName,log.message);	
	log_to_file("Error", moduleName, functionName, message);
	return temp;

}

int main()
{
			send_info("aaa","aaa","ok\t");
        	printf("The status in this function of this module is OK!\n");
			send_warning("aaa","aaa","warning\t");
	        printf("This function of this module sending its warning\n");
			send_error("aaa","aaa","error\t");	
	        printf("This function of this module sending its error\n");
	

	return 0;
}

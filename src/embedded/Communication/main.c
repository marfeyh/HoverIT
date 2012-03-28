/*
 * main.c
 *
 *  Created on: Mar 28, 2012
 */

#include "stdio.h"
#include "info.h"
int main (int argc, char** argv){
	printf("group_name %s\n", group_name());
	printf("member_number %d\n", member_number());
	printf("group_manager %s\n", group_manager());
	printf("group_respons %s\n", group_respons());
	return 0;
}

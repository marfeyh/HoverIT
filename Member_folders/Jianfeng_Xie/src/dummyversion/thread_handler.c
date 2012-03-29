//Atuhor:Jianfeng 2012/03/28
#include <unistd.h>     /* Symbolic Constants */
#include <sys/types.h>  /* Primitive System Data Types */ 
#include <errno.h>      /* Errors */
#include <stdio.h>      
#include <stdlib.h>     /* General Utilities */
#include <pthread.h>    /* POSIX Threads */
#include <string.h>     
#include <stdint.h>  


#include "bit_gen.h"  

void* main_loop(void *arg); /*main thread generate a 16bits number for Bluebooth everytime*/
void* new_task(void *arg); /*another thread deals with receving request e.g. speed up and change direction*/
void thread_init();        /*creat two await threads  */ 
void thread_control(uint8_t request); /*lock and unlock 2 threads depending on different request*/
void thread_wait();  /*close both threads*/



pthread_t thread1,thread2; /* main loop:thread1 and add_task: thread2 */
pthread_mutex_t mutex; /*mutex variable for locking and unlocking*/
pthread_cond_t cond; /*condition variable will be sent to activate await thread*/
uint8_t request; /*reuqest varibale decides to activate which thread. request= 1 it means going to thread1(main_loop) */

int main(){
	
	thread_init();	
	thread_control(1); /*activate main loop */
	
	exit(0);

}

void thread_init(){
	pthread_mutex_init(&mutex,NULL); /* init mutex and condition variables*/
	pthread_cond_init(&cond,NULL); 
	
	if(pthread_create(&thread1, NULL,main_loop, NULL)!= 0) /*create thread1 and routine function is main_loop*/
		printf("fail to create main thread \n");
	else
		printf("main thread created successfully \n");  
	
	
	if(pthread_create(&thread2, NULL,new_task, NULL)!= 0) /*create thread2 and routine function is new_task*/
		printf("fail to add new thread \n");
	else
		printf("new thread added successfully \n");
}


void thread_control(uint8_t request){
	do{ 
		if(request ==1){
			//sleep(1);
			pthread_cancel(thread2);   /* cancel thread2 */ 
			sleep(1);  
			pthread_cond_signal(&cond); /*send thread1 a signal to activate it*/
		}
		else{
			//sleep(1);  
			pthread_cancel(thread1); 
			sleep(1); 
			pthread_cond_signal(&cond);
		} 
	}while(1); 
	sleep(100); 
	pthread_exit(0); 
}  




void thread_wait(){             
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	printf("close both threads\n");
}


void *main_loop(void *arg){
	pthread_cleanup_push(pthread_mutex_unlock,&mutex); /* */ 
	while(1){ 
		//sleep(1);
		printf("main_loop get running \n"); 
		//printf("pthread_mutex_lock returns %d\n", 
		pthread_mutex_lock(&mutex); 
		pthread_cond_wait(&cond,&mutex); /*thread wait for signal */
		printf("%d \n", rando());  
		pthread_mutex_unlock(&mutex); 
		}		 
		pthread_cleanup_pop(0); /* */ 
} 

void *new_task(void *arg){
	pthread_cleanup_push(pthread_mutex_unlock,&mutex); 
	while(1){ 
		//sleep(1); /* */ 
		printf("new_task get running.\n"); 
		//printf("pthread_mutex_lock returns %d\n", 
		pthread_mutex_lock(&mutex); 
		pthread_cond_wait(&cond,&mutex); 
		/*call other fucntion*/ 
		pthread_mutex_unlock(&mutex); 
		//sleep(1); 
		} 
		pthread_cleanup_pop(0); 
} 
	


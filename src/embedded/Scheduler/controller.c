/*
   This file is part of Hoverit.

   Hoverit is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Hoverit is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Hoverit.  If not, see <http://www.gnu.org/licenses/>.
*/
/*! 
@file controller.c	
@details This module was added to the scheduler modules in order to
integrate this work package with the other ones.
It provides a control function which coordinates the other 
work packages included in the project through an infinite while loop. 
@date 14-05-2012 
@version 0.4
@authors Amir Almasi, Sebastian Hansson, Mozhan Soltani
@attention 
- Since the air pressure sensor was not found to be sensitive enough,
no pressure value will be retrieved and shown to the user. Therefore,
the associated code has been commented out. 
@copyright 2012 Amir Almasi, Sebastian Hansson, and Mozhan Soltani. 
 */

#include <list.h>
#include <external.h>
#include <jobpriority.h>
#include <jobtype.h>
#include <job.h>
#include <Theta-API.h>
#include <stdlib.h>
#include <gps.h>
#include "calculateSpeed.h"
#include "pressure.h"
#include "battery_meter.h"
#include "API_communication_controler.h"
 
static struct List *g_taskList;

/**
@brief Initializes the task list.
@attention Borrowed from the first version of scheduler.
 */
void init_list() {
	g_taskList = (struct List *) calloc(1, sizeof(struct List));
	g_taskList->size = 0;
} /* init_list function */

/**
@brief executes the jobs added to the task list.
@attention Partly borrowed from the first version of scheduler and
would be modified for each integration session accordingly.
 */
void execute_jobs() {
  while (g_taskList->size > 0) {
	 struct Job currentJob = pop(g_taskList);
       if(currentJob.job_num == 0){
         int(*task)(int);
         task = currentJob.task_p1;
         (*task)(currentJob.arg1); //execute the job
        } /* If job_num == 0 */
		
	   else if (currentJob.job_num == 1) {
	     int(*task)();
	     task = currentJob.task_p2;
		 (*task)(); //execute the job
		} /* If job_num == 1 */

       else if (currentJob.job_num == 2){
         void(*task)(int);
         task = currentJob.task_p3;
         (*task)(currentJob.arg1); //execute the job
       } /* If job_num == 2 */
	   else if (currentJob.job_num == 3){
         void(*task)(unsigned char,unsigned char);
         task = currentJob.task_p4;
         (*task)(currentJob.arg,currentJob.arg2); //execute the job
       } /* If job_num == 3 */
	}
} /* execute_jobs function */

/** 
@brief Contains an infinite while loop in which tasks are coordinated and jobs are set
and added to a task list and executed accordingly. 
@attention The function control is to be modified and updated for each integration session.
 */
void control() {
	init_list(); // A task list is initialized.
	while (1) {
	  check_serial_input();
	  execute_jobs();
	  
      // Get pressure value (was not included in the project).	 
	  //struct Job pressure_job;
	  //pressure_job.job_num = 2;
      //pressure_job.prio = PRIO_HIGH;
	  //pressure_job.arg1 = get_pressure();
	  //pressure_job.task_p3 = hovercraft_pressure;
	  //putJobInQueue(pressure_job);
      //hovercraft_pressure(get_pressure()); old
	  	
	  // Get speed value
	  extern Speed *g_speed_p;  
	  calculate_speed(g_speed_p);
	  int speed = get_speed(g_speed_p);
	  // Prepare and put the speed job in the queue
	  struct Job speed_job;
	  speed_job.job_num = 2;
      speed_job.prio = PRIO_HIGH;
	  speed_job.arg1 = speed;
	  speed_job.task_p3 = hovercraft_speed;
	  putJobInQueue(speed_job);
	  //hovercraft_speed(speed); old
		
	  // Get the first battery level
	  struct Job battery1_job;
	  battery1_job.job_num = 3;
      battery1_job.prio = PRIO_HIGH;
	  battery1_job.arg = 1;
	  battery1_job.arg2 = get_battery_level(FIRST_BATTERY);
	  battery1_job.task_p4 = battery_level;
	  putJobInQueue(battery1_job);
	  
	  // Get the second battery level
	  struct Job battery2_job;
	  battery2_job.job_num = 3;
      battery2_job.prio = PRIO_HIGH;
	  battery2_job.arg = 2;
	  battery2_job.arg2 = get_battery_level(SECOND_BATTERY);
	  battery2_job.task_p4 = battery_level;
	  putJobInQueue(battery2_job);
	  
	  // Get the third battery level
	  struct Job battery3_job;
	  battery3_job.job_num = 3;
      battery3_job.prio = PRIO_HIGH;
	  battery3_job.arg = 3;
	  battery3_job.arg2 = get_battery_level(THIRD_BATTERY);
	  battery3_job.task_p4 = battery_level;
	  putJobInQueue(battery3_job);
	
	  // Get Sonar data
	  
	  execute_jobs();

	}

} /* Control function */

/** 
@brief Gets an instance of Job struct and adds it to the g_taskList.
@param job The job that is to be added to the g_taskList.
@attention This function is replaced here from its original module,"main.c". 
 */
void putJobInQueue(struct Job job) {
	addJob(job, g_taskList);
} /* putJobInQueue function */

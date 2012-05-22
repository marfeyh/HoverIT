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
/**
@file job.h
@date 23-03-2012
@version 0.1
@author Dmitry Igoshin
@n 
@date 09-04-2012
@version 0.2
@author Mozhan Soltani
@attention Sections added/modified are as follow:
- Fields "job_num","arg1", "*task_p1", "*task_p2", "*task_p3", and
were added to the definition of struct Job in the first integration session.
@copyright 2012 Dmitry Igoshin, and Mozhan Soltani 
 */
#pragma once
#include <jobpriority.h>
#include <jobtype.h>
#if !defined job_h
#define job_h

/**
@struct Job
@brief Job to be executed
**/
struct Job {
    unsigned char job_num;          	  /* @var indicates which task pointer is used */
	int arg1;              				  /* @var is passed to the task pointers that take integer arguments */
	int (*task_p1)(int);                  /* @var pointer to a function taking an int argument and returning an int*/
	int (*task_p2)();                	  /* @var pointer to a function returning an int */
	void (*task_p3)(int);                 /* @var pointer to a void function taking an int argument*/
	enum PRIORITY prio;            		  /* @var job priority */
	enum JOB_TYPE type;            		  /* @var type of job */     
};


#endif

/*!
  This file is part of Hoveritu.
  
  Hoveritu is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Hoveritu is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with Hoveritu.  If not, see <http://www.gnu.org/licenses/>.
*/
/**
@author: Dmitry Igoshin
@brief Linked sorted list header file
**/
#pragma once
#include "jobtype.h";
#include "job.h";
#include "stdlib.h";
#include "stdio.h";

/**
@struct List node
**/
struct Node {
	struct Job value;   /** @var node value **/
	struct Node *next;  /** @var pointer to the next node **/
	struct Node *prev;  /** @var pointer to the previous node **/
};

/**
@struct List 
**/
struct List {
	struct Node * head;  /** @var pointer to the first element **/
	struct Node * tail;  /** @var pointer to the last element **/
	int size;
};

//Prototypes
void addJob(struct Job job, struct List * list);
struct Job pop(struct List * list);
void printList(struct List * list);
//void removeJobByType(JOB_TYPE type);




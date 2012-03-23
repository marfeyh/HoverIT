/**
Author: Dmitry Igoshin
Linked sorted list header file
**/
#pragma once
#include "jobtype.h"
#include "job.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef __list_h_
#define __list_h_

struct Node {
	struct Job value;
	struct Node *next;
	struct Node *prev;
};

struct List {
	struct Node * head;
	struct Node * tail;
	int size;
};

//Prototypes
void addJob(struct Job, struct List * list);
struct Job pop(struct List * list);
void printList(struct List * list);
//void removeJobByType(JOB_TYPE type);


#endif

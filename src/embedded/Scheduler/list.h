/**
Author: Dmitry Igoshin
Linked sorted list header file
**/
#pragma once
#include <job.h>

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
void addJob(struct Job job, struct List * list);
struct Job pop(struct List * list);
void printList(struct List * list);
//void removeJobByType(JOB_TYPE type);



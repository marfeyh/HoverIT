/**
@file list.h
@author Dmitry Igoshin
@brief Linked sorted list header file
**/
#pragma once
#include <job.h>

/**
@struct Node
@brief linked list element
**/
struct Node {
	struct Job value;   //@var element value
	struct Node *next;  //@var pointer to the next element
	struct Node *prev;  //@var pointer to the previous element
};

/**
@struct List
@brief linked list
**/
struct List {
	struct Node * head; //@var first element
	struct Node * tail; //@var last element
	int size;           //@var list size  
};

//Prototypes
void addJob(struct Job job, struct List * list);
struct Job pop(struct List * list);
void printList(struct List * list);




/**
Author: Dmitry Igoshin
Linked sorted list implementation
**/
#pragma once
#define NULL ((void *)0); //to be able to work with null pointers
#include "list.h"
#include "job.h"
#include "jobtype.h"
#include "jobpriority.h"
#include <stdio.h>
#include <stdlib.h>


//Add a job to the specific list
void addJob(struct Job job, struct List * list) {
	struct Node * node = (struct Node *)  calloc( 1, sizeof(struct Node) );
	if (node != NULL) {	
	node->value = job;
	if (list->size > 1) {
		struct Node * current;
		int added = 0;
		current = list->head;
		while (current != NULL) {
			if (current->value.prio < job.prio) {
				node->next = current;
				node->prev = current->prev;
				if (list->head == current) {
					list->head = node;
					list->head->next = current;
					current->prev = node;
				} else {
					current->prev->next = node;
					current->prev = node;
				}
				added = 1;
				break;
			}
			current = current->next;
		}
		if (added == 0) {
			node->next = NULL;
			node->prev = list->tail;
			list->tail->next = node;
			list->tail = node;
		}
	} else if (list->size > 0) {
		if (job.prio <= list->head->value.prio) {
			node->next = NULL;
			node->prev = list->head;
			list->tail = node;
			list->head->next = node;
		} else {
			node->prev = NULL;
			node->next = list->head;
			list->tail = list->head;
			list->head = node;
			list->tail->prev = list-> head;
		}
	} else if (list->size == 0) {
		list->head = node;
		node->next = NULL;
		node->prev = NULL;
	}
	list->size++;
	}
}

//Take out the first job
struct Job pop(struct List * list) {
	struct Job h = list->head->value;
	struct Node * node = list->head;
	list->size--;
	list->head = list->head->next;
	free(node);
	return h;
}

//Print ou list information
void printList(struct List * list) {
	struct Node * current;
	current = list->head;
	printf("-------------\n");
	printf("List size: %d\n", list->size);

	while (current != NULL) {
		printf("List item priority: %d\n", current->value.prio);
		current = current->next;
	}
	printf("-------------\n");
}



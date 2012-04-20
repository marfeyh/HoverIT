/**
Author: Dmitry Igoshin
Linked sorted list header file
**/

#include <stdlib.h>
#include <stdio.h>
#include "loc_struct.h"

//Prototypes
void addJob(struct Job job, struct List * list);
struct Job pop(struct List * list);
void printList(struct List * list);
//void removeJobByType(JOB_TYPE type);



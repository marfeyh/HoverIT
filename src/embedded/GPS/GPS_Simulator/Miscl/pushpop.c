#include "stack.h"


#define MAXSTACK 100
#define EMPTYSTACK -1
int top = EMPTYSTACK;
char items[MAXSTACK];
int i = -1;
int topE = -1;


void push(char c) {
   items[++top] = c;
   /* int p = top; */
   /* items[p] = 0x0A; */
   /* topE = 0; */
}

char pop() {
  return items[top--];
  /* i++; */
  /* char ret = items[i]; */
  /* if(ret!='\n'){ */
  /*   topE = -1; */
  /* } */
  /* else{ */
  /*   return items[i]; */
  /* } */
}

int full()  {
   return top+1 == MAXSTACK;
}

int empty()  {
  /*return top == EMPTYSTACK;*/
   return top == EMPTYSTACK;
}

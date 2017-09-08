#pragma once
#ifndef _LITF_STACK_h_
#define _LITF_STACK_h_
#include <stdbool.h>
typedef struct _liststack { 
	char *data;
	 int size;
	 int capacity;
}liststack,*liststackPtr;
typedef void(*LITE_FUNC)(char);

void push(liststackPtr *, char);
char pop(liststackPtr *);
bool isEmpty(liststackPtr);
void printStack(liststackPtr currentPtr, LITE_FUNC func);




#endif
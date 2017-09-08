#include"list_stack.h"
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include "liststack_test.h"
static const int ALLOC_STEP = 2;
void push(liststackPtr *ptr,const char data)
{
	/*assert(fptr != 0);
	if (*fptr == 0)
	{
		*fptr = calloc(1, sizeof(liststack));
	}
	if ((*fptr)->size + 1 > (*fptr)->capacity)
	{
		(*fptr)->data = realloc((*fptr)->data, (*fptr)->capacity + ALLOC_STEP);
		(*fptr)->capacity = (*fptr)->capacity + ALLOC_STEP;
	}
	(*fptr)->data[(*fptr)->size] = data;
	(*fptr)->size += 1;*/
	assert(ptr != 0);
	//考虑空队列
	if (*ptr == 0)
	{
		*ptr = calloc(1, sizeof(liststack));
	}
	//考虑队列内部数据空间不足时扩容
	if ((*ptr)->size + 1 > (*ptr)->capacity)
	{
		//给数据成员分配空间
		(*ptr)->data = (char*)realloc((*ptr)->data, (*ptr)->capacity + ALLOC_STEP);
		(*ptr)->capacity = (*ptr)->capacity + ALLOC_STEP;
	}
	//给队列内部数据按索引赋值(尾部)
	(*ptr)->data[(*ptr)->size] = data;
	(*ptr)->size += 1;

}
char pop(liststackPtr *fptr )
{
	assert(fptr != 0 && (*fptr) != 0 && (*fptr)->size != 0);
	//char *nptr;
	//nptr = (char*)malloc((*fptr)->capacity);
	//memcpy(nptr, (*fptr)->data, (*fptr)->size - 1);
	//char ret = (*fptr)->data[(*fptr)->size - 1];
	//(*fptr)->data[(*fptr)->size - 1] = '\0';
	//memove((*fptr)->data, (*fptr)->data + 1, (*fptr)->size - 1);
	//free(&(*fptr)->data);
	//(*fptr)->data = nptr;
	//printf("The popped value is %c.\n",
	printf("The popped value is%c\n", (*fptr)->data[(*fptr)->size - 1]);
	(*fptr)->size -= 1;
	//return ret;
}
bool isEmpty(liststackPtr topPtr)
{
	assert(topPtr != 0);
	return  topPtr->size==0;
}
void printStack(liststackPtr currentPtr, LITE_FUNC func)
{
	
	assert(currentPtr);
	for (int i = 0; i < currentPtr->size; i++)
	{
		func(currentPtr->data[i]);
	}
}


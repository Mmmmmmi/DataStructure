#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stddef.h>
#include "Queue.h"



void Queue_Initialize(Queue *pqueue)
{
	assert(pqueue != NULL);
	pqueue->front = NULL;
	pqueue->rear = NULL;
}

void Queue_Destroy(Queue *pqueue)
{
	Node *del = NULL;
	Node *cur = NULL;
	assert(pqueue != NULL);
	if (pqueue->front == NULL)
		return;
	cur = pqueue->front;
	del = pqueue->front;
	while (cur != NULL) {
		del = cur;
		cur = cur->next;
		free(del);
		del = NULL;
	}
	pqueue->front = NULL;
	pqueue->rear = NULL;
}
Node * Creat_Node(DataType data)
{
	Node *NewNode = (Node*)malloc(sizeof(Node));
	if (NewNode == NULL) {
		perror("error for Creat_Node");
		exit(EXIT_FAILURE);
	}
	NewNode->data = data;
	NewNode->next = NULL;
	return NewNode;
}
void Queue_Push(Queue *pqueue, DataType data)
{
	Node *cur = NULL;
	assert(pqueue);
	if (pqueue->front == NULL)
	{
		pqueue->front = Creat_Node(data);
		pqueue->rear = pqueue->front;
		return;
	}
	cur = pqueue->front; 
	while (cur->next != NULL) {
		cur = cur->next;
	}
	cur->next = Creat_Node(data);
	pqueue->rear = cur->next;
}
DataType Queue_Top(const Queue *pqueue)
{
	assert(pqueue);
	if (pqueue->front == NULL) {
		printf("\n队列为空，无法查看! \n");
		exit(EXIT_FAILURE);
	}
	return pqueue->front->data;
}

void Queue_Pop(Queue *pqueue)
{
	Node *del = NULL;
	assert(pqueue);
	if (pqueue->front == NULL) {
		return;
	}
#if 0
	if (pqueue->front == pqueue->rear) {
		free(pqueue->front);
		pqueue->front = NULL;
		pqueue->rear = NULL;
	}
	del = pqueue->front;
	pqueue->front = pqueue->front->next;
	free(del);
	del = NULL;
#else
	del = pqueue->front;
	pqueue->front = pqueue->front->next;
	free(del);
	del = NULL;
	if (pqueue->front == NULL) {
		pqueue->rear = NULL;
	}
#endif

}

int Queue_Empty(const Queue *pqueue)
{
    return pqueue->front == NULL && pqueue->rear == NULL;
}


unsigned Queue_Size(const Queue *pqueue)
{
	Node *cur = NULL;
	size_t size = 0;
	assert(pqueue);
	cur = pqueue->front;
	while (cur != NULL) {
		cur = cur->next;
		size++;
	}
	return size;
}


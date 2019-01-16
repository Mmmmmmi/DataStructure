#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stddef.h>
#include "Queue.h"



void QueueInitialize(Queue *pqueue)
{
	assert(pqueue != NULL);
	pqueue->front = NULL;
	pqueue->rear = NULL;
}

void QueueDestroy(Queue *pqueue)
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
Node * CreatNode(DataType data)
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
void QueuePush(Queue *pqueue, DataType data)
{
	Node *cur = NULL;
	assert(pqueue);
	if (pqueue->front == NULL)
	{
		pqueue->front = CreatNode(data);
		pqueue->rear = pqueue->front;
		return;
	}
	cur = pqueue->front; 
	while (cur->next != NULL) {
		cur = cur->next;
	}
	cur->next = CreatNode(data);
	pqueue->rear = cur->next;
}
DataType QueueTop(const Queue *pqueue)
{
	assert(pqueue);
	if (pqueue->front == NULL) {
		printf("\n队列为空，无法查看! \n");
		exit(EXIT_FAILURE);
	}
	return pqueue->front->data;
}

void QueuePop(Queue *pqueue)
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

int QueueEmpty(const Queue *pqueue)
{
    return pqueue->front == NULL && pqueue->rear == NULL;
}

unsigned QueueSize(const Queue *pqueue)
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

void test()
{
	Queue queue;
	QueueInitialize(&queue);
	QueuePush(&queue, 1);
	QueuePush(&queue, 2);
	QueuePush(&queue, 3);
	QueuePush(&queue, 4);
	QueuePush(&queue, 5);
	QueuePush(&queue, 6);
	printf("QueueSize = %d    \n", QueueSize(&queue));
	//printf("%d    ", QueueTop(&queue));
	//QueuePop(&queue);
	//printf("%d    ", QueueTop(&queue));
	//QueuePop(&queue);
	//printf("%d    ", QueueTop(&queue));
	//QueuePop(&queue);
	//printf("%d    ", QueueTop(&queue));
	//QueuePop(&queue);
	//printf("%d    ", QueueTop(&queue));
	//QueuePop(&queue);
	//printf("%d    ", QueueTop(&queue));
	//QueuePop(&queue);
	//printf("\nQueueSize = %d    \n", QueueSize(&queue));
	QueueDestroy(&queue);

}

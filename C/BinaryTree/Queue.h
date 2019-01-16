#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "BinaryTree.h"

typedef BNode* DataType;

typedef struct Node {
	DataType data;
	struct Node *next;
}Node;

typedef struct Queue{
	struct Node *front;
	struct Node *rear;
}Queue;



void Queue_Initialize(Queue *pqueue);							   //���г�ʼ��
void Queue_Destroy(Queue *pqueue);								   //��������
void Queue_Push(Queue *pqueue, DataType data);                     //β��
DataType Queue_Top(const Queue *pqueue);                                 //���ض���Ԫ��
void Queue_Pop(Queue *pqueue);                                     //ͷɾ
int Queue_Empty(const Queue *pqueue);								//�������Ƿ�Ϊ��
unsigned Queue_Size(const Queue *pqueue);							// ���ض��еĴ�С
void test();													   //���Ժ���

#endif // !__QUEUE_H__

#ifndef __QUEUE_H__
#define __QUEUE_H__

typedef int DataType;

typedef struct Node {
	DataType data;
	struct Node *next;
}Node;

typedef struct Queue{
	struct Node *front;
	struct Node *rear;
}Queue;



void QueueInitialize(Queue *pqueue);							   //���г�ʼ��
void QueueDestroy(Queue *pqueue);								   //��������
void QueuePush(Queue *pqueue, DataType data);                      //β��
DataType QueueTop(const Queue *pqueue);                            //���ض���Ԫ��
void QueuePop(Queue *pqueue);                                      //ͷɾ
int QueueEmpty(const Queue *pqueue);							   //�������Ƿ�Ϊ��
unsigned QueueSize(const Queue *pqueue);						   // ���ض��еĴ�С
void test();													   //���Ժ���

#endif // !__QUEUE_H__

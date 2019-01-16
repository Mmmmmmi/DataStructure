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



void Queue_Initialize(Queue *pqueue);							   //队列初始化
void Queue_Destroy(Queue *pqueue);								   //队列销毁
void Queue_Push(Queue *pqueue, DataType data);                     //尾插
DataType Queue_Top(const Queue *pqueue);                                 //返回队首元素
void Queue_Pop(Queue *pqueue);                                     //头删
int Queue_Empty(const Queue *pqueue);								//检查队列是否为空
unsigned Queue_Size(const Queue *pqueue);							// 返回队列的大小

#endif // !__QUEUE_H__

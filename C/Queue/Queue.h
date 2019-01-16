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



void QueueInitialize(Queue *pqueue);							   //队列初始化
void QueueDestroy(Queue *pqueue);								   //队列销毁
void QueuePush(Queue *pqueue, DataType data);                      //尾插
DataType QueueTop(const Queue *pqueue);                            //返回队首元素
void QueuePop(Queue *pqueue);                                      //头删
int QueueEmpty(const Queue *pqueue);							   //检查队列是否为空
unsigned QueueSize(const Queue *pqueue);						   // 返回队列的大小
void test();													   //测试函数

#endif // !__QUEUE_H__

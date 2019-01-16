#pragma once
#include "Stack.h"

typedef struct SQueue {
    Stack push;
    Stack pop;
}SQueue;


void SQueueInitialize(SQueue *pSQueue) {
    assert(pSQueue != NULL);
    Stack_Initialize(&(pSQueue->push));
    Stack_Initialize(&(pSQueue->pop));
}


void SQueuePush(SQueue *pSQueue, DataType d)
{
    assert(pSQueue != NULL);
    Stack_Push(&(pSQueue->push), d);
}

void SQueuePop(SQueue *pSQueue)
{
    DataType data = 0;
    assert(pSQueue != NULL);
    if (Stack_Empty(&(pSQueue->pop)) && Stack_Empty(&(pSQueue->push))) {
        return;
    }
    if( Stack_Empty(&(pSQueue->pop))) {
        while(!Stack_Empty(&(pSQueue->push))) {
            data = Stack_Top(&(pSQueue->push));
            Stack_Pop(&(pSQueue->push));
            Stack_Push(&(pSQueue->pop), data);
        }
    }
    Stack_Pop(&(pSQueue->pop));
}

DataType SQueueTop(SQueue *pSQueue)
{

    DataType data = 0;
    assert(pSQueue != NULL);
    if( Stack_Empty(&(pSQueue->pop))) {
        while(!Stack_Empty(&(pSQueue->push))) {
            data = Stack_Top(&(pSQueue->push));
            Stack_Pop(&(pSQueue->push));          
            Stack_Push(&(pSQueue->pop), data);
        }
    }
    data = Stack_Top(&(pSQueue->pop));
    return data;
}

int SQueueEmpty(SQueue *squeue)
{
    return Stack_Empty(&(squeue->push)) && Stack_Empty(&(squeue->pop));
}














void SQueueTest()
{
    SQueue squeue;
    SQueueInitialize(&squeue);
    SQueuePush(&squeue, 1);
    SQueuePush(&squeue, 2);
    SQueuePush(&squeue, 3);
    SQueuePush(&squeue, 4);
    SQueuePush(&squeue, 5);

    while(!SQueueEmpty(&squeue)) { 
         printf("%d\n", SQueueTop(&squeue));    
         SQueuePop(&squeue);                    
    }
}

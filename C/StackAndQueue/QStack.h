#pragma once
#include "Queue.h"

typedef struct QStack {
    Queue s1;
    Queue s2;
}QStack;


void QStackInitialize(QStack *pQStack)
{
    assert(pQStack != NULL);
    Queue_Initialize(&(pQStack->s1));
    Queue_Initialize(&(pQStack->s2));
}

void QStackPush(QStack *pQStack, DataType data)
{
    assert(pQStack != NULL);
    if (Queue_Empty(&(pQStack->s1))) {
        Queue_Push(&(pQStack->s2), data);
    }      
    else {
        Queue_Push(&(pQStack->s1), data);
    }
}

void QStackPop(QStack *pQStack)
{
    DataType data = 0;
    Queue *queue0 = NULL;
    Queue *queue1 = NULL;
    assert(pQStack != NULL);
    if(Queue_Empty(&(pQStack->s1)) && Queue_Empty(&(pQStack->s2))) {
        return;
    }       //两个都为空
    queue0 = &(pQStack->s1);
    queue1 = &(pQStack->s2);
    if (Queue_Empty(&(pQStack->s1))) {
        queue0 = &(pQStack->s2);
        queue1 = &(pQStack->s1);
    }
    while(Queue_Size(queue0) > 1) {
        data = Queue_Top(queue0);
        Queue_Pop(queue0);
        Queue_Push(queue1, data);
    }
    Queue_Pop(queue0);    
}
 
  
DataType  QStackTop(QStack *pQStack)                                              
 {                                                                            
     DataType data = 0;                                                       
     Queue *queue0 = NULL;                                                    
     Queue *queue1 = NULL;                                                    
     assert(pQStack != NULL);                                                 
     if(Queue_Empty(&(pQStack->s1)) && Queue_Empty(&(pQStack->s2))) {         
         printf("空队列");
         exit(EXIT_FAILURE);                                                              
     }       //两个都为空                                                     
     queue0 = &(pQStack->s1);                                                 
     queue1 = &(pQStack->s2);                                                 
     if (Queue_Empty(&(pQStack->s1))) {                                       
         queue0 = &(pQStack->s2);                                             
         queue1 = &(pQStack->s1);                                             
     }                                                                        
     while(Queue_Size(queue0) > 1) {                                          
         data = Queue_Top(queue0);                                            
         Queue_Pop(queue0); 
         Queue_Push(queue1, data);                                            
     }                                                                        
     data = Queue_Top(queue0);
     Queue_Pop(queue0);
     Queue_Push(queue1, data);
     return data;
 }                                                                            
 
int QStackEmpty(QStack *pQStack)
{
    return Queue_Empty(&(pQStack->s1)) && Queue_Empty(&(pQStack->s2));
}








void QStackTest()
{
    QStack qstack;
    QStackInitialize(&qstack);
    QStackPush(&qstack, 1);
    QStackPush(&qstack, 2);
    QStackPush(&qstack, 3);
    QStackPush(&qstack, 4);
    QStackPush(&qstack, 5);
    while(!QStackEmpty(&qstack)) {
      printf("%d \n", QStackTop(&qstack));
        QStackPop(&qstack);
    }
}

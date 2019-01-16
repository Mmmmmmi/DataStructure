#pragma once

#include "Stack.h"


typedef struct MinStack {
    Stack s;
    Stack m;
}MinStack;



void MinStackInitiliz (MinStack *pMinStack)
{
    assert(pMinStack != NULL);
    Stack_Initialize(&(pMinStack->m));
    Stack_Initialize(&(pMinStack->s));
}

void MinStackPrint(MinStack *pMinStack)
{
    assert(pMinStack != NULL);
    //assert(Stack_Empty(&(pMinStack->s)) != 1);
    //assert(Stack_Empty(&(pMinStack->s)) != 0);
    if(Stack_Empty(&(pMinStack->s)) + Stack_Empty(&(pMinStack->s)) == 0) {
        printf("min = %d\n", Stack_Top(&(pMinStack->m)));  
    }
}

void MinStackPush(MinStack *pMinStack, DataType data)
{
    assert(pMinStack != NULL);
    if (Stack_Empty(&(pMinStack->m)) || data <= Stack_Top(&(pMinStack->s))) {
                   Stack_Push(&(pMinStack->m), data);
                   }
    Stack_Push(&(pMinStack->s), data);
}

void MinStackPop(MinStack *pMinStack)
{
    assert(pMinStack != NULL);
    if (Stack_Top(&(pMinStack->s)) == Stack_Top(&(pMinStack->m))) {
        Stack_Pop(&(pMinStack->m));
    }
    Stack_Pop(&(pMinStack->s));
}


void MinSrackTest()
{
    MinStack minstack;
    MinStackInitiliz(&minstack);
    MinStackPush(&minstack, 4);
    MinStackPush(&minstack, 5);
    MinStackPush(&minstack, 1);
    MinStackPush(&minstack, 1);
    MinStackPush(&minstack, 4);
    //while(!Stack_Empty(&(minstack.s))) {
    //    MinStackPop(&minstack);
    //    MinStackPrint(&minstack);
    //}
    
    MinStackPrint(&minstack);
}





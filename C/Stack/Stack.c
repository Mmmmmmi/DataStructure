
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
#include"Stack.h"




void StackInitialize(Stack *pStack)
{
	assert(pStack);
	pStack->base = (DataType *)malloc((sizeof(DataType) * DEFAULT_CAPACITY));
	if (pStack->base == NULL) {
		perror("error for realloc Stack");
		exit(EXIT_FAILURE);
	}
	pStack->capacity = DEFAULT_CAPACITY;
	pStack->top = 0;
}
void StackPush(Stack *pStack, DataType data)
{
	DataType *tmp = NULL;
	assert(pStack);
	if (pStack->top < pStack->capacity) {
		pStack->base[pStack->top] = data;
		pStack->top++;
		return;
	}
	tmp = (DataType *)realloc(pStack->base, (sizeof(DataType) * (pStack->capacity + ADD_CAPACITY)));
	if (tmp == NULL) {
		perror("error for realloc Stack");
		exit(EXIT_FAILURE);
	}
	pStack->base = tmp;
	pStack->base[pStack->top] = data;
	pStack->top++;
	pStack->capacity += ADD_CAPACITY;
}
DataType StackTop(const Stack *pStack)
{
	assert(pStack != NULL);
	if (pStack->top == 0) {
		printf("Stack Is Empty , Failure!\n");
		exit(EXIT_FAILURE);
	}
	return pStack->base[pStack->top - 1];
}
unsigned StackSize(Stack *pStack)
{
	return (unsigned)pStack->top;
}
void StackPop(Stack *pStack)
{
	assert(pStack != NULL);
	if (pStack->top == 0) {
		printf("Stack Is Empty , Failure!\n");
		return;
	}
	pStack->top--;
}
int StackFull(const Stack *pStack)
{
	assert(pStack);
	return pStack->top == pStack->capacity;
}
int StackEmpty(const Stack *pStack)
{
	assert(pStack);
	return pStack->top == 0;
}
void StackCopy(Stack *pStackDest, const Stack *pStackSrc)
{
	DataType *tmp = NULL;
	assert(pStackDest != NULL);
	assert(pStackSrc != NULL);
	tmp = (DataType*)malloc(sizeof(DataType) * pStackSrc->capacity);
	if (tmp == NULL) {
		perror("error for malloc pStackDest");
		exit(EXIT_FAILURE);
	}

	memcpy(tmp, pStackSrc->base, (sizeof(DataType) * pStackSrc->top));
	pStackDest->base = tmp;
	pStackDest->capacity = pStackSrc->capacity;
	pStackDest->top = pStackSrc->top;


}
void StackDestroy(Stack *pStack)
{
	assert(pStack);
	assert(pStack->base);
	free(pStack->base);
	pStack->base = NULL;
	pStack->capacity = 0;
	pStack->top = 0;
}

void test()
{
	Stack stack = { NULL, 0 };
	Stack stack1 = { NULL, 0 };

	StackInitialize(&stack);
	StackPush(&stack, 3);
	StackPush(&stack, 2);
	StackPush(&stack, 1);
	StackPush(&stack, 0);
	StackCopy(&stack1, &stack);
	printf("stack:\n");
	printf("%d\n", StackTop(&stack));
	StackPop(&stack);
	printf("%d\n", StackTop(&stack));
	StackPop(&stack);
	printf("%d\n", StackTop(&stack));
	StackPop(&stack);
	printf("%d\n", StackTop(&stack));
	StackPop(&stack);
	printf("stack1:\n");
	printf("%d\n", StackTop(&stack1));
	StackPop(&stack1);
	printf("%d\n", StackTop(&stack1));
	StackPop(&stack1);
	printf("%d\n", StackTop(&stack1));
	StackPop(&stack1);
	printf("%d\n", StackTop(&stack1));
	StackPop(&stack1);
	StackDestroy(&stack);
	StackDestroy(&stack1);
}

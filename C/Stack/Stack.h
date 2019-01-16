#ifndef __Stack_H__
#define __Stack_H__



typedef int DataType;

typedef struct Stack 
{
	DataType *base;
	int capacity;
	int top;
}Stack;

#define ADD_CAPACITY 3
#define DEFAULT_CAPACITY 2


void StackInitialize(Stack *pStack);		      //ջ��ʼ��
void StackPush(Stack *pStack, DataType data);    //ѹջ
DataType StackTop(const Stack *pStack);		  //����ջ��Ԫ��
void StackPop(Stack *pStack);					  //��ջ
unsigned StackSize(Stack *pStack);					  //����ջʹ�õĸ���
int StackFull(const Stack *pStack);			  //�ж�ջ�Ƿ�Ϊ��
int StackEmpty(const Stack *pStack);			  //�ж�ջ�Ƿ�Ϊ��
void StackCopy(Stack *pStackDest, const Stack *pStackSrc);    //ջ����
void StackDestroy(Stack *pStack);                //����ջ
void test();                                       //����
#endif // !__Stack_H__

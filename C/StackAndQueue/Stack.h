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


void Stack_Initialize(Stack *pStack);		      //ջ��ʼ��
void Stack_Push(Stack *pStack, DataType data);    //ѹջ
DataType Stack_Top(const Stack *pStack);		  //����ջ��Ԫ��
void Stack_Pop(Stack *pStack);					  //��ջ
unsigned Stack_Size(Stack *pStack);					  //����ջʹ�õĸ���
int Stack_Full(const Stack *pStack);			  //�ж�ջ�Ƿ�Ϊ��
int Stack_Empty(const Stack *pStack);			  //�ж�ջ�Ƿ�Ϊ��
void Stack_Copy(Stack *pStackDest, const Stack *pStackSrc);    //ջ����
void Stack_Destroy(Stack *pStack);                //����ջ
#endif // !__Stack_H__

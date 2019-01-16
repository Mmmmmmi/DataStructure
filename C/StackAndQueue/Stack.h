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


void Stack_Initialize(Stack *pStack);		      //栈初始化
void Stack_Push(Stack *pStack, DataType data);    //压栈
DataType Stack_Top(const Stack *pStack);		  //返回栈顶元素
void Stack_Pop(Stack *pStack);					  //出栈
unsigned Stack_Size(Stack *pStack);					  //返回栈使用的个数
int Stack_Full(const Stack *pStack);			  //判断栈是否为空
int Stack_Empty(const Stack *pStack);			  //判断栈是否为空
void Stack_Copy(Stack *pStackDest, const Stack *pStackSrc);    //栈拷贝
void Stack_Destroy(Stack *pStack);                //销毁栈
#endif // !__Stack_H__

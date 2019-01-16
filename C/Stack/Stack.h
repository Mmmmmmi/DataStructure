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


void StackInitialize(Stack *pStack);		      //栈初始化
void StackPush(Stack *pStack, DataType data);    //压栈
DataType StackTop(const Stack *pStack);		  //返回栈顶元素
void StackPop(Stack *pStack);					  //出栈
unsigned StackSize(Stack *pStack);					  //返回栈使用的个数
int StackFull(const Stack *pStack);			  //判断栈是否为空
int StackEmpty(const Stack *pStack);			  //判断栈是否为空
void StackCopy(Stack *pStackDest, const Stack *pStackSrc);    //栈拷贝
void StackDestroy(Stack *pStack);                //销毁栈
void test();                                       //测试
#endif // !__Stack_H__

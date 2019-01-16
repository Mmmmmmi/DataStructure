#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int DataType;

typedef struct Node
{
	int data;
	struct Node *next;
	struct Node *random;
}Node;
Node *CreatNode(DataType data)
{
	Node *NewNode = (Node *)malloc(sizeof(Node));
	if (NewNode == NULL)
	{
		perror("error for malloc");
		exit(EXIT_FAILURE);
	}
	NewNode->data = data;
	NewNode->next = NULL;
	NewNode->random = NULL;
	return NewNode;
}
void Link_Creat(Node **plink1, DataType data)
{

	Node *cur = NULL;
	assert(plink1);
	cur = *plink1;
	if (*plink1 == NULL)   //空链表
	{
		*plink1 = CreatNode(data);
		return;
	}
	while (cur->next != NULL)    //非空链表
	{
		cur = cur->next;
	}
	cur->next = CreatNode(data);
}
void Link_Print(const Node *link1)
{
	Node *cur = NULL;
	cur = link1;
	while (cur != NULL)
	{
		//如果有的节点的random指向空
		if (cur->random == NULL)
		{
			printf("Node->data = %d   Node->random = NULL\n", cur->data);
		}
		else
		{
			printf("cur = %p   cur->data = %d    cur->random = %p    cur->random->data = %d\n\n", cur, cur->data, cur->random, cur->random->data);
		}
		cur = cur->next;
	}
}
void Link_Copy(Node **plink1, Node **plink2)
{
	Node *cur1 = NULL;
	Node *cur2 = NULL;
	Node *front2 = NULL;
	assert(plink1 && plink2);
	if (*plink1 == NULL)       //链表1为空
	{
		printf("plink1 NULL");
		return;
	}
	cur1 = *plink1;
	//拷贝开始
	while (cur1 != NULL)
	{
		//拷贝next
		Node *NewNode = CreatNode(cur1->data);
		NewNode->next = cur1->next;
		cur1->next = NewNode;
		cur1 = cur1->next->next;
	}
	cur1 = *plink1;
	while (cur1 != NULL)
	{
		//拷贝random
		if (cur1->random->next != NULL)
		{
			cur1->next->random = cur1->random->next;
		}
		cur1 = cur1->next->next;
	}
	//结束拷贝
	//Link_Print(*plink1);
	//printf("\n");
	//分离
	cur1 = *plink1;
	cur2 = *plink2;
	while (cur1 != NULL)
	{
		//第一个
		if (*plink2 == NULL)
		{

			*plink2 = cur1->next;
			cur1->next = cur1->next->next;
			cur2 = *plink2;
		}
		//其他
		else
		{
			cur2->next = cur1->next;
			cur1->next = cur1->next->next;
			cur2 = cur2->next;
		}
		cur1 = cur1->next;
	}
	//结束分离
}
void test_exp(Node **plink1)
{

	//简单的用例   
	Node *link1 = NULL;
	assert(plink1);
	Link_Creat(plink1, 1);
	Link_Creat(plink1, 2);
	Link_Creat(plink1, 3);
	Link_Creat(plink1, 4);
	Link_Creat(plink1, 5);
	Link_Creat(plink1, 6);
	link1 = *plink1;
	link1->random = link1->next->next->next->next->next;
	link1->next->random = link1;
	link1->next->next->random = link1->next;
	link1->next->next->next->random = link1->next->next;
	link1->next->next->next->next->random = link1->next->next->next;
	link1->next->next->next->next->next->random = link1->next->next->next->next;
}
int main()
{
	int i = 0;
	Node *link1 = NULL;
	Node *link2 = NULL;
	test_exp(&link1);
	printf("link1: \n");
	Link_Print(link1);
	printf("\n");
	Link_Copy(&link1, &link2);
	printf("link2: \n");
	Link_Print(link2);
	return 0;
}



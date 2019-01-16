#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;


typedef struct Node {
    DataType data;
    struct Node *next;
}Node, *pNode;


typedef struct SNode {
    DataType data;
    struct SNode *next;
    struct SNode *random;
}SNode, *pSNode;



void LinkListInitialize(pNode *ppNode)   //链表的初始化
{
    assert(ppNode != NULL);
    *ppNode = NULL; 
}

void LinkListDestroy(pNode *ppNode)    //链表的销毁
{
    Node *cur = NULL;
    Node *del = NULL;
    assert(ppNode != NULL);
    cur = *ppNode;
    while(cur != NULL)
    {
        del = cur;
        cur = cur->next;
        free(del);
    }
    *ppNode = NULL;
}

Node *CreatNode(DataType data)         //创建节点
{
    Node *newnode = (Node *) malloc (sizeof(Node));
    assert(newnode != NULL);
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void LinkListPushFront(pNode *ppNode, DataType data)         //链表的头插
{
    assert(ppNode != NULL);
    Node *newnode = CreatNode(data);
    newnode->next = *ppNode; 
    *ppNode = newnode;
}

void LinkListPrint(const pNode pnode)             //链表的输出
{
    Node *cur = pnode;
    while(cur != NULL) {
        printf("%d ", cur->data);
        cur =cur->next;
    }
    printf("\n");
}


void LinkListSPrint(const pSNode psnode)      
{                                          
    SNode *cur = psnode;                     
    while(cur != NULL) {
        printf("cur = %p  cur->data = %d cur ->random = %p  cur->random->data =  %d\n", cur, cur->data, cur->random, cur->random->data);          
        cur =cur->next;                    
    }                                      
    printf("\n");                          
}                                          


void  LinkListReverse(pNode *ppNode)            //逆置单链表
{
    Node *NewNode = NULL;
    assert(ppNode != NULL);
    if(*ppNode == NULL || (*ppNode)->next == NULL) {                  //链表为空或只有一个节点 不需要逆置
        return;
    }
    
    Node *p1 = NULL;
    Node *p2 = *ppNode;
    Node *p3 = NULL;


    while(p2 != NULL) {
        p3 = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p3;
    }
    *ppNode = p1;
}

void JocephCircle(pNode *ppNode, int k)                       //约瑟夫环
{
    int i = 0;
    Node *prev = NULL;
    Node *cur = NULL;
    assert(ppNode != NULL);
    if(*ppNode == NULL)              //空链表 返回
        return;
    if((*ppNode)->next != NULL) {
        cur = *ppNode;
        while(cur->next != NULL) {             //先变成环
            cur = cur->next;
        }
        cur->next = *ppNode;
        prev = cur;
        cur = *ppNode;
        while(cur->next != cur) {
            for(i = 0; i < k - 1; i++) {
                prev = cur;
                cur = cur->next;
            }
            prev->next = cur->next;
            free(cur);
            cur = prev->next;
        }
    }
    cur->next = NULL;
    *ppNode = cur;
    printf("JocephCircle  k = %d  : %d \n", k,  cur->data);
}

Node *Merge(pNode list1, pNode list2)       //合并两个链表，使之依然有序
{
    Node *new = NULL;
    Node *newcur = NULL;
    Node *cur1 = NULL;
    Node *cur2 = NULL;
    assert(list1 != NULL && list2 != NULL);
    cur1 = list1;
    cur2 = list2;
    while(cur1 != NULL && cur2 != NULL) {
        if(cur1->data <= cur2->data) {
            if(new == NULL) {
                new = cur1;
            }
            else {
                newcur->next = cur1;
            }
            newcur = cur1;
            cur1 = cur1->next;
        }
        else {
            if(new == NULL) {
                new = cur2;               
            }  
            else { 
                newcur->next = cur2;
            }
            newcur = cur2;
            cur2 = cur2->next;
        }
    }
    newcur->next = NULL;
    if(cur1 == NULL) {
        newcur->next = cur2;
    }
    if(cur2 == NULL) {
        newcur->next = cur1;
    }
    LinkListPrint(new);
    return new;
}

Node *ReturnNode(pNode pnode, int k)
{
    int i = k;
    Node *prev = NULL;
    Node *cur = NULL;
    if(pnode == NULL || pnode->next == NULL) {         //只有一个 或者为空
        return pnode;
    }
    cur = pnode;
    prev = pnode;
    while(i--) {
        cur = cur->next;
    }
    while(cur != NULL) {
        prev = prev->next;
        cur = cur->next;
    }
    printf("ReturnNode k = %d:  %d\n", k, prev->data);

}

SNode *CreatSNode(DataType data)
{
    SNode *NewNode = (SNode*) malloc (sizeof(SNode));
    NewNode->data = data;
    NewNode->random = NULL;
    NewNode->next = NULL;
    return NewNode;
}

SNode *SNodeCopy(pSNode head)
{
    SNode *cur = NULL;
    SNode *next = NULL;
    SNode *New = NULL;
    SNode *newcur = NULL;
    SNode *newnext = NULL;
    SNode *newnode = NULL;
    //复制链表
    cur = head;
    while(cur != NULL) {
        next = cur->next;
        newnode = CreatSNode(cur->data);
        newnode->next = next;
        cur->next = newnode;
        cur = next;
    }

    //复制random
    cur = head;
    newcur = head->next;
    while(cur != NULL) {
        if(cur->random == NULL) {
            newcur->random = cur->random;
        }
        else {
            newcur->random = cur->random->next;
        }
        cur = newcur->next;
        if(cur != NULL) {
            newcur = cur->next;
        }
    }
    
//    LinkListSPrint(head);
   
    //分离
    cur = head;
    New = head->next;
    newcur = New;
    while(cur != NULL) {

        cur->next = newcur->next;
        next = newcur->next;
        if(next == NULL) {
            break;
        }
        newcur->next = next->next;
        newcur = newcur->next; 
    }


    return New;
}

void test()
{
       Node *head = NULL;         
       Node *head0 = NULL;        
       LinkListInitialize(&head); 
       LinkListInitialize(&head0);
       LinkListPushFront(&head, 1);
       LinkListPushFront(&head, 3);
       LinkListPushFront(&head, 5);
       LinkListPushFront(&head, 7);
       LinkListPushFront(&head, 9);
       LinkListPushFront(&head0, 2);
       LinkListPushFront(&head0, 4);
       LinkListPushFront(&head0, 6);
       LinkListPushFront(&head0, 8);
       LinkListPushFront(&head0, 1);
      // printf("LinkListPushFront
       LinkListPrint(head);       
       LinkListReverse(&head);    
       ReturnNode(head, 3);       
       LinkListPrint(head);       
      // LinkListReverse(&head0); 
       // printf("LinkListReverse 
      // LinkListPrint(head);     
      // JocephCircle(&head, 3);  
       //Merge(head,head0);       
      // LinkListDestroy(&head);  
      // LinkListDestroy(&head0); 


 }


void test1()
{

    int i = 0;
    SNode *shead = NULL;
    SNode *cur = NULL;
    SNode *newnode = NULL;
    newnode = CreatSNode(0);
    shead = newnode;     
    cur = shead;
    for(i = 1; i < 4; i++) {
         newnode = CreatSNode(i);
         cur->next  = newnode;
         cur = cur->next;
    }

    shead->random = shead->next->next->next;
    shead->next->random = shead;
    shead->next->next->random = shead->next;
    shead->next->next->next->random = shead->next->next;

    LinkListSPrint(shead);
    LinkListSPrint(SNodeCopy(shead));
}









int main()
{
   // test();
    test1();
    return 0;
}



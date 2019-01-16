#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "BinaryTree.h"
#include "Queue.h"
#include "Stack.h"
                                                      
BNode* CreateNode(TDataType data)              
{                                                     
    BNode *NewNode = (BNode*) malloc (sizeof(BNode));
    assert(NewNode != NULL);
    NewNode->data = data;
    NewNode->left = NULL;
    NewNode->right = NULL;
    return NewNode;
}                                                     
                                                                                         
Result CreateTree(TDataType preorder[], int size)      
{   
    TDataType rootValue = preorder[0];   
    Result ret = {NULL, 0};
    Result leftret = {NULL, 0};
    Result rightret = {NULL, 0};
    if(size == 0) {
        Result ret = {NULL, 0};
        return ret;
    }
    if (rootValue == -1) {
        Result ret = {NULL, 1};
        return ret;
    }
    ret.result = CreateNode(rootValue);
    leftret = CreateTree(preorder + 1, size - 1);
    (ret.result)->left = leftret.result;
    rightret = CreateTree(preorder + 1 + leftret.use, size - 1 - leftret.use);
    (ret.result)->right = rightret.result;
    ret.use = 1 + leftret.use + rightret.use;
    return ret;
}

void PreOrderRec(BNode *root)
{
    if (root == NULL) {
        return;
    }    
    printf("%d ", root->data);
    PreOrderRec(root->left);
    PreOrderRec(root->right);
}

void InOrderRec(BNode *root)
{
    if (root == NULL) {
       return; 
    }
    InOrderRec(root->left);
    printf("%d ", root->data);
    InOrderRec(root->right);
}

void PostOrderRec(BNode *root) 
{
    if (root == NULL) {
        return;
    }
    PostOrderRec(root->left);
    PostOrderRec(root->right);
    printf("%d ", root->data);
}

void PreOrderLoop(BNode *root)
{
    if (root == NULL) {
        return;
    }    
    printf("%d ", root->data);
    PreOrderRec(root->left);
    PreOrderRec(root->right);
}

void PreOrderLoop(BNode *root)
{
    Stack stack;
    BNode *cur = NULL;
    BNode *top = NULL;
    Stack_Initialize(&stack);
    if (root == NULL) {
        return;
    }

    cur = root;
    while(!Stack_Empty(&stack) || cur != NULL) {
        while (cur != NULL) {
            Stack_Push(&stack, cur);
            printf("%d ", cur->data);
            cur = cur->left;
        }
        top = Stack_Top(&stack);
        Stack_Pop(&stack);
        cur = top->right;
    }
}

void InOrderLoop(BNode *root)
{
    if (root == NULL) {
       return; 
    }
    InOrderRec(root->left);
    printf("%d ", root->data);
    InOrderRec(root->right);
    BNode *cur = NULL;
    BNode *top = NULL;
    if (root == NULL) {
       return; 
    }
}

void PostOrderLoop(BNode *root) 
{
    if (root == NULL) {
        return;
    }
    PostOrderRec(root->left);
    PostOrderRec(root->right);
    printf("%d ", root->data);
}

int GetBTNodeSize(BNode *root)
{
    if (root == NULL) {
        return 0;
    }
    return GetBTNodeSize(root->left) + GetBTNodeSize(root->right) + 1;
}

int GetBTNodeLeafSize(BNode *root)
{
    if (root == NULL) {
        return 0;
    }
    else if  (root->left == NULL &&  root->right == NULL) {
        return 1;
    }
    else {
        return GetBTNodeLeafSize(root->left) + GetBTNodeLeafSize(root->right);
    }
}

int GetKLevelSize(BNode *root, int k)
{
    assert(k > 0);
    if (root == NULL) {
        return 0;
    }
    if (k == 1) {
        return 1;
    }
    return GetKLevelSize(root->left, k - 1) + GetKLevelSize(root->right, k - 1);
}

int GetBTNodeHeight(BNode *root)
{
    int left = 0;
    int right = 0;
    if (root == NULL) {
        return 0;
    }
    left = GetBTNodeHeight(root->left);
    right = GetBTNodeHeight(root->right);
    return (left > right ? left :right) + 1;
}

BNode *SearchBTNode(BNode *root, TDataType key)
{
    BNode *ret = NULL;
    if (root == NULL) {
        return NULL;
    }
    if (root->data == key) {
        return root;
    }
    ret = SearchBTNode(root->left, key);
    if (ret) {
        return ret;
    }
    ret = SearchBTNode(root->right, key);
    return ret;
}

void LevelOrder(BNode *root)
{
    BNode *front = NULL;
    Queue queue;
    Queue_Initialize(&queue);
    Queue_Push(&queue, root);
    while(!Queue_Empty(&queue)) {
        front = Queue_Top(&queue);
        Queue_Pop(&queue);
        printf("%d  ", front->data);
        if (front->left != NULL) {
            Queue_Push(&queue, front->left);
        }
        if (front->right != NULL) {
            Queue_Push(&queue, front->right);
        }
    }
    Queue_Destroy(&queue);
}

int IsCompleteTree(BNode *root)
{
    int flag = 1;
    BNode *front = NULL;
    Queue queue;
    if (root == NULL) {
        return 1;
    }
    Queue_Initialize(&queue);
    Queue_Push(&queue, root);
    while(!Queue_Empty(&queue)) {
        front = Queue_Top(&queue);
        Queue_Pop(&queue);
        if (front != NULL && flag == 0) {
            printf("No\n");
            Queue_Destroy(&queue);
            return 0;
        }
        if (front == NULL) {
            flag = 0;
            continue;
        }
        Queue_Push(&queue, front->left);
        Queue_Push(&queue, front->right);
    }
    Queue_Destroy(&queue);
    printf("Is\n");
    return 1;
}


void  BinaryTreeTest()                                
{ 
    int key = 0;
    TDataType preorder[] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6 ,7};                         
    int size = sizeof(preorder) / sizeof(preorder[0]);
    BNode *btree = NULL;
    Result result = {NULL, 0};
    result = CreateTree(preorder, size);
    btree = result.result;
    printf("PreOrderRec          :");
    PreOrderRec(btree);
    printf("\n");
    printf("PreOrderLoop         :");
    PreOrderLoop(btree);
    printf("\n");
    printf("InOrderRec           :");
    InOrderRec(btree);
    printf("\n");
    printf("PostOrderRec         :");
    PostOrderRec(btree);
    printf("\n");
//    printf("GetBTNodeSize        :%d \n", GetBTNodeSize(btree));
//    printf("GetBTNodeLeafSize    :%d \n", GetBTNodeLeafSize(btree));
//    key = 3;   
//    printf("GetKLevelSize  %d     :%d \n", key, GetKLevelSize(btree, key));
//    printf("GetBTNodeHeight      :%d \n", GetBTNodeHeight(btree));
//    key = 8;
//    printf("SearchBTNode   %d     :%p \n", key, SearchBTNode(btree, key));
//    printf("LevelOrder           :");
//    LevelOrder(btree); 
//    printf("\n");
//    printf("IsCompleteTree       :");
//    IsCompleteTree(btree);
//    printf("\n");
}                      


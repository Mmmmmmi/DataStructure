#pragma once


typedef int TDataType;

typedef struct BNode{
    TDataType data;
    struct BNode *left;
    struct BNode *right;

} BNode;

typedef struct Result {
    BNode *result;
    int use;
}Result;



Result CreateTree(TDataType preorder[], int size);  //创建树
//递归
void PreOrderRec(BNode *root);          //先序遍历
void InOrderRec(BNode *root);           //中序遍历
void PostOrderRec(BNode *root);         //后序遍历 
//循环
void PreOrderLoop(BNode *root);          //先序遍历
void InOrderLoop(BNode *root);           //中序遍历
void PostOrderLoop(BNode *root);         //后序遍历 

int GetBTNodeSize(BNode *root);         //获取节点个数
int GetBTNodeLeafSize(BNode *root);     //获取叶子节点个数
int GetKLevelSize(BNode *root, int k);  //获取第K层节点个数
int GetBTNodeHeight(BNode *root);       //获取深度
BNode *SearchBTNode(BNode *root, TDataType key);    //查找节点
void BinaryTreeTest();     //测试

#ifndef __SEQLIST_H__ 
#define __SEQLIST_H__ 

#include <stdbool.h>



typedef int DataType;

////动态顺序表
#define Dynamic_List

#define DEFAULT_CAPACITY 3 
#define DEFAULT_ADD 2 

typedef struct SeqList
{
	DataType *data;//数据区 
	int sz;//有效个数 
	int capacity;//容量 
}SeqList, *pSeqList;


////静态顺序表 
//#define static_List
//
//#define MAX 100
//typedef struct SeqList 
//{ 
//	DataType data[MAX]; 
//	int sz; 
//}SeqList, *pSeqList; 




void InitSeqList(pSeqList ps);							//初始化

void DestroySeqList(pSeqList ps);						//销毁

void PushBack(pSeqList ps, DataType d);					//尾插

void PrintSeqList(const pSeqList ps);					 //输出

void PopBack(pSeqList ps);				       			//尾删

void PushFront(pSeqList ps, DataType d);				  	//头插

void PopFront(pSeqList ps);								   //头删

void PosInsert(pSeqList ps, int pos, DataType d);			   //指定坐标插入元素

void DataInsert(pSeqList ps, DataType src, DataType d);			   //指定元素前面插入元素

void Sort(pSeqList ps);									   //排序

int BinarySearch(pSeqList ps, DataType d);			   	   //二分搜索

int Find(pSeqList ps, DataType d);						   //查找

void Remove(pSeqList ps, DataType d);					  //删除遇到的第一个d

void RemoveALL(pSeqList ps, DataType d);                   //删除所有的d

int SeqList_Size(const pSeqList ps);                       //顺序表中数据个数

bool SeqListEmpty(const pSeqList ps);                      //顺序表是否为空

bool SeqListFull(const pSeqList ps);						//顺序表是否为满


void test();											//测试程序

#endif //__SEQLIST_H__ 

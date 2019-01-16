#ifndef __SEQLIST_H__ 
#define __SEQLIST_H__ 

#include <stdbool.h>



typedef int DataType;

////��̬˳���
#define Dynamic_List

#define DEFAULT_CAPACITY 3 
#define DEFAULT_ADD 2 

typedef struct SeqList
{
	DataType *data;//������ 
	int sz;//��Ч���� 
	int capacity;//���� 
}SeqList, *pSeqList;


////��̬˳��� 
//#define static_List
//
//#define MAX 100
//typedef struct SeqList 
//{ 
//	DataType data[MAX]; 
//	int sz; 
//}SeqList, *pSeqList; 




void InitSeqList(pSeqList ps);							//��ʼ��

void DestroySeqList(pSeqList ps);						//����

void PushBack(pSeqList ps, DataType d);					//β��

void PrintSeqList(const pSeqList ps);					 //���

void PopBack(pSeqList ps);				       			//βɾ

void PushFront(pSeqList ps, DataType d);				  	//ͷ��

void PopFront(pSeqList ps);								   //ͷɾ

void PosInsert(pSeqList ps, int pos, DataType d);			   //ָ���������Ԫ��

void DataInsert(pSeqList ps, DataType src, DataType d);			   //ָ��Ԫ��ǰ�����Ԫ��

void Sort(pSeqList ps);									   //����

int BinarySearch(pSeqList ps, DataType d);			   	   //��������

int Find(pSeqList ps, DataType d);						   //����

void Remove(pSeqList ps, DataType d);					  //ɾ�������ĵ�һ��d

void RemoveALL(pSeqList ps, DataType d);                   //ɾ�����е�d

int SeqList_Size(const pSeqList ps);                       //˳��������ݸ���

bool SeqListEmpty(const pSeqList ps);                      //˳����Ƿ�Ϊ��

bool SeqListFull(const pSeqList ps);						//˳����Ƿ�Ϊ��


void test();											//���Գ���

#endif //__SEQLIST_H__ 

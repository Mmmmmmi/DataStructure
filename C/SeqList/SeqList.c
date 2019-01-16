#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "SeqList.h"


#ifdef static_List

void InitSeqList(pSeqList ps)
{
	assert(ps != NULL);
	ps->sz = 0;
}

void DestroySeqList(pSeqList ps)
{
	assert(ps != NULL);
	ps->sz = 0;
}

void PushBack(pSeqList ps, DataType d)
{
	assert(ps != NULL);
	if (ps->sz == MAX){
		printf("SeqList Full, Can't Push");
		return;
	}
	ps->data[ps->sz] = d;
	ps->sz++;
}

void PrintSeqList(const pSeqList ps)
{
	assert(ps != NULL);
	for (int i = 0; i < ps->sz; i++) {
		printf("%d  ", ps->data[i]);
	}
	printf("\n");
}

void PopBack(pSeqList ps)
{
	assert(ps != NULL);
	if (ps->sz == 0) {
		return;
	}
	ps->sz--;
}

void PushFront(pSeqList ps, DataType d)
{
	int i = 0;
	assert(ps != NULL);
	if (ps->sz == MAX) {
		printf("满了！\n");
		return;
	}
	for (i = ps->sz; i > 0; i--) {
		ps->data[i] = ps->data[i - 1];
	}
	ps->data[0] = d;
	ps->sz++;

}

void PopFront(pSeqList ps)
{
	int i = 0;
	assert(ps != NULL);
	if (ps->sz == 0) {
		return;
	}
	for (i = 0; i < ps->sz - 1; i++) {
		ps->data[i] = ps->data[i + 1];
	}
	ps->sz--;
}

void PosInsert(pSeqList ps, int pos, DataType d)
{
	int i = 0;
	assert(ps != NULL);
	if (ps->sz == MAX) {          //顺序表满了
		printf("满了，插入失败！\n");
		return;
	}
	if (pos <= 0 || pos > ps->sz) {        //给定下标错误
		return;
	}
	for (i = ps->sz; i > pos; i--) {
		ps->data[i] = ps->data[i - 1];
	}
	ps->data[pos] = d;
	ps->sz++;
}

void DataInsert(pSeqList ps, DataType src, DataType d)
{
	int i = 0;
	assert(ps != NULL);
	i = Find(ps, src);
	if (i == -1) {
		printf("插入失败！");
		return;
	}
	PosInsert(ps, i, d);

}

void Sort(pSeqList ps)
{
	int i = 0;
	int j = 0;
	int flag = 0;
	assert(ps != NULL);
	if (ps->sz <= 1) {
		return;
	}
	for (i = 0; i < ps->sz - 1; i++) {
		for (j = 0; j < ps->sz - i - 1; j++) {
			if (ps->data[j] > ps->data[j + 1]) {
				DataType tmp = ps->data[j];
				ps->data[j] = ps->data[j + 1];
				ps->data[j + 1] = tmp;
				flag = 1;
			}
		}
		if (flag == 0) {
			break;
		}
		flag = 0;
	}
}

int BinarySearch(pSeqList ps, DataType d)
{
	int left = 0;
	int right = 0;
	int mid = 0;
	assert(ps != NULL);
	right = ps->sz - 1;
	while (left <= right) {
		mid = left + ((right - left) >> 1);
		if (d < ps->data[mid]) {
			right = mid - 1;
		}
		else if (d > ps->data[mid]) {
			left = mid + 1;
		}
		else if (d == ps->data[mid]) {
			return mid;
		}
	}
	return -1;
}

int Find(pSeqList ps, DataType d)
{
	int i = 0;
	assert(ps != NULL);
	for (i = 0; i < ps->sz; i++) {
		if (d == ps->data[i]) {
			return i;
		}
	}
	printf("未找到！\n");
	return -1;
}

void Remove(pSeqList ps, DataType d)
{
	int i = 0;
	int j = 0;
	assert(ps != NULL);
	for (i = 0; i < ps->sz; i++) {
		if (d == ps->data[i]) {
			break;
		}
	}
	if (i == ps->sz) {
		printf("未找到， 无法删除！\n");
		return;
	}
	else {
		for (j = i; j < ps->sz - 1; j++) {
			ps->data[j] = ps->data[j + 1];
		}
		ps->sz--;
	}
}

void RemoveALL(pSeqList ps, DataType d)
{
	int i = 0;
	int j = 0;
	assert(ps != NULL);
	for (i = 0; i < ps->sz; i++) {
		if (ps->data[i] != d) {
			ps->data[j] = ps->data[i];
			j++;
		}
	}
	ps->sz = j;
}

int SeqList_Size(const pSeqList ps)
{
	assert(ps != NULL);
	return ps->sz;
}

bool SeqListEmpty(const pSeqList ps)
{
	assert(ps != NULL);
	return ps->sz == 0;
}

bool SeqListFull(const pSeqList ps)
{
	assert(ps != NULL);
	return ps->sz == MAX;
}

#endif // static_arr


#ifdef Dynamic_List

void InitSeqList(pSeqList ps)
{
	assert(ps);
	ps->data = (DataType *)malloc(DEFAULT_CAPACITY * sizeof(DataType));
	if (ps->data == NULL) {
		perror("error foe Initialize");
		exit(EXIT_FAILURE);
	}
	ps->sz = 0;
	ps->capacity = DEFAULT_CAPACITY;
	
}

void DestroySeqList(pSeqList ps)
{
	assert(ps != NULL);
	free(ps->data);
	ps->data = NULL;
	ps->capacity = 0;
	ps->sz = 0;
}

static void CheckCapacity(pSeqList ps)
{
	if (ps->sz < ps->capacity) {
		return;
	}
	DataType *tmp = (DataType *)realloc(ps->data, sizeof(DataType) * (ps->capacity + DEFAULT_ADD));
	if (tmp == NULL) {
		perror("error for realloc");
		exit(EXIT_FAILURE);
	}
	ps->data = tmp;
	ps->capacity += DEFAULT_ADD;
}

void PushBack(pSeqList ps, DataType d)
{
	assert(ps != NULL);
	CheckCapacity(ps);
	ps->data[ps->sz] = d;
	ps->sz++;
}

void PrintSeqList(const pSeqList ps)
{
	int i = 0;
	assert(ps != NULL);
	while (i < ps->sz)
	{
		printf("%d ", ps->data[i]);
		i++;
	}
	printf("\n");
}

void PopBack(pSeqList ps)
{
	if (ps->sz == 0) {
		return;
	}
	ps->sz--;
}

void PushFront(pSeqList ps, DataType d)
{
	int i = 0;
	assert(ps != NULL);
	CheckCapacity(ps);
	for (i = ps->sz; i > 0; i--) {
		ps->data[i] = ps->data[i - 1];
	}
	ps->data[0] = d;
	ps->sz++;
}

void PopFront(pSeqList ps)
{
	int i = 0;
	assert(ps != NULL);
	if (ps->sz == 0) {
		return;
	}
	for (i = 0; i < ps->sz - 1; i++) {
		ps->data[i] = ps->data[i + 1];
	}
	ps->sz--;
}

void Insert(pSeqList ps, int pos, DataType d)
{
	int i = 0;
	assert(ps != NULL);
	if (pos < 0 || pos > ps->sz) {
		printf("插入位置错误！\n");
		return;
	}
	CheckCapacity(ps);
	for (i = ps->sz; i > pos; i--) {
		ps->data[i] = ps->data[i - 1];
	}
	ps->data[pos] = d;
	ps->sz++;
}

void Sort(pSeqList ps)
{
	int flag = 0;
	int i = 0;
	int j = 0;
	for (i = 0; i < ps->sz - 1; i++) {
		for (j = 0; j < ps->sz - i - 1; j++) {
			if (ps->data[j] > ps->data[j + 1]) {
				DataType tmp = ps->data[j];
				ps->data[j] = ps->data[j + 1];
				ps->data[j + 1] = tmp;
				flag = 1;
			}
		}
		if (flag == 0) {
			break;
		}
	}
}

int BinarySearch(pSeqList ps, DataType d)
{
	int mid = 0;
	int left = 0;
	int right = ps->sz - 1;
	assert(ps != NULL);
	while (left <= right)
	{
		mid = left + ((right - left) >> 1);
		if (d < ps->data[mid]) {
			right = mid - 1;
		}
		else if (d > ps->data[mid]) {
			left = mid + 1;
		}
		else {
			return mid;
		}
	}
	return -1;
}

int Find(pSeqList ps, DataType d)
{
	int i = 0;
	assert(ps != NULL);
	for (i = 0; i < ps->sz; i++) {
		if (ps->data[i] == d) {
			return i;
		}
	}
	printf("\nNOT FOUND! \n");
	return -1;
}

void Remove(pSeqList ps, DataType d)
{
	int i = 0;
	assert(ps != NULL);
	i = Find(ps, d);
	if (i == -1) {
		printf("CAN'T REMOVE");
		return;
	}
	for (; i < ps->sz - 1; i++) {
		ps->data[i] = ps->data[i + 1];
	}
	ps->sz--;
}

void RemoveALL(pSeqList ps, DataType d)
{
	int i = 0;
	int j = 0;
	assert(ps != NULL);
	for (i = 0; i < ps->sz; i++) {
		if (ps->data[i] != d) {
			ps->data[j] = ps->data[i];
			j++;
		}
	}
	ps->sz = j;
}


int SeqList_Size(const pSeqList ps)
{
	return ps->sz;
}

bool SeqListEmpty(const pSeqList ps)
{
	return ps->sz == 0;
}

bool SeqListFull(const pSeqList ps)
{
	return ps->sz == ps->capacity;
}

#endif // static_arr

void test()
{
	int n = 0;
	int pos = 0;
	DataType d = 0;
	SeqList seqlist;

	InitSeqList(&seqlist);

	PushFront(&seqlist, 3);
	PushFront(&seqlist, 3);
	PushFront(&seqlist, 6);
	PushFront(&seqlist, 3);
	PushBack(&seqlist, 1);
	PushBack(&seqlist, 3);
	PushBack(&seqlist, 5);
	PushBack(&seqlist, 7);


	PrintSeqList(&seqlist);


	//n = 1;
	//DataInsert(&seqlist, 999, 555);
	//PrintSeqList(&seqlist);

	//Sort(&seqlist);
	//printf("\nSort: ");
	//PrintSeqList(&seqlist);

	//n = 5;
	//printf("\nBinarySearch %d pos =  %d\n", n, BinarySearch(&seqlist, 5));
	


	//PopBack(&seqlist);
	//printf("\nPopBack : ");
	//PrintSeqList(&seqlist);


	//PopFront(&seqlist);
	//printf("\nPopFront : ");
	//PrintSeqList(&seqlist);

	//pos = 5;
	//d = 999;
	//PosInsert(&seqlist, pos, d);
	//printf("\nInsert  pos = %d  DataType = %d : ", pos, d);
	//PrintSeqList(&seqlist);


	//d = 3;
	//RemoveALL(&seqlist, d);
	//printf("\nRemoveALL %d  : ", d);
	//PrintSeqList(&seqlist);


	//d = 999;
	//printf("\nFind  d = %d    pos = %d\n", d, Find(&seqlist, d));



	//printf("\nSeqList_Size = %d \n", SeqList_Size(&seqlist));

	//printf("\nSeqList_Empty = %d \n", SeqListEmpty(&seqlist));

	//printf("\nSeqList_Full = %d \n", SeqListFull(&seqlist));

	DestroySeqList(&seqlist);
}
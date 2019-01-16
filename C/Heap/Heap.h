#pragma once

typedef int HDataType;

typedef struct Heap {
    HDataType  array[100];
    int size;
}Heap;



void HeapInitialize(Heap *pheap, HDataType array[], int size);
void AdjustDown(HDataType array[], int size, int root);   //向下调整
void CreateHeap(Heap *pheap);              //创建堆
void Print(Heap *pheap);            //输出堆
HDataType HeapTop(Heap *pheap);            //返回堆顶元素
void AdjustUp(HDataType array[], int size, int child);        //向上调整
void HeapPush(Heap *pheap, HDataType data);     //插入元素

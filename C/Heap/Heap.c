#include <stdio.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "Heap.h"



void HeapInitialize(Heap *pheap, HDataType array[], int size)
{
    assert(pheap != NULL);
    assert(size <= 100);
    memcpy(pheap->array, array, sizeof(int) * size);
    pheap->size = size;
}


static void Swap(HDataType array[], int root, int max)
{

    int tmp = array[root];
    array[root] = array[max];
    array[max] = tmp;

}

void AdjustDown(HDataType  array[], int size, int root)
{
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    while(1) {

        //root 为叶子节点
        if (left >= size) {
            return;
        }

        //右孩子存在，并且右孩子大
        int max = left;
        if (right < size && array[right] > array[left]) {
            max = right;
        }
        
        //判断root与max的大小
        if (array[root] >= array[max]) {
            return;
        }

        //交换
        Swap(array, root, max);
        root = max;
        left = 2 * root + 1;
        right = 2 * root + 2;
        
    }

}

void CreateHeap(Heap *pheap)
{
    int i = 0;
    assert(pheap != NULL);
    for (i = (pheap->size - 2) / 2; i >=0; i--) {
        AdjustDown(pheap->array, pheap->size, i);
    }
}

void Print(Heap *pheap) 
{
    int i = 0;
    assert(pheap != NULL);
    printf("Heap：");
    for (i = 0; i < pheap->size; i++) {
        printf("%d ", pheap->array[i]);
    }
    printf("\n");
}

int HeapTop(Heap *pheap)
{
    assert(pheap != NULL);
    return pheap->array[0];
}

void HeapPop(Heap *pheap)
{
    assert(pheap != NULL);
    //把最后面的元素拿上来，覆盖最上面的
    pheap->array[0] = pheap->array[pheap->size - 1];
    //进行一次向下调整
    AdjustDown(pheap->array, pheap->size, pheap->array[0]);
}

void AdjustUp(HDataType array[], int size, int child)
{

    while (child >= 0) {
        //先找到父母节点         
        int parent = (child - 1) / 2;
        
        //判断与父母的大小
        if (array[child] <= array[parent]) {
            return;
        }
        //交换，往上走 
        Swap(array, child, parent);
        child = parent;
        parent = (child - 1) / 2;
    
    }
}

void HeapPush(Heap *pheap, HDataType data)
{

    //指针有效
    assert(pheap != NULL);
    
    //是否还有空间插入
    assert(pheap->size < 100);
    
    //插入
    pheap->array[pheap->size] = data;   
    
    //个数加一
    pheap->size++;
    //向上调整
    AdjustUp(pheap->array, pheap->size, pheap->size - 1);
}

#include <stdio.h>
#include <stdlib.h>
void Swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void Print(int array[], int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

//插入排序//
void InsertSort(int array[], int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = i; j > 0; j--) {
            if (array[j] >= array[j - 1]) {
                break;
            }
            Swap(array + j, array + j - 1);
        }
    }
}

#if 1
//希尔排序
void __InsertSort(int array[], int size, int gap)
{
    int i = 0;
    int j = 0;
    for (i = gap; i < size; i++) {
        int k = array[i];
        for (j = i - gap; j >= 0; j -= gap) {
            if (k >= array[j]) {
                break;
            }
            array[j + gap] = array[j];
        }
        array[j + gap] = k;
    }
}




void ShellSort(int array[], int size)
{
    int gap = size / 3 + 1;
    while(1) {
        gap = gap / 3 + 1;
        __InsertSort(array, size, gap);
        if (gap == 1) {
            return;
        }
    }
}


#else 
void __InsertSort(int array[], int size, int gap)                                                                                                                        
{
        int key;
        int i, j;
        for (i = gap; i < size; i++) {
            printf("i == %d gap == %d \n", i, gap);
            key = array[i];
            for (j = i - gap; j >= 0; j -= gap) {
                printf("j == %d \n", j);
                if (key >= array[j]) {
                    break;
                }
                else {
                   array[j + gap] = array[j];
                }
            }
            array[j + gap] = key;
            Print(array, size);
       }
}
 
//希尔排序
// 1. 不稳定
// 2. 最好/平均/最差    O(n)/O(n^1.2~1.3)/O(n^2)
// 3. 空间复杂度        O(1)
void ShellSort(int array[], int size)
{
    int gap = size;
    // gap 动态变化
    while (1) {
        gap = gap / 3 + 1;
        printf("gap == %d \n", gap);
        __InsertSort(array, size, gap);
        if (gap == 1) {
           break;
        }
    }
}
#endif

//冒泡排序//
void BubbleSort(int array[], int size)
{
    int flag = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 -i; j++) {
            if (array[j] > array[j + 1]) {
                Swap(array + j, array + j + 1);
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }
}


//选择排序// 
void SelectSort_0(int array[], int size) {
    int max = 0;         //用来保存本次求出的最大值的下标
    int i = 0;
    int j = 0;
    for (i = 0; i < size - 1; i++) {
        max = 0;
        for (j = 0; j < size - 1 - i; j++) {
            if (array[j + 1] > array[max]) {
                max = j + 1;
            }
        }
        if (max != j) {
        Swap(array + max, array + j);
        }
    }
}

void SelectSort_1(int array[], int size)
{
    int min = 0;
    int max = 0;
    int left = 0;
    int right = size - 1;
    while(left < right) {
        min = left;
        max = right;
        for (int j = 0; j <= right; j++) {

            if (array[left + j] > array[max]) {
                max = j;
            }
            if (array[left + j] < array[min]) {
                min = j;
            }
            if (min != left) {
                Swap(array + min, array + left);
            }
            if (max == left) {
                max = min;
            }
            if (max != right) {
                Swap(array + max, array + right);
            }
        }
        left++;
        right--;
    }
}



//堆排序//
void AdjustDown(int array[], int size, int root)
{
    int left = 2 * root + 1;
    int right = 2 * root + 2;
    if (left >= size) {
        return;
    }
    int max = left;
    if (right < size && array[right] > array[left]) {
        max = right;
    } 
    if (array[root] >= array[max]) {
        return;
    }
    
    Swap(array + root, array + max);
    
    AdjustDown(array, size, max);


}

void CreatHeap(int array[], int size)
{
    int root = (size- 1 - 1) / 2;
    while(root >= 0) {
        AdjustDown(array, size, root);
        root--;
    } 
    
}

void HeapSort(int array[], int size)
{
    CreatHeap(array, size);
    for (int i = size - 1; i > 0; i--) {
        Swap(array + i, array);
        AdjustDown(array, i, 0);
    }
}
  

//快速排序//
int Partition_01(int array[], int left, int right)
{
    int start = left;
    int end = right - 1;
    while(start < end) {
        while(start < end && array[start] <= array[right]) {
            start++;
        }
        while(start < end && array[end] >= array[right]) {
            end--;
        }
        Swap(array + start, array + end);
    }
    Swap(array + end, array + right);
    return start;
}

int Partition_02(int array[], int left, int right)
{
    int begin = left;
    int end = right;
    int tmp = array[right];
    while(begin < end) {
        while(begin < end && array[begin] <= tmp) {
            begin++;
        }
        array[end] = array[begin];
        while(begin < end && array[end] >= tmp) {
            end--;
        }
        array[begin] = array[end];
    }
    array[begin] = tmp;
    return begin;
}

int Partition_03(int array[], int left, int right)
{
    int less = left;       //第一个大于基准的 最后与基准进行交换 并返回
    int great = left;      //大于基准的最右边
    while (great < right) {
        if (array[great] < array[right]) {
                Swap(array + less, array + great);
                less++;     //多了一个小于的 往前走一步
 //               printf("less == %d", less);
        }
        great++;
    }
    Swap(array + less, array + right);
    return less;    //指向的是基准
}

#if 0
void QuickSort(int array[], int size)             //数组的首地址和数组的元素的个数
{
    int left = 0;
    int right = size - 1;
    if (size <= 1) {    //当个数小于等于一个的时候，不继续排序
        return;
    }
  //  printf("未：");
  //  Print(array, size);
    int i = Partition_03(array, left, right);
  //  printf("已：");
 //   Print(array, size);
//    printf("i == %d\n", i);
    QuickSort(array, i);        
    QuickSort(array + i + 1, size - i - 1);
}

#else 

void QuickSort(int array[], int left, int right) {
    if (left >= right) {
        return;
    }
    int i = Partition_01(array, left , right);
    QuickSort(array, left, i - 1);
    QuickSort(array, i + 1, right);

}

#endif 


//归并排序
//
 
void Merage(int array[], int left, int mid, int right, int extra[])
{
    int left_i = left;
    int right_i = mid;
    int extra_i =left;
    while(left_i < mid && right_i < right) {
        if (array[left_i] <= array[right_i]) {
            extra[extra_i++] = array[left_i++];
        }
        else {
            extra[extra_i++] = array[right_i++];
        }
    }

    while(left_i < mid) {
        extra[extra_i++] = array[left_i++];
    }

    while(right_i < right) {
        extra[extra_i++] = array[right_i++];
    }
    for (int i = left; i < right; i++) {
        array[i] = extra[i];
    }
}




void  _MergeSort(int array[], int left, int right, int extra[])
{

    // 区间内只有一个数
    if (left == right - 1) {
        return;
    }
    //区间内没有数
    if (left >= right) {
        return;
    }
    int mid = left +  (right - left) / 2;
    _MergeSort(array, left, mid, extra);
    _MergeSort(array, mid, right, extra);
    Merage(array, left, mid, right, extra);
}

void MergeSort(int array[], int size)
{
    int *extra = (int *) malloc (sizeof(int) * size);
    _MergeSort(array, 0, size, extra);
    free(extra);
}



int main()
{
    int array[] = {2, 6, 4, 3, 7, 1, 0, 8, 9, 5};
    int size = sizeof(array) / sizeof(array[0]);
    Print(array, size);
  //  QuickSort(array, size);
  //  HeapSort(array, size);
  //  BubbleSort(array, size);
  //  SelectSort_0(array, size);
  //  SelectSort_1(array, size);
  //  InsertSort(array, size);
  //  ShellSort(array, size);
    MergeSort(array, size);   
    Print(array, size);
    return 0;
}

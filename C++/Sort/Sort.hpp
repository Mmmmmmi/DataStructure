#pragma once
/*************************************************************************

  > File Name: Sort.hpp
  > Created Time: 2019/7/29 22:47:50

 ************************************************************************/

/*
 * 七大排序
 * 冒泡
 * 选择
 * 插入
 * 希尔
 * 堆
 * 快速
 * 归并
 * 
 * 传参支持 指针 容器 
 * 支持范围传参(指针、迭代器) 以及 起始下标 + 元素个数
 * 排序范围为 [)
 * 默认比较器都是 Less  >=  true    < false
 *                Great >=  true    < false
 * 
 *
 */

#include <iostream>
#include <vector>
#include <assert.h>

template<class T>
class MySort
{
    typedef typename std::vector<T>::iterator Iterator;
public:

    static void BubbleSort(T* arr, size_t size);
    static void BubbleSort(T* left, T* right);
    static void BubbleSort(Iterator left, Iterator right);

    template<class Compare>
    static void BubbleSort(T* arr, size_t size, Compare comp);

    template<class Compare>
    static void BubbleSort(T* left, T* right, Compare comp);

    template<class Compare>
    static void BubbleSort(Iterator left, Iterator right, Compare comp);

    static void SelectSort(T* arr, size_t size);
    static void SelectSort(T* left, T* right);
    static void SelectSort(Iterator left, Iterator right);

    template<class Compare>
    static void SelectSort(T* arr, size_t size, Compare comp);

    template<class Compare>
    static void SelectSort(T* left, T* right, Compare comp);

    template<class Compare>
    static void SelectSort(Iterator left, Iterator right, Compare comp);

    static void InsertSort(T* arr, size_t size);
    static void InsertSort(T* left, T* right);
    static void InsertSort(Iterator left, Iterator right);

    template<class Compare>
    static void InsertSort(T* arr, size_t size, Compare comp);

    template<class Compare>
    static void InsertSort(T* left, T* right, Compare comp);

    template<class Compare>
    static void InsertSort(Iterator left, Iterator right, Compare comp);

    template<class Compare>
    static void ShellSort(T* arr, size_t size, Compare comp);
    template<class Compare>
    static void HeapSort(T* arr, size_t size, Compare comp);

    template<class Compare>
    static void QuickSort(T* arr, size_t size, Compare comp);

    template<class Compare>
    static void MergeSort(T* arr, size_t size, Compare comp);

private:

    ////////////////////////////////
    //辅助函数 START

    static void _Print(T* arr, size_t size);

    template<class Compare>
    static void _InsertSort(T* arr, size_t size, Compare comp, int gap);

    template<class Compare>
    static void _AdjustDown(T* arr, size_t size, Compare comp, int cur);

    template<class Compare>
    static void _CreateHeap(T* arr, size_t size, Compare comp);

    template<class Compare>
    static int _Partition(T* arr, int left, int right, Compare comp);

    template<class Compare>
    static void _MergeSort(T* arr, int left, int right, Compare comp, T* extra);

    template<class Compare>
    static void _Merge(T* arr, int left, int mid, int right, Compare comp, T* extra);

    //辅助函数 END
    ///////////////////////////////
};


template<class T>
void MySort<T>::_Print(T* arr, size_t size)
{
    assert(arr != nullptr);
    for (size_t i = 0; i < size; i++)
    {
        std::cout << *(arr + i) << " ";
    }
    std::cout << std::endl;
}


////////////////////////////////////////// 
// BubbleSort Start
////////////////////////////////////////// 
template<class T>
void MySort<T>::BubbleSort(T* arr, size_t size)
{
    assert(arr != nullptr);
    MySort<T>::BubbleSort(arr, size, std::less<T>());
}

template<class T>
void MySort<T>::BubbleSort(T* left, T* right)
{
    assert(left != nullptr && right != nullptr && left <= right);
    MySort<T>::BubbleSort(left, right, std::less<T>());
}
template<class T>
void MySort<T>::BubbleSort(Iterator left, Iterator right)
{
    return;
}

template<class T>
template<class Compare>
void MySort<T>::BubbleSort(T* arr, size_t size, Compare comp)
{
    assert(arr != nullptr);
    int flag = 0;
    for (size_t i = 0; i < size - 1; ++i)
    {
        for (size_t j = 0; j < size - 1 - i; ++j)
        {
            if (comp(*(arr + j + 1), *(arr + j)))
            {
                std::swap(*(arr + j), *(arr + j + 1));
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}

template<class T>
template<class Compare>
void MySort<T>::BubbleSort(T* left, T* right, Compare comp)
{
    assert(left != nullptr && right != nullptr && left <= right);
    int num = right - left;
    BubbleSort(left, num, comp);
}

template<class T>
template<class Compare>
void MySort<T>::BubbleSort(Iterator left, Iterator right, Compare comp)
{
    return;
}
////////////////////////////////////////// 
// BubbleSort END
////////////////////////////////////////// 



////////////////////////////////////////// 
// SelectSort Start
////////////////////////////////////////// 

template<class T>
void MySort<T>::SelectSort(T* arr, size_t size)
{
    assert(arr != nullptr);
    SelectSort(arr, size, std::less<T>());
}

    template<class T>
void MySort<T>::SelectSort(T* left, T* right)
{
    assert(left != nullptr && right != nullptr && left <= right);
    int num = right - left;
    SelectSort(left, num, std::less<T>());
}

template<class T>
template<class Compare>
void MySort<T>::SelectSort(T* arr, size_t size, Compare comp)
{
    assert(arr != nullptr);
    for (size_t i = 0; i < size - 1; ++i)
    {
        size_t pos = 0;
        size_t j = 0;
        for (j = 0; j < size - 1 - i; ++j)
        {
            if (comp(*(arr + pos), *(arr + j + 1)))
            {
                pos = j + 1;
            }
        }
        if (pos != j)
        {
            std::swap(*(arr + pos), *(arr + j));
        }
    }
}


template<class T>
template<class Compare>
void MySort<T>::SelectSort(T* left, T* right, Compare comp)
{
    assert(left != nullptr && right != nullptr && left <= right);
    int num = right - left;
    SelectSort(left, num, comp);
}

////////////////////////////////////////// 
// SelectSort END
////////////////////////////////////////// 

////////////////////////////////////////// 
// InsertSort START
////////////////////////////////////////// 
template<class T>
template<class Compare>
void MySort<T>::InsertSort(T* arr, size_t size, Compare comp)
{
    assert(arr != nullptr);
    for (size_t i = 0; i < size; ++i)
    {
        for (size_t j = i; j > 0; --j)
        {
            if (comp(*(arr + j), *(arr + j - 1)))
            {
                std::swap(*(arr + j), *(arr + j - 1));
            }
            else
            {
                break;
            }
        }
    }
}

////////////////////////////////////////// 
// InsertSort END
////////////////////////////////////////// 

////////////////////////////////////////// 
// ShellSort START 
////////////////////////////////////////// 
template<class T>
template<class Compare>
void MySort<T>::_InsertSort(T* arr, size_t size, Compare comp, int gap)
{
    assert(arr != nullptr);
    for (int i = gap; i < size; ++i)
    {
        int cur = i;
        for (int j = i - gap; j >= 0; j -= gap)
        {
            if (comp(*(arr + cur), *(arr + j)))
            {
                std::swap(*(arr + cur), *(arr + j));
                cur = j;
            }
            else
            {
                //插入排序，不能插入就是有序了
                break;
            }
        }
    }
}

template<class T>
template<class Compare>
void MySort<T>::ShellSort(T* arr, size_t size, Compare comp)
{
    assert(arr != nullptr);	
    int gap = size;
    while(1)
    {
        gap = gap / 3 + 1;
        _InsertSort(arr, size, comp, gap);
        if (gap == 1)
            return;
    }
}
////////////////////////////////////////// 
// ShellSort END
////////////////////////////////////////// 

////////////////////////////////////////// 
// HeapSort START
////////////////////////////////////////// 



template<class T>
template<class Compare>
void MySort<T>::_AdjustDown(T* arr, size_t size, Compare comp, int cur)
{
    assert(arr != nullptr);
    int left = (cur << 1) + 1;
    int right = (cur << 1) + 2;
    if (left >= size)
    {
        return;
    }
    int max = left;
    if (right < size && comp(*(arr + left), *(arr + right)))
    { 
        max = right;
    }
    if (comp(*(arr + cur), *(arr + max)))
    {
        std::swap(*(arr + cur), *(arr + max));
        _AdjustDown(arr, size, comp, max);
    }
}


template<class T>
template<class Compare>
void MySort<T>::_CreateHeap(T* arr, size_t size, Compare comp)
{
    assert(arr != nullptr);
    //1. 创建堆步骤，从第一个非叶子节点开始，做向下调整
    int cur = (size - 1 - 1) >> 1; 
    while(cur >= 0)
    {
        _AdjustDown(arr, size, comp, cur);
        --cur;
    }
}



template<class T>
template<class Compare>
void MySort<T>::HeapSort(T* arr, size_t size, Compare comp)
{
    assert(arr != nullptr);
    //1. 创建堆
    //默认创建的是大堆，这样能保证堆顶的是最大值
    _CreateHeap(arr, size, comp);
    //2. 堆排序
    //根据大堆特性，每次向下调整后，将最大值交换到最后去，然后继续开始向下调整
    int end = size - 1; //最后一个元素
    while(end >= 0)
    {
        //std:: cout << "Befor Swap : " ;
        //_Print(arr, size);
        std::swap(*(arr + 0), *(arr + end)); //最大的挪走
        //std:: cout << "After Swap : " ;
        //_Print(arr, size);
        _AdjustDown(arr, end, comp, 0);
        --end;
    }
}

////////////////////////////////////////// 
// HeapSort END
////////////////////////////////////////// 

////////////////////////////////////////// 
// QuickSort END
////////////////////////////////////////// 

template<class T>
template<class Compare>
int MySort<T>::_Partition(T* arr, int left, int right, Compare comp)
{
    assert(arr != nullptr);
    /*
       if (left >= right)
       {
       return left;
       }
       */
    while(left < right)
    {
        while(left < right && comp(*(arr + left), *(arr + right)))
        {
            left++;
        }

        while(left < right && comp(*(arr + left), *(arr + right)))
        {
            right--;
        }
        std::swap(*(arr + left), *(arr + right));
    }
    std::swap(*(arr + left), *(arr + right));
    return left;
}
template<class T>
template<class Compare>
void MySort<T>::QuickSort(T* arr, size_t size, Compare comp)
{
    assert(arr != nullptr);
    if (size <= 1)
    {
        return;
    }
    //1 2 3 4 5 6 
    //0 1 2 3 4 5     
    int left = 0;
    int right = size - 1;
    std:: cout << "Befor Swap : " ;
    _Print(arr, size);
    int ret = _Partition(arr, left, right, comp);
    std:: cout << "After Swap : " ;
    _Print(arr, size);
    QuickSort(arr, ret, comp);
    QuickSort(arr + ret + 1, size - ret - 1, comp);
}

////////////////////////////////////////// 
// QuickSort END
////////////////////////////////////////// 

////////////////////////////////////////// 
// MergeSort END
////////////////////////////////////////// 

template<class T>
template<class Compare>
void MySort<T>::_Merge(T* arr, int left, int mid, int right, Compare comp, T* extra)
{
    assert(arr != nullptr && extra != nullptr);
    int leftcur = left;
    int rightcur = mid + 1;
    int extracur = left;
    while(leftcur <= mid && rightcur <= right)
    {
        if (comp(*(arr + leftcur), *(arr + rightcur)))
        {
            *(extra + extracur) = *(arr + leftcur);
            ++leftcur;
            ++extracur;
        }
        else
        {
            *(extra + extracur) = *(arr + rightcur);
            ++rightcur;
            ++extracur;
        }
    }
    while(leftcur <= mid)
    {
        *(extra + extracur) = *(arr + leftcur);
        ++leftcur;
        ++extracur;
    }
    while(rightcur <= right)
    {
        *(extra + extracur) = *(arr + rightcur);
        ++rightcur;
        ++extracur;
    }
    _Print(extra + left, right - left + 1);
    for (int i = left; i <= right; ++i)
    {
        *(arr + i) = *(extra + i);
    }
}


template<class T>
template<class Compare>
void MySort<T>::_MergeSort(T* arr, int left, int right, Compare comp, T* extra)
{
    assert(arr != nullptr && extra != nullptr);
    //_Print(arr + left, right - left + 1);
    /*if (left == right - 1)
    {
        //only one
        return;
    }*/
    if (left >= right)
    {
        //zero 
        return;
    }
    int mid = left + (right - left) / 2;
    _MergeSort(arr, left, mid, comp, extra);
    _MergeSort(arr, mid + 1, right, comp, extra);
    _Merge(arr, left, mid, right, comp, extra);
}



template<class T>
template<class Compare>
void MySort<T>::MergeSort(T* arr, size_t size, Compare comp)
{
    assert(arr != nullptr);
    T* extra = new T[size];
    _MergeSort(arr, 0, size - 1, comp, extra);     
    delete[] extra;
}


////////////////////////////////////////// 
// MergeSort END
////////////////////////////////////////// 

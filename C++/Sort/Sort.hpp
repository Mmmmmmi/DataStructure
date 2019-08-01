#pragma once
/*
 * 七大排序
 * 冒泡
 * 选择
 * 插入
 * 希尔
 * 堆
 * 快速
 * 归并
 */

#include <iostream>
#include <vector>

template<class T>
class MySort
{
    typedef typename std::vector<T>::iterator Iterator;
public:
    static void BubbleSort(T* left, T* right);
    static void BubbleSort(Iterator left, Iterator right);
	static void SelectSort();
	static void InsertSort();
	static void ShellSort();
	static void HeapSort();
	static void QuickSort();
	static void MerageSort();

    template<class Compare>
    static void BubbleSort(T* left, T* right, Compare comp);

    template<class Compare>
    static void BubbleSort(Iterator left, Iterator right, Compare comp);

};

template<class T>
void MySort<T>::BubbleSort(T* left, T* right)
{
    BubbleSort(left, right, std::less<T>());
    return;
}

template<class T, class Compare>
void MySort<T, Compare>::BubbleSort(T* left, T* right, Compare comp)
{
    return;
}

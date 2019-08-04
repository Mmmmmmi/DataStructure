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
 * 默认比较方式为 less，可以自定义比较器 
 * 排序范围为 [)
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
	static void HeapSort();
	static void QuickSort();
	static void MerageSort();

};
 
  
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
			if (comp(arr[j], arr[j - 1]))
			{
				std::swap(arr[j], arr[j - 1]);
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
void MySort<T>::ShellSort(T* arr, size_t size, Compare comp)
{
	
}
////////////////////////////////////////// 
// ShellSort END
////////////////////////////////////////// 

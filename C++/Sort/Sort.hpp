pragma once
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

template <class T>
void Swap(T &left, T &right)
{
	T temp = left;
	left = right;
	right = temp;
}


template<class RandomIt, class comp>
class MySort
{
public:
    static void BubbleSort();
	static void SelectSort();
	static void InsertSort();
	static void ShellSort();
	static void HeapSort();
	static void QuickSort();
	static void MerageSort();
};

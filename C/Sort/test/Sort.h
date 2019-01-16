#pragma once

#include <stdio.h>
#include <stdlib.h>


// ��������
// �ȶ�
// ���/ƽ��/���	O(n) ��ȫ����/O(n^2)/O(n^2)
// �ռ�			O(1)
void InsertSort(int array[], int size)
{
	int key;
	int i, j;
	for (i = 1; i < size; i++) {
		key = array[i];
		for (j = i - 1; j >= 0; j--) {
			if (key >= array[j]) {
				break;
			}
			else {
				array[j + 1] = array[j];
			}
		}

		array[j + 1] = key;
	}
}

#if 0
void __InsertSort(int array[], int size, int gap)
{
	for (int g = 0; g < gap; g++) {
		int key;
		int i, j;
		for (i = gap + g; i < size; i += gap) {
			key = array[i];
			for (j = i - gap; j >= 0; j -= gap) {
				if (key >= array[j]) {
					break;
				}
				else {
					array[j + gap] = array[j];
				}
			}

			array[j + gap] = key;
		}
	}
}
#else
void __InsertSort(int array[], int size, int gap)
{
		int key;
		int i, j;
		for (i = gap; i < size; i++) {
			key = array[i];
			for (j = i - gap; j >= 0; j -= gap) {
				if (key >= array[j]) {
					break;
				}
				else {
					array[j + gap] = array[j];
				}
			}

			array[j + gap] = key;
		}
}
#endif

// 1. ���ȶ�
// 2. ���/ƽ��/���	O(n)/O(n^1.2~1.3)/O(n^2)
// 3. �ռ临�Ӷ�		O(1)
void ShellSort(int array[], int size)
{
	int gap = size;
	// gap ��̬�仯
	while (1) {
		gap = gap / 3 + 1;
		__InsertSort(array, size, gap);
		if (gap == 1) {
			break;
		}
	}
}


void Swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

// ���ȶ�
// ʱ�临�Ӷ�	O(n^2)
// �ռ临�Ӷ�	O(1)
void SelectSort(int array[], int size)
{
	for (int i = size; i > 1; i--) {
		int max = 0;
		for (int j = 1; j < i; j++) {
			if (array[j] > array[max]) {
				max = j;
			}
		}

		Swap(array + max, array + i - 1);
	}
}

void SelectSortOP(int array[], int size)
{
	int left = 0, right = size - 1;
	while (left < right) {
		int min = left, max = left;
		for (int j = left + 1; j <= right; j++) {
			if (array[j] > array[max]) {
				max = j;
			}

			if (array[j] < array[min]) {
				min = j;
			}
		}
		Swap(array + left, array + min);
		if (max == left) {
			max = min;
		}
		Swap(array + right, array + max);

		left++; right--;
	}
}

void AdjustDown(int array[], int size, int root)
{
	int left = 2 * root + 1;
	int right = 2 * root + 2;
	// Ҷ��	|| ����ѵ�����
	// û�����Һ���
	// ��Ϊ��ȫ��������û������
	// �����±�Խ��
	if (left >= size) {
		return;
	}

	// �ҵ����Һ�����˭�����ģ�����û���Һ��ӣ�
	int max = left;
	if (right < size && array[right] > array[left]) {
		max = right;
	}

	// ���� [root] >= [���ĺ���]����������
	// ���򣬽��� [root] [���ĺ���]
	// ������ [���ĺ���] �������µ����Ĺ���
	if (array[root] >= array[max]) {
		return;
	}

	Swap(array + root, array + max);
	AdjustDown(array, size, max);
}

void CreateHeap(int array[], int size)
{
	// �����һ����Ҷ�ӽ�� -> 0
	// ���һ������˫�׽��
	// [size - 1]	(child - 1)/2
	// ���ϵĽ������µ���

	for (int i = size / 2 - 1; i >= 0; i--) {
		AdjustDown(array, size, i);
	}
}

// ���ȶ�
// ʱ�临�Ӷ�	O(N*logN)
// �ռ临�Ӷ�	O(1)
void HeapSort(int array[], int size)
{
	// 1. ����ѣ�����
	CreateHeap(array, size);

	for (int i = 0; i < size; i++) {
		Swap(&array[0], &array[size - 1 - i]);
		AdjustDown(array, size - i - 1, 0);
	}
}

// ð������
// �ȶ�
// ���/ƽ��/���		O(n) �Ѿ�����/O(n^2)/O(n^2)
// �ռ临�Ӷ�			O(1)
void BubbleSort(int array[], int size)
{
	for (int i = 0; i < size - 1; i++) {
		int isSorted = 1;
		for (int j = 0; j < size - 1 - i; j++) {
			if (array[j] > array[j + 1]) {
				Swap(array + j, array + j + 1);
				isSorted = 0;
			}
		}

		if (isSorted == 1) {
			break;
		}
	}
}



void PrintArray(int array[], int size)
{
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

int Partition_01(int array[], int left, int right)
{
	int begin = left;	// ���� 0
	int end = right;	// ���� right - 1

	while (begin < end) {
		// �����׼ֵ�����ұߣ����ȶ� begin
		// array[begin] Ҫ <= ���� <
		while (begin < end && array[begin] <= array[right]) {
			begin++;
		}

		while (begin < end && array[end] >= array[right]) {
			end--;
		}

		Swap(array + begin, array + end);
	}

	Swap(array + begin, array + right);

	return begin;
}

int Partition_02(int array[], int left, int right)
{
	int begin = left;	// ���� 0
	int end = right;	// ���� right - 1
	int pivot = array[right];		// pivot ��ľ��ǻ�׼ֵ

	while (begin < end) {
		// �����׼ֵ�����ұߣ����ȶ� begin
		// array[begin] Ҫ <= ���� <
		while (begin < end && array[begin] <= pivot) {
			begin++;
		}

		array[end] = array[begin];

		while (begin < end && array[end] >= pivot) {
			end--;
		}

		array[begin] = array[end];
	}

	array[begin] = pivot;

	return begin;
}


int Partition_03(int array[], int left, int right)
{
	int cur, div;

	for (cur = left, div = left; cur < right; cur++) {
		if (array[cur] < array[right]) {
			Swap(array + cur, array + div);
			div++;
		}
	}

	Swap(array + div, array + right);

	return div;
}

// array [left, right]
// ����ұ�
void __QuickSort(int array[], int left, int right)
{
	if (left == right) {
		// ֻ�� 1 �������Ѿ�����
		return;
	}

	if (left > right) {
		// û����������Ҫ����
		return;
	}

	int div = Partition_03(array, left, right);	// ʱ�临�Ӷ� O(N) �ռ� O(1)
	// div �ǻ�׼ֵ���ڵ��±�
	// [left, div-1]
	// [div+1, right]
	__QuickSort(array, left, div - 1);
	__QuickSort(array, div + 1, right);
}


void QuickSort(int array[], int size)
{
	__QuickSort(array, 0, size - 1);
}

// [left, mid)	����
// [mid, right)	����
// O(n)
// O(n)
void Merge(int array[], int left, int mid, int right, int extra[])
{
	int left_i = left;	// [left, mid)
	int right_i = mid;	// [mid, right)
	int extra_i = left;

	while (left_i < mid && right_i < right) {
		if (array[left_i] <= array[right_i]) {
			extra[extra_i++] = array[left_i++];
		}
		else {
			extra[extra_i++] = array[right_i++];
		}
	}

	while (left_i < mid) {
		extra[extra_i++] = array[left_i++];
	}

	while (right_i < right) {
		extra[extra_i++] = array[right_i++];
	}

	for (int i = left; i < right; i++) {
		array[i] = extra[i];
	}
}

// [left, right)
void __MergeSort(int array[], int left, int right, int extra[])
{
	// [0,1)
	if (left == right - 1) {
		// ������ֻʣһ�������Ѿ�����
		return;
	}

	if (left >= right) {
		// ������û������
		return;
	}
	/// [left, right)
	// [left, mid)
	// [mid, right)
	int mid = left + (right - left) / 2;
	__MergeSort(array, left, mid, extra); 
	__MergeSort(array, mid, right, extra);
	Merge(array, left, mid, right, extra);
}

// �ȶ�
void MergeSort(int array[], int size)
{
	int *extra = (int *)malloc(sizeof(int)* size);
	__MergeSort(array, 0, size, extra);
	free(extra);
}

void MergeSortLoop(int array[], int size)
{
	int *extra = (int *)malloc(sizeof(int)* size);
	for (int i = 1; i < size; i *= 2) {	// һ��ѭ�� log(size)
		for (int j = 0; j < size; j = j + 2 * i) {
			int left = j;
			int mid = j + i;
			int right = mid + i;

			if (mid >= size) {
				continue;
			}

			if (right > size) {
				right = size;
			}

			Merge(array, left, mid, right, extra);
		}
	}
	free(extra);
}

#include "�߾��ȼ�ʱ.h"

void Test()
{
	srand(20181025);
	const int size = 100000;
	int array[size];
	for (int i = 0; i < size; i++) {
		array[i] = rand() % 10000;
	}

	�߾��ȼ�ʱ	��ʱ��;
	��ʱ��.��ʼ();
	MergeSort(array, size);
	��ʱ��.����();

	printf("ִ��ʱ�� %f ����\n", ��ʱ��.�������());
}

/*
void Test()
{
	int array[] = { 3, 5, 1, 4, 7, 2, 6, 0, 9, 8, 8 };
	// 1. �Ѿ�����
	// 2. ��ȫ����
	// 3. ����
	// 4. ���
	// 5. 1 ����
	// 6. 0 ����
	// 7. �����
	//int array[] = { 1, 1, 1, 1, 1, 1, 1,1, 1 };
	int size = sizeof(array) / sizeof(int);

	MergeSortLoop(array, size);
	PrintArray(array, size);
}
*/
/*************************************************************************

	> File Name: test.cc
	> Created Time: 2019/7/29 22:46:47

 ************************************************************************/


#include "Sort.hpp"
#include <iostream>
using namespace std;

template<class T>
class Great
{
public:
    bool operator()(T& left, T& right) const
    {
        if (left >= right)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

template<class T>
class Less
{
public:
    bool operator()(T& left, T& right) const
    {
        if (left <= right)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    int a[] = {9, 9, 7, 11, 15, 12, 25, 6};
    //int a[] = {9, 6};
    //MySort<int>::BubbleSort(a, a + 4, Great<int>());
    //MySort<int>::SelectSort(a, a + 4, Great<int>());
    MySort<int>::QuickSort(a, sizeof(a) / sizeof(a[0]), std::less<int>());
    //MySort<int>::QuickSort(a, sizeof(a) / sizeof(a[0]), Great<int>());
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}

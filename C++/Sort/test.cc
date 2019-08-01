/*************************************************************************

	> File Name: test.cc
	> Created Time: 2019/7/29 22:46:47

 ************************************************************************/


#include "Sort.hpp"
#include <iostream>
using namespace std;

template<class T>
class comp
{
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

int main()
{
    int a[] = {1, 2, 3, 4};
    MySort<int, comp<int>()> m;
    //m.BubbleSort(1, 2, comp<int>());
    m.BubbleSort(a, a + 1);
    return 0;
}

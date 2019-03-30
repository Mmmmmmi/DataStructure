#include <iostream>
#include "BinarySearchTree.hpp"
using namespace std;


int main()
{
	BinarySearchTree<int> bst;
	bst.Insert(5);
	bst.Insert(6);
	bst.Insert(1);
	bst.Insert(3);
	bst.Insert(2);
	bst.Insert(7);
	bst.Insert(0);
	bst.Insert(9);
	bst.Insert(8);
	bst.InOrder();
	bst.Erase(1);
	bst.Erase(2);
	bst.Erase(3);
	bst.Erase(4);
	bst.Erase(5);
	bst.InOrder();
	bst.Destroy();
	bst.InOrder();
	bst.Insert(5);
	bst.Insert(6);
	bst.Insert(1);
	bst.Insert(3);
	bst.Insert(2);
	bst.Insert(7);
	bst.Insert(0);
	bst.Insert(9);
	bst.Insert(8);
	bst.InOrder();
	return 0;
}
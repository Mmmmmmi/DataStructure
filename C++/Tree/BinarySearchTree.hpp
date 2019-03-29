#pragma once


template <class T>
struct BSNode
{
	BSNode() :
		data(T),
		_leftChild(nullptr),
		_rightChild(nullptr),
		_parent(void)
	{}
	T _data;
	BSNode* _leftChild;
	BSNode* _rightChild;
	BSNode* _parent;

};


class 
class BinarySearchTree
{
public:
    BinarySearchTree() {}
    ~BinarySearchTree() {}

private:

};

typedef BinarySearchTree BSTree;

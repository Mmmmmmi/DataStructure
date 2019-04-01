#pragma once

/*
	红黑树：
		1. 每个节点不是红色就是黑色
		2. 根节点是黑色
		3. 如果一个节点是红色的，那么它的两个孩子是黑色的
		4. 对于每个节点，从该节点到它所有后代叶子节点的路径上，黑色节点的个数相同
		5. 每个叶子节点都是黑色的(空节点)

	红黑树中引入了颜色的概念，通过颜色的规律来保证红黑树的平衡
*/


enum Color
{
	RED,
	BLACK
};

template <class T>
struct RBTreeNode
{
	RBTreeNode(const T& data)
		:_data(data)
		,_leftChild(nullptr)
		,_rightChild(nullptr)
		,_parent(nullptr)
		,_color(RED)			//这里将节点的默认颜色设置为红色
	{}
	T _data;
	RBTreeNode<T>* _leftChild;
	RBTreeNode<T>* _rightChild;
	RBTreeNode<T>* _parent;
	Color _color;
};

template <class T>
class RBTree
{
	typedef RBTreeNode<T> Node;
	typedef	Node* PNode;
public:
	RBTree()
		:_root(nullptr)
	{}

	void Insert(const T& data)
	{
		if (_root == nullptr) {
			_root = new Node(data);
			_root->_color = BLACK;	//根节点是黑色的
			return true;
		}

		PNode pParent = nullptr;
		PNode pCur = _root;

		while (pCur) {
			if (data == pCur->_data) {
				return false;
			}
			else if (data < pCur->_data) {
				//在左子树上
				pParent = pCur;
				pCur = pCur->_leftChild;
			}
			else if (data > pCur->_data) {
				//在右子树上
				pParent = pCur;
				pCur = pCur->_rightChild;
			}
		}

		//走到这里，就找到了插入点
		PNode newNode = new Node(data);

		if (data > pParent->_data) {
			pParent->_rightChild = newNode;
			
		}
		else if (data < pParent->_data){
			pParent->_leftChild = newNode;
		}

		newNode->_parent = pParent;

		//插入完成，开始判断平衡性
		while (pParent && pParent == RED) {
			
		}





	}

private:
	PNode _root;
};
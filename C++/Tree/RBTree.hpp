#pragma once

#include <iostream>

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

	bool Insert(const T& data)
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
		pCur = new Node(data);

		if (data > pParent->_data) {
			pParent->_rightChild = pCur;
			
		}
		else if (data < pParent->_data){
			pParent->_leftChild = pCur;
		}

		pCur->_parent = pParent;

		
		//插入完成，开始判断平衡性
		while (pParent && pParent->_color == RED) {
			//如果双亲为黑，就说明已经平衡性了
			
			
			PNode pGrandFather = pParent->_parent;
			//祖父节点一定存在，因为，如果祖父节点不存在
			//那么就说明，双亲节点在根节点上
			//说明上一次调整的节点为根节点的孩子节点
			//又因为根节点为黑色，就不会进入循环


			//如果双亲为红，有三种情况，同时，还应该关注叔叔节点的情况，也就是祖父节点的另一个孩子
			// pParent = pGrandFather->_leftChild 情况：
			//1. 如果双亲为 红 ，叔叔为 红，并且插入位置为左左。  
			//处理方法：双亲和叔叔都变为黑色，祖父变为红色，然后cur变为祖父节点向上循环
			
			//2. 如果双亲为 红 ，叔叔为 红，并且插入位置为左右。  
			//处理方法：因为不存在旋转问题，所以和1操作相同

			//3. 如果双亲为 红 ，叔叔为 黑/不存在，并且插入位置为左左
			//对pGrandFather进行右旋
			
			//4. 如果双亲为 红 ，叔叔为 黑/不存在，并且插入位置为左右
			//先对pParent 进行左旋
			//再对pGrandFather进行右旋


			// pParent = pGrandFather->_rightChild 情况：     像上面一样，执行反操作就好
			//5. 如果双亲为 红 ，叔叔为 红，并且插入位置为右右。	 处理方法：和1相同
			//6. 如果双亲为 红 ，叔叔为 红，并且插入位置为右左。  处理方法：和1相同

			//7. 如果双亲为 红 ，叔叔为 黑/不存在，并且插入位置为右右  
			//对pGrandFather进行左旋

			//8. 如果双亲为 红 ，叔叔为 黑/不存在，并且插入位置为右左
			//对pParent进行右旋
			//对pGrandFather进行左旋


			//pParent 肯定为红,如果为黑的话就不进入循环
			//pGrandFather 有可能不存在，不存在就说明到根节点了，只要pGrandFather 为空，就说明pParent 为根节点
			if (pParent == pGrandFather->_leftChild) {
				//双亲为祖父的左
				PNode pUncle = pGrandFather->_rightChild;
				if (pUncle && pUncle->_color == RED) {
					//1 2
					pParent->_color = BLACK;
					pUncle->_color = BLACK;
					pCur = pGrandFather;
					pParent = pCur->_parent;
				}
				else if (pUncle == nullptr || pUncle->_color == BLACK) {
					if (pCur == pParent->_rightChild) {  
						//4   旋转后变为 3
						//旋转
						RotateL(pParent);
						//旋转完之后，让pCur 再指向下面的节点，pParent 再指向上面的节点
						//也就是两个指针交换
						std::swap(pParent, pCur);	
					}
					//3
					//再进行一次旋转，这次是右旋
					pParent->_color = BLACK;
					//双亲变为黑，就不用再旋转了
					pGrandFather->_color = RED;
					RotateR(pGrandFather);
					break;
				}
			}
			else if (pParent == pGrandFather->_rightChild){
				//双亲为祖父的右
				PNode pUncle = pGrandFather->_leftChild;
				if (pUncle && pUncle->_color == RED) {
					//5 6
					pParent->_color = BLACK;
					pUncle->_color = BLACK;
					pGrandFather->_color = RED;
					pCur = pGrandFather;
					pParent = pCur->_parent;
				}
				else if (pUncle == nullptr || pUncle->_color == BLACK){
					//8   旋转后变为7
					if (pCur == pParent->_leftChild) {
						RotateR(pParent);
						std::swap(pCur, pParent);
					}
					//7
					pParent->_color = BLACK;
					pGrandFather->_color = RED;
					RotateL(pGrandFather);
					break;
				}
			}
		}

		_root->_color = BLACK;

		return true;
	}

	void InOrder()
	{
		_InOrder(_root);
		std::cout << std::endl;
	}

	void Destroy()
	{
		_Destroy(_root);
	}

	~RBTree()
	{
		_Destroy(_root);
	}


private:

	void _Destroy(PNode& root)
	{
		if (root) {
			_Destroy(root->_leftChild);
			_Destroy(root->_rightChild);
			delete root;
			root = nullptr;
		}
	}

	void _InOrder(const PNode& root) const
	{
		if (root == nullptr) {
			return;
		}
		_InOrder(root->_leftChild);
		std::cout << root->_data << " ";
		_InOrder(root->_rightChild);
	}

	void RotateL(PNode pParent)
	{
		//左旋
		PNode pRight = pParent->_rightChild;
		PNode pRightL = pRight->_leftChild;
		if (pRightL) {
			pRightL->_parent = pParent;
		}
		PNode pGrandFather = pParent->_parent;
		pParent->_rightChild = pRightL;
		pRight->_leftChild = pParent;
		pRight->_parent = pGrandFather;
		pParent->_parent = pRight;
		if (pGrandFather == nullptr) {
			_root = pRight;
		}
		else {
			if (pParent == pGrandFather->_leftChild) {
				pGrandFather->_leftChild = pRight;
			}
			else if (pParent == pGrandFather->_rightChild) {
				pGrandFather->_rightChild = pRight;
			}
		}
	}

	void RotateR(PNode pParent)
	{
		//右旋
		PNode pLeft = pParent->_leftChild;
		PNode pLeftR = pLeft->_rightChild;
		if (pLeftR) {
			pLeftR->_parent = pParent;
		}
		PNode pGrandFather = pParent->_parent;
		pParent->_leftChild = pLeftR;
		pLeft->_rightChild = pParent;
		pParent->_parent = pLeft;
		pLeft->_parent = pGrandFather;
		pParent->_parent = pLeft;
		if (pGrandFather == nullptr) {
			_root = pLeft;
		}
		else {
			if (pParent == pGrandFather->_leftChild) {
				pGrandFather->_leftChild = pLeft;
			}
			else if (pParent == pGrandFather->_rightChild) {
				pGrandFather->_rightChild = pLeft;
			}
		}
	}

	PNode _root;
};
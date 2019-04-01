#pragma once

/*
	�������
		1. ÿ���ڵ㲻�Ǻ�ɫ���Ǻ�ɫ
		2. ���ڵ��Ǻ�ɫ
		3. ���һ���ڵ��Ǻ�ɫ�ģ���ô�������������Ǻ�ɫ��
		4. ����ÿ���ڵ㣬�Ӹýڵ㵽�����к��Ҷ�ӽڵ��·���ϣ���ɫ�ڵ�ĸ�����ͬ
		5. ÿ��Ҷ�ӽڵ㶼�Ǻ�ɫ��(�սڵ�)

	���������������ɫ�ĸ��ͨ����ɫ�Ĺ�������֤�������ƽ��
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
		,_color(RED)			//���ｫ�ڵ��Ĭ����ɫ����Ϊ��ɫ
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
			_root->_color = BLACK;	//���ڵ��Ǻ�ɫ��
			return true;
		}

		PNode pParent = nullptr;
		PNode pCur = _root;

		while (pCur) {
			if (data == pCur->_data) {
				return false;
			}
			else if (data < pCur->_data) {
				//����������
				pParent = pCur;
				pCur = pCur->_leftChild;
			}
			else if (data > pCur->_data) {
				//����������
				pParent = pCur;
				pCur = pCur->_rightChild;
			}
		}

		//�ߵ�������ҵ��˲����
		PNode newNode = new Node(data);

		if (data > pParent->_data) {
			pParent->_rightChild = newNode;
			
		}
		else if (data < pParent->_data){
			pParent->_leftChild = newNode;
		}

		newNode->_parent = pParent;

		//������ɣ���ʼ�ж�ƽ����
		while (pParent && pParent == RED) {
			
		}





	}

private:
	PNode _root;
};
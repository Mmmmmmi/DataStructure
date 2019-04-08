#pragma once

#include <iostream>

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

	bool Insert(const T& data)
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
		pCur = new Node(data);

		if (data > pParent->_data) {
			pParent->_rightChild = pCur;
			
		}
		else if (data < pParent->_data){
			pParent->_leftChild = pCur;
		}

		pCur->_parent = pParent;

		
		//������ɣ���ʼ�ж�ƽ����
		while (pParent && pParent->_color == RED) {
			//���˫��Ϊ�ڣ���˵���Ѿ�ƽ������
			
			
			PNode pGrandFather = pParent->_parent;
			//�游�ڵ�һ�����ڣ���Ϊ������游�ڵ㲻����
			//��ô��˵����˫�׽ڵ��ڸ��ڵ���
			//˵����һ�ε����Ľڵ�Ϊ���ڵ�ĺ��ӽڵ�
			//����Ϊ���ڵ�Ϊ��ɫ���Ͳ������ѭ��


			//���˫��Ϊ�죬�����������ͬʱ����Ӧ�ù�ע����ڵ�������Ҳ�����游�ڵ����һ������
			// pParent = pGrandFather->_leftChild �����
			//1. ���˫��Ϊ �� ������Ϊ �죬���Ҳ���λ��Ϊ����  
			//��������˫�׺����嶼��Ϊ��ɫ���游��Ϊ��ɫ��Ȼ��cur��Ϊ�游�ڵ�����ѭ��
			
			//2. ���˫��Ϊ �� ������Ϊ �죬���Ҳ���λ��Ϊ���ҡ�  
			//����������Ϊ��������ת���⣬���Ժ�1������ͬ

			//3. ���˫��Ϊ �� ������Ϊ ��/�����ڣ����Ҳ���λ��Ϊ����
			//��pGrandFather��������
			
			//4. ���˫��Ϊ �� ������Ϊ ��/�����ڣ����Ҳ���λ��Ϊ����
			//�ȶ�pParent ��������
			//�ٶ�pGrandFather��������


			// pParent = pGrandFather->_rightChild �����     ������һ����ִ�з������ͺ�
			//5. ���˫��Ϊ �� ������Ϊ �죬���Ҳ���λ��Ϊ���ҡ�	 ����������1��ͬ
			//6. ���˫��Ϊ �� ������Ϊ �죬���Ҳ���λ��Ϊ����  ����������1��ͬ

			//7. ���˫��Ϊ �� ������Ϊ ��/�����ڣ����Ҳ���λ��Ϊ����  
			//��pGrandFather��������

			//8. ���˫��Ϊ �� ������Ϊ ��/�����ڣ����Ҳ���λ��Ϊ����
			//��pParent��������
			//��pGrandFather��������


			//pParent �϶�Ϊ��,���Ϊ�ڵĻ��Ͳ�����ѭ��
			//pGrandFather �п��ܲ����ڣ������ھ�˵�������ڵ��ˣ�ֻҪpGrandFather Ϊ�գ���˵��pParent Ϊ���ڵ�
			if (pParent == pGrandFather->_leftChild) {
				//˫��Ϊ�游����
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
						//4   ��ת���Ϊ 3
						//��ת
						RotateL(pParent);
						//��ת��֮����pCur ��ָ������Ľڵ㣬pParent ��ָ������Ľڵ�
						//Ҳ��������ָ�뽻��
						std::swap(pParent, pCur);	
					}
					//3
					//�ٽ���һ����ת�����������
					pParent->_color = BLACK;
					//˫�ױ�Ϊ�ڣ��Ͳ�������ת��
					pGrandFather->_color = RED;
					RotateR(pGrandFather);
					break;
				}
			}
			else if (pParent == pGrandFather->_rightChild){
				//˫��Ϊ�游����
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
					//8   ��ת���Ϊ7
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
		//����
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
		//����
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
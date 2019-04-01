#pragma once


/*
	AVL����
		�����Ƕ���������
		���������ĸ߶ȲҲ����ƽ�����ӵľ���ֵ������1
		��������Ҳ��ƽ�������

	AVL����������ƽ�����ӵĸ���������ö������������ҵ������
	����󣬿��ܻ�ʧȥƽ�⣬���ݵ����㷨����ƽ������
	����涨������ - ��


*/

template <class T>
struct AVLTreeNode
{
	AVLTreeNode(const T& data)
		:_data(data)
		,_bf(0)
		, _leftChild(nullptr)
		, _rightChild(nullptr)
		, _parent(nullptr)
	{}

	T _data;					 //������
	int _bf;					 // ƽ������
	AVLTreeNode<T>* _leftChild;	 //����
	AVLTreeNode<T>* _rightChild; //�Һ���
	AVLTreeNode<T>* _parent;	 //˫��
};

template <class T>
class AVLTree
{
	typedef AVLTreeNode<T> Node;
	typedef Node* PNode;
public:
	AVLTree()
		:_root(nullptr)
	{}

	bool Insert(const T& data)
	{
		if (_root == nullptr) {
			_root = new Node(data);
			return true;
		}

		PNode pParent = nullptr;
		PNode pCur = _root;

		//���ҵ������
		while (pCur != nullptr) {
			if (pCur->_data == data) {
				return false;
			}
			else if (pCur->_data < data) {
				pParent = pCur;
				pCur = pCur->_rightChild;
			}
			else if (pCur->_data > data) {
				pParent = pCur;
				pCur = pCur->_leftChild;
			}
		}
		
		//����
		PNode newNode = new Node(data);
		if (data > pParent->_data) {
			pParent->_rightChild = newNode;
		}
		else if (data < pParent->_data) {
			pParent->_leftChild = newNode;
		}
		newNode->_parent = pParent;	  //�����´����Ľڵ���Ϣ
		
		while (pParent) {

			if (data < pParent->_data) {    //���
				pParent->_bf--;
			}
			else {			//�ұ�
				pParent->_bf++;
			}

			//����ƽ����
			if (pParent->_bf == 0) {		//˵�����ĸ߶�û�з����仯
				break;
			}
			else if (pParent->_bf == 1 || pParent->_bf == -1) {
				pCur = pParent;			//������ĸ߶ȷ����� 0---->1 �ı仯��˵�����ܻ�ʧȥƽ�⣬�������ϵ���
				pParent = pCur->_parent;
			}
			else {		//== 0   == 1 == - ��������ˣ�ʣ�µľ��Ǵ�1--->2 ���� -1 ---->-2
				//�ߵ������˵��	pParent->_bf == 2 || pParent->_bf == -2	pParent  ʧȥƽ��
				//��������Ҫ��ת��
				//�ж���� 
				if (pParent->_bf == -2) {	//����Ľڵ���ʧȥƽ��ڵ����������
					if (pCur->_bf == -1) {		//����
						RightTotate(pParent);
						break;
					}
					else if (pCur->_bf == 1) {	//����
						Left_RightTotate(pParent);
						break;
					}
				}
				else if (pParent->_bf == 2) {		//����Ľڵ���ʧȥƽ��ڵ����������
					if (pCur->_bf == 1) {		//����
						LeftTotate(pParent);
						break;
					}
					else if (pCur->_bf == -1) {	//����
						Right_LeftTotate(pParent);
						break;
					}
				}
			}
		}
	}

	bool IsBalanceTree() const
	{
		return _IsBalanceTree(_root);
	}

	void InOrder() const
	{
		_InOrder(_root);
		std::cout << std::endl;
	}

	void Destroy()	//����
	{
		_Destroy(_root);
	}

	~AVLTree()		//����
	{
		_Destroy(_root);
	}

private:

	void RightTotate(PNode pParent /*ʧȥƽ��Ľڵ�*/)		
	{
		//����ʧȥƽ��Ľڵ㣬���е���

		//����϶���Ϊ�գ����Ϊ�գ��Ͳ���ʧȥƽ����  pParent->_rightChild �����п���Ϊ��
		PNode pLeft = pParent->_leftChild;	
		
		//parent ���ӵ��Һ��ӣ���Ϊparent ������Ϊ pLeft ���к���
		//��ˣ�Ӧ�ð���������ҵ�parent��������ȥ�������п���Ϊ��
		PNode pLeftR = pLeft->_rightChild;
		
		//��ΪҪ��ת�������Ȱ�pParent->_Child ����  Ҳ���� pGrandFather �� ����
		PNode pGrandFather = pParent->_parent;
		//�����ǰ�ڵ���˫�׽ڵ�
		if (pGrandFather) {		
			if (pParent->_data > pGrandFather->_data) {
				//pParent �� pGrandFather ���Һ���
				pGrandFather->_rightChild = pLeft;
			}
			else {
				//����
				pGrandFather->_leftChild = pLeft;
			}
		}
		else {
			//���û�У���˵���Ǹ��ڵ�
			_root = pParent->_leftChild;
		}
		pLeft->_parent = pGrandFather;

		//PNode pLeft = pParent->_leftChild;
		//PNode pLeftR = pLeft->_rightChilde;
		//pParent ���� �����ӵ��Һ��ӣ����pParent �����Ӵ�Ӧ�ù��Լ����ӵ��Һ���  ����п���Ϊ��
		
		pParent->_leftChild = pLeftR;
		if (pLeftR) {
			pLeftR->_parent = pParent;
		}
		pLeft->_rightChild = pParent;
		pParent->_parent = pLeft;
		//���pLeft �� �Һ��ӣ���ô pParent �϶�Ҳ�У����������ĸ߶�Ҳ��ͬ��ͬʱ���²���Ľڵ�϶���pLeft �����ӣ�������ڲ���pLeft ���ӵ�ʱ��ʧȥƽ����
		//���pLeft û���Һ��ӣ���ôpParent�϶�Ҳû�У����ң��²���Ľڵ���pLeft �ĺ���
		//����������ת֮��pLeft pParent ��ƽ����
		pParent->_bf = pLeft->_bf = 0;
	}
	
	void LeftTotate(PNode pParent /*ʧȥƽ��Ľڵ�*/)
	{
		PNode pRight = pParent->_rightChild;
		PNode pRightL = pRight->_leftChild;			//����Ϊ��

		//����pParent ��˫�׽ڵ�
		PNode pGrandFather = pParent->_parent;		//����Ϊ��
		if (pGrandFather) {
			if (pParent->_data > pGrandFather->_data) {
				//������
				pGrandFather->_rightChild = pRight;
			}
			else {
				pGrandFather->_leftChild = pRight;
			}
		}
		else {
			_root = pRight;
		}
		pRight->_parent = pGrandFather;

		//��ת
		pParent->_rightChild = pRightL;
		if (pRightL) {
			pRightL->_parent = pParent;
		}
		pRight->_leftChild = pParent;
		pParent->_parent = pRight;

		//����ƽ������
		pParent->_bf = pRight->_bf = 0;
	}

	void Right_LeftTotate(PNode pParent /*ʧȥƽ��Ľڵ�*/)
	{
		PNode pRight = pParent->_rightChild;
		PNode pRightL = pRight->_leftChild;

		int pRightLbf = pRightL->_bf;

		RightTotate(pRight);
		LeftTotate(pParent);

		//��ͼ���ܿ�����
		//�������Ľڵ����pRightL ��ô ��ת��ɺ�pParent->_bf = 0, pRight->_bf = 0 , pRightL->_bf = 0
		//�������ڵ�ΪpRightL->_leftChild ��ô������²���Ľڵ�����ҵ� pParent->_rightChild
		//�������ڵ�ΪpRightL->_rightChild ��ô������²���Ľڵ�����ҵ�pRight->_leftChild 
		if (pRightLbf == -1) {
			pRight->_bf = 1;
		}
		else if (pRightLbf == 1) {
			pParent->_bf = -1;
		}
	}

	void Left_RightTotate(PNode pParent /*ʧȥƽ��Ľڵ�*/)
	{
		PNode pLeft = pParent->_leftChild;
		PNode pLeftR = pLeft->_rightChild;

		int pLeftRbf = pLeftR->_bf;

		LeftTotate(pLeft);
		RightTotate(pParent);
		
		//�������Ľڵ����pRightL ��ô ��ת��ɺ�pParent->_bf = 0, pRight->_bf = 0 , pRightL->_bf = 0
		//��� �²���Ľڵ��� pLeftR->_leftChild  ��ô ��ת����½ڵ�͹ҵ�pLeft->_rightChild ��ȥ��	
		//��ôpParent->_leftChild �Ϳ���
		//��� �²���Ľڵ��� pLeftR->_rightChild  ��ô ��ת����½ڵ�͹ҵ�pParent->_leftChild ��ȥ��
		//��ôpLeft->_rightChild �Ϳ���
		if (pLeftRbf == -1) {
			pParent->_bf = 1;
		}
		else if (pLeftRbf == 1) {
			pLeft->_bf = -1;
		}
	}

	int HeightTree(const PNode root) const
	{
		if (root == nullptr) {
			return 0;
		}
		int heightleft = HeightTree(root->_leftChild);
		int heightright = HeightTree(root->_rightChild);
		return (heightleft > heightright ? heightleft : heightright) + 1;
	}

	bool _IsBalanceTree(const PNode root) const
	{
		if (root == nullptr) {
			return true;
		}
		//�ж�ƽ�����ӶԲ���
		int leftHeight = HeightTree(root->_leftChild);
		int rightHeight = HeightTree(root->_rightChild);
		int rootbf = rightHeight - leftHeight;
		if (rootbf != root->_bf || rootbf > 1 || rootbf < -1) {		//����������ܳ���1
			return false;
		}
		//�ж���С�Ҵ�Բ���
		if (root->_leftChild) {
			if (root->_leftChild->_data >= root->_data) {		//��������ֵС���м�ڵ�
				return false;
			}
		}
		if (root->_rightChild) {
			if (root->_rightChild->_data <= root->_data) {		//��������ֵ�����м�ڵ�
				return false;
			}
		}

		return _IsBalanceTree(root->_leftChild) && _IsBalanceTree(root->_rightChild);

	}

	void _InOrder(const PNode root) const
	{
		if (root == nullptr) {
			return;
		}
		_InOrder(root->_leftChild);
		std::cout << root->_data << " ";
		_InOrder(root->_rightChild);
	}
	
	void _Destroy(PNode& root)
	{
		if (root) {
			_Destroy(root->_leftChild);
			_Destroy(root->_rightChild);
			delete root;
			root = nullptr;
		}
	}

	PNode _root;
};




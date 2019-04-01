#pragma once


/*
	AVL树：
		首先是二叉搜索树
		左右子树的高度差，也就是平衡因子的绝对值不超过1
		左右子树也是平衡二叉树

	AVL树中引入了平衡因子的概念，首先利用二叉树的性质找到插入点
	插入后，可能会失去平衡，根据调整算法调整平衡因子
	这里规定的是右 - 左


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

	T _data;					 //数据域
	int _bf;					 // 平衡因子
	AVLTreeNode<T>* _leftChild;	 //左孩子
	AVLTreeNode<T>* _rightChild; //右孩子
	AVLTreeNode<T>* _parent;	 //双亲
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

		//先找到插入点
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
		
		//插入
		PNode newNode = new Node(data);
		if (data > pParent->_data) {
			pParent->_rightChild = newNode;
		}
		else if (data < pParent->_data) {
			pParent->_leftChild = newNode;
		}
		newNode->_parent = pParent;	  //更新新创建的节点信息
		
		while (pParent) {

			if (data < pParent->_data) {    //左边
				pParent->_bf--;
			}
			else {			//右边
				pParent->_bf++;
			}

			//调整平衡性
			if (pParent->_bf == 0) {		//说明树的高度没有发生变化
				break;
			}
			else if (pParent->_bf == 1 || pParent->_bf == -1) {
				pCur = pParent;			//如果树的高度发生了 0---->1 的变化，说明可能会失去平衡，继续向上调整
				pParent = pCur->_parent;
			}
			else {		//== 0   == 1 == - 都处理过了，剩下的就是从1--->2 或者 -1 ---->-2
				//走到这里就说明	pParent->_bf == 2 || pParent->_bf == -2	pParent  失去平衡
				//这样就需要旋转了
				//判断情况 
				if (pParent->_bf == -2) {	//插入的节点在失去平衡节点的左子树上
					if (pCur->_bf == -1) {		//左左
						RightTotate(pParent);
						break;
					}
					else if (pCur->_bf == 1) {	//左右
						Left_RightTotate(pParent);
						break;
					}
				}
				else if (pParent->_bf == 2) {		//插入的节点在失去平衡节点的右子树上
					if (pCur->_bf == 1) {		//右右
						LeftTotate(pParent);
						break;
					}
					else if (pCur->_bf == -1) {	//右左
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

	void Destroy()	//销毁
	{
		_Destroy(_root);
	}

	~AVLTree()		//销毁
	{
		_Destroy(_root);
	}

private:

	void RightTotate(PNode pParent /*失去平衡的节点*/)		
	{
		//传入失去平衡的节点，进行调整

		//这个肯定不为空，如果为空，就不会失去平衡了  pParent->_rightChild 倒是有可能为空
		PNode pLeft = pParent->_leftChild;	
		
		//parent 左孩子的右孩子，因为parent 即将称为 pLeft 的有孩子
		//因此，应该把这个子数挂到parent的左孩子上去，但是有可能为空
		PNode pLeftR = pLeft->_rightChild;
		
		//因为要旋转，所以先把pParent->_Child 变了  也就是 pGrandFather 的 孩子
		PNode pGrandFather = pParent->_parent;
		//如果当前节点有双亲节点
		if (pGrandFather) {		
			if (pParent->_data > pGrandFather->_data) {
				//pParent 是 pGrandFather 的右孩子
				pGrandFather->_rightChild = pLeft;
			}
			else {
				//左孩子
				pGrandFather->_leftChild = pLeft;
			}
		}
		else {
			//如果没有，就说明是根节点
			_root = pParent->_leftChild;
		}
		pLeft->_parent = pGrandFather;

		//PNode pLeft = pParent->_leftChild;
		//PNode pLeftR = pLeft->_rightChilde;
		//pParent 成了 它左孩子的右孩子，因此pParent 的左孩子处应该挂自己左孩子的右孩子  这个有可能为空
		
		pParent->_leftChild = pLeftR;
		if (pLeftR) {
			pLeftR->_parent = pParent;
		}
		pLeft->_rightChild = pParent;
		pParent->_parent = pLeft;
		//如果pLeft 有 右孩子，那么 pParent 肯定也有，并且子数的高度也相同，同时，新插入的节点肯定是pLeft 的孙子，否则就在插入pLeft 孩子的时候失去平衡了
		//如果pLeft 没有右孩子，那么pParent肯定也没有，并且，新插入的节点是pLeft 的孩子
		//所以这样旋转之后，pLeft pParent 都平衡了
		pParent->_bf = pLeft->_bf = 0;
	}
	
	void LeftTotate(PNode pParent /*失去平衡的节点*/)
	{
		PNode pRight = pParent->_rightChild;
		PNode pRightL = pRight->_leftChild;			//可能为空

		//处理pParent 的双亲节点
		PNode pGrandFather = pParent->_parent;		//可能为空
		if (pGrandFather) {
			if (pParent->_data > pGrandFather->_data) {
				//右子树
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

		//旋转
		pParent->_rightChild = pRightL;
		if (pRightL) {
			pRightL->_parent = pParent;
		}
		pRight->_leftChild = pParent;
		pParent->_parent = pRight;

		//调整平衡因子
		pParent->_bf = pRight->_bf = 0;
	}

	void Right_LeftTotate(PNode pParent /*失去平衡的节点*/)
	{
		PNode pRight = pParent->_rightChild;
		PNode pRightL = pRight->_leftChild;

		int pRightLbf = pRightL->_bf;

		RightTotate(pRight);
		LeftTotate(pParent);

		//画图就能看到：
		//如果插入的节点就是pRightL 那么 旋转完成后，pParent->_bf = 0, pRight->_bf = 0 , pRightL->_bf = 0
		//如果插入节点为pRightL->_leftChild 那么，这个新插入的节点最后会挂到 pParent->_rightChild
		//如果插入节点为pRightL->_rightChild 那么，这个新插入的节点最后会挂到pRight->_leftChild 
		if (pRightLbf == -1) {
			pRight->_bf = 1;
		}
		else if (pRightLbf == 1) {
			pParent->_bf = -1;
		}
	}

	void Left_RightTotate(PNode pParent /*失去平衡的节点*/)
	{
		PNode pLeft = pParent->_leftChild;
		PNode pLeftR = pLeft->_rightChild;

		int pLeftRbf = pLeftR->_bf;

		LeftTotate(pLeft);
		RightTotate(pParent);
		
		//如果插入的节点就是pRightL 那么 旋转完成后，pParent->_bf = 0, pRight->_bf = 0 , pRightL->_bf = 0
		//如果 新插入的节点是 pLeftR->_leftChild  那么 旋转完后，新节点就挂到pLeft->_rightChild 上去了	
		//那么pParent->_leftChild 就空了
		//如果 新插入的节点是 pLeftR->_rightChild  那么 旋转完后，新节点就挂到pParent->_leftChild 上去了
		//那么pLeft->_rightChild 就空了
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
		//判断平衡因子对不对
		int leftHeight = HeightTree(root->_leftChild);
		int rightHeight = HeightTree(root->_rightChild);
		int rootbf = rightHeight - leftHeight;
		if (rootbf != root->_bf || rootbf > 1 || rootbf < -1) {		//左右子数差不能超过1
			return false;
		}
		//判断左小右大对不对
		if (root->_leftChild) {
			if (root->_leftChild->_data >= root->_data) {		//左子树的值小于中间节点
				return false;
			}
		}
		if (root->_rightChild) {
			if (root->_rightChild->_data <= root->_data) {		//右子树的值大于中间节点
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




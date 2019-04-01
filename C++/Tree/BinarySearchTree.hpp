#pragma once





template <class T>
struct BSNode
{
	BSNode(const T& data = T())	//节点构造函数
		:_data(data)
		,_leftChild(nullptr)
		,_rightChild(nullptr)
	{}

	T _data;
	BSNode* _leftChild;
	BSNode* _rightChild;
};

template <class T>
class BinarySearchTree
{
	typedef BSNode<T> Node;
	typedef Node* PNode;
public:

    BinarySearchTree()	//构造函数
		:_root(nullptr)
	{}

	bool Insert(const T& data)	//插入数据
	{
		if (_root == nullptr) {		//空
			_root = new BSNode<T> (data);
			return true;
		}
		PNode pParent = nullptr;
		PNode pCur = _root;
		while (pCur != nullptr) {
			pParent = pCur;
			if (pCur->_data == data) {
				return false;
			}
			else if (pCur->_data < data) {
				pCur = pCur->_rightChild;
			}
			else if (pCur->_data > data) {
				pCur = pCur->_leftChild;
			}
		}
		if (data > pParent->_data) {
			//右
			pParent->_rightChild = new BSNode<T> (data);
		}
		else {
			//左
			pParent->_leftChild = new BSNode<T> (data);
		}
		return true;
	}

	bool Erase(const T& data)		//删除
	{
		if (_root == nullptr) {		//空树
			return false;
		}
		PNode curparent = nullptr;
		PNode pCur = _root;
		while (pCur != nullptr) {

			if (pCur->_data < data) {
				curparent = pCur;
				pCur = pCur->_rightChild;
			}
			else if (pCur->_data > data){
				curparent = pCur;
				pCur = pCur->_leftChild;
			}
			else if (pCur->_data == data) {
				if (pCur->_leftChild == nullptr) {		//左为空
					if (pCur == curparent->_leftChild) {
						curparent->_leftChild = pCur->_rightChild;
					}
					else if (pCur == curparent->_rightChild){
						curparent->_rightChild = pCur->_rightChild;
					}
					delete pCur;
					pCur = nullptr;
					return true;
				}
				else if (pCur->_rightChild == nullptr){		//右为空
					if (pCur == curparent->_leftChild) {
						curparent->_leftChild = pCur->_leftChild;
					}
					else if (pCur == curparent->_rightChild) {
						curparent->_rightChild = pCur->_leftChild;
					}
					delete pCur;
					pCur = nullptr;
					return true;
				}
				else {
					//找该节点左边最大 与要删除的节点交换 删除左边最大
					PNode delparent = pCur;		//这步肯定不为空
					PNode del = pCur->_leftChild;		//这步肯定不为空
					while (del->_rightChild != nullptr) {
						delparent = del;
						del = del->_rightChild;
					}
					pCur->_data = del->_data;
					if (del == pCur->_leftChild) {	//如果最大值是删除节点的左孩子
						pCur->_leftChild = del->_leftChild;
					}
					else {
						delparent->_rightChild = del->_leftChild;
					}
					delete del;
					return true;
				}
			}
		}
		return false;
	}

	PNode Find(const T& data) const			//查找
	{
		PNode pCur = _root;
		while (pCur != NULL) {
			if (pCur->_data == data) {
				return pCur;
			}
			else if (pCur->_data > data) {
				pCur = pCur->_leftChild;
			}
			else if (pCur->_data < data) {
				pCur = pCur->_rightChild;
			}
		}
		return nullptr;
	}

	void InOrder() const			//中序遍历
	{
		_InOrder(_root);
		std::cout << std::endl;
	}

	void Destroy()
	{
		_DestroyTree(_root);
	}

    ~BinarySearchTree()			//析构函数
	{
		_DestroyTree(_root);
	}

private:

	void _InOrder(const PNode& root) const 
	{
		if (root == nullptr) {
			return;
		}
		_InOrder(root->_leftChild);
		std::cout << root->_data << " ";
		_InOrder(root->_rightChild);
	}

	void _DestroyTree(PNode& root)	//销毁
	{
		if (root) {
			_DestroyTree(root->_leftChild);
			_DestroyTree(root->_rightChild);
			delete root;
			root = nullptr;
		}
	}

	PNode _root;
};
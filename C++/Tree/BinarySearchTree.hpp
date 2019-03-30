#pragma once


template <class T>
struct BSNode
{
	BSNode(const T& data = T()) :	//节点构造函数
		_data(data),
		_leftChild(nullptr),
		_rightChild(nullptr)
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
		PNode parent = nullptr;
		PNode cur = _root;
		while (cur != nullptr) {
			parent = cur;
			if (cur->_data == data) {
				return false;
			}
			else if (cur->_data < data) {
				cur = cur->_rightChild;
			}
			else if (cur->_data > data) {
				cur = cur->_leftChild;
			}
		}
		if (data > parent->_data) {
			//右
			parent->_rightChild = new BSNode<T> (data);
		}
		else {
			//左
			parent->_leftChild = new BSNode<T> (data);
		}
		return true;
	}

	bool Erase(const T& data)		//删除
	{
		if (_root == nullptr) {		//空树
			return false;
		}
		PNode curparent = nullptr;
		PNode cur = _root;
		while (cur != nullptr) {

			if (cur->_data < data) {
				curparent = cur;
				cur = cur->_rightChild;
			}
			else if (cur->_data > data){
				curparent = cur;
				cur = cur->_leftChild;
			}
			else if (cur->_data == data) {
				if (cur->_leftChild == nullptr) {		//左为空
					if (cur == curparent->_leftChild) {
						curparent->_leftChild = cur->_rightChild;
					}
					else if (cur == curparent->_rightChild){
						curparent->_rightChild = cur->_rightChild;
					}
					delete cur;
					cur = nullptr;
					return true;
				}
				else if (cur->_rightChild == nullptr){		//右为空
					if (cur == curparent->_leftChild) {
						curparent->_leftChild = cur->_leftChild;
					}
					else if (cur == curparent->_rightChild) {
						curparent->_rightChild = cur->_leftChild;
					}
					delete cur;
					cur = nullptr;
					return true;
				}
				else {
					//找该节点左边最大 与要删除的节点交换 删除左边最大
					PNode delparent = cur;		//这步肯定不为空
					PNode del = cur->_leftChild;		//这步肯定不为空
					while (del->_rightChild != nullptr) {
						delparent = del;
						del = del->_rightChild;
					}
					cur->_data = del->_data;
					if (del == cur->_leftChild) {	//如果最大值是删除节点的左孩子
						cur->_leftChild = del->_leftChild;
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
		PNode cur = _root;
		while (cur != NULL) {
			if (cur->_data == data) {
				return cur;
			}
			else if (cur->_data > data) {
				cur = cur->_leftChild;
			}
			else if (cur->_data < data) {
				cur = cur->_rightChild;
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
		if (_root) {
			_DestroyTree(_root);
		}
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
			root->_leftChild = nullptr;
			_DestroyTree(root->_rightChild);
			root->_rightChild = nullptr;
			delete root;
			root = nullptr;
		}
	}

	PNode _root;
};
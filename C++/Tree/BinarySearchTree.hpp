#pragma once


template <class T>
struct BSNode
{
	BSNode(const T& data = T()) :	//�ڵ㹹�캯��
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
    BinarySearchTree()	//���캯��
		:_root(nullptr)
	{}

	bool Insert(const T& data)	//��������
	{
		if (_root == nullptr) {		//��
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
			//��
			parent->_rightChild = new BSNode<T> (data);
		}
		else {
			//��
			parent->_leftChild = new BSNode<T> (data);
		}
		return true;
	}

	bool Erase(const T& data)		//ɾ��
	{
		if (_root == nullptr) {		//����
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
				if (cur->_leftChild == nullptr) {		//��Ϊ��
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
				else if (cur->_rightChild == nullptr){		//��Ϊ��
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
					//�Ҹýڵ������� ��Ҫɾ���Ľڵ㽻�� ɾ��������
					PNode delparent = cur;		//�ⲽ�϶���Ϊ��
					PNode del = cur->_leftChild;		//�ⲽ�϶���Ϊ��
					while (del->_rightChild != nullptr) {
						delparent = del;
						del = del->_rightChild;
					}
					cur->_data = del->_data;
					if (del == cur->_leftChild) {	//������ֵ��ɾ���ڵ������
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

	PNode Find(const T& data) const			//����
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

	void InOrder() const			//�������
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



    ~BinarySearchTree()			//��������
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

	void _DestroyTree(PNode& root)	//����
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
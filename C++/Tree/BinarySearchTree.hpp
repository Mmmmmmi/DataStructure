#pragma once





template <class T>
struct BSNode
{
	BSNode(const T& data = T())	//�ڵ㹹�캯��
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

    BinarySearchTree()	//���캯��
		:_root(nullptr)
	{}

	bool Insert(const T& data)	//��������
	{
		if (_root == nullptr) {		//��
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
			//��
			pParent->_rightChild = new BSNode<T> (data);
		}
		else {
			//��
			pParent->_leftChild = new BSNode<T> (data);
		}
		return true;
	}

	bool Erase(const T& data)		//ɾ��
	{
		if (_root == nullptr) {		//����
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
				if (pCur->_leftChild == nullptr) {		//��Ϊ��
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
				else if (pCur->_rightChild == nullptr){		//��Ϊ��
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
					//�Ҹýڵ������� ��Ҫɾ���Ľڵ㽻�� ɾ��������
					PNode delparent = pCur;		//�ⲽ�϶���Ϊ��
					PNode del = pCur->_leftChild;		//�ⲽ�϶���Ϊ��
					while (del->_rightChild != nullptr) {
						delparent = del;
						del = del->_rightChild;
					}
					pCur->_data = del->_data;
					if (del == pCur->_leftChild) {	//������ֵ��ɾ���ڵ������
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

	PNode Find(const T& data) const			//����
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

	void InOrder() const			//�������
	{
		_InOrder(_root);
		std::cout << std::endl;
	}

	void Destroy()
	{
		_DestroyTree(_root);
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
			_DestroyTree(root->_rightChild);
			delete root;
			root = nullptr;
		}
	}

	PNode _root;
};
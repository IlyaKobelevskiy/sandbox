#pragma once

template<class KeyType, class ValueType>
class RedBlackBstNode
{
public:
	inline RedBlackBstNode()
		: parent(0)
		, left(0)
		, right(0)
		, isBlack(false)
	{
	}

	inline ~RedBlackBstNode()
	{
		if(left)
			delete left;
		if(right)
			delete right;
	}

	RedBlackBstNode			*parent,*left,*right;
	bool					isBlack;
	KeyType					key;
	ValueType				value;
};

template <class OutputStream, class K, class V>
inline OutputStream & operator << (OutputStream &stream, const RedBlackBstNode<K,V> &value)
{
	stream << "[" << value.key << "," << value.value << "," << (value.isBlack ? "black" : "red") << "] ";
	return stream;
}

template <class KeyType,class ValueType>
class RedBlackBst
{
public:
	RedBlackBst();
	~RedBlackBst();

	void insert(const KeyType &key, const ValueType &value);
	void remove(KeyType key);
	RedBlackBstNode<KeyType,ValueType>* find(const KeyType &key) const;

	inline RedBlackBstNode<KeyType,ValueType>* getRoot() const 
	{
		return root;
	}

private:
	RedBlackBstNode<KeyType,ValueType>	*root;
};

template <class KeyType,class ValueType> inline 
	RedBlackBst<KeyType,ValueType>::RedBlackBst()
	: root(0)
{
}

template <class KeyType,class ValueType> inline 
	RedBlackBst<KeyType,ValueType>::~RedBlackBst()
{
	if(root)
		delete root;
}

template <class KeyType,class ValueType> inline 
	void RedBlackBst<KeyType,ValueType>::insert(const KeyType &key, const ValueType &value)
{
	if(!this->root)
	{
		root = new RedBlackBstNode<KeyType,ValueType>();
		root->key = key;
		root->value = value;
		return;
	}

	RedBlackBstNode<KeyType,ValueType>	*currNode(this->getRoot());
	while(1)
	{
		if(currNode->key < key)
		{
			if(currNode->left)
			{
				currNode = currNode->left;
				continue;
			}
			else
			{
				//insert as left child
				currNode->left = new RedBlackBstNode<KeyType,ValueType>();
				currNode->left->parent = currNode;
				currNode->left->key = key;
				currNode->left->value = value;
				return;
			}
		}
		if(currNode->key > key)
		{
			if(currNode->right)
			{
				currNode = currNode->right;
				continue;
			}
			else
			{
				//insert as left child
				currNode->right = new RedBlackBstNode<KeyType,ValueType>();
				currNode->right->parent = currNode;
				currNode->right->key = key;
				currNode->right->value = value;
			}
		}
		if(currNode->key == key)
		{
			currNode->value = value;
			return;
		}
	}
}

template <class OutputStream, class K, class V> inline
void printHelper(OutputStream &stream, const RedBlackBstNode<K,V> *val, int &currDepth, int &maxReachedDepth)
{
	if(!val)
		return;

	if(maxReachedDepth < currDepth)
	{
		maxReachedDepth = currDepth;
		stream << std::endl;
	}
	++currDepth;

	if(val->left)
		stream << *(val->left);
	if(val->right)
		stream << *(val->right);

	printHelper(stream,val->left,currDepth,maxReachedDepth);
	printHelper(stream,val->right,currDepth,maxReachedDepth);
	--currDepth;
}

template <class OutputStream, class K, class V> inline
OutputStream & operator << (OutputStream &stream, const RedBlackBst<K,V> &val)
{
	RedBlackBstNode<K,V>* root = val.getRoot();
	int currDepth(0),maxReachedDepth(0);
	if(root)
	{
		std::cout<< *root;
		++currDepth;
	}
	printHelper(stream,root,currDepth,maxReachedDepth);
	return stream;
}
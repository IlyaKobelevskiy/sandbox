#pragma once
class RedBlackBstNode;
class RedBlackBst
{
public:
	RedBlackBst();
	~RedBlackBst();

	void				insert(int key);
	void				remove(int key);

	RedBlackBstNode*	getNode(int key) const;
	RedBlackBstNode*	getRoot() const;

private:
	RedBlackBstNode*	rootPtr;
};


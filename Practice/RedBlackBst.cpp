#include "RedBlackBst.h"

RedBlackBst::RedBlackBst()
	: rootPtr(0)
{
}

RedBlackBst::~RedBlackBst()
{
	if(rootPtr)
		delete rootPtr;
}

void	RedBlackBst::insert(int key)
{
}

void	RedBlackBst::remove(int key)
{
}

RedBlackBstNode*	RedBlackBst::getNode(int key) const
{
	return 0;
}

RedBlackBstNode*	RedBlackBst::getRoot() const
{
	return 0;
}
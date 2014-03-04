#include "RedBlackBstNode.h"

RedBlackBstNode::RedBlackBstNode(int keyIn, RedBlackBstNode* parentIn)
	: key(keyIn)
	, parent(parentIn)
	, left(0)
	, right(0)
	, isBlack(true)
{
}

RedBlackBstNode::~RedBlackBstNode()
{
	if(left)
		delete left;
	if(right)
		delete right;
}
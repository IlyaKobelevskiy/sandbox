#pragma once

class RedBlackBstNode
{
public:

	RedBlackBstNode(int keyIn = 0, RedBlackBstNode* parent = 0);
	~RedBlackBstNode();

	RedBlackBstNode		*parent,*left,*right;
	int					key;
	bool				isBlack;
};
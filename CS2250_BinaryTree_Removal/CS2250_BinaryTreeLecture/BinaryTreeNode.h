#ifndef BINARY_TREE_NODE_H
#define BINARY_TREE_NODE_H

#include <iostream>
#include <string>

#include "Trophy.h"

using namespace std;

class BinaryTreeNode
{
public:
	// Constructors and Destructors
	BinaryTreeNode(const Trophy& item);
	BinaryTreeNode(const BinaryTreeNode& node);
	~BinaryTreeNode();

	// Accessors
	BinaryTreeNode* GetLeft() const;
	BinaryTreeNode* GetRight() const;
	const Trophy& GetData() const;
	int GetHeight() const;
	
	// Mutators
	void SetLeft(BinaryTreeNode* left);
	void SetRight(BinaryTreeNode* right);
	void SetData(const Trophy& data);
	void SetHeight(int height);

	// Operators
	friend ostream& operator<<(ostream& sout, const BinaryTreeNode& node);



	// Facilitators
	static int GetNbrNodes();
private:

	BinaryTreeNode* left;
	BinaryTreeNode* right;
	Trophy* data;
	int height;

	static int nbrNodes;
};

#endif
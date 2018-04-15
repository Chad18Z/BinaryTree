#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <string>

#include "BinaryTreeNode.h"

using namespace std;

class BinaryTree
{
public:
	// Constructors and Destructors
	BinaryTree();
	~BinaryTree();

	// Facilitators
	void Insert(const Trophy& item);
	bool Search(const Trophy& item) const;
	bool Remove(const Trophy& item);

	// Operators
	friend ostream& operator<< (ostream& sout, const BinaryTree& tree);

	// Print methods
	//void InOrderPrint(ostream& sout) const;
	//void PreOrderPrint(ostream& sout) const;
	//void PostOrderPrint(ostream& sout) const;

	// Recursive Print methods
	void InOrderPrint(ostream& sout, BinaryTreeNode* curr) const;
	void PreOrderPrint(ostream& sout, BinaryTreeNode* curr) const;
	void PostOrderPrint(ostream& sout, BinaryTreeNode* curr) const;

	BinaryTreeNode* root;

private:

	// Recursive Facilitators
	void Insert(const Trophy& item, BinaryTreeNode* curr);
	bool Search(const Trophy& item, BinaryTreeNode* curr) const;
	bool Remove(const Trophy& item, BinaryTreeNode* curr);
	void MakeEmpty(BinaryTreeNode* curr);

	// Facilitators
	BinaryTreeNode* RemoveNode(BinaryTreeNode* curr);
	bool NeedsRebalancing(BinaryTreeNode* curr);
	BinaryTreeNode* Rebalance(BinaryTreeNode* curr);
	void FixHeight(BinaryTreeNode* curr);
	

};

#endif
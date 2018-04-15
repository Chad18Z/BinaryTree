#include "BinaryTreeNode.h"

int BinaryTreeNode::nbrNodes = 0;

int BinaryTreeNode::GetNbrNodes()
{
	return nbrNodes;
}

// BinaryTreeNode Constructor
// Store the item in the node
// Set it to have no children
// Increment the node count
BinaryTreeNode::BinaryTreeNode(const Trophy& item)
{
	data = new Trophy(item);
	right = NULL;
	left = NULL;
	height = 0;
	++nbrNodes;
	cout << nbrNodes;
}

// Copy Constructor
// Increment the node count
BinaryTreeNode::BinaryTreeNode(const BinaryTreeNode& node)
{
	data = node.data;
	right = node.right;
	left = node.left;
	height = node.height;
	++nbrNodes;
	cout << nbrNodes;
}

// BinaryTreeNode Destructor
// Delete this node.  Decrement the node count.
BinaryTreeNode::~BinaryTreeNode()
{
	--nbrNodes;
}

// Return a pointer to the left child
BinaryTreeNode* BinaryTreeNode::GetLeft() const
{
	return left;
}

// Return a pointer to the right child
BinaryTreeNode* BinaryTreeNode::GetRight() const
{
	return right;
}

// Return the data in the node
const Trophy& BinaryTreeNode::GetData() const
{
	
	return *data;
}

// Return the height of the node
// If this is not an AVL tree, this should
// always return zero.
int BinaryTreeNode::GetHeight() const
{
	return height;
}

// Set the left child
void BinaryTreeNode::SetLeft(BinaryTreeNode* left)
{
	this->left = left;
}

// Set the right child
void BinaryTreeNode::SetRight(BinaryTreeNode* right)
{
	this->right = right;
}

// Set the data
void BinaryTreeNode::SetData(const Trophy& trophy)
{
	*data = trophy;
}

// Set the height
void BinaryTreeNode::SetHeight(int height)
{
	this->height = height;
}

// Display the node's data
ostream& operator<<(ostream& sout, const BinaryTreeNode& node)
{
	sout << "Should be printing node data";
	return sout;
}




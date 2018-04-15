#include "BinaryTree.h"
#include <sstream>


// BinaryTree Constructor
// Initialize the tree to empty
BinaryTree::BinaryTree()
{
	root = NULL;
}

// BinaryTree Destructor
// Deletes the root node.
// Relies on Node's delete method.
BinaryTree::~BinaryTree()
{
	MakeEmpty(root);
	delete root;
	root = NULL;
}


// Returns the root node of the tree
//BinaryTreeNode* BinaryTree::GetRoot()
//{
//	cout << *root;
//	return root;
//}

void BinaryTree::MakeEmpty(BinaryTreeNode* curr)
{
	// If the current node is null, nothing to delete
	if (curr == NULL)
	{
		return;
	}
	if (curr->GetLeft() != NULL)
	{
		MakeEmpty(curr->GetLeft());
		delete curr->GetLeft();
		curr->SetLeft(NULL);
	}
	if (curr->GetRight() != NULL)
	{
		MakeEmpty(curr->GetRight());
		delete curr->GetRight();
		curr->SetRight(NULL);
	}
	curr = NULL;
}

/////////////////////////////////////////////////////////////////
// Insert Methods
/////////////////////////////////////////////////////////////////

// BinaryTree Insert
// Public Insert adds the item into the tree.
// If the tree is empty, adds the item as the root.
// Otherwise, uses the private insert to recursively insert.
void BinaryTree::Insert(const Trophy& item)
{	
	if (root == NULL)
	{		
		BinaryTreeNode* temp = new BinaryTreeNode(item);
		root = temp;
		cout << root;
		root->GetData().Print();
	}
	else
	{
		cout << root;
		root->GetData().Print();
		Insert(item, root);
	}
}

// Insert
// Insert the item starting at the current node.  If the
// item is less than the current node, the item is added
// to the left subtree.  If the item is greater, it is
// added to the right subtree.  If there is no subtree,
// the node is added as a child of this node.
void BinaryTree::Insert(const Trophy& item, BinaryTreeNode* curr)
{
	//curr->GetData().Print();
	// If the item is less than the current node, add it
	// to the left subtree
	if (item < curr->GetData())
	{
		// If there is no left subtree, add a new child
		if (curr->GetLeft() == NULL)
		{ 

			curr->SetLeft(new BinaryTreeNode(item));

		}
		// Recursively insert into the left subtree
		else
		{
			Insert(item, curr->GetLeft());
		}
	}
	// If the item is greater than the current node, add it
	// to the right subtree
	else if (curr->GetData() < item)
	{
		// If there is no right subtree, add a new child
		if (curr->GetRight() == NULL)
		{			
			curr->SetRight(new BinaryTreeNode(item));
			curr->GetRight()->GetData().Print();		
		}
		// Recursively insert into the right subtree
		else
		{
			Insert(item, curr->GetRight());
		}
	}
}

/////////////////////////////////////////////////////////////////
// AVL Methods
/////////////////////////////////////////////////////////////////
// Determine if the current node needs to be rebalanced
// Returns FALSE if this is not an AVL tree OR if the node
// does not need to be rebalanced.
// Returns TRUE otherwise.
bool BinaryTree::NeedsRebalancing(BinaryTreeNode* curr)
{
	// TODO: AVL Extra Credit
	return false;
}

// Rebalance the current node
// Return the new node
BinaryTreeNode* BinaryTree::Rebalance(BinaryTreeNode* curr)
{
	// TODO: AVL Extra Credit

	return NULL;
}

// Fix the height of the current node
void BinaryTree::FixHeight(BinaryTreeNode* curr)
{
	// TODO: AVL Extra Credit

}

/////////////////////////////////////////////////////////////////
// Search Methods
/////////////////////////////////////////////////////////////////

// Search
// Public Search method that uses the private version to search
// from the root.  Returns TRUE if the item is found.  Returns 
// FALSE if the tree is empty or if the item is not found.
bool BinaryTree::Search(const Trophy& item) const
{
	if (root == NULL)
	{
		return false;
	}
	else
	{
		return Search(item, root);
	}
}

// Search
// Private Search method that examines the current node and
// recursively its children until it finds the item.  If
// the current node has no children and does not match
// the item, then the search is exhausted and the item
// was not found.
// Returns TRUE if the item is found, FALSE if not. 
bool BinaryTree::Search(const Trophy& item, BinaryTreeNode* curr) const
{

	if (item == curr->GetData()) return true;
	if (item < curr->GetData())
	{
		// If the node has a left subtree, print that first
		if (curr->GetLeft() != NULL)
		{
			// Print the left subtree
			//InOrderPrint(sout, curr->GetLeft());
			if (item == curr->GetData())
			{
				return true;
			}
			else Search(item, curr->GetLeft());
		}
		else return false;
	}
	else if (item > curr->GetData())
	{
		// If the node has a left subtree, print that first
		if (curr->GetRight() != NULL)
		{
			// Print the left subtree
			//InOrderPrint(sout, curr->GetLeft());
			if (item == curr->GetData())
			{
				return true;
			}
			else Search(item, curr->GetRight());

		}
		else return false;
	}
	else return false;
}

/////////////////////////////////////////////////////////////////
// Removal Methods
// Implement in the Removal Assignment
/////////////////////////////////////////////////////////////////
// Remove(item)
// This method initiates the recursive removal from the tree
// It should test the root to see if the root is the item
// to remove, if so, then it should remove the root node
// and then fix the root pointer.  Note that since the root
// has no parent, it must be handled slightly differently
// than the rest of the tree
bool BinaryTree::Remove(const Trophy& item)
{
	// TODO: Implement in Removal Assignment
	return false;
}

// Remove(item, curr)
// Find the PARENT of the node to remove, remove that node, and then
// adjust the parent's pointer to point to the new subtree
bool BinaryTree::Remove(const Trophy& item, BinaryTreeNode* curr)
{
	// TODO: Implement in Removal Assignment
	return false;
}

// Remove(curr)
// Remove the current node by finding its correct "in order successor"
// and then return a pointer to the new node that will replace the current
// node in the tree (assuming some of the nodes were repositioned as in a
// removal with no children or with a single child).  If curr has two
// children, then only its value will be changed, so curr will be
// returned.
BinaryTreeNode* BinaryTree::RemoveNode(BinaryTreeNode* curr)
{
	// TODO: Implement in Removal Assignment
	return NULL;	
}
void BinaryTree::InOrderPrint(ostream& sout) const
{
	cout << root;
	InOrderPrint(sout, this->root);
}
void BinaryTree::PreOrderPrint(ostream& sout) const
{
	PreOrderPrint(sout, this->root);
}
void BinaryTree::PostOrderPrint(ostream& sout) const
{
	PostOrderPrint(sout, this->root);
}

// InOrderPrint
// Prints the tree "in-order".  Prints the left subtree, prints
// the current node, then prints the right subree.
void BinaryTree::InOrderPrint(ostream& sout, BinaryTreeNode* curr) const
{
	// If the current Node exists
	if (curr == NULL)
	{	
		cout << "null";
		return;
	}
	// If the node has a left subtree, print that first
	if (curr->GetLeft() != NULL)
	{
		// Print the left subtree
		InOrderPrint(sout, curr->GetLeft());
	}

	// Print the current node
	sout << *curr;

	// If the node has a right subtree, print it last
	if (curr->GetRight() != NULL)
	{

		// Print the right subtree
		InOrderPrint(sout, curr->GetRight());
	}
}

// PreOrderPrint
// Prints the tree "pre-order".  Prints the node, prints
// the left subtree, then prints the right subree.
void BinaryTree::PreOrderPrint(ostream& sout, BinaryTreeNode* curr) const
{
	sout << curr->GetData();
	// If the current Node exists
	if (curr == NULL)
	{
		return;
	}

	// Print the current node
	//sout << curr->GetData() << endl;
	sout << *curr << " ";

	// If the node has a left subtree, print that first
	if (curr->GetLeft() != NULL)
	{
		// Print the left subtree
		PreOrderPrint(sout, curr->GetLeft());
	}

	// If the node has a right subtree, print it last
	if (curr->GetRight() != NULL)
	{
		// Print the right subtree
		PreOrderPrint(sout, curr->GetRight());
	}
}

// PostOrderPrint
// Prints the tree "post-order".  Prints
// the left subtree, prints the right subree, then the current node.
void BinaryTree::PostOrderPrint(ostream& sout, BinaryTreeNode* curr) const
{
	// If the current Node exists
	if (curr == NULL)
	{
		return;
	}
	// If the node has a left subtree, print that first
	if (curr->GetLeft() != NULL)
	{
		// Print the left subtree
		PostOrderPrint(sout, curr->GetLeft());
	}
	// If the node has a right subtree, print it last
	if (curr->GetRight() != NULL)
	{
		// Print the right subtree
		PostOrderPrint(sout, curr->GetRight());
	}
	// Print the current node
	//sout << curr->GetData() << endl;
	sout << *curr << " ";
}

/////////////////////////////////////////////////////////////////
// Operators
/////////////////////////////////////////////////////////////////

// Insertion Operator
// Display the tree using all 3 print styles
ostream& operator<<(ostream& sout, const BinaryTree& tree)
{
	sout << "PreOrderPrint:   ";
	tree.PreOrderPrint(sout, tree.root);
	sout << "\n";

	sout << "InOrderPrint:    ";
	tree.InOrderPrint(sout, tree.root);
	sout << "\n";

	sout << "PostOrderPrint:  ";
	tree.PostOrderPrint(sout, tree.root);
	sout << "\n";
	return sout;
}
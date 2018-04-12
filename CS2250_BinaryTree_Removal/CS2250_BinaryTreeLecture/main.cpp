#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>


#include "BinaryTree.h"

#define DO_NOT_TEST_AVL 1		// TODO: Change this to 0 if you implemented AVL
#define TEST_REMOVAL 0			// TODO: Change this to 1 for the second week to test your removal code

using namespace std;

string smallRootOnlyTree[] = { "A" };
string smallRootOnlyTreeOutput[] = { "A ", "A ", "A " };

string smallSimpleTree[] = { "D", "B", "F" };
string smallSimpleTreeOutput[] = { "D B F ", "B D F ", "B F D " };

string leftLeftTree[] = { "C", "B", "A" };
string leftLeftTreeOutput[] = { "C B A ", "A B C ", "A B C " };
string leftLeftTreeOutputAVL[] = { "B A C ", "A B C ", "A C B " };

string rightRightTree[] = { "A", "B", "C" };
string rightRightTreeOutput[] = { "A B C ", "A B C ", "C B A " };
string rightRightTreeOutputAVL[] = { "B A C ", "A B C ", "A C B " };

string leftRightTree[] = { "C", "A", "B" };
string leftRightTreeOutput[] = { "C A B ", "A B C ", "B A C " };
string leftRightTreeOutputAVL[] = { "B A C ", "A B C ", "A C B " };

string rightLeftTree[] = { "A", "C", "B" };
string rightLeftTreeOutput[] = { "A C B ", "A B C ", "B C A " };
string rightLeftTreeOutputAVL[] = { "B A C ", "A B C ", "A C B " };

string smallFullTree[] = { "D", "B", "F", "C", "A", "E", "G" };
string smallFullTreeOutput[] = { "D B A C F E G ", "A B C D E F G ", "A C B E G F D " };

string largeTree[] = { "M", "J", "C", "B", "S", "I", "P", "D", "U", "F", "W", "H", "K", "N", "X", "O", "V", "A", "L", "Q", "R", "G", "T", "E", "Y" };
string largeTreeOutput[] = { "M J C B A I D F E H G K L S P N O Q R U T W V X Y ", 
							 "A B C D E F G H I J K L M N O P Q R S T U V W X Y ", 
							 "A B E G H F D I C L K J O N R Q P T V Y X W U S M " };
string largeTreeOutputAVL[] = { "J F C B A D E H G I P M K L N O U R Q S T W V X Y ",
								"A B C D E F G H I J K L M N O P Q R S T U V W X Y ",
								"A B E D C G I H F L K O N M Q T S R V Y X W U P J " };

const int testNameSize = 35;

void TestTree(string test, string nodes[], int nbrNodes, string output[])
{
	
//	BinaryTree* tree = new BinaryTree();
//	string testName = "";
//
//	cout << "************************************************************************" << endl;
//	cout << "TESTING " << test << endl;
//	cout << "************************************************************************" << endl;
//
//	// Test node insertion
//	for (int i = 0; i < nbrNodes; ++i)
//	{
//		//tree->Insert(nodes[i]);
//		testName = "Inserting " + nodes[i] + " NumberOfNodes = " + to_string(BinaryTreeNode::GetNbrNodes());
//		cout << left << setw(testNameSize) << testName << ((BinaryTreeNode::GetNbrNodes() == (i + 1)) ? "PASSED" : "FAILED") << endl;
//		cout << *tree << endl;
//	}
//
//	// Test search
//	for (int i = 0; i < nbrNodes; ++i)
//	{
//		testName = "Searching for " + nodes[i];
//		cout << left << setw(testNameSize) << testName << (tree->Search(nodes[i]) ? "PASSED" : "FAILED") << endl;
//	}
//	testName = "Searching for Z ";
//	cout << left << setw(testNameSize) << testName << (!tree->Search("Z") ? "PASSED" : "FAILED") << endl;
//
//	// Test Output
//	ostringstream stream;
//	stream << *tree;
//	string actualResult = stream.str();
//	string expectedResult = "PreOrderPrint:   " + output[0] + "\n"
//		+ "InOrderPrint:    " + output[1] + "\n"
//		+ "PostOrderPrint:  " + output[2] + "\n";
//
//	cout << "Actual Result: " << endl << actualResult << endl;
//	cout << "Expected Result: " << endl << expectedResult << endl;
//	cout << left << setw(testNameSize) << "Output of Tree (above) " << ((actualResult == expectedResult) ? "PASSED" : "FAILED") << endl;
//
//#if TEST_REMOVAL
//
//	// Test Removal
//	testName = "Removing Z ";
//	cout << left << setw(testNameSize) << testName << (!tree->Remove("Z") ? "PASSED" : "FAILED") << endl;
//	for (int i = 0; i < nbrNodes; ++i)
//	{
//		testName = "Removing " + nodes[i];
//		cout << left << setw(testNameSize) << testName << (tree->Remove(nodes[i]) ? "PASSED" : "FAILED") << endl;
//		testName = "Number of Nodes = " + to_string(BinaryTreeNode::GetNbrNodes());
//		cout << left << setw(testNameSize) << testName << ((BinaryTreeNode::GetNbrNodes() == (nbrNodes - i - 1)) ? "PASSED" : "FAILED") << endl;
//	}
//
//#endif // TEST_REMOVAL
//
//	delete tree;
//	cout << endl;
}

void RunTests()
{
	TestTree("smallRootOnlyTree", smallRootOnlyTree, 1, smallRootOnlyTreeOutput);
	TestTree("smallSimpleTree", smallSimpleTree, 3, smallSimpleTreeOutput);
	TestTree("smallFullTree", smallFullTree, 7, smallFullTreeOutput);

#if DO_NOT_TEST_AVL
	TestTree("rightLeftTree", rightLeftTree, 3, rightLeftTreeOutput);
	TestTree("leftRightTree", leftRightTree, 3, leftRightTreeOutput);
	TestTree("rightRightTree", rightRightTree, 3, rightRightTreeOutput);
	TestTree("leftLeftTree", leftLeftTree, 3, leftLeftTreeOutput);
	TestTree("largeTree", largeTree, 25, largeTreeOutput);
#else
	TestTree("rightLeftTree", rightLeftTree, 3, rightLeftTreeOutputAVL);
	TestTree("leftRightTree", leftRightTree, 3, leftRightTreeOutputAVL);
	TestTree("rightRightTree", rightRightTree, 3, rightRightTreeOutputAVL);
	TestTree("leftLeftTree", leftLeftTree, 3, leftLeftTreeOutputAVL);
	TestTree("largeTree", largeTree, 25, largeTreeOutputAVL);
#endif
}

int main()
{
	RunTests();

	// TODO: Put your menu structure here

	char c;
	cin.get(c);
	return 0;
}
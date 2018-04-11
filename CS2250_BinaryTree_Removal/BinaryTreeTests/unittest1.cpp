#include "stdafx.h"
#include "CppUnitTest.h"
#include "BinaryTree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#define DO_NOT_TEST_AVL 1

namespace BinaryTreeTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		string actual;
		string expected;

		////////////////////////////////////////////////////////////////////////////////////////////////////////
		// Empty and Deleted Tests
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(RemoveFromEmpty)
		{
			BinaryTree tree;
			Assert::AreEqual(false, tree.Remove("A"), L"tree.Remove from empty failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		TEST_METHOD(RemoveDeleted)
		{
			BinaryTree tree;
			tree.Insert("A");
			tree.Insert("B");
			tree.Insert("C");
			tree.Insert("D");
			tree.Insert("E");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
#if DO_NOT_TEST_AVL
					expected = "A B C D E ";
#else
					expected = "B A D C E ";
#endif
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C D E ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
#if DO_NOT_TEST_AVL
				expected = "E D C B A ";
#else
				expected = "A C E D B ";
#endif
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(5, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(false, tree.Remove("A"), L"tree.Remove already deleted failed", LINE_INFO());
			Assert::AreEqual(4, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(false, tree.Remove("B"), L"tree.Remove already deleted failed", LINE_INFO());
			Assert::AreEqual(3, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(false, tree.Remove("C"), L"tree.Remove already deleted failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("D"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(false, tree.Remove("D"), L"tree.Remove already deleted failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("E"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(false, tree.Remove("E"), L"tree.Remove already deleted failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////
		// Root Tests
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(RemoveRootNoChildren)
		{
			BinaryTree tree;
			tree.Insert("A");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "A ";
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
				expected = "A ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(1, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		TEST_METHOD(RemoveRootLeftChild)
		{
			BinaryTree tree;
			tree.Insert("B");
			tree.Insert("A");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "B A ";
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
				expected = "A B ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(2, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove root's left child failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		TEST_METHOD(RemoveRootRightChild)
		{
			BinaryTree tree;
			tree.Insert("A");
			tree.Insert("B");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "A B ";
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
				expected = "B A ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(2, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove root's right child failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////
		// Child Tests
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(RemoveLeftLeftChild)
		{
			BinaryTree tree;
			tree.Insert("C");
			tree.Insert("B");
			tree.Insert("A");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
#if DO_NOT_TEST_AVL
				expected = "C B A ";
#else
				expected = "B A C ";
#endif
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
#if DO_NOT_TEST_AVL
				expected = "A B C ";
#else
				expected = "A C B ";
#endif
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(3, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove left left child failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove left child failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		TEST_METHOD(RemoveLeftRightChild)
		{
			BinaryTree tree;
			tree.Insert("C");
			tree.Insert("A");
			tree.Insert("B");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
#if DO_NOT_TEST_AVL
				expected = "C A B ";
#else
				expected = "B A C ";
#endif
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
#if DO_NOT_TEST_AVL
				expected = "B A C ";
#else
				expected = "A C B ";
#endif
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(3, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove left right child failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove left child failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		TEST_METHOD(RemoveRightLeftChild)
		{
			BinaryTree tree;
			tree.Insert("A");
			tree.Insert("C");
			tree.Insert("B");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
#if DO_NOT_TEST_AVL
				expected = "A C B ";
#else
				expected = "B A C ";
#endif
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
#if DO_NOT_TEST_AVL
				expected = "B C A ";
#else
				expected = "A C B ";
#endif
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(3, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove right left child failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove left child failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		TEST_METHOD(RemoveRightRightChild)
		{
			BinaryTree tree;
			tree.Insert("A");
			tree.Insert("B");
			tree.Insert("C");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
#if DO_NOT_TEST_AVL
				expected = "A B C ";
#else
				expected = "B A C ";
#endif
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
#if DO_NOT_TEST_AVL
				expected = "C B A ";
#else
				expected = "A C B ";
#endif
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(3, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove right left child failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove left child failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////
		// Two Child Tests
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(RemoveRootWithTwoChildren)
		{
			BinaryTree tree;
			tree.Insert("B");
			tree.Insert("A");
			tree.Insert("C");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
#if DO_NOT_TEST_AVL
				expected = "B A C ";
#else
				expected = "B A C ";
#endif
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
#if DO_NOT_TEST_AVL
				expected = "A C B ";
#else
				expected = "A C B ";
#endif
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(3, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove root with 2 children failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		TEST_METHOD(RemoveLeftChildWithTwoChildren)
		{
			BinaryTree tree;
			tree.Insert("D");
			tree.Insert("B");
			tree.Insert("A");
			tree.Insert("C");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
#if DO_NOT_TEST_AVL
				expected = "D B A C ";
#else
				expected = "B A D C ";
#endif
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C D ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
#if DO_NOT_TEST_AVL
				expected = "A C B D ";
#else
				expected = "A C D B ";
#endif
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(4, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove left child with 2 children failed", LINE_INFO());
			Assert::AreEqual(3, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove left child failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove left child failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("D"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		TEST_METHOD(RemoveRightChildWithTwoChildren)
		{
			BinaryTree tree;
			tree.Insert("A");
			tree.Insert("C");
			tree.Insert("B");
			tree.Insert("D");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
#if DO_NOT_TEST_AVL
				expected = "A C B D ";
#else
				expected = "B A C D ";
#endif
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C D ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
#if DO_NOT_TEST_AVL
				expected = "B D C A ";
#else
				expected = "A D C B ";
#endif
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(4, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove right child with 2 children failed", LINE_INFO());
			Assert::AreEqual(3, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("D"), L"tree.Remove right child failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove right child failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////
		// Root Grand Child Tests
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(RemoveRootWithRightInnerGrandChild)
		{
			BinaryTree tree;
			tree.Insert("B");
			tree.Insert("A");
			tree.Insert("D");
			tree.Insert("C");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
#if DO_NOT_TEST_AVL
				expected = "B A D C ";
#else
				expected = "B A D C ";
#endif
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C D ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
#if DO_NOT_TEST_AVL
				expected = "A C D B ";
#else
				expected = "A C D B ";
#endif
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(4, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove root with right inner child failed", LINE_INFO());
			Assert::AreEqual(3, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove root with two children failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("D"), L"tree.Remove root with left child failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		TEST_METHOD(RemoveRootWithLeftInnerGrandChild)
		{
			BinaryTree tree;
			tree.Insert("C");
			tree.Insert("A");
			tree.Insert("D");
			tree.Insert("B");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
#if DO_NOT_TEST_AVL
				expected = "C A B D ";
#else
				expected = "C A B D ";
#endif
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C D ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
#if DO_NOT_TEST_AVL
				expected = "B A D C ";
#else
				expected = "B A D C ";
#endif
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(4, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove root with right inner child failed", LINE_INFO());
			Assert::AreEqual(3, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("D"), L"tree.Remove root with left inner child", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove root with right child failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		TEST_METHOD(RemoveRootWithRightOuterGrandChild)
		{
			BinaryTree tree;
			tree.Insert("B");
			tree.Insert("A");
			tree.Insert("C");
			tree.Insert("D");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
#if DO_NOT_TEST_AVL
				expected = "B A C D ";
#else
				expected = "B A C D ";
#endif
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C D ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
#if DO_NOT_TEST_AVL
				expected = "A D C B ";
#else
				expected = "A D C B ";
#endif
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(4, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove root with right outer child failed", LINE_INFO());
			Assert::AreEqual(3, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove root with two children", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("D"), L"tree.Remove root with left child failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		TEST_METHOD(RemoveRootWithLeftOuterGrandChild)
		{
			BinaryTree tree;
			tree.Insert("C");
			tree.Insert("B");
			tree.Insert("D");
			tree.Insert("A");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
#if DO_NOT_TEST_AVL
				expected = "C B A D ";
#else
				expected = "C B A D ";
#endif
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C D ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
#if DO_NOT_TEST_AVL
				expected = "A B D C ";
#else
				expected = "A B D C ";
#endif
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(4, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove root with left outer child failed", LINE_INFO());
			Assert::AreEqual(3, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("D"), L"tree.Remove root with left left child", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove root with left child failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////
		// Nonroot Grand Child Tests
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(RemoveLeftChildWithInnerChild)
		{
			BinaryTree tree;
			tree.Insert("E");
			tree.Insert("B");
			tree.Insert("A");
			tree.Insert("D");
			tree.Insert("C");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
#if DO_NOT_TEST_AVL
				expected = "E B A D C ";
#else
				expected = "B A D C E ";
#endif
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C D E ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
#if DO_NOT_TEST_AVL
				expected = "A C D B E ";
#else
				expected = "A C E D B ";
#endif
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(5, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove left child with inner child failed", LINE_INFO());
			Assert::AreEqual(4, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove left child with two children failed", LINE_INFO());
			Assert::AreEqual(3, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("D"), L"tree.Remove left child with left child failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove left child failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("E"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		TEST_METHOD(RemoveRightChildWithInnerChild)
		{
			BinaryTree tree;
			tree.Insert("A");
			tree.Insert("C");
			tree.Insert("B");
			tree.Insert("E");
			tree.Insert("D");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
#if DO_NOT_TEST_AVL
				expected = "A C B E D ";
#else
				expected = "B A D C E ";
#endif
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C D E ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
#if DO_NOT_TEST_AVL
				expected = "B D E C A ";
#else
				expected = "A C E D B ";
#endif
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(5, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove right child with inner child failed", LINE_INFO());
			Assert::AreEqual(4, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("D"), L"tree.Remove right child with two children failed", LINE_INFO());
			Assert::AreEqual(3, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("E"), L"tree.Remove right child with right child failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove right child failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		TEST_METHOD(RemoveLeftChildWithOuterChild)
		{
			BinaryTree tree;
			tree.Insert("E");
			tree.Insert("B");
			tree.Insert("A");
			tree.Insert("C");
			tree.Insert("D");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
#if DO_NOT_TEST_AVL
				expected = "E B A C D ";
#else
				expected = "B A D C E ";
#endif
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C D E ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
#if DO_NOT_TEST_AVL
				expected = "A D C B E ";
#else
				expected = "A C E D B ";
#endif
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(5, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove right child with outer child failed", LINE_INFO());
			Assert::AreEqual(4, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove right child with two children failed", LINE_INFO());
			Assert::AreEqual(3, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("D"), L"tree.Remove right child with left child failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove right child failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("E"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		TEST_METHOD(RemoveRightChildWithOuterChild)
		{
			BinaryTree tree;
			tree.Insert("A");
			tree.Insert("C");
			tree.Insert("B");
			tree.Insert("D");
			tree.Insert("E");
			Assert::AreEqual(5, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove right child with outer child failed", LINE_INFO());
			Assert::AreEqual(4, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("D"), L"tree.Remove right child with two children failed", LINE_INFO());
			Assert::AreEqual(3, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("E"), L"tree.Remove right child with left child failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove right child failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////
		// Root Great Grand Child Tests
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(RemoveRootWithRightLeftLeftChild)
		{
			BinaryTree tree;
			tree.Insert("B");
			tree.Insert("A");
			tree.Insert("E");
			tree.Insert("D");
			tree.Insert("C");
			Assert::AreEqual(5, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove root with right left left child failed", LINE_INFO());
			Assert::AreEqual(4, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove root with right left child failed", LINE_INFO());
			Assert::AreEqual(3, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("D"), L"tree.Remove root with right child failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("E"), L"tree.Remove root with left child failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		TEST_METHOD(RemoveRootWithRightLeftRightChild)
		{
			BinaryTree tree;
			tree.Insert("B");
			tree.Insert("A");
			tree.Insert("E");
			tree.Insert("C");
			tree.Insert("D");
			Assert::AreEqual(5, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove root with right left right child failed", LINE_INFO());
			Assert::AreEqual(4, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove root with right left child failed", LINE_INFO());
			Assert::AreEqual(3, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("D"), L"tree.Remove root with right child failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("E"), L"tree.Remove root with left child failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////
		// Nonroot Great Grand Child Tests
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(RemoveRootLeftWithRightLeftLeftChild)
		{
			BinaryTree tree;
			tree.Insert("F");
			tree.Insert("B");
			tree.Insert("A");
			tree.Insert("E");
			tree.Insert("D");
			tree.Insert("C");
			Assert::AreEqual(6, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove nonroot with right left left child failed", LINE_INFO());
			Assert::AreEqual(5, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove nonroot with right left child failed", LINE_INFO());
			Assert::AreEqual(4, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("D"), L"tree.Remove nonroot with two children failed", LINE_INFO());
			Assert::AreEqual(3, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("E"), L"tree.Remove nonroot with left child failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove root's left child failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("F"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		TEST_METHOD(RemoveRootRightWithRightLeftLeftChild)
		{
			BinaryTree tree;
			tree.Insert("A");
			tree.Insert("C");
			tree.Insert("B");
			tree.Insert("F");
			tree.Insert("E");
			tree.Insert("D");
			Assert::AreEqual(6, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove nonroot with right left left child failed", LINE_INFO());
			Assert::AreEqual(5, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("D"), L"tree.Remove nonroot with right left child failed", LINE_INFO());
			Assert::AreEqual(4, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("E"), L"tree.Remove nonroot with two children failed", LINE_INFO());
			Assert::AreEqual(3, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("F"), L"tree.Remove nonroot with left child failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove root's left child failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		TEST_METHOD(RemoveRootLeftWithRightLeftRightChild)
		{
			BinaryTree tree;
			tree.Insert("F");
			tree.Insert("B");
			tree.Insert("A");
			tree.Insert("E");
			tree.Insert("C");
			tree.Insert("D");
			Assert::AreEqual(6, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove nonroot with right left right child failed", LINE_INFO());
			Assert::AreEqual(5, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove nonroot with right left child failed", LINE_INFO());
			Assert::AreEqual(4, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("D"), L"tree.Remove nonroot with two children failed", LINE_INFO());
			Assert::AreEqual(3, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("E"), L"tree.Remove nonroot with left child failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove root's left child failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("F"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		TEST_METHOD(RemoveRootRightWithRightLeftRightChild)
		{
			BinaryTree tree;
			tree.Insert("A");
			tree.Insert("C");
			tree.Insert("B");
			tree.Insert("F");
			tree.Insert("D");
			tree.Insert("E");
			Assert::AreEqual(6, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove nonroot with right left right child failed", LINE_INFO());
			Assert::AreEqual(5, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("D"), L"tree.Remove nonroot with right left child failed", LINE_INFO());
			Assert::AreEqual(4, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("E"), L"tree.Remove nonroot with two children failed", LINE_INFO());
			Assert::AreEqual(3, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("F"), L"tree.Remove nonroot with left child failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove root's left child failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////
		// Remove Min Chain
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(RemoveRootMinChain)
		{
			BinaryTree tree;
			tree.Insert("A");
			tree.Insert("H");
			tree.Insert("G");
			tree.Insert("F");
			tree.Insert("E");
			tree.Insert("D");
			tree.Insert("C");
			tree.Insert("B");
			Assert::AreEqual(8, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove root with min chain", LINE_INFO());
			Assert::AreEqual(7, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove root with min chain failed", LINE_INFO());
			Assert::AreEqual(6, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove root with min chain failed", LINE_INFO());
			Assert::AreEqual(5, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("D"), L"tree.Remove root with min chain failed", LINE_INFO());
			Assert::AreEqual(4, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("E"), L"tree.Remove root with min chain failed", LINE_INFO());
			Assert::AreEqual(3, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("F"), L"tree.Remove root with min chain failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("G"), L"tree.Remove root with min chain failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("H"), L"tree.Remove root failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////////
		// Remove Big Tree
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(RemoveBigTree)
		{
			BinaryTree tree;
			tree.Insert("N");
			tree.Insert("Z");
			tree.Insert("O");
			tree.Insert("A");
			tree.Insert("X");
			tree.Insert("B");
			tree.Insert("V");
			tree.Insert("Y");
			tree.Insert("E");
			tree.Insert("H");
			tree.Insert("W");
			tree.Insert("K");
			tree.Insert("R");
			tree.Insert("I");
			tree.Insert("Q");
			tree.Insert("C");
			tree.Insert("U");
			tree.Insert("J");
			tree.Insert("P");
			tree.Insert("S");
			tree.Insert("D");
			tree.Insert("T");
			tree.Insert("M");
			tree.Insert("F");
			tree.Insert("G");
			tree.Insert("L");
			Assert::AreEqual(26, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(25, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(24, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(23, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("D"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(22, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("E"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(21, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("F"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(20, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("G"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(19, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("H"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(18, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("I"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(17, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("J"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(16, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("K"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(15, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("L"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(14, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("M"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(13, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("N"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(12, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("O"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(11, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("P"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(10, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("Q"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(9, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("R"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(8, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("S"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(7, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("T"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(6, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("U"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(5, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("V"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(4, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("W"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(3, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("X"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("Y"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("Z"), L"tree.Remove Big Tree", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode::GetNbrNodes(), L"GetNbrNodes after Remove failed", LINE_INFO());
		}


		////////////////////////////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////////////////////////////////

#if DO_NOT_TEST_AVL
		// No additional testing for unbalanced BinaryTree
#else
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		// AVL Testing Root Rebalancing
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(AVL_RootLeftLeft)
		{
			BinaryTree tree;
			tree.Insert("C");
			tree.Insert("B");
			tree.Insert("A");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "B A C ";
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
				expected = "A C B ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(3, BinaryTreeNode::GetNbrNodes(), L"AVL_RootLeftLeft Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"AVL_RootLeftLeft Remove failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode::GetNbrNodes(), L"AVL_RootLeftLeft Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"AVL_RootLeftLeft Remove failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode::GetNbrNodes(), L"AVL_RootLeftLeft Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"AVL_RootLeftLeft Remove failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode::GetNbrNodes(), L"AVL_RootLeftLeft Remove failed", LINE_INFO());
			
		}
		TEST_METHOD(AVL_RootRightRight)
		{
			BinaryTree tree;
			tree.Insert("A");
			tree.Insert("B");
			tree.Insert("C");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "B A C ";
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
				expected = "A C B ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(3, BinaryTreeNode::GetNbrNodes(), L"AVL_RootRightRight Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"AVL_RootRightRight Remove failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode::GetNbrNodes(), L"AVL_RootRightRight Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"AVL_RootRightRight Remove failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode::GetNbrNodes(), L"AVL_RootRightRight Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"AVL_RootRightRight Remove failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode::GetNbrNodes(), L"AVL_RootRightRight Remove failed", LINE_INFO());
		}

		TEST_METHOD(AVL_RootRightLeft)
		{
			BinaryTree tree;
			tree.Insert("A");
			tree.Insert("C");
			tree.Insert("B");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "B A C ";
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
				expected = "A C B ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(3, BinaryTreeNode::GetNbrNodes(), L"AVL_RootRightLeft Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"AVL_RootRightLeft Remove failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode::GetNbrNodes(), L"AVL_RootRightLeft Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"AVL_RootRightLeft Remove failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode::GetNbrNodes(), L"AVL_RootRightLeft Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"AVL_RootRightLeft Remove failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode::GetNbrNodes(), L"AVL_RootRightLeft Remove failed", LINE_INFO());
		}

		TEST_METHOD(AVL_RootLeftRight)
		{
			BinaryTree tree;
			tree.Insert("C");
			tree.Insert("A");
			tree.Insert("B");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "B A C ";
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
				expected = "A C B ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(3, BinaryTreeNode::GetNbrNodes(), L"AVL_RootLeftRight Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"AVL_RootLeftRight Remove failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode::GetNbrNodes(), L"AVL_RootLeftRight Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"AVL_RootLeftRight Remove failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode::GetNbrNodes(), L"AVL_RootLeftRight Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"AVL_RootLeftRight Remove failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode::GetNbrNodes(), L"AVL_RootLeftRight Remove failed", LINE_INFO());
		}
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		// AVL Testing Non-Root Rebalancing
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(AVL_NonrootRightRight)
		{
			BinaryTree tree;
			tree.Insert("B");
			tree.Insert("C");
			tree.Insert("A");
			tree.Insert("D");
			tree.Insert("E");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "B A D C E ";
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C D E ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
				expected = "A C E D B ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(5, BinaryTreeNode::GetNbrNodes(), L"AVL_NonrootRightRight Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"AVL_NonrootRightRight Remove failed", LINE_INFO());
			Assert::AreEqual(4, BinaryTreeNode::GetNbrNodes(), L"AVL_NonrootRightRight Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"AVL_NonrootRightRight Remove failed", LINE_INFO());
			Assert::AreEqual(3, BinaryTreeNode::GetNbrNodes(), L"AVL_NonrootRightRight Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"AVL_NonrootRightRight Remove failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode::GetNbrNodes(), L"AVL_NonrootRightRight Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("D"), L"AVL_NonrootRightRight Remove failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode::GetNbrNodes(), L"AVL_NonrootRightRight Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("E"), L"AVL_NonrootRightRight Remove failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode::GetNbrNodes(), L"AVL_NonrootRightRight Remove failed", LINE_INFO());
		}
		TEST_METHOD(AVL_NonrootLeftLeft)
		{
			BinaryTree tree;
			tree.Insert("D");
			tree.Insert("C");
			tree.Insert("E");
			tree.Insert("B");
			tree.Insert("A");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "D B A C E ";
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C D E ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
				expected = "A C B E D ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(5, BinaryTreeNode::GetNbrNodes(), L"AVL_NonrootLeftLeft Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"AVL_NonrootLeftLeft Remove failed", LINE_INFO());
			Assert::AreEqual(4, BinaryTreeNode::GetNbrNodes(), L"AVL_NonrootLeftLeft Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"AVL_NonrootLeftLeft Remove failed", LINE_INFO());
			Assert::AreEqual(3, BinaryTreeNode::GetNbrNodes(), L"AVL_NonrootLeftLeft Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"AVL_NonrootLeftLeft Remove failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode::GetNbrNodes(), L"AVL_NonrootLeftLeft Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("D"), L"AVL_NonrootLeftLeft Remove failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode::GetNbrNodes(), L"AVL_NonrootLeftLeft Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("E"), L"AVL_NonrootLeftLeft Remove failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode::GetNbrNodes(), L"AVL_NonrootLeftLeft Remove failed", LINE_INFO());
		}

		TEST_METHOD(AVL_NonrootRightleft)
		{
			BinaryTree tree;
			tree.Insert("D");
			tree.Insert("C");
			tree.Insert("E");
			tree.Insert("A");
			tree.Insert("B");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "D B A C E ";
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C D E ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
				expected = "A C B E D ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(5, BinaryTreeNode::GetNbrNodes(), L"AVL_NonrootRightleft Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"AVL_NonrootRightleft Remove failed", LINE_INFO());
			Assert::AreEqual(4, BinaryTreeNode::GetNbrNodes(), L"AVL_NonrootRightleft Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"AVL_NonrootRightleft Remove failed", LINE_INFO());
			Assert::AreEqual(3, BinaryTreeNode::GetNbrNodes(), L"AVL_NonrootRightleft Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"AVL_NonrootRightleft Remove failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode::GetNbrNodes(), L"AVL_NonrootRightleft Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("D"), L"AVL_NonrootRightleft Remove failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode::GetNbrNodes(), L"AVL_NonrootRightleft Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("E"), L"AVL_NonrootRightleft Remove failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode::GetNbrNodes(), L"AVL_NonrootRightleft Remove failed", LINE_INFO());
		}
		TEST_METHOD(AVL_NonrootLeftRight)
		{
			BinaryTree tree;
			tree.Insert("B");
			tree.Insert("C");
			tree.Insert("A");
			tree.Insert("E");
			tree.Insert("D");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "B A D C E ";
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C D E ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
				expected = "A C E D B ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(5, BinaryTreeNode::GetNbrNodes(), L"AVL_NonrootLeftRight Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"AVL_NonrootLeftRight Remove failed", LINE_INFO());
			Assert::AreEqual(4, BinaryTreeNode::GetNbrNodes(), L"AVL_NonrootLeftRight Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"AVL_NonrootLeftRight Remove failed", LINE_INFO());
			Assert::AreEqual(3, BinaryTreeNode::GetNbrNodes(), L"AVL_NonrootLeftRight Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"AVL_NonrootLeftRight Remove failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode::GetNbrNodes(), L"AVL_NonrootLeftRight Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("D"), L"AVL_NonrootLeftRight Remove failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode::GetNbrNodes(), L"AVL_NonrootLeftRight Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("E"), L"AVL_NonrootLeftRight Remove failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode::GetNbrNodes(), L"AVL_NonrootLeftRight Remove failed", LINE_INFO());
		}
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		// AVL Testing Root Rebalancing from Descendent
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(AVL_RootRightRightDescendent)
		{
			BinaryTree tree;
			tree.Insert("B");
			tree.Insert("A");
			tree.Insert("D");
			tree.Insert("C");
			tree.Insert("E");
			tree.Insert("F");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "D B A C E F ";
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C D E F ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
				expected = "A C B F E D ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(6, BinaryTreeNode::GetNbrNodes(), L"AVL_RootRightRightDescendent Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"AVL_RootRightRightDescendent Remove failed", LINE_INFO());
			Assert::AreEqual(5, BinaryTreeNode::GetNbrNodes(), L"AVL_RootRightRightDescendent Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"AVL_RootRightRightDescendent Remove failed", LINE_INFO());
			Assert::AreEqual(4, BinaryTreeNode::GetNbrNodes(), L"AVL_RootRightRightDescendent Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"AVL_RootRightRightDescendent Remove failed", LINE_INFO());
			Assert::AreEqual(3, BinaryTreeNode::GetNbrNodes(), L"AVL_RootRightRightDescendent Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("D"), L"AVL_RootRightRightDescendent Remove failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode::GetNbrNodes(), L"AVL_RootRightRightDescendent Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("E"), L"AVL_RootRightRightDescendent Remove failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode::GetNbrNodes(), L"AVL_RootRightRightDescendent Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("F"), L"AVL_RootRightRightDescendent Remove failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode::GetNbrNodes(), L"AVL_RootRightRightDescendent Remove failed", LINE_INFO());
		}
		TEST_METHOD(AVL_RootLeftLeftDescendent)
		{
			BinaryTree tree;
			tree.Insert("E");
			tree.Insert("C");
			tree.Insert("F");
			tree.Insert("B");
			tree.Insert("D");
			tree.Insert("A");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "C B A E D F ";
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C D E F ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
				expected = "A B D F E C ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(6, BinaryTreeNode::GetNbrNodes(), L"AVL_RootLeftLeftDescendent Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"AVL_RootLeftLeftDescendent Remove failed", LINE_INFO());
			Assert::AreEqual(5, BinaryTreeNode::GetNbrNodes(), L"AVL_RootLeftLeftDescendent Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"AVL_RootLeftLeftDescendent Remove failed", LINE_INFO());
			Assert::AreEqual(4, BinaryTreeNode::GetNbrNodes(), L"AVL_RootLeftLeftDescendent Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"AVL_RootLeftLeftDescendent Remove failed", LINE_INFO());
			Assert::AreEqual(3, BinaryTreeNode::GetNbrNodes(), L"AVL_RootLeftLeftDescendent Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("D"), L"AVL_RootLeftLeftDescendent Remove failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode::GetNbrNodes(), L"AVL_RootLeftLeftDescendent Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("E"), L"AVL_RootLeftLeftDescendent Remove failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode::GetNbrNodes(), L"AVL_RootLeftLeftDescendent Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("F"), L"AVL_RootLeftLeftDescendent Remove failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode::GetNbrNodes(), L"AVL_RootLeftLeftDescendent Remove failed", LINE_INFO());
		}
		TEST_METHOD(AVL_RootLeftRightDescendent)
		{
			BinaryTree tree;
			tree.Insert("E");
			tree.Insert("B");
			tree.Insert("F");
			tree.Insert("A");
			tree.Insert("D");
			tree.Insert("C");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "D B A C E F ";
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C D E F ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
				expected = "A C B F E D ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(6, BinaryTreeNode::GetNbrNodes(), L"AVL_RootLeftLeftDescendent Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"AVL_RootLeftLeftDescendent Remove failed", LINE_INFO());
			Assert::AreEqual(5, BinaryTreeNode::GetNbrNodes(), L"AVL_RootLeftLeftDescendent Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"AVL_RootLeftLeftDescendent Remove failed", LINE_INFO());
			Assert::AreEqual(4, BinaryTreeNode::GetNbrNodes(), L"AVL_RootLeftLeftDescendent Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"AVL_RootLeftLeftDescendent Remove failed", LINE_INFO());
			Assert::AreEqual(3, BinaryTreeNode::GetNbrNodes(), L"AVL_RootLeftLeftDescendent Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("D"), L"AVL_RootLeftLeftDescendent Remove failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode::GetNbrNodes(), L"AVL_RootLeftLeftDescendent Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("E"), L"AVL_RootLeftLeftDescendent Remove failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode::GetNbrNodes(), L"AVL_RootLeftLeftDescendent Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("F"), L"AVL_RootLeftLeftDescendent Remove failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode::GetNbrNodes(), L"AVL_RootLeftLeftDescendent Remove failed", LINE_INFO());
		}

		TEST_METHOD(AVL_RootRightLeftDescendent)
		{
			BinaryTree tree;
			tree.Insert("B");
			tree.Insert("A");
			tree.Insert("E");
			tree.Insert("C");
			tree.Insert("F");
			tree.Insert("D");

			{
				ostringstream stream;
				tree.PreOrderPrint(stream);
				actual = stream.str();
				expected = "C B A E D F ";
				Assert::AreEqual(expected, actual, L"Preorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.InOrderPrint(stream);
				actual = stream.str();
				expected = "A B C D E F ";
				Assert::AreEqual(expected, actual, L"Inorder failed", LINE_INFO());
			}
			{
				ostringstream stream;
				tree.PostOrderPrint(stream);
				actual = stream.str();
				expected = "A B D F E C ";
				Assert::AreEqual(expected, actual, L"Postorder failed", LINE_INFO());
			}

			Assert::AreEqual(6, BinaryTreeNode::GetNbrNodes(), L"AVL_RootLeftLeftDescendent Insert failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("A"), L"AVL_RootLeftLeftDescendent Remove failed", LINE_INFO());
			Assert::AreEqual(5, BinaryTreeNode::GetNbrNodes(), L"AVL_RootLeftLeftDescendent Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("B"), L"AVL_RootLeftLeftDescendent Remove failed", LINE_INFO());
			Assert::AreEqual(4, BinaryTreeNode::GetNbrNodes(), L"AVL_RootLeftLeftDescendent Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("C"), L"AVL_RootLeftLeftDescendent Remove failed", LINE_INFO());
			Assert::AreEqual(3, BinaryTreeNode::GetNbrNodes(), L"AVL_RootLeftLeftDescendent Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("D"), L"AVL_RootLeftLeftDescendent Remove failed", LINE_INFO());
			Assert::AreEqual(2, BinaryTreeNode::GetNbrNodes(), L"AVL_RootLeftLeftDescendent Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("E"), L"AVL_RootLeftLeftDescendent Remove failed", LINE_INFO());
			Assert::AreEqual(1, BinaryTreeNode::GetNbrNodes(), L"AVL_RootLeftLeftDescendent Remove failed", LINE_INFO());
			Assert::AreEqual(true, tree.Remove("F"), L"AVL_RootLeftLeftDescendent Remove failed", LINE_INFO());
			Assert::AreEqual(0, BinaryTreeNode::GetNbrNodes(), L"AVL_RootLeftLeftDescendent Remove failed", LINE_INFO());
		}
#endif
	};
}
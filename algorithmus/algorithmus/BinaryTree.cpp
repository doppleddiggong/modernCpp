#include "pch.h"
#include "header.h"
#include "TreeNode.h"
#include "BinaryTree.h"

BinaryTree::BinaryTree() { }
BinaryTree::~BinaryTree() {}

void BinaryTree::init(char ch)
{
	Tree<char> tree = Tree<char>(ch);
	tree.buildTree();

	printf("Preorder >> ");
	tree.preorder(tree.getRoot());
	cout << endl;

	printf("Inorder >> ");
	tree.inorder(tree.getRoot());
	cout << endl;

	printf("Postorder >> ");
	tree.postorder(tree.getRoot());
	cout << endl;
}

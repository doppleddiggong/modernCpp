#pragma once

#include <vector>
using namespace std;

typedef struct NodeStruct
{
	int value;
	struct NodeStruct* leftChild;
	struct NodeStruct* rightChild;
}Node;

class BinaryTree
{
private:
	Node* root = NULL;
public:
	BinaryTree();
	~BinaryTree();

	void init();

	Node* BST_insert(Node* root, int value);
	Node* findMinNode(Node* root);
	Node* findMaxNode(Node* root);
	Node* BST_delete(Node* root, int value);
	Node* BST_search(Node* root, int value);
	void BST_print(Node* root);
};

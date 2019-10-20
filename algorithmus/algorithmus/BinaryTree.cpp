#include "pch.h"
#include "header.h"
#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
	Node* root = NULL;
}

BinaryTree::~BinaryTree() {}

void BinaryTree::init()
{
	srand((unsigned int)time(0));

	vector<int> vectorData;
	vectorData.clear();
	// 리스트 데이터를 임의로 생성한다
	for (int i = 0; i < 10; i++)
	{
		vectorData.push_back( rand() % 100 );
	}

	// 이진 트리에 생성된 데이터를 넣는다
	for (auto iter = vectorData.begin(); iter != vectorData.end(); ++iter)
	{
		root = BST_insert(root, *iter);
	}

	// 데이터를 출력한다
	BST_print(root);
}


Node* BinaryTree::BST_insert(Node* root, int value)
{
	if (root == NULL)
	{
		// Node 자체가 struct 
		root = new Node();
		root->leftChild = root->rightChild = NULL;
		root->value = value;
		return root;
	}
	else
	{
		if (value < root->value )
			root->leftChild = BST_insert(root->leftChild, value);
		else
			root->rightChild = BST_insert(root->rightChild, value);
	}
	return root;
}

Node* BinaryTree::findMinNode(Node* root)
{
	Node* tmp = root;
	while (tmp->leftChild != NULL)
		tmp = tmp->leftChild;
	return tmp;
}

Node* BinaryTree::findMaxNode(Node* root)
{
	Node* tmp = root;
	while (tmp->rightChild != NULL)
		tmp = tmp->rightChild;
	return tmp;
}

Node* BinaryTree::BST_delete(Node* root, int value)
{
	Node* node = NULL;
	if (root == NULL)
		return NULL;

	if (root->value > value)
		root->leftChild = BST_delete(root->leftChild, value);
	else if (root->value < value)
		root->rightChild = BST_delete(root->rightChild, value);
	else
	{
		// 자식 노드가 둘 다 있을 경우
		if (root->rightChild != NULL && root->leftChild != NULL)
		{
			node = findMinNode(root->rightChild);
			root->value = node->value;
			root->rightChild = BST_delete(root->rightChild, node->value);
		}
		else
		{
			node = (root->leftChild == NULL) ? root->rightChild : root->leftChild;
			free(root);
			return node;
		}
	}

	return root;
}

Node* BinaryTree::BST_search(Node* root, int value)
{
	if (root == NULL)
		return NULL;

	if (root->value == value)
		return root;
	else if (root->value > value)
		return BST_search(root->leftChild, value);
	else
		return BST_search(root->rightChild, value);
}

// center, left, right
void BinaryTree::BST_print(Node* root)
{
	if (root == NULL)
		return;

	printf("%d  ", root->value);
	BST_print(root->leftChild);
	BST_print(root->rightChild);
}

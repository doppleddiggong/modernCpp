#include <stdio.h>
#include <stdlib.h>


	


	//template <typename T>
	//class Tree;

	//template <typename T>
	//class TreeNode 
	//{
	//	friend class Tree<T>;

	//private:
	//	T data;
	//	TreeNode* left;
	//	TreeNode* right;

	//public:
	//	TreeNode(T data = 0, TreeNode* left = null, TreeNode* right = null)
	//	{
	//		this->data = data;
	//		this->left = left;
	//		this->right = right;
	//	}
	//};

	//template <typename T>
	//class Tree {
	//private:
	//	TreeNode<T>* root = null;
	//public:
	//	Tree(T data = 0)
	//	{
	//		root = new TreeNode<T>(data);
	//	}
	//	// Tree 만들기
	//	/*
	//				    A
	//			   B        C
	//		    D    E    F    G
	//		 H     I   J         K
	//	*/
	//	void buildTree()
	//	{
	//		root->left = new TreeNode<T>('B', new TreeNode<T>('D', new TreeNode<T>('H')), new TreeNode<T>('E', new TreeNode<T>('I'), new TreeNode<T>('J')));
	//		root->right = new TreeNode<T>('C', new TreeNode<T>('F'), new TreeNode<T>('G', null, new TreeNode<T>('K')));
	//	}

	//	int findCenterValue(list<T> lt)
	//	{
	//		int min = min(lt, less<int>());
	//		int max = max(lt, less<int>());

	//		int sum_of_elems = std::accumulate(lt.begin(), lt.end(), 0);

	//		//int centerValue = min + max / lt.size;


	//		//for (list<int>::iterator iter = lt.begin(); iter != lt.end(); ++iter)
	//		//{

	//		//}
	//	}

	//	void buildTree2( list<T> _list )
	//	{
	//		auto it = _list.begin();
	//		std::advance(it, _list.size() / 2);
	//		printf("center is : %d\n", *it);
	//		root = new TreeNode<T>(*it);


	//		root = insert(root, 7);
	//		root = insert(root, 4);
	//		root = insert(root, 3);
	//		root = insert(root, 7);


	///*		for (auto iter = _list.begin(); iter != _list.end(); ++iter)
	//		{
	//			root = insert(root, *iter);
	//		}*/
	//	}

	//	TreeNode<T>* insert(TreeNode<T> *pNode, int value)
	//	{
	//		if (pNode == NULL)
	//		{
	//			TreeNode<T>* p_new_tree = new TreeNode<T>(value);
	//			p_new_tree->left = NULL;
	//			p_new_tree->right = NULL;
	//			p_new_tree->data = value;
	//			return p_new_tree;
	//		}
	//		if (value < pNode->data)
	//		{
	//			pNode->left = insert(pNode->left, value);
	//		}
	//		else
	//		{
	//			pNode->right = insert(pNode->right, value);
	//		}

	//		return pNode;
	//	}


	//	TreeNode<T>* getRoot() 
	//	{
	//		return root;
	//	}

	//	void visit(TreeNode<T>* current)
	//	{
	//		std::cout << current->data << " ";
	//	}

	//	// 전위 순회 Current - Left - Right
	//	void preorder(TreeNode<T>* current)
	//	{
	//		if (current != null)
	//		{
	//			visit(current);
	//			preorder(current->left);
	//			preorder(current->right);
	//		}
	//	}

	//	// 중위 순회 Left - Current - Right
	//	void inorder(TreeNode<T>* current)
	//	{
	//		if (current != null)
	//		{
	//			inorder(current->left);
	//			visit(current);
	//			inorder(current->right);
	//		}
	//	}

	//	// 후위 순회 Left - Right - Current
	//	void postorder(TreeNode<T>* current)
	//	{
	//		if (current != null)
	//		{
	//			postorder(current->left);
	//			postorder(current->right);
	//			visit(current);
	//		}
	//	}
	//};



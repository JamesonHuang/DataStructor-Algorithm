// Written by Zack Rosales
// Advanced C++ Programming ITSE 2431 1001
// Program from page 1164, #1
// Class template definition file for BinaryTree

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream> // for cout and cin
using namespace std;

template <class T>
class BinaryTree
{
private:
	// TreeNode struct definition
	struct TreeNode
	{
		T value; // value stored in node
		TreeNode *left, // pointer to left child node
				 *right; // pointer to right child node
	}; // TreeNode struct end

	TreeNode *root; // pointer to root node

	// recursive insert method traverses tree to find correct location to add new node
	void insert(TreeNode *&nodePtr, TreeNode *&newNode) // insert method start
	{
		if (nodePtr == NULL)
		{
			nodePtr = newNode; // insert new node
		} // end if
		else if (newNode->value < nodePtr->value)
		{
			insert(nodePtr->left, newNode);
		} // end else if
		else
		{
			insert(nodePtr->right, newNode);
		} // end else
	} // insert method end

	// recursive destroySubTree is called by destructor to destroy tree
	void destroySubTree(TreeNode *nodePtr) // destroySubTree method start
	{
		if (nodePtr)
		{
			if (nodePtr->left)
			{
				destroySubTree(nodePtr->left);
			} // end if
			if (nodePtr->right)
			{
				destroySubTree(nodePtr->right);
			} // end if
			delete nodePtr;
		} // end if
	} // destroySubTree method end

	// recursive deleteNode method traverses tree to locate node to remove from tree
	void deleteNode(T val, TreeNode *&nodePtr) // deleteNode method start
	{
		if (val < nodePtr->value)
		{
			deleteNode(val, nodePtr->left);
		} // end if
		else if (val > nodePtr->value)
		{
			deleteNode(val, nodePtr->right);
		} // end else if
		else
		{
			makeDeletion(nodePtr);
		} // end else
	} // deleteNode method end

	// makeDeletion method removes the selected node and re-attaches any children to the tree
	void makeDeletion(TreeNode *&nodePtr) // makeDeletion method start
	{
		TreeNode *tempNodePtr;

		if (nodePtr == NULL)
		{
			throw EmptyNode();
		} // end if
		else if (nodePtr->right == NULL)
		{
			tempNodePtr = nodePtr;
			nodePtr = nodePtr->left;
			delete tempNodePtr;
		} // end else if
		else if (nodePtr->left == NULL)
		{
			tempNodePtr = nodePtr;
			nodePtr = nodePtr->right;
			delete tempNodePtr;
		} // end else if
		else
		{
			tempNodePtr = nodePtr->right;
			while (tempNodePtr->left)
			{
				tempNodePtr = tempNodePtr->left;
			} // end while
			tempNodePtr->left = nodePtr->left;
			tempNodePtr = nodePtr;
			nodePtr = nodePtr->right;
			delete tempNodePtr;
		} // end else
	} // makeDeletion method end

	// recursive displayInOrder method displays the values of the tree in ascending order
	void displayInOrder(TreeNode *nodePtr) const // displayInOrder method start
	{
		if (nodePtr)
		{
			displayInOrder(nodePtr->left);
			cout << nodePtr->value << endl;
			displayInOrder(nodePtr->right);
		} // end if
	} //displayInOrder method end

	// recursive displayPreOrder method displays the values of the tree starting at the root and working down the branches
	void displayPreOrder(TreeNode *nodePtr) const // displayPreOrder method start
	{
		if (nodePtr)
		{
			cout << nodePtr->value << endl;
			displayPreOrder(nodePtr->right);
			displayPreOrder(nodePtr->left);
		} // end if
	} // displayPreOrder method end

	// recursive displayPostOrder method displays the values of the tree in postorder traversal
	void displayPostOrder(TreeNode *nodePtr) const // displayPostOrder method start
	{
		if (nodePtr)
		{
			displayPostOrder(nodePtr->left);
			displayPostOrder(nodePtr->right);
			cout << nodePtr->value << endl;
		} // end if
	} // displayPostOrder method end

	// recursive countNodes method counts the number of nodes in the tree
	int countNodes(TreeNode *nodePtr, int count) // countNodes method start
	{
		if (nodePtr)
		{
			count++;
			countNodes(nodePtr->left, count);
			countNodes(nodePtr->right, count);
		} // end if

		return count;
	} // countNodes method end

	// recursive countLeaves method counts the number of leaves in the tree
	int countLeaves(TreeNode *nodePtr, int count) // countLeaves method start
	{
		if (nodePtr->right == NULL && nodePtr->left == NULL)
		{
			count++;
		} // end if
		if (nodePtr->left != NULL)
		{
			countLeaves(nodePtr->left, count);
		} // end if
		if (nodePtr->right != NULL)
		{
			countLeaves(nodePtr->right, count);
		} // end if

		return count;
	} // countLeaves method end

	// recursive copy method works with the copy constructor to copy a tree
	void copy(TreeNode *thisNode, TreeNode *sourceNode) // copy method start
	{
		if (sourceNode == NULL)
		{
			thisNode = NULL;
		} // end if
		else
		{
			thisNode = new TreeNode;
			thisNode->value = sourceNode->value;
			copy(thisNode->left, sourceNode->left);
			copy(thisNode->right, sourceNode->right);
		} // end else
	} // copy method end

	public:
		// exception class
		class EmptyNode
		{};

		// constructor
		BinaryTree()
		{
			root = NULL;
		} // constructor end

		// copy constructor
		BinaryTree(BinaryTree<T> &tree)
		{
			if (tree.root == NULL)
			{
				root = NULL;
			} // end if
			else
			{
				copy(this->root, tree.root);
			} // end else
		} // copy constructor end

		// desctructor
		~BinaryTree()
		{
			destroySubTree(root);
		} // destructor end

		// insertNode method creates a new node and passes it to insert method
		void insertNode(T val) // insertNode method start
		{
			TreeNode *newNode;

			newNode = new TreeNode;
			newNode->value = val;
			newNode->left = newNode->right = NULL;

			insert(root, newNode);
		} // insertNode method end

		// searchNode method searches tree for a value and returns true if found, false if not in tree
		bool searchNode(T val) // searchNode method start
		{
			TreeNode *nodePtr = root;

			while (nodePtr)
			{
				if (nodePtr->value = val)
				{
					return true;
				} // end if
				else if (val < nodePtr->value)
				{
					nodePtr = nodePtr->left;
				} // end else if
				else
				{
					nodePtr = nodePtr->right;
				} // end else
			} // end while

			return false;
		} // searchNode method end

		// remove method calls private deleteNode method to remove the node containing the passed value
		void remove(T val) // remove method start
		{
			deleteNode(val, root);
		} // remove method end

		// public displayInOrder calls private displayInOrder with root as argument
		void displayInOrder() // displayInOrder method start
		{
			displayInOrder(root);
		} // displayInOrder method end

		// public displayPreOrder calls private displayPreOrder with root as argument
		void displayPreOrder() // displayPreOrder method start
		{
			displayPreOrder(root);
		} // displayPreOrder method end

		// public displayPostOrder calls private displayPostOrder with root as argument
		void displayPostOrder() // displayPostOrder method start
		{
			displayPostOrder(root);
		} // displayPostOrder method end

		// isEmpty returns true if tree is empty, false otherwise
		bool isEmpty() // isEmpty methos start
		{
			if (root == NULL)
			{
				return true;
			} // end if
			else
			{
				return false;
			} // end else
		} // isEmpty method end

		// public countNodes method calls private countNodes method with root as argument
		int countNodes() // countNodes method start
		{
			// local variable
			int count = 0;

			count = countNodes(root, count);

			return count;
		} // countNodes method end

		// public countLeaves method calls private countLeaves method with root as argument
		int countLeaves() // countLeaves method start
		{
			int count = 0;

			count = countLeaves(root, count);

			return count;
		} // countLeaves method end
};

#endif // !BINARYTREE_H
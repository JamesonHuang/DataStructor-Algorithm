#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream> // for cout and cin
#include <string>
using namespace std;

template <class T>
class BinaryTree{
public:
		// 二叉树结点的结构体
		struct TreeNode
		{
			T data; 
			TreeNode *l_child,
					 *r_child;
		};
		// 构造函数
		BinaryTree(const string &s);				
		//拷贝构造函数
		BinaryTree(BinaryTree<T> &tree);
		//析构函数
		~BinaryTree();
		//外部删除二叉树函数
		bool pubForDelBTree();		
		//外部访问先序遍历
		void pubForPreOrder();
		//外部访问中序遍历
		void pubForInOrder();	
private:

		//构建二叉树
		TreeNode* createBTree(const string &s, int &i);
		//销毁二叉树
		void delBTree(TreeNode* &p);
		//内部先序遍历
		void PreOrder(TreeNode* p);
		//内部中序遍历
		void InOrder(TreeNode* p);
		TreeNode* root; 



};

// 构造函数
template <class T>
BinaryTree<T>::BinaryTree(const string &s){
	root = NULL;
	int i = 0;
	root = createBTree(s, i);
} 
template <class T>

//构建二叉树	
BinaryTree<T>::TreeNode* createBTree(const string &s, int &i){
	TreeNode* BTree; 
	if(s[i] == '#'){
		return NULL;
	}
	else{
		BTree = new BTNode();
		BTree->data = s[i];
		BTree->l_child = createBTree(s,++i);
		BTree->r_child = createBTree(s,++i);
		return BTree;
	}
}
		
// copy constructor
template <class T>
BinaryTree<T>::BinaryTree(BinaryTree<T> &tree)
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
template <class T>
BinaryTree<T>::~BinaryTree()
{
	delBTree(root);
	root = NULL;
} // destructor end

template <class T>
bool BinaryTree<T>::pubForDelBTree(){
	delBTree(root);
	if(root){
		return false;
	}
	return true;
			
}

//销毁二叉树
template<class T>
void BinaryTree<T>::delBTree(TreeNode* &p){
	if(p != NULL){
		delBTree(p->l_child);
		delBTree(p->r_child);
		delete(p);
		p = NULL;
	}
}

//外部访问先序遍历
template<class T>
void Binary<T>::pubForPreOrder(){
	PreOrder(root);
}
template<class T>
void Binary<T>::PreOrder(TreeNode* p){
	if(p != NULL){
		cout << p->data << "\t";
		PreOrder(p->l_child);
		PreOrder(p->r_child);
	}
}

//外部访问中序遍历
template<class T>
void Binary<T>::pubForInOrder(){
	InOrder(root);
}
template<class T>
void Binary<T>::InOrder(TreeNode* p){
	if(p != NULL){
		InOrder(p->l_child);
		cout << p->data << "\t";				
		InOrder(p->r_child);
	}
}



#endif;
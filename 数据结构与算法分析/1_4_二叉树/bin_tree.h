/*********************************************************************
	@ Title:			实现二叉树基本操作	

	@ Description:		
                        1.C++实现二叉树模板类（递归形式）					
	@ Conclusion:			
						
	@ Author:		rh_Jameson

	@ Date:			2014/12/22
**********************************************************************/

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <string>
//#include <deque>
#include<queue>
#include<stack>
using namespace std;

//二叉树类声明
template<typename T>class BinaryTree;

//二叉树结点类
template<typename T>
class TreeNode{
private:
	TreeNode<T> *l_child,*r_child;
	T data;

public:
	TreeNode(){l_child = NULL;r_child = NULL;}
	TreeNode(T value,TreeNode<T> *left = NULL,TreeNode<T> *right = NULL){
		data = value;
		l_child = left;
		r_child = right;
	}
	friend class BinaryTree<T>;		// 将二叉树类声明为友元类，方便访问该类私有变量
};

//二叉树类
template<typename T>
class BinaryTree{
public:
	// 构造函数
	BinaryTree(const string &s);				
    // 拷贝构造函数
	//BinaryTree(BinaryTree<T> &tree);
	// 析构函数
	~BinaryTree();
	// 外部删除二叉树函数
	bool pubForDelBTree();		
	// 外部访问先序遍历
	void pubForPreOrder();
	// 外部访问中序遍历
	void pubForInOrder();
	// 外部访问后序遍历
	void pubForPostOrder(int method);
	// 外部访问层次遍历
	void pubForLayerOrder();
	// 外部查找值为et_value的二叉树结点
	void pubForFindNode(T et_value);
	// 获得二叉树的根
	TreeNode<T>* getRoot();
	// 外部获得二叉树的深度
	int pubForGetBTDepth();

private:
	TreeNode<T> *root;                  //二叉树的根指针
    
    
	//构建二叉树
	TreeNode<T>* createBTree(const string &s, int &i);
	//销毁二叉树
	void delBTree(TreeNode<T>* &p);
	//内部先序遍历
	void PreOrder(TreeNode<T>* p);
	//内部中序遍历
	void InOrder(TreeNode<T>* p);
	//内部后序遍历
	void PostOrder(TreeNode<T>* p, int method);
	//内部层次遍历
    void LayerOrder(TreeNode<T> *p);  
	//内部查找值为et_value的二叉树结点
	TreeNode<T>* findNode(TreeNode<T> *p, T et_value);    
	//内部获得二叉树的深度
	int getBTDepth(TreeNode<T> *p);
};

// 构造函数
template <typename T>
BinaryTree<T>::BinaryTree(const string &s){
	root = NULL;
	int i = 0;
	root = createBTree(s, i);
} 
//构建二叉树	
template <typename T>
TreeNode<T>* BinaryTree<T>::createBTree(const string &s, int &i){
	TreeNode<T>* BTree; 
	if(s.empty() ){
		return NULL;
	}

	if(s[i] == '#'){
		return NULL;
	}
	else{
		BTree = new TreeNode<T>();
		BTree->data = s[i];
		BTree->l_child = createBTree(s,++i);
		BTree->r_child = createBTree(s,++i);
		return BTree;
	}
}

//根据前序遍历序列和中序遍历序列构建二叉树
//失败，模板类惹的祸，只允许TreeNode<char>,待另写一个cpp实现
/*template<typename T>
TreeNode<T>* createBTreeByPreAndInOrder(string &PreOrder, string &InOrder){
    if(PreOrder.empty() || InOrder.empty()) return NULL;
    TreeNode<T> *tmp; 
    if(PreOrder.size()){
        tmp = new TreeNode<T>();
        tmp->data = PreOrder[0];
        int idx = InOrder.find(PreOrder[0]);
        
        string PreLeft = PreOrder.substr(1, idx);
        string PreRight = PreOrder.substr(idx + 1);
        string InLeft = InOrder.substr(0, idx);
        string InRight = InOrder.substr(idx + 1);

        tmp->l_child = createBTreeByPreAndInOrder(PreLeft, InLeft);
        tmp->r_child = createBTreeByPreAndInOrder(PreRight,InRight);
    }
    return tmp;
}*/

//// 拷贝构造函数
//template <typename T>
//BinaryTree<T>::BinaryTree(BinaryTree<T> &tree){
//	
//} 

//析构函数
template <typename T>
BinaryTree<T>::~BinaryTree(){
	delBTree(root);
}
//外部销毁二叉树
template <class T>
bool BinaryTree<T>::pubForDelBTree(){
	delBTree(root);
	if(root){
		return false;
	}
	return true;
			
}
//内部销毁二叉树
template<typename T>
void BinaryTree<T>::delBTree(TreeNode<T>* &p){
	if(p != NULL){
		delBTree(p->l_child);
		delBTree(p->r_child);
		delete(p);
		p = NULL;
	}
}

//外部访问先序遍历
template<typename T>
void BinaryTree<T>::pubForPreOrder(){
	PreOrder(root);
}
//内部访问先序遍历
template<typename T>
void BinaryTree<T>::PreOrder(TreeNode<T>* p){
	if(p != NULL){
		cout << p->data << "\t";
		PreOrder(p->l_child);
		PreOrder(p->r_child);
	}
}

//外部访问中序遍历
template<typename T>
void BinaryTree<T>::pubForInOrder(){
	InOrder(root);
}
//内部访问中序遍历
template<typename T>
void BinaryTree<T>::InOrder(TreeNode<T>* p){
	if(p != NULL){
		InOrder(p->l_child);
		cout << p->data << "\t";				
		InOrder(p->r_child);
	}
}

//外部访问后序遍历
template<typename T>
void BinaryTree<T>::pubForPostOrder(int method){
	PostOrder(root, method);
}
//内部访问后序遍历
template<typename T>
void BinaryTree<T>::PostOrder(TreeNode<T> *p, int method){
    if(!p){
        cout << "空二叉树！" << endl;
    }
    switch(method){
        case 1:     //递归形式实现
            if(p != NULL){
                PostOrder(p->l_child, method);
                PostOrder(p->r_child, method);
                cout << p->data << "\t";
            }
            break;

        case 2:     //栈形式实现
            stack<TreeNode<T>* > QForBTree;
            TreeNode<T> *pre = NULL, *top = NULL;
            while(p != NULL || (!QForBTree.empty()) ){
                if(p != NULL){
                    QForBTree.push(p);
                    p = p->l_child;
                }
                else{
                    top = QForBTree.top();
                    if(top->r_child != NULL && top->r_child != pre ){
                        p = top->r_child;
                    }
                    else{
                        cout << top->data << "\t";
                        pre = top;
                        QForBTree.pop();
                    }
                }
            }
            break;
    }
}

//外部查找值为et_value的二叉树结点
template<typename T>
void BinaryTree<T>::pubForFindNode(T et_value){
	TreeNode<T> *res = findNode(root, et_value);
	if(res == NULL){
		cout << "找不到相应结点" << endl;
	}
	else{
		cout << "找到该结点，该结点值为:" << res->data << endl;
	}
	
}
//查找值为et_value的二叉树结点
template<typename T>
TreeNode<T>* BinaryTree<T>::findNode(TreeNode<T> *p, T et_value){
	if(p == NULL){
		return NULL;
	}
	if(p->data == et_value){
		return p;
	}	
	TreeNode<T> *tmp = findNode(p->l_child, et_value);
	if(tmp != NULL){
		return tmp;
	}
	else{
		return findNode(p->r_child, et_value);
	}
}

//外部获得二叉树的深度
template<typename T>
int BinaryTree<T>::pubForGetBTDepth(){
	return getBTDepth(root);
}
//获得二叉树的深度
template<typename T>
int BinaryTree<T>::getBTDepth(TreeNode<T> *p){
	int depth = 0;
	if(p != NULL){
		int l_child_depth = getBTDepth(p->l_child);
		int r_child_depth = getBTDepth(p->r_child);
		depth =  (l_child_depth >= r_child_depth) ? (l_child_depth + 1) : (r_child_depth + 1);
        //depth = 1 + (l_child_depth >= r_child_depth ? l_child_depth : r_child_depth);
	}
	return depth;	
}

//外部访问层次遍历
template<typename T>
void  BinaryTree<T>::pubForLayerOrder(){
	LayerOrder(root);
}
//内部层次遍历
template<typename T>
void  BinaryTree<T>::LayerOrder(TreeNode<T> *p){
	if(p == NULL){
        cout << "空树！" << endl;
        return;
	}
	queue<TreeNode<T> *> queueTreeNode;
	queueTreeNode.push(p);
	while(queueTreeNode.size() ){
		TreeNode<T> *tmp = queueTreeNode.front();
		queueTreeNode.pop();
		cout << tmp->data << "\t";

		if(tmp->l_child != NULL){
			queueTreeNode.push(tmp->l_child);
		}
		if(tmp->r_child != NULL){
			queueTreeNode.push(tmp->r_child);
		}
	}
	/*deque双向队列版
	deque<TreeNode<T> *> dequeTreeNode;
	dequeTreeNode.push_back(p);
	while(dequeTreeNode.size() ){
		TreeNode<T> *tmp = dequeTreeNode.front();
		dequeTreeNode.pop_front();
		cout << tmp->data << "\t";

		if(tmp->l_child != NULL){
			dequeTreeNode.push_back(tmp->l_child);
		}
		if(tmp->r_child != NULL){
			dequeTreeNode.push_back(tmp->r_child);
		}
	}*/
}

//获得二叉树的根
template<typename T>
TreeNode<T>* BinaryTree<T>::getRoot(){
	return root;
}

#endif

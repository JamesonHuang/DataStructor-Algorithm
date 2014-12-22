/*@description: 实现链栈的基本操作
﻿ *PS:因为使用了模板编程的方式，vs2010环境下，无法实现类模板分离编译，
﻿ *因此，实现代码也放在头文件中，找时间测试下gcc下可否实现类模板分离编译~~
  */

#ifndef _BINTREE_H_
#define _BINTREE_H_

#include <iostream>
#include <string>
using namespace std;

template <class ElemType>
class BinTree
{
public:
	//构造函数
	BinTree(const string &s);
	//析构函数
	~BinTree();
    //销毁二叉树
    BTNode<ElemType>* delBTree(BTNode<ElemType> *p); 
	
  	//查找值为et_value的二叉树结点
	BTNode<ElemType>* findNode(BTNode<ElemType> *p, ElemType et_value);
    
    //获得二叉树的深度
	int getBTDepth(BTNode<ElemType> *p);
    //外部访问先序遍历
    void pubForPreOrder(){
        PreOrder(root);
    }
    //外部访问中序遍历
    void pubForInOrder(){
        InOrder(root);
    }
    //外部访问后续遍历
    void pubForPostOrder(){
        PostOrder(root);
    }


private:
   //构建二叉树
    BTNode<ElemType>* createBTree(const string &s, int i);
    //先序遍历
    void PreOrder(BTNode<ElemType> *p);
	//中序遍历
    void InOrder(BTNode<ElemType> *p);
    //后续遍历
    void PostOrder(BTNode<ElemType> *p);
    //层次遍历
    void LayerOrder(BTNode<ElemType> *p);  
   //获得二叉树的根
	BTNode<ElemType>* getRoot();
    //获得结点的左孩子
	BTNode<ElemType>* getLChild(BTNode<ElemType> *p);
	//获得结点的右孩子
	BTNode<ElemType>* getRChild(BTNode<ElemType> *p);
	 
    //二叉树结构体
    struct BTNode
    {
        ElemType data;
        node *l_child;
        node *r_child;
    }; 
//BTNode,*BTNodePtr;
    
	//二叉树根结点
	BTNode<ElemType> *root;
};
//二叉树结构体
template<class ElemType>
struct BTNode
{
    ElemType data;
    node *l_child;
    node *r_child;
};
//构造函数，构造二叉树
template <class ElemType>
BinTree<ElemType>::BinTree(const string &s){
    root = createBTree(s,0);    
}
//根据先序遍历序列构造二叉树
template <class ElemType>
BinTree<ElemType>::createBTree(const string &s,int i){
    BTNode<ElemType> *BTree; 
    if(s[i] == '#'){
        return NULL;
    }
    else{
        BTree = new BTNode<ElemType>();
        BTree->data = s[i];
        BTree->l_child = createBTree(s,++i);
        BTree->r_child = createBTree(s,++i);
        return BTree;
    }
}

//析构函数，销毁二叉树
template <class ElemType>
BinTree<ElemType>::~BinTree(){
    delBTree(root);
}
//销毁二叉树
template <class ElemType>
void delBTree(BTNode<ElemType> *p){
    if(p != NULL){
        delBTree(p->l_child);
        delBTree(P->r_child);
        delete(p);
        p = NULL;
    }
}
//获得二叉树的根
template <class ElemType>
BTNode *BinTree<ElemType>::getRoot(){
    return root;
}
//查找值为et_value的二叉树结点
template <class ElemType>
BTNode* BinTree<ElemType>::findNode(BTNode<ElemType> *p, ElemType et_value){
    
}
//获得结点的左孩子
template <class ElemType>
BTNode* BinTree<ElemType>:: getLChild(BTNode<ElemType> *p){
    return p->l_child;
}
//获得结点的右孩子
template <class ElemType>
BTNode* BinTree<ElemType>:: getRChild(BTNode<ElemType> *p){
    return p->r_child;
}
//获得二叉树的深度
template <class ElemType>
int BinTree<ElemType>:: getBTDepth(BTNode<ElemType> *p){
    
}
//先序遍历
template <class ElemType>
void BinTree<ElemType>::PreOrder(BTNode<ElemType> *p){
    if(p != NULL){
        cout << p->data << "\t";
        PreOrder(p->l_child);
        PreOrder(p->r_child);
    }
   
}
//中序遍历
template <class ElemType>
void BinTree<ElemType>::InOrder(BTNode<ElemType> *p){
    if(p != NULL){
        InOrder(p->l_child);
        cout << p->data << "\t";
        InOrder(p->r_child);
    }

}
//后续遍历
template <class ElemType>
void BinTree<ElemType>::PostOrder(BTNode<ElemType> *p){
    if(p != NULL){
        PostOrder(p->l_child);
        PostOrder(p->r_child);
        cout << p->data << "\t";
    }
}
//层次遍历
template <class ElemType>
void BinTree<ElemType>::LayerOrder(){
    
}


#endif

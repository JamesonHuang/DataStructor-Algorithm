/*******************************************************************************
	@ Title:			实现二叉树基本操作	

	@ Description:		
                        1.C++实现二叉树模板类（递归）
                        2.C++实现二叉树模板类（非递归）
                        3.C++实现二叉排序树模板类（递归）
                        4.C++实现二叉排序树模板类（非递归）
	@ Conclusion:			
						1.构建二叉树（递归）：
							A.判断传入字符串参数是否为空
							B.遇“#”返回NULL
							C.遇其他字符，new一个二叉树结点
								a.data域是该字符
								b.左孩子递归调用该函数，所传标志变量i加1
								c.右孩子同b
						
						2.先序遍历（非递归）：
							策略一：
								A.向左深搜直至BTree的最左叶子节点的l_child指针
								B.搜的同时，访问每一结点，并将结点入栈
								C.逐一获取栈中结点的右孩子，重复A，B
								D.每获取一个栈中结点，就将该结点弹出，直至栈空
							
							策略二：
								A.将根节点入栈
								B.访问栈顶结点，并弹出栈顶结点
								C.将该栈顶结点的右孩子入栈,如果有的话
								D.将该栈顶结点的左孩子入栈,如果有的话
								E.重复BCD,直至栈空

						3.中序遍历（非递归）
							策略一：
								A.向左深搜直至BTree的最左叶子节点的l_child指针
								B.搜的同时，将结点入栈
								C.逐一访问栈顶结点，并将栈顶结点的右孩子入栈
								D.重复ABC，直至栈空

						4.后序遍历（非递归）
							策略一：
								A.向左深搜直至BTree的最左叶子节点的l_child指针
								B.搜的同时，将结点入栈
								C.向右深搜栈顶元素的右孩子，直至最右叶子节点，
									*、每搜一个节点时，先重复AB
								D.将栈中元素逐个弹出，并访问之
                                E.执行D时，需注意将p指针置空
							
							策略二：双栈法
								A.构建两个栈s1,s2
								B.将根节点入栈s1
								C.弹出s1的栈顶元素，并将该元素入栈s2
								D.将该元素的左孩子入栈，如果有的话
								E.将该元素的右孩子入栈，如果有的话
								F.重复CDE,直至栈s1空
								G.通过栈顶指针逐一遍历栈s2的元素

                        5.根据先序遍历序列构建二叉树（非递归）：
                            策略：
                                A.判空
                                B.向左深搜构造，并将结点入栈
                                C.重复执行B直至最左叶子节点的左指针
                                D.逐一访问栈顶结点，向右深搜构造
                                E.执行D时，检测是否有左结点，有则执行C

                        6.根据后序遍历序列构建二叉树（非递归）：
                            策略：
                                A.同5类似，顺序颠倒一下就可以了
                        
                        7.求二叉树深度（非递归实现）
                        8.前中后Morris遍历测试
                        9.测试BST相关操作 + 创建二叉排序树（递归 & 非递归）
                        10.二叉树findnode（非递归实现）
						11.BST insertNode非递归 & removeNode非递归


	@ Author:		rh_Jameson

	@ Date:			2014/12/22
**********************************************************************************/

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <string>
//#include <deque>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>

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
	
	/* 二叉树常用操作 */

	// 构造函数
	BinaryTree(const string &s, int method);				
    // 拷贝构造函数
	//BinaryTree(BinaryTree<T> &tree);
	// 析构函数
	~BinaryTree();
	// 外部删除二叉树函数
	bool pubForDelBTree();		
	// 外部访问先序遍历
	void pubForPreOrder(int method);
	// 外部访问中序遍历
	void pubForInOrder(int method);
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

	/* 二叉排序树常用操作 */
    
    // 二叉排序树构造函数
	//BinaryTree(vector<T> v);				
	BinaryTree(int v[]);				
	// 外部插入新结点
	void pubForInsertNode(T &et_value);
	// 外部删除指定结点
	void pubForRemoveNode(T et_value);
	// 外部查找最大值
	void pubForFindMax();
	// 外部查找最小值
	void pubForFindMin();
	// 外部查找二叉树是否包含指定值的结点
	bool pubForContains(T et_value);

private:
	TreeNode<T> *root;                  //二叉树的根指针
    
    /* 二叉树常用操作 */

	//构建二叉树
	TreeNode<T>* createBTree(const string &s, int &i, int method);
	//销毁二叉树
	void delBTree(TreeNode<T>* &p);
	//内部先序遍历
	void PreOrder(TreeNode<T>* p, int method);
	//内部中序遍历
	void InOrder(TreeNode<T>* p, int method);
	//内部后序遍历
	void PostOrder(TreeNode<T>* p, int method);
	//内部层次遍历
    void LayerOrder(TreeNode<T> *p);  
	//内部查找值为et_value的二叉树结点
	TreeNode<T>* findNode(TreeNode<T> *p, T et_value);    
	//内部获得二叉树的深度
	int getBTDepth(TreeNode<T> *p);

	/* 二叉排序树常用操作 */

    // 构建二叉排序树
	TreeNode<T>* createBST(int v[], int start, int end);
	//TreeNode<T>* createBST(int v[], int start, int end);
	// 插入新结点
	void insertNode(T &et_value, TreeNode<T>* &p);
	// 删除指定结点
	void removeNode(T et_value, TreeNode<T>* &p);
	// 查找最大值
	TreeNode<T>* findMax(TreeNode<T> *p);
	// 查找最小值
	TreeNode<T>* findMin(TreeNode<T> *p);
	// 查找二叉树是否包含指定值的结点
	bool contains(T et_value, TreeNode<T> *p);
};

// 构造函数
template <typename T>
BinaryTree<T>::BinaryTree(const string &s, int method){
	root = NULL;
	int i = 0;
	root = createBTree(s, i, method);
} 
//构建二叉树	
template <typename T>
TreeNode<T>* BinaryTree<T>::createBTree(const string &s, int &i,int method){
    switch(method){
        case 1:     //递归构建
        {
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
                BTree->l_child = createBTree(s,++i, method);
                BTree->r_child = createBTree(s,++i, method);
                return BTree;
            }
        }
        case 2:     //根据先序遍历序列构建（非递归）
        {
            if(s.empty()){
                return NULL;
            }
            TreeNode<T> *BTNode = new TreeNode<T>, *head = BTNode;
            BTNode->data = s[i++];
            stack<TreeNode<T>* > SForBTree;
            while(BTNode || !SForBTree.empty() ){
                if(s[i] == '\0'){
                    break;
                }
                if(BTNode){             //向左深搜
                    SForBTree.push(BTNode);
                    if(s[i] == '#'){    //遇#置NULL
                        BTNode->l_child = NULL;
                    }
                    else{               //遇其他符号则新建结点
                        BTNode->l_child = new TreeNode<T>();
                        BTNode->l_child->data = s[i];
                    }
                    BTNode = BTNode->l_child;
                }
                else{                   //反过来，向右深搜
                    BTNode = SForBTree.top();
                    SForBTree.pop();
                    if(s[i] == '#'){
                        BTNode->r_child = NULL;
                    }
                    else{
                        BTNode->r_child = new TreeNode<T>();
                        BTNode->r_child->data = s[i];
                    }
                    BTNode = BTNode->r_child;
                }
                i++;
            }
            return head;
        }
        case 3:     //根据后序遍历序列构建二叉树
        {
            if(s.empty()){
                return NULL;
            }
            int cur = s.size() - 1;
            stack<TreeNode<T>* > SForBTree;
            TreeNode<T> *node = new TreeNode<T>(), *head = node;
            node->data = s[cur--];
            while(node || !SForBTree.empty()){
                if(cur < 0){
                    break;
                }
                if(node){                   //向右深搜
                    SForBTree.push(node);
                    if(s[cur] == '#'){      //遇#置NULL
                        node->r_child = NULL;
                    }
                    else{                   //其他符号新建一个结点
                        node->r_child = new TreeNode<T>();
                        node->r_child->data = s[cur];
                    }
                    node = node->r_child;
                }
                else{                       //反过来，向左深搜
                    node = SForBTree.top();
                    SForBTree.pop();
                    if(s[cur] == '#'){
                        node->l_child = NULL;
                    }
                    else{
                        node->l_child = new TreeNode<T>();
                        node->l_child->data = s[cur];
                    }
                    node = node->l_child;
                }
                --cur;
            }
            return head;
        }
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
	
    /* 递归销毁
     if(p != NULL){
		delBTree(p->l_child);
		delBTree(p->r_child);
		delete(p);
		p = NULL;
	}*/
    //待实现：自上而下层次遍历销毁
    //
	//非递归实现(自下而上后续遍历销毁)
    stack<TreeNode<T>* > SForBTree;
    TreeNode<T> *pre;
    while(p || !SForBTree.empty() ){
        if(p){
            SForBTree.push(p);
            p = p->l_child;
        }
        else{
            p = SForBTree.top();
            if(p->r_child && p->r_child != pre ){   //有右子树且右子树未被访问过
                p = p->r_child;
            }
            else{
                pre = p;
                SForBTree.pop();
                delete p;
                p = NULL;           //!!!须置空，否则陷入死循环
                                    //反复出栈 / 入栈
            }
        }
    }
}

//外部访问先序遍历
template<typename T>
void BinaryTree<T>::pubForPreOrder(int method){
	if(!root){
		cout << "空二叉树！" << endl;
	}
	PreOrder(root, method);
}
//内部访问先序遍历
template<typename T>
void BinaryTree<T>::PreOrder(TreeNode<T>* p, int method){
	switch(method){
		case 1:		//递归形式
			if(p != NULL){
				cout << p->data << "\t";
				PreOrder(p->l_child, method);
				PreOrder(p->r_child, method);
			}
			break;
		case 2:		//栈的实现形式
		    {	
                stack<TreeNode<T>* > SForBTree;
                while(p != NULL || !SForBTree.empty() ){
                    if(p != NULL){
                        cout << p->data << "\t";
                        SForBTree.push(p);
                        p = p->l_child;
                    }
                    else{
                        p = SForBTree.top();
                        SForBTree.pop();
                        p = p->r_child;
                    }
                }
                break;
            }
		case 3:		//栈实现形式二
            {   
                stack<TreeNode<T>* > SForBTree;
                if(p != NULL)
                    SForBTree.push(p);
                while( !SForBTree.empty() ){
                    p = SForBTree.top();
                    cout << p->data << "\t";
                    SForBTree.pop();

                    if(p->r_child){
                        SForBTree.push(p->r_child);
                    }
                    if(p->l_child){
                        SForBTree.push(p->l_child);
                    }
                }
                break;
        	}
        case 4:		//Morris遍历
        {
        	TreeNode<T> *cur = p, *pre;
        	while(cur){
        		if(!cur->l_child){      //左孩子为空时，输出当前结点，cur指向其右孩子
        			cout << cur->data << "\t";
        			cur = cur->r_child;
        		}
        		else{                   //左孩子不为空时
        			pre = cur->l_child;
                    //找该结点的中序遍历序列的前驱结点
        			while(pre->r_child != NULL && pre->r_child != cur){     
        				pre = pre->r_child;
        			}
                    //前驱结点的右孩子指向当前结点，并输出当前节点，cur指向其左孩子
        			if(pre->r_child == NULL){   
        				pre->r_child = cur;
        				cout << cur->data << "\t";  //与中序遍历唯一的不同！
        				cur = cur->l_child;
        			}
                    //将前驱结点右孩子指向当前结点的连接断开，cur指向其右孩子
        			else{
        				pre->r_child = NULL;
        				cur = cur->r_child;
        			}
        		}
        	}
        }
    }
}

//外部访问中序遍历
template<typename T>
void BinaryTree<T>::pubForInOrder(int method){
	if(!root){
		cout << "空二叉树" << endl;
	}
	InOrder(root, method);
}
//内部访问中序遍历
template<typename T>
void BinaryTree<T>::InOrder(TreeNode<T>* p, int method){
	switch(method){
		case 1:		//递归形式
		{	if(p != NULL){
				InOrder(p->l_child, method);
				cout << p->data << "\t";				
				InOrder(p->r_child, method);
			}
			break;
		}
		case 2:		//栈的实现形式
		{
			stack<TreeNode<T>* > SForBTree;
			while(p != NULL || !SForBTree.empty() ){
				if(p != NULL){
					SForBTree.push(p);
					p = p->l_child;
				}
				else{
					p = SForBTree.top();
					cout << p->data << "\t";
					SForBTree.pop();
					p = p->r_child;
				}
			}
			break;
		}
		case 3:		//morris遍历
		{
			TreeNode<T> *cur = p, *pre;
			while(cur){
				if(cur->l_child == NULL){
					cout << cur->data << "\t";
					cur = cur->r_child;
				}
				else{
					pre = cur->l_child;
					while(pre->r_child != NULL && pre->r_child != cur){
						pre = pre->r_child;
					}
					if(pre->r_child == NULL){
						pre->r_child = cur;
						cur = cur->l_child;
					}
					else{
						pre->r_child = NULL;
						cout << cur->data << "\t";      //与前序遍历代码的不同！
						cur = cur->r_child;
					}
				}
			}
		}
	}
	
}

//外部访问后序遍历
template<typename T>
void BinaryTree<T>::pubForPostOrder(int method){
    if(!root){
        cout << "空二叉树！" << endl;
    }
    PostOrder(root, method);
}
//内部访问后序遍历
template<typename T>
void BinaryTree<T>::PostOrder(TreeNode<T> *p, int method){
    switch(method){
        case 1:     //递归形式实现
            if(p != NULL){
                PostOrder(p->l_child, method);
                PostOrder(p->r_child, method);
                cout << p->data << "\t";
            }
            break;

        case 2:     //栈形式实现，该代码应该可以转作非递归销毁二叉树
        {
            stack<TreeNode<T>* > SForBTree;
            TreeNode<T> *pre;
            while(p || !SForBTree.empty() ){
                if(p){
                    SForBTree.push(p);
                    p = p->l_child;
                }
                else{
                    p = SForBTree.top();
                    if(p->r_child && p->r_child != pre ){   //有右子树且右子树未被访问过
                        p = p->r_child;
                    }
                    else{
                        cout << p->data << "\t";    
                        pre = p;
                        SForBTree.pop();
                        p = NULL;           //!!!须置空，否则陷入死循环
                                            //反复出栈 / 入栈
                    }
                }
            }
            break;
        }
        case 3:		//双栈形式实现
        {
            stack<TreeNode<T>* > s1, s2;
            if(p != NULL)   s1.push(p);
            while(!s1.empty()){
                p = s1.top();
                s1.pop();
                s2.push(p);

                if(p->l_child){
                    s1.push(p->l_child);
                }
                if(p->r_child){
                    s1.push(p->r_child);
                }
            }
            while(!s2.empty()){
                p = s2.top();
                cout << p->data << "\t";
                s2.pop();
            }
            break;
        }
        case 4:		//morris遍历
        {
        	TreeNode<T> *cur = p, *pre;
        	while(cur != NULL){
        		if(cur->l_child == NULL){
        			cur = cur->r_child;
        		}
        		else{
        			pre = cur->l_child;
        			while(pre->r_child != NULL && pre->r_child != cur){
        				pre = pre->r_child;
        			}
        			if(pre->r_child == NULL){
        				pre->r_child = cur;
        				cur = cur->l_child;
        			}
        			else{
        				//printReverse(cur->l_child, pre);
        				pre->r_child = NULL;
        				cur = cur->r_child;
        			}
        		}
        	}
        }
    }
}
/*Morris 后续遍历相关函数
 * template<typename T>
void reverse(TreeNode<T> *from, TreeNode<T> *to){
	if(from = to){
		return;
	}
	TreeNode<T>  =
}
template<typename T>
void printReverse(TreeNode<T> *from, TreeNode<T> *to){
	TreeNode<T> *p = to;
	reverse(from, to);
	while(true){
		cout << p->data << "\t";
		if(p == from){
			break;
		}
		p = p->r_child;
	}
	reverse(to, from); 
}*/

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
    //递归实现
/*	if(p == NULL){
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
*/
    //非递归实现
    stack<TreeNode<T>*> s;
    while(p != NULL || !s.empty()){
        if(p != NULL){
            s.push(p);
            p = p->l_child;
        }
        else{
            p = s.top();
            s.pop();
            if(p->data == et_value) break;
            p = p->r_child;
        }
    }
    return p;
}

//外部获得二叉树的深度
template<typename T>
int BinaryTree<T>::pubForGetBTDepth(){
	return getBTDepth(root);
}
//获得二叉树的深度
template<typename T>
int BinaryTree<T>::getBTDepth(TreeNode<T> *p){
    /* 递归实现1 
    int depth = 0;
	if(p != NULL){
		int l_child_depth = getBTDepth(p->l_child);
		int r_child_depth = getBTDepth(p->r_child);
		depth =  (l_child_depth >= r_child_depth) ? (l_child_depth + 1) : (r_child_depth + 1);
        //depth = 1 + (l_child_depth >= r_child_depth ? l_child_depth : r_child_depth);
	}
	return depth;	
    */
    /* 递归实现2 
    if(p == NULL) return 0;
    return 1 + max(getBTDepth(p->l_child), getBTDepth(p->r_child));
    */
    //非递归实现
/*    int depth = 0, maxDepth = 0;
    stack<TreeNode<T>*> *s = new stack<TreeNode<T>*>();
    while(p != NULL || !s->empty()){
        if(p != NULL){
            s->push(p);
            ++depth;
            p = p->l_child;
        }
        else{
            p = s->top();
            s->pop();
            p = p->r_child;
            if(p == NULL){
                if(depth > maxDepth){
                    maxDepth = depth;
                }   
                depth--;
            }
        }
    }
    return maxDepth - 1;
*/
    /* 双栈形式 
    if (p == NULL) return 0;
    stack<TreeNode<T> *> gray;
    stack<int> depth;
    int maxDepth = 0;

    gray.push(p);
    depth.push(1);
    while (!gray.empty()) {
        TreeNode<T> *tmp = gray.top();
        int num = depth.top();
        gray.pop();
        depth.pop();
        if (tmp->l_child == NULL && tmp->r_child == NULL) {
            maxDepth = num > maxDepth ? num : maxDepth;
        }
        else {
            if (tmp->l_child != NULL) {
                gray.push(tmp->l_child);
                depth.push(num + 1);
            }
            if (tmp->r_child != NULL) {
                gray.push(tmp->r_child);
                depth.push(num + 1);
            }
        }
    }
    return maxDepth;
    */

    /* 队列层次遍历实现 
    int height = 0,rowCount = 1;
    if(root == NULL){
        return 0;
    }
    queue<TreeNode<T>*> queue;
    queue.push(p);
    while(!queue.empty()){
        TreeNode<T> *node = queue.front();
        queue.pop();
        //一层的元素个数减1，一层遍历完高度加1
        rowCount --;
        if(node->l_child){
            queue.push(node->l_child);
        }
        if(node->r_child){
            queue.push(node->r_child);
        }
        //一层遍历完
        if(rowCount == 0){
            //高度加1
            height++;
            //下一层元素个数
            rowCount = queue.size();
        }
    }
    return height;
    */
    /* 层次遍历树的层数,NULL为每一层节点的分割标志 */
    if(p == NULL)return 0;
    int res = 0;
    queue<TreeNode<T>*> Q;
    Q.push(p);
    Q.push(NULL);
    while(Q.empty() == false)
    {
        TreeNode<T> *p = Q.front();
        Q.pop();
        if(p != NULL)
        {
            if(p->l_child)Q.push(p->l_child);
            if(p->r_child)Q.push(p->r_child);
        }
        else
        {
            res++;
            if(Q.empty() == false)Q.push(NULL);
        }
    }
    return res;
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


/* 二叉排序树常用操作 */

// 二叉排序树构造函数
template<typename T>
BinaryTree<T>::BinaryTree(int v[]){
    //vector<int> vv(v, v + sizeof(v)/sizeof(v[0]));
    /*vector<int> vv(v, v + 10);
    if(!vv.size()){
        cout << "生成失败，原因：空数组" << "\t";
        return;
    }
    sort(vv.begin(), vv.end());
    */
    sort(v, v + 9);
    /*if(sizeof(v) / sizeof(int)){
        cout << "生成失败，原因：空数组" << "\t";
        return;
    }*/

    root = createBST(v, 0, 9 - 1);
}
 // 构建二叉排序树
template<typename T>
TreeNode<T>* BinaryTree<T>::createBST(int sorted_Vec[],int start,int end){    
    //递归实现
    if(end < start){
        return NULL;
    }
    int mid = (start + end) / 2;
    TreeNode<T> *node = new TreeNode<T>();
    node->data = sorted_Vec[mid];
    node->l_child = createBST(sorted_Vec, start, mid - 1);
    node->r_child = createBST(sorted_Vec, mid + 1, end);
    return node;
    
    //非递归实现
/*失败，每个结点的start和end都需记住，该模板无相应属性
 * 为避免大量修改代码，放弃实现～～
 *  mid = (start + end) / 2;
    stack<TreeNode<T>* > s = new stack<TreeNode<T>* >();
    stack<int> mid_s = new stack<int>();
    TreeNode<T> *node = new TreeNode<T>();
    mid_s.push(end);
    while(mid >= 0 || !s.empty()){
        if(mid >= 0){
            node = new TreeNode<T>();
            node->data = sorted_Vec[mid];
            mid_s.push(mid);
            s.push(node);
            node = node->l_child;
            mid = (0 + mid - 1) / 2;
        }
        else{
            mid = mid_s.top();
            node = s.top();
            mid_s.pop();
            s.pop();
            
        }
    }
*/
}


// 外部插入新结点
template<typename T>
void BinaryTree<T>::pubForInsertNode(T &et_value){
	insertNode(et_value, root);
}
// 插入新结点
template<typename T>
void BinaryTree<T>::insertNode(T &et_value, TreeNode<T>* &p){
	//递归实现
/*	if(p == NULL){
		p = new TreeNode<T>();
		p->data = et_value;
	}
	else if(et_value < p->data){
		insertNode(et_value, p->l_child);
	}
	else if(et_value > p->data){
		insertNode(et_value, p->r_child);
	}
	else	//相等（重复）则不做任何操作
		;
	*/
	//非递归实现
	TreeNode<T> *cur = p, *parent = NULL, *newNode = new TreeNode<T>();
	newNode->data = et_value;
	if(p == NULL){				//二叉树为空的情况
		p = newNode;
		return;
	}			
	while(true){
		if(cur == NULL){
			if(et_value < parent->data)			//插入到叶子节点的左孩子
				parent->l_child = newNode;
			else
				parent->r_child = newNode;
			return;
		}
		parent = cur;
		if(et_value < cur->data)
			cur = cur->l_child;
		else if(et_value > cur->data)
			cur = cur->r_child;
		else
			return;		//重复，不插入，直接退出
	}
}

// 外部删除指定结点
template<typename T>
void BinaryTree<T>::pubForRemoveNode(T et_value){
	removeNode(et_value, root);
}
// 删除指定结点
template<typename T>
void BinaryTree<T>::removeNode(T et_value, TreeNode<T> * &p){
	//递归实现
/*	if(p == NULL){
		return;		//该值未找到，停止
	}
	if(et_value < p->data){
		removeNode(et_value, p->l_child);
	}
	else if(et_value > p->data){
		removeNode(et_value, p->r_child);
	}
	else if(p->l_child != NULL && p->r_child != NULL){ 		//待删结点有两个孩子的情况
		p->data = findMin(p->r_child)->data;		//需琢磨另一种写法
		removeNode(p->data, p->r_child);
	}
	else{		//无孩子或有一个孩子情况
		TreeNode<T> *tmp = p;
		p = (p->l_child != NULL) ? p->l_child : p->r_child;
		delete tmp;
	}
*/

	//非递归实现	
/*	TreeNode<T> *cur = p, *pre, *tmp, *child;
	if(p->data == et_value && !p->l_child && !p->r_child){	//只有一个节点的情况
		p = NULL;
		return;
	}
	while(true){		
		if(cur == NULL)	break;
		if(et_value < cur->data){
			pre = cur;
			cur = cur->l_child;
		}else if(et_value > cur->data){	
			pre = cur;
			cur = cur->r_child;
		}else if(cur->l_child != NULL && cur->r_child != NULL){		//待删结点有两个孩子的情况
			tmp = findMin(cur->r_child); 
			cur->data = tmp->data;
            child = tmp->r_child;			//暂存其右孩子
			pre = cur->r_child;
			while(pre->l_child != tmp)		//找倒数第二小的结点
				pre = pre->l_child;
			pre->l_child = child;
			delete tmp;
			break;
		}
		else{		//无孩子或有一个孩子情况
			tmp = cur;
			cur = (cur->l_child != NULL) ? cur->l_child : cur->r_child;
			(pre->l_child == tmp) ? pre->l_child = cur : pre->r_child = cur;
			delete tmp;
			break;
		}
	}
*/
	//非递归实现	
	TreeNode<T> *cur = p, *pre, *tmp, *child;
	if(p->data == et_value && !p->l_child && !p->r_child){	//只有一个节点的情况
		p = NULL;
		return;
	}
	while(true){		
		if(cur == NULL)	break;		//找不到或BST为空
		if(et_value < cur->data){
			pre = cur;
			cur = cur->l_child;
		}
		else if(et_value > cur->data){	
			pre = cur;
			cur = cur->r_child;
		}
		else{		
			if(cur->l_child != NULL && cur->r_child != NULL){	//待删结点有两个孩子的情况
				tmp = findMin(cur->r_child); 
				cur->data = tmp->data;
				child = tmp->r_child;			//暂存其右孩子
				pre = cur->r_child;
				while(pre->l_child != tmp)	pre = pre->l_child;	//找倒数第二小的结点	
				pre->l_child = child;
			}
			else{		//无孩子或有一个孩子情况
				tmp = cur;
				cur = (cur->l_child != NULL) ? cur->l_child : cur->r_child;
				(pre->l_child == tmp) ? pre->l_child = cur : pre->r_child = cur;

			}
			delete tmp;
			break;
		}
	}
}

// 外部查找最大值
template<typename T>
void BinaryTree<T>::pubForFindMax(){
	cout << "该二叉树的最大值为：" << findMax(root)->data << endl;
}
// 查找最大值
template<typename T>
TreeNode<T>* BinaryTree<T>::findMax(TreeNode<T> *p){
	/* 递归实现 */
/*	if(p == NULL){
		return NULL;
	}
	if(p->r_child == NULL){
		return p;
	}
	return findMax(p->r_child);
*/	
	/* 非递归实现 */
/*	while(p != NULL){
		if(p->r_child == NULL){
			return p;
		}
		p = p->r_child;
	}
	return NULL; 
*/
	/* 非递归实现2 */
	if(p != NULL){
		while(p->r_child != NULL){
			p = p->r_child;
		}
	}
	return p;
	
}

// 外部查找最小值
template<typename T>
void BinaryTree<T>::pubForFindMin(){
	cout << "该二叉树的最小值为：" << findMin(root)->data << endl;
}
// 查找最小值
template<typename T>
TreeNode<T>* BinaryTree<T>::findMin(TreeNode<T> *p){
	/* 递归实现 */
/*	if(p == NULL){
		return NULL;
	}
	//if(p->l_child == NULL || *((unsigned int *)p->l_child) == 0xFEEEFEEE ){
	if(p->l_child == NULL){
		p->l_child = NULL;
		return p;
	}
	return findMin(p->l_child);
*/
	/* 非递归实现 
	while(p != NULL){
		if(p->l_child == NULL){
			return p;
		}
		p = p->l_child;
	}
	return NULL; 
*/
	/* 非递归实现2 */
	if(p != NULL){
		while(p->l_child != NULL){
			p = p->l_child;
		}
	}
	return p;
}

// 外部查找二叉树是否包含指定值的结点
template<typename T>
bool BinaryTree<T>::pubForContains(T et_value){
	return contains(et_value, root);
}
// 查找二叉树是否包含指定值的结点
template<typename T>
bool BinaryTree<T>::contains(T et_value, TreeNode<T> *p){
	//递归实现
/*	if(p == NULL){
		return false;
	}
	if(et_value < p->data){
		contains(et_value, p->l_child);
	}
	else if(et_value > p->data){
		contains(et_value, p->r_child);
	}
	else{
		return true;
	}
*/
	//非递归实现
	while(p != NULL){
		if(et_value < p->data)
			p = p->l_child;
		else if(et_value > p->data)
			p = p->r_child;
		else
			return true;
	}
	return false;

}

#endif

/*********************************************************************
	@ Title:			实现二叉树基本操作	

	@ Description:		
                        1.实现二叉树的ADT（递归形式）
	                    2.实现二叉树的ADT（迭代形式）					
	@ Conclusion:			

	@ Author:		rh_Jameson

	@ Date:			2014/12/22
**********************************************************************/

#include<iostream>
#include<vector>
#include<string>
#include"bin_tree.h"

using namespace std;
//---------------------2、测试重建二叉树（递归）----------------------//
/*void testReBuildTree()
{
	string pres = "12473568";
    string ins = "47215386";
    cout << "pres: " << pres << endl;
    cout << "ins: " << ins << endl;

    BinaryTree<string> *bt = new BinaryTree<string>(pres, ins);
    cout << "构建二叉树ing..." << endl;
    bt->pubForPreOrder();
    bt->pubForInOrder();

}*/

//---------------------1、测试二叉树的ADT----------------------//
void testBinaryTree()
{
	//string s = "124###35#6###";         //先序遍历序列构建
	string s = "12#47###3589####6##";         //先序遍历序列构建
    //string s = "12#46###3#5##";
    BinaryTree<string> *bt = new BinaryTree<string>(s, 2);

/*  string s = "##4#2###65#31";             //后序遍历序列构建
    BinaryTree<string> *bt = new BinaryTree<string>(s, 3);
*/
    cout << "构建二叉树ing..." << endl;
    
    cout << "二叉树前序遍历(递  归)：";
	bt->pubForPreOrder(1);
	cout << endl;
	
    cout << "二叉树前序遍历(栈实现)：";
	bt->pubForPreOrder(2);
	cout << endl;
    
    cout << "二叉树前序遍历(栈实现2)：";
	bt->pubForPreOrder(3);
	cout << endl;
	
    cout << "二叉树前序遍历(Morris)：";
	bt->pubForPreOrder(4);
	cout << endl << endl;
	
    cout << "二叉树中序遍历(递  归)：";
	bt->pubForInOrder(1);
	cout << endl;
    
    cout << "二叉树中序遍历(栈实现)：";
	bt->pubForInOrder(2);
	cout << endl;
    
    cout << "二叉树中序遍历(Morris)：";
	bt->pubForInOrder(3);
	cout << endl << endl;
	
    cout << "二叉树后序遍历(递  归)：";
	bt->pubForPostOrder(1);
	cout << endl;

    cout << "二叉树后序遍历(栈实现)：";
    bt->pubForPostOrder(2);
    cout << endl;
    
    cout << "二叉树后序遍历(双栈实现)：";
    bt->pubForPostOrder(3);
    cout << endl;
    
    cout << "二叉树后序遍历(Morris)：";
    bt->pubForPostOrder(4);
    cout << "未完成";
    cout << endl << endl;
	cout << "二叉树层次遍历(队实现)：";
	bt->pubForLayerOrder();
	cout << endl;
	bt->pubForFindNode("4");
	
    cout << "二叉树深度为：" << bt->pubForGetBTDepth() << endl;
	
    cout << "销毁二叉树是否成功：" << bt->pubForDelBTree() << endl;

}

//---------------------2、测试二叉排序树的ADT----------------------//
void testBST(){
    int a[] = {0, 1, 4, 2, 9, 8, 7, 6, 3};
/*  vector<int> v;
    for(int i = 1; i <= 10; ++i){
        v.push_back(i);
        cout << v[i] << "\t";
    }
*/
    BinaryTree<int> *bt = new BinaryTree<int>(a);
    int val = 5;
    bt->pubForInsertNode(val);
	bt->pubForRemoveNode(++val);
    cout << "构建二叉排序树ing..." << endl;
    
    cout << "二叉树前序遍历(递  归)：";
	bt->pubForPreOrder(1);
	cout << endl;
    
    cout << "二叉树中序遍历(栈实现)：";
	bt->pubForInOrder(2);
	cout << endl;
    
    cout << "二叉树后序遍历(栈实现)：";
    bt->pubForPostOrder(3);
    cout << endl;

	cout << "二叉树层次遍历(队实现)：";
	bt->pubForLayerOrder();
	cout << endl;

	bt->pubForFindMax();
	bt->pubForFindMin();
	cout << bt->pubForContains(2) << endl;
	cout << bt->pubForContains(8) << endl;
	cout << bt->pubForContains(11) << endl;
   
}

int main()
{
    testBST();
    //testBinaryTree();	
	return 0;
}

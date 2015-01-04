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

//---------------------1、测试二叉树的ADT（递归）----------------------//
void testBinaryTree()
{
	string s = "124###35#6###";
    BinaryTree<string> *bt = new BinaryTree<string>(s);
    cout << "构建二叉树ing..." << endl;

	cout << "二叉树前序遍历(递  归)：";
	bt->pubForPreOrder(1);
	cout << endl;
	
    cout << "二叉树前序遍历(栈实现)：";
	bt->pubForPreOrder(2);
	cout << endl;
	
    cout << "二叉树前序遍历(栈实现2)：";
	bt->pubForPreOrder(3);
	cout << endl << endl;
	
    cout << "二叉树中序遍历(递  归)：";
	bt->pubForInOrder(1);
	cout << endl;
    
    cout << "二叉树中序遍历(栈实现)：";
	bt->pubForInOrder(2);
	cout << endl << endl;;
	
    cout << "二叉树后序遍历(递  归)：";
	bt->pubForPostOrder(1);
	cout << endl;

    cout << "二叉树后序遍历(栈实现)：";
    bt->pubForPostOrder(2);
    cout << endl;
    
    cout << "二叉树后序遍历(双栈实现)：";
    bt->pubForPostOrder(3);
    cout << endl << endl;

	cout << "二叉树层次遍历(队实现)：";
	bt->pubForLayerOrder();
	cout << endl;
	bt->pubForFindNode("4");
	
    cout << "二叉树深度为：" << bt->pubForGetBTDepth() << endl;
	
    cout << "销毁二叉树是否成功：" << bt->pubForDelBTree() << endl;

}

int main()
{
    //testReBuildTree();
    testBinaryTree();	
	return 0;
}

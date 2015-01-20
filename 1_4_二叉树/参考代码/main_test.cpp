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

//---------------------1、测试二叉树的ADT（递归）----------------------//
void testBinaryTree()
{
	string s = "124###35#6###";
    BinaryTree<string> *bt = new BinaryTree<string>(s);
    cout << "构建二叉树ing..." << endl;
	cout << "二叉树前序遍历：";
	bt->pubForPreOrder();
	cout << endl;
	cout << "二叉树中序遍历：";
	bt->pubForInOrder();
	cout << endl;
	cout << "二叉树后序遍历：";
	bt->pubForPostOrder();
	cout << endl;
	cout << "二叉树层次遍历：";
	bt->pubForLayerOrder();
	cout << endl;
	bt->pubForFindNode("4");
	cout << "二叉树深度为：" << bt->pubForGetBTDepth() << endl;
	cout << "销毁二叉树是否成功：" << bt->pubForDelBTree() << endl;;


}

int main()
{
    testBinaryTree();	
	return 0;
}

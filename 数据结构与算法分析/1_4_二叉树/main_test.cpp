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
#include"BinTree.h"

using namespace std;

//---------------------1、测试二叉树的ADT（递归）----------------------//
void testBinaryTree()
{
    string s = "AB#D##CE###";
    BinTree<int> *bt = new BinTree<int>(s);
    bt->pubForPreOrder();
    bt->pubForInOrder();
    bt->pubForPostOrder();
}

int main()
{
    testBinaryTree();	
	return 0;
}

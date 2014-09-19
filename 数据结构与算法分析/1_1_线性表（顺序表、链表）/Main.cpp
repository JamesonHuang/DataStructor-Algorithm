/*********************************************************************
	@ Title:		实现线性表（顺序表、链表）	

	@ Description:		1、使用顺序表的基本操作

				2、指针初始化或者不初始化均不等于NULL
			
				3、使用链表的基本操作

				4、使用双向循环链表的基本操作


	@ Conclusion:			

	@ Author:		rh_Jameson

	@ Date:			2014/08/09
**********************************************************************/

#include<iostream>
#include<cstdlib>
#include<ctime>
#include"Sqlist.h"
#include"LinkList.h"
#include"DLinkList.h"

using namespace std;


//-------------2、指针初始化或者不初始化均不等于NULL-----------------//
void testPointInit()
{
	//int *ip = ( int* )malloc (MAXSIZE * sizeof(int));
	int *ip = ( int* )malloc (100000 * sizeof(int));
	int *iptr;
	//cout << ( *iptr == NULL ) << endl;
	cout << ( *ip == NULL ) << endl;
	cout << ip << endl;
}

int main()
{
	//testPointInit();
	//testSqlist();
	//TestSRand();
	//int res = gcd( 15, 20 );
	//cout << res << endl;
	
	//testDLinkList();
	
	testLinkList();
	return 0;
}
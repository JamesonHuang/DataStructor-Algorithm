/*********************************************************************
	@ Title:		实现线性表（顺序表、链表）	

	@ Description:		1、实现顺序表的基本操作

	@ Conclusion:			

	@ Author:		rh_Jameson

	@ Date:			2014/08/09
**********************************************************************/

#include <iostream>
#include <cstdlib>
#include "Sqlist.h"

using namespace std;

//初始化顺序表
void initList ( Sqlist* &L )
{
	L = ( Sqlist* )malloc ( MAXSIZE * sizeof(ElemType) );
	
	L->length = 0;
}

//创建顺序表
void createList ( Sqlist *L,const ElemType elem[], const int len )
{
	for(int i = 0; i < len; ++i)
	{
		L->data[i] = elem[i];
		//L->length++;
	}
	L->length = len;

}
//销毁顺序表
void destroyList ( Sqlist *L )
{
	free ( L );
	L = NULL;
}
//判断是否为空表
bool isListEmpty ( Sqlist *L )
{
	return ( L->length == 0 );
}

//返回该表的长度
int listLength ( Sqlist *L )
{
	return ( L->length );
}

//输出顺序表元素
void dispList ( Sqlist *L )
{
	if( isListEmpty( L ) )						//判断非空再输出
	{
		cout << "顺序表中没有元素！" <<endl;
		return;
	}
	//遍历输出
	for(int i = 0; i < L->length; ++i )
	{
		cout << L->data[i] << "   ";
		if( (i + 1) % 10 == 0 )
		{
			cout << endl;
		}
	}
}

//求线性表中某个元素的值
ElemType GetElem ( Sqlist *L, const int iter)
{
	//下标
	/*if( iter < 0 || iter >= L->length)
	{
		return NULL;
	}
	return L->data[iter];*/
	//第几个元素
	if( iter < 1 || iter > L->length)
	{
		return NULL;
	}
	return L->data[iter - 1];
	
}

//寻找顺序表中与值e相等的元素，并返回该元素下标
int findElem ( Sqlist *L, const ElemType e )
{
	for(int i = 0; i <= L->length; ++i)
	{
		if( L->data[i] == e )
		{
			return i;
		}
	}
	return -1;					//返回-1的话说明顺序表中没有该元素
}

//插入元素到顺序表的指定下标的位置
bool insertElem ( Sqlist *L, int iter, ElemType e )
{
	iter--;										//调整为下标
	if(iter < 0 || iter >= L->length )						//边界处理
	{
		return 0;
	}
	for(int i = L->length -1 ; i >= iter; --i )				//指定下标以后的元素向后移动一位
	{
		L->data[i + 1] = L->data[i];
		if( i == iter )
		{
			L->data[i] = e;
		}
	}
	L->length++;
	return 1;
}

//删除顺序表指定下标的元素
bool deleteElem ( Sqlist *L, int iter )
{
	iter--;								//调整下标
	if( iter < 0 || iter >= L->length )
	{
		return 0;
	}
	for(;iter < L->length; ++iter)					//指定下标以后的元素向前移动一位
	{
		L->data[iter] = L->data[iter + 1];
	}
	L->length--;
	return 1;
}

//-----------------------1、测试顺序表的基本操作----------------------//
void testSqlist()
{
	int arr[10], len = 10;
	for(int i = 0; i < 10; ++i)			//初始化元素
	{
		arr[i] = i;
	}
	
	Sqlist *L;
	initList ( L );
	createList ( L, arr, len );

	if( !isListEmpty( L ) )
	{
		cout << "顺序表已创建完毕，已有元素！" << endl;
	}
	
	cout << "顺序表的长度为：" <<listLength( L ) << endl;
	
	cout<< "此时顺序表中的元素有：";
	dispList ( L );

	cout << "第五个元素为：" << GetElem ( L, 5 ) << endl;
	
	cout << "元素值为3的元素下标是：" << findElem ( L, 3 ) << endl;

	insertElem ( L, 3, 100 );
	cout << "插入元素100后，顺序表的元素表有：";	
	dispList ( L );
	cout << endl;

	deleteElem ( L, 3 );
	cout << "删去第三个元素后的顺序表：";
	dispList ( L );
	cout << endl; 

}
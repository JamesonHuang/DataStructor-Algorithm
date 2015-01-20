/*********************************************************************
	@ Title:		实现线性表（顺序表、链表）	

	@ Description:		1、实现双向循环链表的基本操作

	@ Conclusion:			

	@ Author:		rh_Jameson

	@ Date:			2014/08/14
**********************************************************************/

#include<iostream>
#include<cstdlib>
#include"DLinkList.h"

using namespace std;

//初始化链表
void initList ( DLinkList* &L )
{
	L = ( DLinkList* )malloc( sizeof(DLinkList) );
	L->e = 0;
	L->prior = L;
	L->next = L;
}

//创建链表
//尾插法
void createListR ( DLinkList *L, const ElemType elem[], const int len )
{
	DLinkList *newNode, *rear = L, *front = L;
	for( int i = 0; i < len; ++i )
	{
		//新建节点，赋值元素
		newNode = ( DLinkList* )malloc( sizeof(DLinkList) );	
		newNode->e = elem[i];
		
		//尾指针与新建节点互连
		rear->next = newNode;
		newNode->prior = rear;

		//移动尾指针
		rear = rear->next;
	}
	//头指针与尾节点互连
	front->prior = rear;
	rear->next = front;
	L->e = len;

}

//头插法
void createListH( DLinkList *L, const ElemType elem[], const int len )
{
	DLinkList *front = L, *newNode,*rear;								//头结点指针、新插入结点指针

	for(int i = 0; i < len; ++i)
	{
		newNode = ( DLinkList* )malloc( sizeof(DLinkList) );					//创建新节点，赋值元素
		newNode->e = elem[i];
		if(front->next == L)									//插入第一个节点的话，rear指针指向第一个节点
		{
			rear =( DLinkList* )malloc( sizeof(DLinkList) );
			rear = newNode;
		}

		if(front->next != L )									//链表有元素时执行
		{
			newNode->next = front->next;
			front->next->prior = newNode;			
		}

		front->next = newNode;
		newNode->prior = front;
	}
	front->prior = rear;										//头结点与rear结点互连
	rear->next = front;
	L->e = len;

}

//销毁链表
void destroyList ( DLinkList *L )
{
	DLinkList *head = L, *p = L, *q = L->next;
	while( p->next != head)					//判断链表是否已到尽头
	{
		p->next = q->next;				//删除结点q
		q->next->prior = p;
		
		free( q );					//销毁结点q

		q = p->next;					//指向下一个结点
		
	}
	free(p);						//销毁链表（头结点）
}

//判断是否为空表
bool isListEmpty ( DLinkList *L )
{
	return ( L->next == L );
}

//返回该表的长度
int listLength ( DLinkList *L )
{
	//return L->e;
	DLinkList *p = L;
	int len = 0;
	while( p->next != L )
	{
		len++;
		p = p->next;
	}
	return len;
}

//输出链表元素
void dispList ( DLinkList *L )
{
	DLinkList *p = L->next;
	int num = 0;
	while( p->next != L )
	{
		num++;
		cout << p->e << "   ";
		if(num % 10 == 0)
		{
			cout << endl;
		}
		p = p->next;
	}
	cout << p->e << "   ";				//输出最后一个结点
}

//求线性表中某个元素的值
ElemType GetElem ( DLinkList *L, const int iter)
{
	if( iter < 1 || iter > L->e )
	{
		cout << "获取元素越界！" << endl;
	}
	DLinkList *p = L;
	for(int i = 0; i < iter; ++i)			//跳转到第iter个元素
	{
		p = p->next;
	}
	//cout << p->e << endl;
	return p->e; 
}

//寻找链表中与值e相等的元素，并返回该元素下标
int findElem ( DLinkList *L, const ElemType e )
{	
	if(L->next == L)				//判断非空
	{
		return -1;
	}

	DLinkList *p = L->next;				//指向第一个元素
	int num = 1;
	do
	{
		if( p->e == e )				//判断指向元素值是否为值e
		{
			return num;
		}
		num++;							
		p = p->next;				//指向下一个元素
	}while( p != L );

	return num;
}

//插入元素到链表的指定下标的位置
bool insertElem ( DLinkList *L, int iter, ElemType e )
{
	if(iter < 1 || iter > L->e)				//判断越界
	{
		return 0;
	}
	DLinkList *p = L;
	
	while( iter != 0 )					//跳转到要插入的地方
	{
		p = p->next;
		iter--;
	}

	DLinkList *newNode = ( DLinkList* )malloc( sizeof(DLinkList) );
	newNode->e = e;
	
	//插入结点
	newNode->next = p->next;
	p->next->prior = newNode;

	p->next = newNode;
	newNode->prior = p;
	L->e++;

	return 1;
}

//删除链表指定下标的元素
bool deleteElem ( DLinkList *L, int iter )
{
	if(iter < 1 || iter > L->e)
	{
		return 0;
	}
	DLinkList *p = L;
	DLinkList *q = p->next;
	
	while( iter != 1 )			//跳转到要删除结点的前一个结点
	{
		p = p->next;
		q = p->next;
		iter--;
	}

	p->next = q->next;
	q->next->prior = p;
	free(q);
	L->e++;

	return 1;
}


//-------------------4、使用双向循环链表的基本操作-------------------//
void testDLinkList()
{
	int arr[10], len = 10;
	for(int i = 0; i < 10; ++i)			//初始化元素
	{
		arr[i] = i;
	}
	DLinkList *L;
	
	initList ( L );
	createListH ( L, arr, len );			//头插法创建链表
	//createListR( L, arr, len );
	if( !isListEmpty( L ) )
	{
		cout << "单链表创建完毕，已有元素！" << endl;
	}
	
	cout << "链表的长度为：" <<listLength( L ) << endl;
	
	cout<< "此时链表中的元素有：";
	dispList ( L );

	cout << "第五个元素为：" << GetElem ( L, 5 ) << endl;
	
	cout << "元素值为3的元素下标是：" << findElem ( L, 3 ) << endl;

	insertElem ( L, 3, 100 );
	cout << "插入元素100后，链表的元素表有：";	
	dispList ( L );
	cout << endl;

	deleteElem ( L, 3 );
	cout << "删去第三个元素后的链表：";
	dispList ( L );
	cout << endl; 
	//destroyList ( L );
	
	//cout << listLength( L ) << endl;
}




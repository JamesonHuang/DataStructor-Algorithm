/*********************************************************************
	@ Title:		实现线性表（顺序表、链表）	

	@ Description:		1、实现链表的基本操作

	@ Conclusion:			

	@ Author:		rh_Jameson

	@ Date:			2014/08/13
**********************************************************************/

#include <iostream>
#include <cstdlib>
#include "LinkList.h"

using namespace std;

//初始化链表，创建头结点
void initList ( linkList* &L )
{
	L = ( linkList* )malloc ( sizeof( linkList ) );						//头结点
	L->data = 0;											//头结点数据域为链表大小
	L->next = NULL;										//头结点指针域初始化为null
}

//尾插法创建链表，创建链表之前须初始化链表
void createListR ( linkList *L,const ElemType elem[], const int len )
{
	linkList *rear;										//尾指针，指向最后一个节点，一开始指向头结点
			
	rear = L;								

	for(int i = 0; i < len; ++i)								//循环插入元素
	{
		linkList *newNode =( linkList* )malloc( sizeof( linkList ) );			//新结点
		newNode->data = elem[i];
		rear->next = newNode;
		rear = newNode;
		L->data++;
	}
	rear->next = NULL;
}

//头插法创建链表，创建链表之前须初始化链表
void createListH( linkList *L, const ElemType elem[], const int len )
{
	linkList *front = L;									//头指针，指向第一个节点，一开始指向头结点
	

	for(int i = 0; i < len; ++i )
	{
		linkList *newNode = ( linkList* )malloc( sizeof( linkList ) );			//指向要插入的新节点
		newNode->data = elem[i];
		newNode->next = front->next;							//新节点指针指向头结点指向的第一个元素
		front->next = newNode;								//头结点指针指向新插入结点
		L->data++;
	}

}

//销毁链表
void destroyList ( linkList *L )
{
	linkList *present = L;						//当前结点
	linkList *next = present->next;					//下一个结点
	while( next != NULL )						//遍历释放结点
	{
		free ( present );
		present = next;
		next = present->next;
	}
	free( present );						//释放最后一个结点
	present = NULL;
}
//判断是否为空表
bool isListEmpty ( linkList *L )
{
	//return ( L->data == 0 );
	return ( L->next == NULL );
}

//返回该表的长度
int listLength ( linkList *L )
{
	//头结点数据域存放链表长度的话，直接返回
	return ( L->data );
	
	//如果没有就遍历一遍链表
	/*int len = 0;
	linkList *present = L;
	while( present->next != NULL )
	{
		present = present->next;
		len++;
	}*/
}

//输出链表元素
void dispList ( linkList *L )
{
	if( isListEmpty( L ) )						//判断非空再输出
	{
		cout << "顺序表中没有元素！" <<endl;
		return;
	}
	//int len = L->data;
	//int len = listLength( L );
	linkList *ptr = L->next;					//不输出头结点
	int num = 0;							//逢十换行
	//遍历输出
	while( ptr != NULL )
	{
		cout << ptr->data << "   ";
		num++;
		ptr = ptr->next;

		if( num % 10 == 0 )					//逢十换行
		{
			cout << endl;
		}
	}
}

//求链表中某个元素的值
ElemType GetElem ( linkList *L, const int iter)
{	
	if( iter < 1 || iter > L->data )				//异常处理
	{
		return NULL;
	}
	linkList *ptr = L;
	for( int i = 0; i< iter; ++i )					//遍历到第iter个元素
	{
		ptr = ptr->next;
	}
	return ptr->data;
	
}

//寻找链表中与值e相等的元素，并返回该元素下标
int findElem ( linkList *L, const ElemType e )
{
	linkList *ptr = L->next;
	for(int i = 1; i <= L->data; ++i)		//遍历链表，查找值为e的元素
	{
		if( ptr->data == e )
		{
			return i;
		}
		ptr = ptr->next;
	}
	return -1;					//返回-1的话说明顺序表中没有该元素
}

//插入元素到链表的指定下标的位置
bool insertElem ( linkList *L, int iter, ElemType e )
{
	if(iter < 1 || iter > L->data )						//边界处理
	{
		return 0;
	}

	linkList *p = L;
	
	linkList *s =( linkList* )malloc( sizeof(linkList) );//新结点
	s->data = e;

	for(int i = 1; i <= iter; ++i )						//跳转到第iter个元素处
	{
		p = p->next;
	}

	s->next = p->next;							//插入新结点
	p->next = s;
	
	L->data++;
	return 1;
}

//删除链表指定下标的元素
bool deleteElem ( linkList *L, int iter )
{
	if(iter < 1 || iter > L->data )						//边界处理
	{
		return 0;
	}

	linkList *p = L;
	linkList *q = (linkList* )malloc( sizeof(linkList) );			//待删除结点
	for(int i = 1; i < iter; ++i )						//跳转到第iter-1个元素
	{
		p = p->next;
	}

	q = p->next;								//待删除结点
	p->next = q->next;							//删除结点
	free(q);
	q =	NULL;

	L->data--;															
	return 1;
}

//拆分链表,传进来的L都须初始化
void split( linkList *L, linkList *L1, linkList *L2 )
{
	linkList *p2L = L->next;								//pointer to L->next
	linkList *p2L1 = L1;									//pointer to L1
	linkList *p2L2 = L2;									//pointer to L2
	linkList *s;											//插入结点
	bool L1Flag = true;
	while( p2L != NULL )
	{
		s = ( linkList* )malloc( sizeof(linkList) );
		s->data = p2L->data;		
		if(L1Flag)											//插入L1
		{			
			p2L1->next = s;
			p2L1 = p2L1->next;
			L1->data++;
		}
		else												//插入L2
		{
			p2L2->next = s;
			p2L2 = p2L2->next;	
			L2->data++;
		}
		p2L = p2L->next;
		L1Flag = !L1Flag;
	}
	p2L1->next = NULL;
	p2L2->next = NULL;
}
//void split( linkList *L, linkList *L1, linkList *L2 )
//{
//	linkList *p = L->next;
//	linkList *q;
//	L1 = L;
//	linkList *r1 = L1;
//	
//	L2->next = NULL;
//
//	while( p != NULL )
//	{
//		q = p->next;
//		r1->next = p;
//		r1 = p;
//		p = q->next;
//		q->next = L2->next;
//		L2->next = q;
//	}
//	r1->next = NULL;
//}

//链表逆置：三指针法
linkList* reverseList(linkList *L)
{
	
	linkList *p = L->next;		//第一个结点
	
	linkList *q = p->next;
	linkList *r;

	p->next = NULL;

	while( q->next != NULL )
	{
		r = q->next;
		q->next = p;

		p = q;
		q = r;
		
	}
	q->next = p;
	L->next = q;
	return L;
}


//-----------------------3、使用链表的基本操作-----------------------//
void testLinkList()
{
	int arr[10], len = 10;
	for(int i = 0; i < 10; ++i)			//初始化元素
	{
		arr[i] = i;
	}
	linkList *L;
	
	initList ( L );
	//createListH ( &L, arr, len );						//头插法创建链表
	createListR( L, arr, len );
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

	L = reverseList(L);
	cout << "逆置后的链表：";
	dispList( L );



	/*linkList L1, L2;
	initList( L1 );
	initList( L2 );

	split( &L, &L1, &L2 );
	cout<< "调用split后：" << endl;
	dispList ( &L );
	cout << endl;
	dispList( &L1 );
	cout << endl;
	dispList( &L2 );
	cout << endl;*/

}
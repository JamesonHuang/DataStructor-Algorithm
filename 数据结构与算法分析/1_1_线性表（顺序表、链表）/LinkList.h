//定义顺序表的基本操作
#ifndef _LINKLIST_H_

typedef int ElemType;

typedef struct LNode
{
	ElemType data;
	LNode *next;
} linkList;


//初始化链表
void initList ( linkList &L );

//创建链表
void createListR ( linkList *L, const ElemType elem[], const int len );

void createListH( linkList *L, const ElemType elem[], const int len );

//销毁链表
void destroyList ( linkList *L );

//判断是否为空表
bool isListEmpty ( linkList *L );

//返回该表的长度
int listLength ( linkList *L );

//输出链表元素
void dispList ( linkList *L );

//求线性表中某个元素的值
ElemType GetElem ( linkList *L, const int iter);

//寻找链表中与值e相等的元素，并返回该元素下标
int findElem ( linkList *L, const ElemType e );

//插入元素到链表的指定下标的位置
bool insertElem ( linkList *L, int iter, ElemType e );

//删除链表指定下标的元素
bool deleteElem ( linkList *L, int iter );

//拆分链表
void split( linkList *L, linkList *L1, linkList *L2 );

//逆置链表
linkList* reverseList(linkList *L);

//-----------------------3、使用链表的基本操作-----------------------//
void testLinkList();

#endif
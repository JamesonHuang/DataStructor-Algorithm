#ifndef _DLINKLIST_H_

typedef int ElemType;

typedef struct dNode
{
	ElemType e;
	dNode *prior;
	dNode *next; 
} DLinkList;

//初始化链表
void initList ( DLinkList* &L );

//创建链表
void createListR ( DLinkList *L, const ElemType elem[], const int len );

void createListH( DLinkList *L, const ElemType elem[], const int len );

//销毁链表
void destroyList ( DLinkList *L );

//判断是否为空表
bool isListEmpty ( DLinkList *L );

//返回该表的长度
int listLength ( DLinkList *L );

//输出链表元素
void dispList ( DLinkList *L );

//求线性表中某个元素的值
ElemType GetElem ( DLinkList *L, const int iter);

//寻找链表中与值e相等的元素，并返回该元素下标
int findElem ( DLinkList *L, const ElemType e );

//插入元素到链表的指定下标的位置
bool insertElem ( DLinkList *L, int iter, ElemType e );

//删除链表指定下标的元素
bool deleteElem ( DLinkList *L, int iter );

//-------------------4、使用双向循环链表的基本操作-------------------//
void testDLinkList();

#endif
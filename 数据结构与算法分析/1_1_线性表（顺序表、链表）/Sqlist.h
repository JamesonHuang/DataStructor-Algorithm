//定义顺序表的基本操作
#ifndef _SQLIST_H_

#define MAXSIZE 100

typedef int ElemType;

struct Sqlist
{
	ElemType data[MAXSIZE];
	int length;
};
/*以下是过时的定义结构体方式：
typedef struct
{
	ElemType data[MAXSIZE];
	int length;
} Sqlist;
*/

//初始化顺序表
void initList ( Sqlist* &L );

//创建顺序表
void createList ( Sqlist *L, const ElemType elem[], const int len );

//销毁顺序表
void destroyList ( Sqlist *L );

//判断是否为空表
bool isListEmpty ( Sqlist *L );

//返回该表的长度
int listLength ( Sqlist *L );

//输出顺序表元素
void dispList ( Sqlist *L );

//求线性表中某个元素的值
ElemType GetElem ( Sqlist *L, const int iter);

//寻找顺序表中与值e相等的元素，并返回该元素下标
int findElem ( Sqlist *L, const ElemType e );

//插入元素到顺序表的指定下标的位置
bool insertElem ( Sqlist *L, int iter, ElemType e );

//删除顺序表指定下标的元素
bool deleteElem ( Sqlist *L, int iter );

//测试顺序表的基本操作
void testSqlist();

#endif
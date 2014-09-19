//@description: 实现链栈的基本操作
#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_

#include <iostream>

using namespace std;

template <class ElemType>
class LinkStack
{
public:
	//构造函数，初始化链栈
	LinkStack();
	//析构函数，销毁链栈
	~LinkStack();
	//返回链栈长度
	int StackLength();
	//判断链栈是否为空
	bool StackEmpty();
	//压栈
	bool Push(ElemType e);
	//弹栈
	bool Pop();
	//获取栈顶元素
	ElemType GetTop();
	//遍历输出栈中的元素
	void DispStack();
	
	//栈的应用：中缀转后缀
	ElemType* midToAfter(ElemType* str);	

private:
	//栈结构体
	typedef struct node
	{
		ElemType data;
		node *next;
	} LStack, *LS;

	//成员变量栈
	LS linkS;
};

//构造函数，初始化链栈
template <class ElemType>
LinkStack<ElemType>::LinkStack()
{
	linkS = new LStack();
	linkS->next = NULL;
}

//析构函数，销毁链栈
template <class ElemType>
LinkStack<ElemType>::~LinkStack()
{
	LS p;
	while(linkS->next != NULL)					//	遍历销毁
	{
		p = linkS->next;
		linkS->next = linkS->next->next;
		free(p);
	}
}

//返回链栈长度
template <class ElemType>
int LinkStack<ElemType>::StackLength()
{
	int len = 0;
	LS p = linkS->next;
	while(p != NULL)
	{
		p = p->next;
		
		len++;
	}
	return len;
}

//判断链栈是否为空
template <class ElemType>
bool LinkStack<ElemType>::StackEmpty()
{
	return ( linkS->next == NULL );
}

//压栈
template <class ElemType>
bool LinkStack<ElemType>::Push(ElemType e)
{
	LS p = new LStack();
	p->data = e;
	
	p->next = linkS->next;
	linkS->next = p;
	return 1;
}

//弹栈
template <class ElemType>
bool LinkStack<ElemType>::Pop()
{

	if( linkS->next != NULL )
	{
		LS p = linkS->next;
		linkS->next = linkS->next->next;
		free(p);
		return 1;
	}
	else
	{
		return 0;
	}
}

//获取栈顶元素
template <class ElemType>
ElemType LinkStack<ElemType>::GetTop()
{
	if(linkS->next != NULL)
	{
		return linkS->next->data;
	}
}

//遍历输出栈中的元素
template<class ElemType>
void LinkStack<ElemType>::DispStack()
{
	LS p = new LStack();
	p = linkS->next;			//此处不可以是p = linkS->next,因为会造成浅拷贝
	while( p != NULL )
	{
		cout << p->data << "  ";
		p = p->next;
	}
}
////栈的应用：中缀转后缀
//template<class ElemType>
//ElemType* LinkStack<ElemType>::midToAfter(ElemType* str)
//{
//	if(str == NULL)				//如果为空，
//	{
//		return NULL;
//	}
//	int i = 0;
//	while( str[i] != NULL )
//	{
//		if(str[i] > 48 && str[i] < 57)
//		{
//			cout << str[i];
//		}
//		else
//		{
//			
//		}
//		i++;
//	}
//}


#endif
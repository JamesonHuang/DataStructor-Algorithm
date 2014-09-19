//@description:1、实现顺序栈的基本操作
#ifndef _SQSTACK_H_

#define _SQSTACK_H_

#include <iostream>
using namespace std;

#define MaxSize 100
typedef int iter;				//栈指针		

//栈类
template <class elemType>
class SqStack
{
public:
	//栈的构造函数，初始化栈
	SqStack();
	//析构函数，销毁栈
	~SqStack();
	//获取栈的长度
	int stackLength();
	//判断栈是否为空
	int stackEmpty();
	//入栈
	bool push(elemType e);
	//出栈
	bool pop();
	//获取栈顶元素
	elemType getTop();
	//便利输出栈中元素
	void dispStack();

private:
	//栈元素的结构体
	typedef struct stackNode
	{
		elemType data[MaxSize];
		iter top;
	
	} sk, *stack;
	
	stack s;
};

//构造函数，初始化栈
template <class elemType>
SqStack<elemType>:: SqStack()
{
	s = new sk();
	s->top = -1;
}

//析构函数，销毁栈
template <class elemType>
SqStack<elemType>::~SqStack()
{
	free(s);
}

//求栈的长度
template <class elemType>
int SqStack<elemType>::stackLength()
{
	return (s->top + 1);
}

//判断栈是否为空	
template <class elemType>
int SqStack<elemType>::stackEmpty()
{
	return ( s->top == -1 );
}
//入栈
template <class elemType>
bool SqStack<elemType>::push(elemType e)
{
	if( s->top == MaxSize - 1)
	{
		return 0;
	}
	s->top++;
	s->data[s->top] = e;
	return 1;
}
//出栈	
template <class elemType>
bool SqStack<elemType>::pop()
{
	if(s->top == -1)
	{
		return 0;
	}
	s->top--;
	return 1;
}
//获取栈顶元素
template <class elemType>
elemType SqStack<elemType>::getTop()
{
	if(s->top == -1)
	{
		return 0;
	}
	return s->data[s->top];	

}

//便利输出栈中元素
template <class elemType>
void SqStack<elemType>::dispStack()
{
	for(int i = s->top; i >= 0; i--)
	{
		cout << s->data[i] << "  ";
	}
	cout << endl;
}

#endif


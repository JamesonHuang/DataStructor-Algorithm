/*********************************************************************
	@ Title:			实现栈、队基本操作	

	@ Description:		1、实现顺序栈、链栈
						
				2、实现顺序队、链队、循环队列

				3、测试顺序栈的基本操作

				4、测试链栈的基本操作

				5、实现顺序循环队列操作

				6、测试链式循环队列操作
	@ Conclusion:			

	@ Author:		rh_Jameson

	@ Date:			2014/08/09
**********************************************************************/

#include<iostream>
#include<vector>

#include"SqStack.h"
#include"LinkStack.h"
#include"circularSqQueue.h"
#include"circularLinkQueue.h"

using namespace std;


//---------------------3、测试顺序栈的基本操作-----------------------//
void testSqStack()
{
	SqStack<int>* sq = new SqStack<int>;
	for(int i = 0; i < 10; ++i)			
	{
		sq->push( i );
	}
	cout << "栈中是否有元素：" << sq->stackEmpty() << endl;
	cout << "栈顶元素是：" << sq->getTop() << endl;

	cout << "栈中元素为：" << " ";
	sq->dispStack();
	cout << "栈的长度： " << sq->stackLength() << endl;
	cout << "弹栈ing..." << endl;
	for(vector<int>::size_type i = 0; i < 10; ++i)
	{
		sq->pop();
	}
	cout << "栈中是否有元素：" << sq->stackEmpty() << endl;
}

//---------------------4、测试链栈的基本操作--------------------------//
void testLStack()
{
	LinkStack<int>* ls = new LinkStack<int>;
	for(int i = 0; i < 10; ++i)
	{
		ls->Push( i );
	}
	
	cout << "栈中是否有元素：" << ls->StackEmpty() << endl;
	
	cout << "栈顶元素是：" << ls->GetTop() << endl;
	
	cout << "栈中元素为：" << " ";
	ls->DispStack();
	cout << "栈的长度： " << ls->StackLength() << endl;
	cout << "弹栈ing..." << endl;
	for(vector<int>::size_type i = 0; i < 10; ++i)
	{
		ls->Pop();
	}
	cout << "栈中是否有元素：" << ls->StackEmpty() << endl;
}
//---------------------5、测试顺序循环队列操作-----------------------//
void testSqQueue()
{
	SqQueue<int>* q = new SqQueue<int>;
	for(int i = 0; i < 10; ++i)
	{
		q->enQueue( i );
	}	
	cout << "队中是否有元素：" << q->QueueEmpty() << endl;
	
	cout << "队首元素是：" << q->GetFront() << endl;
	cout << "队尾元素是：" << q->GetRear() << endl;
	
	cout << "队中元素为：" << " ";
	q->DispQueue();
	cout << "队的长度： " << q->QueueLength() << endl;
	cout << "出队ing..." << endl;
	for(vector<int>::size_type i = 0; i < 10; ++i)
	{
		q->deQueue();
		cout << endl;
		q->DispQueue();
	}
	cout << "队中是否有元素：" << q->QueueEmpty() << endl;
}
//------------------------6、测试链式循环队列操作--------------------//
void testLinkQueue()
{
	LQueue<int>* q = new LQueue<int>;
	for(int i = 0; i < 10; ++i)
	{
		q->enQueue( i );
	}	
	cout << "队中是否有元素：" << q->QueueEmpty() << endl;
	
	cout << "队首元素是：" << q->GetFront() << endl;
	cout << "队尾元素是：" << q->GetRear() << endl;
	
	cout << "队中元素为：" << " ";
	q->DispQueue();
	cout << "队的长度： " << q->QueueLength() << endl;
	cout << "出队ing..." << endl;
	for(vector<int>::size_type i = 0; i < 10; ++i)
	{
		q->deQueue();
		cout << endl;
		q->DispQueue();
	}
	cout << "队中是否有元素：" << q->QueueEmpty() << endl;
}
//-------------2、实现每输出10个元素，就换行，再输出-----------------//


int main()
{
	//testLinkQueue();
	//testLStack();
	
	return 0;
}
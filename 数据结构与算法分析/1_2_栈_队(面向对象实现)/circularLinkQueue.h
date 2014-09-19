#ifndef _CIRCULARLINKQUEUE_H_
#define _CIRCULARLINKQUEUE_H_

#include<iostream>
using namespace std;

#define MaxSize 100

//链式结构循环队列
template <class ElemType>
class LQueue
{
public:
	//循环队列构造函数，初始化队列
	LQueue();
	//析构函数，销毁队列
	~LQueue();
	//判断队列是否为空
	bool QueueEmpty();
	//返回队列长度
	int QueueLength();
	//入队
	bool enQueue(ElemType e);
	//出队
	bool deQueue();	
	//获取队首元素
	ElemType GetFront();
	//获取队尾元素
	ElemType GetRear();
	//遍历输出队中的元素
	void DispQueue();

private:
	//队结构体
	typedef struct Queue
	{
		ElemType data;
		Queue *next;
	} *link_queue;
	
	//队头指针
	link_queue lq;
	link_queue front, rear;
};

//循环队列构造函数，初始化队列
template <class ElemType>
LQueue<ElemType>::LQueue()
{
	lq = new Queue();			//作为头结点
	lq->next = lq;
	front = rear = lq;	
}

//析构函数，销毁队列
template <class ElemType>
LQueue<ElemType>::~LQueue()
{
	if(lq->next != lq)
	{
		link_queue p = front->next;
		link_queue q;
		while(p != front )
		{
			q = p;
			p = p->next;
			free(q);
		}
	}		
	free(lq);	
}

//判断队列是否为空
template <class ElemType>
bool LQueue<ElemType>:: QueueEmpty()
{
	return (lq->next == lq);
	//return (rear == lq);
}	
	
//返回队列长度
template <class ElemType>
int LQueue<ElemType>:: QueueLength()
{
	if(lq->next == lq)
	{
		return 0;
	}
	int len = 0;
	link_queue p = front->next;
	while(p != front)
	{
		p = p->next;
		len++;		
	}
	return len;
}	
	
//入队，判断队空--再入队
template <class ElemType>
bool LQueue<ElemType>:: enQueue(ElemType e)
{
	link_queue p = new Queue();
	p->data = e;
	p->next = front;
	rear->next = p;
	rear = rear->next;
	return 1;
}		
	
//出队
template <class ElemType>
bool LQueue<ElemType>:: deQueue()
{
	if(lq->next == lq)
	{
		return 0;
	}
	link_queue p = front->next;
	front->next = front->next->next;
	free(p);
	return 1;
}

//获取队首元素
template <class ElemType>
ElemType LQueue<ElemType>:: GetFront()
{
	return front->data;
}
	
//获取队尾元素	
template <class ElemType>
ElemType LQueue<ElemType>:: GetRear()
{
	return rear->data;
}

//遍历输出队中的元素	
template <class ElemType>
void LQueue<ElemType>:: DispQueue()
{
	if(lq->next == lq)
	{
		return;
	}
	link_queue p = front->next;
	while( p != front )
	{
		cout << p->data << " ";
		p = p->next;
	}

}	

#endif
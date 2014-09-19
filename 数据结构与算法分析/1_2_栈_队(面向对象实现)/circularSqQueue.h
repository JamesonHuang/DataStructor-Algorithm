#ifndef _CIRCULARSQQUEUE_H_
#define _CIRCULARSQQUEUE_H_

#include<iostream>
using namespace std;

#define MaxSize 100

//顺序结构循环队列
template <class ElemType>
class SqQueue
{
public:
	//循环队列构造函数，初始化队列
	SqQueue();
	//析构函数，销毁队列
	~SqQueue();
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
		ElemType data[MaxSize];
		int front, rear;
	} *sq_queue;
	
	//队指针
	sq_queue sq;
};

//循环队列构造函数，初始化队列
template <class ElemType>
SqQueue<ElemType>::SqQueue()
{
	sq = new Queue();			//实例化队对象，并将队的front、rear游标设为0
	sq->front = 0;
	sq->rear = 0;
}
//析构函数，销毁队列
template <class ElemType>
SqQueue<ElemType>::~SqQueue()
{
	free( sq );
}

//判断队列是否为空
template <class ElemType>
bool SqQueue<ElemType>:: QueueEmpty()
{
	return (sq->front == sq->rear);			//队为空时，front == rear
}	
	
//返回队列长度
template <class ElemType>
int SqQueue<ElemType>:: QueueLength()
{
	return (sq->rear - sq->front + MaxSize) % MaxSize;			//求循环顺序队列的长度公式
}	
	
//入队，判断队空--再入队
template <class ElemType>
bool SqQueue<ElemType>:: enQueue(ElemType e)
{
	if( (sq->rear + 1) % MaxSize == sq->front )					
	{
		return 0;
	}
	sq->rear++;
	sq->data[sq->rear] = e;
	return 1;
}		
	
//出队
template <class ElemType>
bool SqQueue<ElemType>:: deQueue()
{
	if(sq->front == sq->rear)
	{
		return 0;
	}	
	sq->front++;
	sq->data[sq->front] = 0;
	return 1;
}

//获取队首元素
template <class ElemType>
ElemType SqQueue<ElemType>:: GetFront()
{
	int tmp = sq->front + 1;
	return sq->data[tmp];
}
	
//获取队尾元素	
template <class ElemType>
ElemType SqQueue<ElemType>:: GetRear()
{
	return sq->data[sq->rear];
}

//遍历输出队中的元素	
template <class ElemType>
void SqQueue<ElemType>:: DispQueue()
{
	if(sq->front == sq->rear)
	{
		return;
	}
	int iter = sq->front;
	while( (iter + 1) % MaxSize != sq->rear )
	{
		cout<<	sq->data[++iter] << " ";
	}
	cout << sq->data[++iter];
}	

#endif
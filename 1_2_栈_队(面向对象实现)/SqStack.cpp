//#include<iostream>
//#include "SqStack.h"
//
//using namespace std;
//
//template <class elemType>
//SqStack<elemType>:: SqStack()
//{
//	s = new sk;
//	s->top = -1;
//}
//
//template <class elemType>
//SqStack<elemType>::~SqStack()
//{
//	free(s);
//}
//
//template <class elemType>
//int SqStack<elemType>::stackLength()
//{
//	return (s->top + 1);
//}
//	
//template <class elemType>
//int SqStack<elemType>::stackEmpty()
//{
//	return ( s->top == -1 );
//}
//
//template <class elemType>
//bool SqStack<elemType>::push(elemType e)
//{
//	if( s->top == MaxSize - 1)
//	{
//		return 0;
//	}
//	s->top++;
//	s->data[s->top] = e;
//	return 1;
//}
//	
//template <class elemType>
//bool SqStack<elemType>::pop()
//{
//	if(s->top == -1)
//	{
//		return 0;
//	}
//	s->top--;
//	return 1;
//}
//
//template <class elemType>
//elemType SqStack<elemType>::getTop()
//{
//	if(s->top == -1)
//	{
//		return 0;
//	}
//	return s->data[s->top];	
//
//}
//
//template <class elemType>
//void SqStack<elemType>::dispStack()
//{
//	for(int i = s->top; i >= 0; i--)
//	{
//		cout << s->data[i] << "  ";
//	}
//	cout << endl;
//}


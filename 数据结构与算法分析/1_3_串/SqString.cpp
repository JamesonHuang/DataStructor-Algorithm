#include "SqString.h"

//串的构造函数
SqString::SqString()
{
	s = new str();
	s->length = 0;
	s->data = new char[MAXSIZE];
}

//串的析构函数
SqString::~SqString()
{
	delete s;
	s = NULL;
}

//获取SqStr
str SqString::getSqStr()
{
	return *s;
}

//将一个串常量赋给目标串
str SqString::strAssign(char* t)
{	
	//方法一：字符指针数组形式使用
	/*int i = 0;
	while(t[i] != '\0')			//遍历串t
	{
		s->data[i] = t[i];		//赋值给目标串				
		cout << s->data[i] << endl;
		i++;				
	}*/

	//方法二：直接操作指针
	while(*t != '\0')			//遍历串t
	{
		*(s->data) = *t;		//赋值给目标串				
		cout << *(s->data) << endl;
		t++;
		s->data++;
		s->length++;
	}
	return *s;
}

//将串t复制给目标串
str SqString::strCopy(SqStr t)
{
	while(*(t->data) != '\0')
	{
		
	}
	//浅拷贝
	//s = t;
	return *s;
}
////判断串是否相等
//bool SqString::strEqual (SqStr t)
//{
//}
////求串长
//int SqString::strLength()
//{
//}
////串连接
//str SqString::Concat(SqStr t)
//{
//}
////求子串
//str SqString::subStr(int i, int j)
//{
//}
////插入串
//str SqString::insertStr(int i, SqStr t)
//{
//}
////删除指定范围的串
//str SqString::delStr(int i, int j)
//{
//}
////替换指定子串
//str SqString::repStr(int i, int j, SqStr t)
//{
//
//}
////遍历输出串
//void SqString::dispStr()
//{
//
//}
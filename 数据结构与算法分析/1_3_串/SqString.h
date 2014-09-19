#ifndef _SQSTRING_H_
#define	_SQSTRING_H_

#include "config.h"

//顺序串的结构体
typedef struct str
{
	//char data[MAXSIZE];
	char* data;
	int length;
} *SqStr;

//顺序串
class SqString
{
private:
	//串成员变量
	SqStr s;
public:
	//串的构造函数
	SqString();
	//串的析构函数
	~SqString();
	//获取SqStr
	str getSqStr();
	//将一个串常量赋给目标串
	str strAssign(char* t);
	//将串t复制给目标串
	str strCopy (SqStr t);
	//判断串是否相等
	bool strEqual (SqStr t);
	//求串长
	int strLength();
	//串连接
	str Concat(SqStr t);
	//求子串
	str subStr(int i, int j);
	//插入串
	str insertStr(int i, SqStr t);
	//删除指定范围的串
	str delStr(int i, int j);
	//替换指定子串
	str repStr(int i, int j, SqStr t);
	//遍历输出串
	void dispStr();
};

#endif
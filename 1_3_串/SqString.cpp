#include "SqString.h"

//′?μ?11?ìoˉêy
SqString::SqString()
{
	s = new str();
	s->length = 0;
	s->data = new char[MAXSIZE];
}

//′?μ???11oˉêy
SqString::~SqString()
{
	delete s;
	s = NULL;
}

//??è?SqStr
str SqString::getSqStr()
{
	return *s;
}

//??ò???′?3￡á??3????±ê′?
str SqString::strAssign(char* t)
{	
	//·?·¨ò?￡o×?·?????êy×éD?ê?ê1ó?
	/*int i = 0;
	while(t[i] != '\0')			//±éàú′?t
	{
		s->data[i] = t[i];		//?3?μ????±ê′?				
		cout << s->data[i] << endl;
		i++;				
	}*/

	//·?·¨?t￡o?±?ó2ù×÷????
	while(*t != '\0')			//±éàú′?t
	{
		*(s->data) = *t;		//?3?μ????±ê′?				
		cout << *(s->data) << endl;
		t++;
		s->data++;
		s->length++;
	}
	return *s;
}

//??′?t?′??????±ê′?
str SqString::strCopy(SqStr t)
{
	while(*(t->data) != '\0')
	{
		
	}
	//?3??±′
	//s = t;
	return *s;
}
////?D??′?ê?·??àμè
//bool SqString::strEqual (SqStr t)
//{
//}
////?ó′?3¤
//int SqString::strLength()
//{
//}
////′?á??ó
//str SqString::Concat(SqStr t)
//{
//}
////?ó×ó′?
//str SqString::subStr(int i, int j)
//{
//}
////2?è?′?
//str SqString::insertStr(int i, SqStr t)
//{
//}
////é?3y???¨·??§μ?′?
//str SqString::delStr(int i, int j)
//{
//}
////ì??????¨×ó′?
//str SqString::repStr(int i, int j, SqStr t)
//{
//
//}
////±éàúê?3?′?
//void SqString::dispStr()
//{
//
//}